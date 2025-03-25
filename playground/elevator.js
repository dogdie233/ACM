export default {
    init: function(elevators, floors) {
        brain = {
            waiting: [],
        };

        for (var i = 0; i < floors.length; i++) {
            brain.waiting.push({
                "up": false,
                "down": false,
            });
        }

        function isOnWay(elevator, floorNum, direction) {
            if (elevator.destinationDirection() === "up" && floorNum > elevator.currentFloor()) {
                if (direction === "up" && elevator.destinationQueue[elevator.destinationQueue.length - 1] >= floorNum) {
                    return true;
                }
                if (direction === "down" && floorNum >= elevator.destinationQueue[elevator.destinationQueue.length - 1]) {
                    return true;
                }
            }
            if (elevator.destinationDirection() === "down" && floorNum < elevator.currentFloor()) {
                if (direction === "down" && elevator.destinationQueue[elevator.destinationQueue.length - 1] <= floorNum) {
                    return true;
                }
                if (direction === "up" && floorNum <= elevator.destinationQueue[elevator.destinationQueue.length - 1]) {
                    return true;
                }
            }
            return false;
        }

        function callBestElevator(floorNum, direction) {
            let onWayElevators = elevators.filter(elevator => isOnWay(elevator, floorNum, direction) && elevator.loadFactor() < 0.8);
            if (onWayElevators.length > 0) {
                var elevator = onWayElevators[0];
                if (floorNum - elevator.currentFloor() > 0 && elevator.destinationDirection() === "up") {
                    elevator.destinationQueue[elevator.destinationQueue.length - 1] = floorNum;
                    elevator.checkDestinationQueue();
                } else if (floorNum - elevator.currentFloor() < 0 && elevator.destinationDirection() === "down") {
                    elevator.destinationQueue[elevator.destinationQueue.length - 1] = floorNum;
                    elevator.checkDestinationQueue();
                }
                return;  // 等他自己走到
            }

            let idleElevators = elevators.filter(elevator => elevator.destinationDirection() === "stopped");
            if (idleElevators.length > 0) {
                let closestElevator = idleElevators.reduce((prev, curr) => {
                    return Math.abs(curr.currentFloor() - floorNum) < Math.abs(prev.currentFloor() - floorNum) ? curr : prev;
                });
                idleGoTo(closestElevator, floorNum, direction);
                return;
            }
            return;
        }

        function idleGoToBestWaiting(elevator) {
            if (elevator.destinationQueue.length > 0) return;
            let bestWaiting = brain.waiting.reduce((prev, curr, index) => {
                if (curr.up || curr.down) {
                    return Math.abs(index - elevator.currentFloor()) < Math.abs(prev - elevator.currentFloor()) ? index : prev;
                }
                return prev;
            }, -1);
            if (bestWaiting === -1) return;
            idleGoTo(elevator, bestWaiting, brain.waiting[bestWaiting].up ? "up" : "down");
        }

        function idleGoTo(elevator, floorNum, direction) {
            if (elevator.destinationDirection() != "stopped") return;
            elevator.goToFloor(floorNum);
            if (elevator.currentFloor() === floorNum) {
                elevator.goingUpIndicator(direction === "up");
                elevator.goingDownIndicator(direction === "down");
            } else {
                elevator.goingUpIndicator(elevator.currentFloor() < floorNum);
                elevator.goingDownIndicator(elevator.currentFloor() > floorNum);
            }
        }

        elevators.forEach(elevator => {
            elevator.on("passing_floor", (floorNum, direction) => {
                if (brain.waiting[floorNum][direction] && elevator.loadFactor() < 0.8) {
                    elevator.goToFloor(floorNum, true);
                    brain.waiting[floorNum][direction] = false;
                    return;
                }
                if (elevator.getPressedFloors().includes(floorNum)) {
                    elevator.goToFloor(floorNum, true);
                    return;
                }
            });
            elevator.on("stopped_at_floor", floorNum => {
                if (elevator.goingUpIndicator()) {
                    brain.waiting[floorNum].up = false;
                }
                if (elevator.goingDownIndicator()) {
                    brain.waiting[floorNum].down = false;
                }
                if (elevator.destinationDirection() === "stopped") {
                    const newDest = elevator.destinationDirection() === "up"
                        ? elevator.getPressedFloors().reduce((prev, curr) => curr > prev ? curr : prev)
                        : elevator.destinationDirection() === "down"
                            ? elevator.getPressedFloors().reduce((prev, curr) => curr < prev ? curr : prev)
                            : null;
                    if (newDest) {
                        elevator.goToFloor(newDest);
                        elevator.goingUpIndicator(newDest > elevator.currentFloor());
                        elevator.goingDownIndicator(newDest < elevator.currentFloor());
                        return;
                    }
                }
            });
            elevator.on("floor_button_pressed", floorNum => {
                if (elevator.destinationQueue.length > 0 && elevator.destinationDirection() === "up" && floorNum > elevator.destinationQueue[elevator.destinationQueue.length - 1]) {
                    elevator.destinationQueue[elevator.destinationQueue.length - 1] = floorNum;
                    elevator.checkDestinationQueue();
                    return;
                }
                if (elevator.destinationQueue.length > 0 && elevator.destinationDirection() === "down" && floorNum < elevator.destinationQueue[elevator.destinationQueue.length - 1]) {
                    elevator.destinationQueue[elevator.destinationQueue.length - 1] = floorNum;
                    elevator.checkDestinationQueue();
                    return;
                }
                if (elevator.destinationDirection() === "stopped") {
                    elevator.goToFloor(floorNum);
                    elevator.goingUpIndicator(floorNum > elevator.currentFloor());
                    elevator.goingDownIndicator(floorNum < elevator.currentFloor());
                }
            });

            elevator.goingUpIndicator(false);
            elevator.goingDownIndicator(false);
        });

        floors.forEach(floor => {
            floor.on("up_button_pressed", () => {
                brain.waiting[floor.floorNum()].up = true;
                callBestElevator(floor.floorNum(), "up");
            });
            floor.on("down_button_pressed", () => {
                brain.waiting[floor.floorNum()].down = true;
                callBestElevator(floor.floorNum(), "down");
            });
        })
    },
    update: function(dt, elevators, floors) {
        
    }
}
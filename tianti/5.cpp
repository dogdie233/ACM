#include <iostream>
#include <stdint.h>
#include <map>

using namespace std;

struct Student {
    uint64_t id;
    int seat1, seat2;
};

int main() {
    map<int, Student> students;
    int N, M, seat1;
    cin >> N;
    while (N--) {
        Student student;
        cin >> student.id >> student.seat1 >> student.seat2;
        students[student.seat1] = student;
    }

    cin >> M;
    while (M--) {
        cin >> seat1;
        cout << students[seat1].id << " " << students[seat1].seat2 << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

typedef int num_t;

using namespace std;

struct Guest {
    num_t a, b;
    bool asked;

    Guest() : a(0), b(0), asked(false) {}
};

int main() {
    num_t n, k, guestCrying = 0;
    cin >> n >> k;
    auto guests = vector<Guest>(k);
    for (auto& guest : guests) {
        cin >> guest.a >> guest.b;
    }
    auto whoSuki = vector<vector<Guest*>>(n + 1);
    for (auto& guest : guests) {
        whoSuki[guest.a].push_back(&guest);
        whoSuki[guest.b].push_back(&guest);
    }

    vector<bool> ateFood(n + 1, false);
    auto eat = [&](auto&& self, int type) -> void {
        auto suki = whoSuki[type];
        for (auto& guest : suki) {
            if (guest->asked) continue;
            guest->asked = true;
            if (ateFood[guest->a] && ateFood[guest->b]) {
                guestCrying++;
                continue;
            }
            ateFood[guest->a] = true;
            ateFood[guest->b] = true;
            self(self, guest->a == type ? guest->b : guest->a);
        }
    };

    for (auto& guest : guests) {
        if (guest.asked) continue;
        eat(eat, guest.a);
    }

    cout << guestCrying;

    return 0;
}
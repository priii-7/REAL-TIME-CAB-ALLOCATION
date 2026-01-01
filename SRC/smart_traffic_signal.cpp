#include <bits/stdc++.h>
using namespace std;

struct Road {
    int id;           
    int vehicles;     
    bool emergency;   
};

struct Intersection {
    int id;                 
    vector<Road> roads;     
};

void controlSignal(Intersection &intersection) {

    for (auto &road : intersection.roads) {
        if (road.emergency) {
            cout << "Intersection " << intersection.id
                 << " -> EMERGENCY PRIORITY for Road "
                 << road.id << " 🚑" << endl;
            return;
        }
    }
    
    priority_queue<pair<int, int>> pq;

    for (auto &road : intersection.roads) {
        pq.push({road.vehicles, road.id});
    }

    auto top = pq.top();

    cout << "Intersection " << intersection.id
         << " -> Green signal for Road "
         << top.second << " ("
         << top.first << " vehicles)" << endl;
}

int main() {

    vector<Intersection> city = {

        {0, {
                {0, 10, false},
                {1, 30, false},
                {2, 5,  false}
            }
        },

        {1, {
                {0, 25, true},   
                {1, 15, false},
                {2, 20, false}
            }
        },

        {2, {
                {0, 40, false},
                {1, 10, false}
            }
        }
    };

    for (auto &intersection : city) {
        controlSignal(intersection);
    }

    return 0;
}

#include <iostream>
#include <vector>
#include "Amithi_Bhawsar_project2.h"
using namespace std;

int main() {
    cout << "=== test: birthday_attack_1 ===" << endl;
    auto out1 = birthday_attack_1(test_hash);
    if (out1.empty()) cout << "No collision found (1)\n";
    else cout << "Collision: " << out1[0] << " , " << out1[1] << endl;

    cout << "\n=== test: birthday_attack_2 ===" << endl;
    auto out2 = birthday_attack_2(test_hash);
    if (out2.size() == 2) cout << "Collision (2): " << out2[0] << " , " << out2[1] << endl;
    else cout << "No collision from attack 2\n";

    cout << "\n=== test: topological_sort (simple) ===" << endl;
    {
        vector<Edge> edges = {{5,2,0},{5,0,0},{4,0,0},{4,1,0},{2,3,0},{3,1,0}};
        auto topo = topological_sort(6, edges);
        if (topo.empty()) cout << "No topo (cycle?)\n";
        else { for (int v: topo) cout << v << " "; cout << endl; }
    }

    cout << "\n=== test: dag_single_source (simple) ===" << endl;
    {
        vector<Edge> edges = {{0,1,5},{0,2,3},{1,3,6},{2,1,2},{2,3,7}};
        auto dist = dag_single_source(4, edges, 0);
        for (int d : dist) {
            if (d == INT_MAX) cout << "inf ";
            else cout << d << " ";
        }
        cout << endl;
    }


}


#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // freopen("gymnastics.in", "r", stdin);
    // freopen("gymnastics.out", "w", stdout);

    int numExercises;
    cin >> numExercises;

    int numCows;
    cin >> numCows;

    vector<int> cowPosition(numExercises, 0);
    vector<vector<int>> cowVector(numCows, cowPosition);

    for (int i = 0; i < numExercises; ++i) {
        for (int j = 0; j < numCows; ++j) {
            cin >> cowVector[j][i];
        }
    }

    int numConsitent = 0;
    bool isConsistent = false;
    for (int i = 0; i < numCows; ++i) {
        for (int j = 0; j < numCows; ++j) {
            isConsistent = true;
            for (int k = 0; k < numExercises; ++k) {
                if (cowVector[i][k] >= cowVector[j][k]) {
                    isConsistent = false;
                }
            }
            if (isConsistent) {
                numConsitent++;
            }
        }
    }

    cout << numConsitent << "\n";
    return 0;
}

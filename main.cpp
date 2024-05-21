#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int numExercises;
    cin >> numExercises;

    int numCows;
    cin >> numCows;

    vector<vector<int>> cowVector(numCows, vector<int> (numExercises, 0));

    int cow;
    for (int i = 0; i < numExercises; ++i) {
        for (int j = 0; j < numCows; ++j) {
            cin >> cow;
            cowVector[cow - 1][i] = j;
        }
    }

    int numConsistent = 0; bool isConsistent = false;
    for (int i = 0; i < numCows; ++i) {
        for (int j = 0; j < numCows; ++j) {
            isConsistent = true;
            for (int k = 0; k < numExercises; ++k) {
                if (cowVector[i][k] >= cowVector[j][k]) {
                    isConsistent = false;
                }
            }
            if (isConsistent) {
                numConsistent++;
            }
        }
    }

    cout << numConsistent << "\n";
    return 0;
}

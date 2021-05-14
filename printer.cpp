#include <iostream>
#include <vector>
using namespace std;

void vectorPrint(vector<vector<vector<int>>> solver) {
    for (int i = 0; i < solver.size(); i++) {
        for (int j = 0; j < solver.at(i).size(); j++) {
            for (int k = 0; k < solver.at(i).at(j).size(); k++) {
                cout << solver.at(i).at(j).at(k) << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

void sudokuPrint(vector<vector<int>> sudoku) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku.at(i).at(j) << " ";
        }
        cout << "\n";
    }
}

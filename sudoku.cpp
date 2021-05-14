#include <iostream>
#include <vector>

#include "printer.h"
#include "removeAccess.h"
using namespace std;

vector<vector<vector<int>>> solver(9, vector<vector<int>>(9));

vector<vector<int>> checkPossible(vector<vector<int>> sudoku) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (solver.at(i).at(j).size() == 1 &&
                solver.at(i).at(j).at(0) != 0) {
                sudoku.at(i).at(j) = solver.at(i).at(j).at(0);
                removeAccess(i, j, sudoku.at(i).at(j));
            }
        }
    }
    return sudoku;
}

int main() {
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            solver.at(i).at(j) = numbers;
        }
    }
    vector<vector<int>> sudoku(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku.at(i).at(j);
            if (sudoku.at(i).at(j) != 0) {
                removeAccess(i, j, sudoku.at(i).at(j));
            }
        }
    }
    cout << "\n";
    for (int i = 0; i < 20; i++) {
        sudoku = checkPossible(sudoku);
    }
    vectorPrint(solver);
    cout << "\n";
    sudokuPrint(sudoku);
    return 0;
}
#include <vector>

#include "removeAccess.h"
using namespace std;
extern vector<vector<vector<int>>> solver;
vector<vector<int>> findPossible(vector<vector<int>> sudoku) {
    for (int number = 1; number < 10; number++) {
        for (int row = 0; row < 9; row++) {
            int row_count = 0, ro_no;
            for (int i = 0; i < 9; i++) {
                if (sudoku.at(row).at(i) == number) {
                    row_count++;
                    ro_no = i;
                }
                for (int j = 0; j < solver.at(row).at(i).size(); j++) {
                    if (solver.at(row).at(i).at(j) == number) {
                        row_count++;
                        ro_no = i;
                        break;
                    }
                }
            }
            if (row_count == 1) {
                sudoku.at(row).at(ro_no) = number;
                removeAccess(row, ro_no, number);
            }
        }

        for (int col = 0; col < 9; col++) {
            int col_count = 0, co_no;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < solver.at(i).at(col).size(); j++) {
                    if (solver.at(i).at(col).at(j) == number) {
                        col_count++;
                        co_no = i;
                        break;
                    }
                }
                if (sudoku.at(i).at(col) == number) {
                    col_count++;
                    co_no = i;
                }
            }
            if (col_count == 1) {
                sudoku.at(co_no).at(col) = number;
                removeAccess(co_no, col, number);
            }
        }

        for (int row = 0; row < 9; row += 3) {
            for (int column = 0; column < 9; column += 3) {
                int box_count = 0, r, c;
                for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++) {
                    for (int j = (column / 3) * 3; j < (column / 3) * 3 + 3;
                         j++) {
                        for (int k = 0; k < solver.at(i).at(j).size(); k++) {
                            if (solver.at(i).at(j).at(k) == number) {
                                r = i;
                                c = j;
                                box_count++;
                            }
                        }
                        if (sudoku.at(i).at(j) == number) {
                            r = i;
                            c = j;
                            box_count++;
                        }
                    }
                }
                if (box_count == 1) {
                    sudoku.at(r).at(c) = number;
                    removeAccess(r, c, number);
                }
            }
        }
    }
    return sudoku;
}

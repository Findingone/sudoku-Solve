#include <vector>
using namespace std;
extern vector<vector<vector<int>>> solver;
void removeAccess(int row, int column, int val) {
    vector<int> zero{0};
    solver.at(row).at(column).swap(zero);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < solver.at(row).at(i).size(); j++) {
            if (solver.at(row).at(i).at(j) == val) {
                solver.at(row).at(i).erase(solver.at(row).at(i).begin() + j);
                break;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < solver.at(i).at(column).size(); j++) {
            if (solver.at(i).at(column).at(j) == val) {
                solver.at(i).at(column).erase(solver.at(i).at(column).begin() +
                                              j);
                break;
            }
        }
    }
    for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++) {
        for (int j = (column / 3) * 3; j < (column / 3) * 3 + 3; j++) {
            for (int k = 0; k < solver.at(i).at(j).size(); k++) {
                if (solver.at(i).at(j).at(k) == val) {
                    solver.at(i).at(j).erase(solver.at(i).at(j).begin() + k);
                    break;
                }
            }
        }
    }
}

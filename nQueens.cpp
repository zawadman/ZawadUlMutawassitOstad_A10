#include <iostream>
#include <vector>
#include <cmath>  
using namespace std;

// 1) Define our Position struct:
struct Position {
    int row, col;
};

class Solution {
public:
    //returns number of ways to place n queens
    int totalNQueens(int n) {
        int count = 0;
        vector<Position> placed;
        backtrack(0, n, placed, count);
        return count;
    }

private:
    //recursion + backtracking
    void backtrack(int row,int n,vector<Position>& placed,int& count) {
        if (row == n) {
            // placed n queens successfully
            ++count;
            return;
        }
        // try every column on this row
        for (int col = 0; col < n; ++col) {
            if (isValid(placed, row, col)) {
                placed.push_back({row, col});
                backtrack(row + 1, n, placed, count);
                placed.pop_back();    // undo
            }
        }
    }

    // check if (row,col) conflicts with any already-placed queen
    bool isValid(const vector<Position>& placed,int row, int col) {
        for (auto& p : placed) {
            if (p.row == row                // same row
             || p.col == col                // same col
             || abs(p.row - row) == abs(p.col - col)) // same diag
            {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    cout << sol.totalNQueens(n) << "\n";
    return 0;
}

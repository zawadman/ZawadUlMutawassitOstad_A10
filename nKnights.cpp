#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Position
{
    int row, col;
};

class Solution
{
public:
    int maxKnights(int n)
    {
        this->n = n;
        best = 0;
        vector<Position> placed;
        dfs(0, placed);
        return best;
    }

private:
    int n, best;

    void dfs(int idx, vector<Position>& placed)
    {
        if (idx == n * n)
        {
            // all cells considered , record how many placed
            best = max(best, (int)placed.size());
            return;
        }
        // prune even if placed on every remaining cell,
        int remain = n * n - idx;
        if ((int)placed.size() + remain <= best)
        {
            return;
        }

        // skip this cell
        dfs(idx + 1, placed);

        // try to place
        int r = idx / n;
        int c = idx % n;
        if (canPlace(placed, r, c))
        {
            placed.push_back({r, c});
            dfs(idx + 1, placed);
            placed.pop_back();
        }
    }

    bool canPlace(const vector<Position>& placed, int r, int c)
    {
        for (auto& p : placed)
        {
            int dr = abs(p.row - r),
                dc = abs(p.col - c);
            if ((dr == 1 && dc == 2) || (dr == 2 && dc == 1))
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    cout << sol.maxKnights(n) << "\n";
    return 0;
}

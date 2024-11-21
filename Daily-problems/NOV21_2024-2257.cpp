class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
        // 0 = free, 1 = Guard, 2 = Wall, 3 = Guarded
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto &guard : guards)
            grid[guard[0]][guard[1]] = 1; // Marking guards
        for (auto &wall : walls)
            grid[wall[0]][wall[1]] = 2; // Marking walls

        auto mark_guarded = [&](int r, int c) {
            for (int row = r + 1; row < m; row++) {
                if (grid[row][c] == 1 || grid[row][c] == 2)
                    break;
                grid[row][c] = 3;
            }
            for (int row = r - 1; row >= 0; row--) {
                if (grid[row][c] == 1 || grid[row][c] == 2)
                    break;
                grid[row][c] = 3;
            }
            for (int col = c + 1; col < n; col++) {
                if (grid[r][col] == 1 || grid[r][col] == 2)
                    break;
                grid[r][col] = 3;
            }
            for (int col = c - 1; col >= 0; col--) {
                if (grid[r][col] == 1 || grid[r][col] == 2)
                    break;
                grid[r][col] = 3;
            }
        };

        for (auto &guard : guards)
            mark_guarded(guard[0], guard[1]); // Marking cells that are being guarded

        int ans = 0;
        for (auto &row : grid) {
            for (auto cell : row) {
                if (cell == 0)
                    ans++;
            }
        }

        return ans;
    }
};
class Solution
{
public:
    int m, n;
    bool checkBounds(int i, int j)
    {
        return !(i < 0 or j < 0 or i >= m or j >= n);
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rotten = 0, fresh = 0;
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2)
                {
                    rotten++;
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        if (fresh == 0)
            return 0;
        int minutes = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                pair<int, int> p = q.front();
                int x = p.first, y = p.second;
                q.pop();
                if (grid[x][y] == 1)
                {
                    grid[x][y] = 2;
                    fresh--;
                    if (fresh == 0)
                        return minutes;
                }

                if (grid[x][y] != 0)
                {
                    if (checkBounds(x + 1, y) and !visited[x + 1][y])
                    {
                        q.push({x + 1, y});
                        visited[x + 1][y] = true;
                    }
                    if (checkBounds(x - 1, y) and !visited[x - 1][y])
                    {
                        q.push({x - 1, y});
                        visited[x - 1][y] = true;
                    }
                    if (checkBounds(x, y + 1) and !visited[x][y + 1])
                    {
                        q.push({x, y + 1});
                        visited[x][y + 1] = true;
                    }
                    if (checkBounds(x, y - 1) and !visited[x][y - 1])
                    {
                        q.push({x, y - 1});
                        visited[x][y - 1] = true;
                    }
                }
            }
            minutes++;
        }
        return (fresh != 0) ? -1 : minutes - 1;
    }
};
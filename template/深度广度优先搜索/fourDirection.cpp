//四个方向上进行广度优先搜索
class Solution {
    static constexpr int DIRS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int nearestExit(vector<vector<char>>& g, vector<int>& entrance) {
        int m = g.size(), n = g[0].size();
        bool vis[m][n]; memset(vis, 0, sizeof(vis));
        vis[entrance[0]][entrance[1]] = true;
        vector<tuple<int, int>> q = {{entrance[0], entrance[1]}}; // 初始位置
        for (int step = 1; !q.empty(); ++step) {
            vector<tuple<int, int>> nxt;
            for (const auto &[X, Y] : q) {
                for (const auto &d : DIRS) {
                    int x = X + d[0], y = Y + d[1];
                    if (x<m && y<n && x>=0 && y>=0 &&!vis[x][y] && g[x][y] == '.') {
                        if (x == m - 1 || y == n - 1 || x==0 ||y==0) return step; // 此时蛇头一定在 (n-1,n-1)
                        vis[x][y] = true;
                        nxt.emplace_back(x, y);
                    }
                }
            }
            q = move(nxt);
        }
        return -1;
    }
};
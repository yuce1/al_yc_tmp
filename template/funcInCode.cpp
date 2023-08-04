
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>> &edges) {
        auto bfs = [&](int start) -> int { // 返回从 start 出发的最大深度
            int depth = 0;
            time[start] = ++clock;
            vector<int> q = {start};
            while (!q.empty()) {
                vector<int> nxt;
                for (int x : q)
                    for (int y : g[x])
                        if (time[y] != clock) { // 没有在同一次 BFS 中访问过
                            time[y] = clock;
                            nxt.push_back(y);
                        }
                q = move(nxt);
                ++depth;
            }
            return depth;
        };

        function<bool(int, int8_t)> is_bipartite = [&](int x, int8_t c) -> bool { // 二分图判定，原理见视频讲解
            nodes.push_back(x);
            color[x] = c;
            for (int y : g[x])
                if (color[y] == c || color[y] == 0 && !is_bipartite(y, -c))
                    return false;
            return true;
        };

    }
};

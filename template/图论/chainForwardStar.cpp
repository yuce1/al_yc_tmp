const int N = 2e4 + 10, M = 4e4 + 10;
int h[N], e[M], ne[M], idx = 0;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        memset(h, -1 ,sizeof h);
        for (auto edge : edges) {
            // 无向边要连接两次
            add(edge[0], edge[1]);
            add(edge[1], edge[0]);
        }

        while (q.size()) {
            int sz = q.size();      // 当前层有多少结点

            for (int i = 0; i<sz; i++) {
                int t = q.front();
                q.pop();
                res.push_back(t);
                for (int i = h[t]; i!=-1; i = ne[i]) {
                    int j = e[i];
                }
            }
        }
    }

    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
};
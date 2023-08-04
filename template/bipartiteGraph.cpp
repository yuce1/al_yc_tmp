//二分图判定
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int8_t color[graph.size()]; 
        memset(color, 0, sizeof(color));
        //二分图判定函数
        function<bool(int, int8_t)> is_bipartite = [&](int x, int8_t c) -> bool { 
            color[x] = c;
            for (int y : graph[x])
                if (color[y] == c || color[y] == 0 && !is_bipartite(y, -c))
                    return false;
            return true;
        };
        for (int i = 0; i < graph.size(); ++i) {
            if (color[i]) continue;
            if (!is_bipartite(i, 1)) return false;
        }
        return true;

    }
};
# include<iostream>
# include<cstring>
# include<algorithm>

using namespace std;
// N**2相对M来说小 是一个稀疏图 采用邻接矩阵存储
const int N = 510,M = 100010,INF = 0x3f3f3f3f;
int g[N][N];
int n,m;
// 记录距离源点的距离
int d[N];
// 标记当前结点是否在集合中
bool st[N];

void Dijkstra(){
    // 初始化距离为正无穷
    memset(d,INF,sizeof(d));
    d[1] = 0;
    // 循环n次(或者n-1次)
    for(int i=1;i<=n;++i){
        // 寻找当前未加入集合中最小的权值
        int t = -1;
        for(int j=1;j<=n;++j){
            if(!st[j] && (t == -1 || d[j] < d[t])){
                t = j;
            }
        }
        // 已经可以推出了  n号结点最短路已经被更新
        if(t == n) break;
        // 当前权值最小结点加入集合
        st[t] = true;
        // 枚举并更新相邻结点
        for(int j=1;j<=n;++j){
            if(d[j] > d[t] + g[t][j]){
                d[j] = d[t] + g[t][j];
            }
        }
    }
}
int main(){
    memset(g,INF,sizeof(g));
    cin >> n >> m;
    
    int a,b,w;
    for(int i=1;i<=m;++i){
        cin >> a >> b >> w;
        // 这是因为图中可能存在重边(只保留最小的权值)
        g[a][b] = min(g[a][b],w);
    }
    
    Dijkstra();
    
    if(d[n] == INF){
        puts("-1");
    }else{
        printf("%d",d[n]);
    }
    
    return 0;
}



//
void Dijkstra(vector<vector<int>>& graph, vector<int>& distances, vector<bool>& visited, int n, int distanceThreshold, int start) {
        distances[start] = 0; //自身到自身的距离为0
        for (int i=0; i<n; ++i) {
            int u=-1, minDis = INT_MAX;
            for (int j=0; j<n; ++j) {
                if (!visited[j] && distances[j] < minDis) {
                    u = j;
                    minDis = distances[j];
                }
            }
            if (u==-1) return; //所有点不可达
            visited[u] = true;
            for (int v=0; v<n; ++v) {
                if (!visited[v] && graph[u][v] != INT_MAX) {
                    if (distances[u] + graph[u][v] < distances[v]) {
                        distances[v] = distances[u] + graph[u][v];
                    }
                }
            }
        }
    }

作者：sui-xin-yuan
链接：https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/solution/zui-duan-lu-jing-mo-ban-da-ji-he-cban-fl-gs7u/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



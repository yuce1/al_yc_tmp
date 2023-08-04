# include<iostream>
# include<cstring>
# include<algorithm>
# include<queue>

using namespace std;
typedef pair<int,int> PII;
// N**2相对M来说小 是一个稀疏图 采用邻接矩阵存储
const int N = 150010,M = 150010,INF = 0x3f3f3f3f;
int h[N],e[M],w[M],ne[M],idx;
int n,m;
// 记录距离源点的距离
int d[N];
// 标记当前结点是否在集合中
bool st[N];
void add(int a,int b,int _w){
    e[idx] = b,w[idx] = _w,ne[idx] = h[a],h[a] = idx ++;
}

void Dijkstra(){
    // 初始化距离为正无穷
    memset(d,INF,sizeof(d));
    d[1] = 0;
    // 采用小根堆距离存正 等价于大根堆距离存负
    priority_queue<PII> pq;
    pq.push({0,1});
    
    while(!pq.empty()){
        // 这里t不能用引用 因为会出队 数值可能发生变化
        auto t = pq.top();pq.pop();
        int u = t.second;
        if(st[u]) continue;
        st[u] = true;
        // 更新相邻结点距离源点距离
        for(int i=h[u];i!=-1;i=ne[i]){
            int j = e[i];
            if(d[j] > d[u] + w[i]){
                d[j] = d[u] + w[i];
                pq.push({-d[j],j});
            }
        }
    }
}
int main(){
    cin >> n >> m;
    
    memset(h,-1,sizeof(h));
    int a,b,_w;
    for(int i=1;i<=m;++i){
        cin >> a >> b >> _w;
        // 这是因为图中可能存在重边(只保留最小的权值)
        add(a,b,_w);
    }
    
    Dijkstra();
    
    if(d[n] == INF){
        puts("-1");
    }else{
        printf("%d",d[n]);
    }
    
    return 0;
}



//堆优化

void Dijkstra(vector<vector<int>>& graph, vector<int>& distances, int n, int distanceThreshold, int start) {
        //小顶堆，按照距离dist从小到大排序，pair中first存dist
        priority_queue <pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> q;
        distances[start] = 0;
        q.push({distances[start],start});
        while (!q.empty()) {
            pair<int, int>p = q.top();
            int u = p.second;
            q.pop();
            if (distances[u] < p.first) {
                continue;
            }
            for (int v=0; v<n; ++v) {
                if (graph[u][v] != INT_MAX && distances[v]>distances[u]+graph[u][v]) {
                    distances[v]=distances[u]+graph[u][v];
                        q.push({distances[v],v});
                }
            }
        }
    }

作者：sui-xin-yuan
链接：https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/solution/zui-duan-lu-jing-mo-ban-da-ji-he-cban-fl-gs7u/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
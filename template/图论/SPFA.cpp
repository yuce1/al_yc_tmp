# include<iostream>
# include<algorithm>
# include<cstring>
# include<queue>

using namespace std;
const int N = 100010,INF = 0x3f3f3f3f;
int n,m;
int d[N];
bool st[N];
int h[N],e[N],w[N],ne[N],idx;
void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx ++;
}

void spfa(){
    memset(d,INF,sizeof(d));
    d[1] = 0;
    
    st[1] = true;
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){
        int t = q.front();
        q.pop();
        // 队列中dist减小的结点当前被处理 出队列
        st[t] = false;
        // 遍历所有出边
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(d[j] > d[t] + w[i]){
                d[j] = d[t] + w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    memset(h,-1,sizeof(h));
    for(int i=1;i<=m;++i){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    spfa();
    // 这里不需要像Bellman_Ford一样判断d[n] > threshold是因为维护的是从源点到各点的距离
    // 不会出现未到达但发生更新的情况
    if(d[n] == INF) puts("impossible");
    else cout << d[n] <<endl;
    
    return 0;
}


//
void SPFA(vector<vector<pair<int, int>>>& graph, vector<int>& distances, vector<bool>& inQueue, int start) {
        queue<int>q;
        q.push(start); //源点入队
        distances[start] = 0;
        inQueue[start] = true; //源点已入队
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false; //已出队
            for (int k=0; k<graph[u].size(); ++k) {
                int v = graph[u][k].first;
                int w = graph[u][k].second;
                if (distances[u] + w < distances[v]) {
                    distances[v] = distances[u] + w;
                    if (!inQueue[v]) {
                        q.push(v);
                        inQueue[v] = true;
                    }
                }
            }
        }
    }

作者：sui-xin-yuan
链接：https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/solution/zui-duan-lu-jing-mo-ban-da-ji-he-cban-fl-gs7u/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
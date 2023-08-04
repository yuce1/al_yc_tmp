//LCA最近公共祖先
# include<iostream>
# include<cstring>
# include<algorithm>
# include<queue>

using namespace std;
const int N = 40010,M = 80010;
int depth[N],fa[N][16];
int h[N], e[M], ne[M], idx;
int n,m;
int root;

void add(int a, int b)  // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs(){
    queue<int> q;
    // 类似bfs最短路的写法 无向图也不会出现来回遍历的情况
    memset(depth,0x3f,sizeof depth);
    depth[0] = 0,depth[root] = 1;          // 0作为哨兵十分有效可以减少很多边界处理
    q.push(root);
    while(q.size()){
        auto u = q.front();
        q.pop();
        for(int i=h[u];i!=-1;i=ne[i]){
            int j = e[i];
            if(depth[j] > depth[u] + 1){
                depth[j] = depth[u] + 1;
                fa[j][0] = u;
                q.push(j);
                // 动态规划递推的过程 必须从小到大递推 因为f[j][k]会用到f[j][k-1]
                for (int k = 1; k <= 15; ++k) { //2^16 = 65536，超过了数据范围，15刚好
                    fa[j][k] = fa[fa[j][k - 1]][k - 1]; //走两次2^k-1就是一次2^k
                }
            }
        }
    }
}

int lca(int a,int b){
    if(depth[a] < depth[b]) swap(a,b);
    
    // 先跳到同一层上 倍增思想
    for(int i=15;i>=0;--i){
        if(depth[fa[a][i]] >= depth[b]){
            a = fa[a][i];
        }
    }
    if(a == b) return b;
    // 一起跳到最近公共祖先的下一个位置 为什么?
    // 这是因为我们由倍增思想从大往小跳 当a == b时的a可能是祖先 但不一定是最近公共祖先
    for(int i=15;i>=0;--i){
        if(fa[a][i] != fa[b][i]){
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    
    return fa[a][0];
}

int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    while (n -- ){
        int a,b;
        cin >> a >> b;
        if(b == -1) root = a;
        add(a,b),add(b,a);
    }
    
    
    bfs();
    
    cin >> m;
    while (m -- ){
        int a,b;
        cin >> a >> b;
        int res = lca(a,b);
        if(res == a) cout << "1" << endl;
        else if(res == b) cout << "2" << endl;
        else cout << "0" << endl;
    }
    return 0;
}
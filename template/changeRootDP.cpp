class Solution {
static constexpr int N = 20010,M = 40010;
int h[N],e[M],ne[M],idx;
//f最大值 g次大值
int f[N],indices[N],g[N];
public:
    //进行链式前向星的存储
    void add(int a,int b){
        e[idx] = b,ne[idx] = h[a],h[a] = idx ++;
    }
    //固定根节点，从上往下交易信息，需要当前节点以及其父节点
    //利用儿子节点的信息更新父节点的信息
    void dfs1(int u,int fa){
        for(int i=h[u];i!=-1;i=ne[i]){
            int j = e[i];
            if(j != fa){
                //一点信息也不知道，先进行递归在进行更新
                dfs1(j,u);
                //更新最大值和次大值
                if(f[j] + 1 > f[u]){
                    g[u] = f[u];
                    f[u] = f[j] + 1;
                }else{
                    if(f[j] + 1 > g[u]){
                        g[u] = f[j] + 1;
                    }
                }
            }
        }
    }
    //利用父节点的信息更新儿子结点的信息
    void dfs2(int u,int fa){
        for(int i=h[u];i!=-1;i=ne[i]){
            int j = e[i];
            if(j != fa){
                // 状态转移方程
                //如果父节点的最大值来源于该儿子节点
                if(f[u] == f[j] + 1){
                    //没必要用最大值更新，需要用次大值更新
                    if(g[u] + 1 > f[j]){
                        f[j] = g[u] + 1;
                    }else{
                        if(g[u] + 1 > g[j]){
                            g[j] = g[u] + 1;
                        }
                    }
                }else{
                    //更新
                    if(f[u] + 1 > f[j]){
                        g[j] = f[j];
                        f[j] = f[u] + 1;
                    }else{
                        if(f[u] + 1 > g[j]){
                            g[j] = f[u] + 1;
                        }
                    }
                }
                dfs2(j,u);
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        memset(h,-1,sizeof(h));
        for(auto& v:edges){
            add(v[0],v[1]),add(v[1],v[0]);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        iota(indices,indices+n,0);
        auto cmp = [&](const int& a,const int& b){
            return f[a] < f[b];
        };

        sort(indices,indices+n,cmp);
        vector<int> ans;
        ans.emplace_back(indices[0]);
        for(int i=1;i<n;++i){
            if(f[indices[0]] != f[indices[i]]){
                break;
            }
            ans.emplace_back(indices[i]);
        }
        return ans;
    }
};
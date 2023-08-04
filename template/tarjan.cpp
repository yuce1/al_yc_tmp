//tarjan算法 luoguP3388题
# include <bits/stdc++.h>
# include<numeric>
# define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PII pair<int,int>
#define ll long long
# define x first
# define y second
using namespace std;
inline ll gcd(ll a,ll b){
    if(b){
        return  gcd(b,a % b);
    }
    return a;
}
// 模意义下快速幂板子
inline int qpow(ll a, ll b,int p) {
  int ans = 1;
  a = (a % p + p) % p;
  for (; b; b >>= 1) {
    if (b & 1) ans = (a * ans) % p;
    a = (a * a) % p;
  }
  return ans;
}
// 扩展欧几里得算法 求gcd并且求一组解
int exgcd(int a,int b,int& x,int& y){
    if(b == 0){
        x = 1,y = 0;
        return a;
    }
    int r = exgcd(b,a%b,x,y);
    int tmp = y;
    y = x - a / b * y;
    x = tmp;
    return r;
}
const int N = 20010,M = 200010;
int h[N],e[M],ne[M],idx;
int root;
int n,m;
int dfn[N],low[N];
int timestamp;
bool cnt[N];



// tarjan找割点和桥的经典应用

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx ++;
}

void tarjan(int u,int fa){
    dfn[u] = low[u] = ++ timestamp;

    int child = 0;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j,u);
            low[u] = min(low[u],low[j]);
            if(low[j] >= dfn[u] && u != fa){
                cnt[u] = true;
            }
            if(u == fa){
                child ++;
            }
        }else{
            low[u] = min(low[u],dfn[j]);
        }
    }

    if(child >= 2 && u == fa){
        cnt[u] = true;
    }
}

int main(){
    scanf("%d %d",&n,&m);
    memset(h,-1,sizeof h);

    while(m --){
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b),add(b,a);
    }

    for(int i=1;i<=n;++i){
        if(!dfn[i]){
            tarjan(i,i);
        }
    }

    int ans = 0;
    for(int i=1;i<=n;++i){
        if(cnt[i]){
            ans ++;
        }
    }
    printf("%d\n",ans);
    
    for(int i=1;i<=n;++i){
        if(cnt[i]){
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}
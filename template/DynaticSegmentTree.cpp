//动态开点线段树
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
// 模意义下快速幂板子 倍增的思想
inline ll qpow(ll a, ll b,ll p) {
  ll ans = 1;
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


const int N = 2e5 + 10,INF = 0x3f3f3f3f,M = 1000000020;
PII q[N];
int root,idx;
int n;

struct tnode{
    int l,r;
    int lazy,minv;
}tr[1000010];

void pushup(int p){
    tr[p].minv = min(tr[tr[p].l].minv,tr[tr[p].r].minv);
}

void build(int &p,int l,int r){
    if(!p) p = ++ idx;
    if(l == r) tr[p].minv = INF;
    else{
        int mid = (l + r) >> 1;
        build(tr[p].l,l,mid);
        build(tr[p].r,mid+1,r);
        pushup(p);
    }
}

void pushdown(int p,int l,int r){
    if(tr[p].lazy){
        int mid = (l + r) >> 1;
        if(!tr[p].l) tr[p].l = ++ idx;
        if(!tr[p].r) tr[p].r = ++ idx;

        tr[tr[p].l].minv += tr[p].lazy;
        tr[tr[p].l].lazy += tr[p].lazy;
        tr[tr[p].r].minv += tr[p].lazy;
        tr[tr[p].r].lazy += tr[p].lazy;
        tr[p].lazy = 0;
    }
}

void update(int& p,int l,int r,int ql,int qr,int val){
    if(!p) p = ++ idx;
    if(ql <= l && r <= qr){
        tr[p].minv += val;
        tr[p].lazy += val;
        return;
    }
    pushdown(p,l,r);
    int mid = (l + r) >> 1;
    if(ql <= mid) update(tr[p].l,l,mid,ql,qr,val);
    if(qr > mid) update(tr[p].r,mid+1,r,ql,qr,val);
    pushup(p);
}

int query(int p,int l,int r,int ql,int qr){
    if(!p) return 0;
    if(l >= ql && r <= qr) { return tr[p].minv; }
	int mid = l + r >> 1;
	pushdown(p, l, r);
	int v = INF;
	if(ql <= mid) v = min(v,query(tr[p].l, l, mid, ql, qr));
	if(qr > mid) v = min(v,query(tr[p].r, mid + 1, r, ql, qr));
	return v;
}


int main(){
    IOS;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int l,r;
        scanf("%d %d",&l,&r);
        q[i] = {l,r};
        update(root,1,M,l+1,r+1,1);
    }
    for (int i=1;i<=n;i++){
        if (query(root,1,M,q[i].x+1,q[i].y+1) >= 2)
	    {
			printf("%d\n",i);
			return 0; 
		}
    }
    printf("-1\n");
    return 0;
}
//线段树
# include <bits/stdc++.h>
# include<numeric>
# define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PII pair<int,int>
#define ll long long
# define ls p << 1
# define rs p << 1 | 1
using namespace std;
const int N = 1e6 + 10;
int a[N];
struct tnode
{
    /* data */
    int l,r;
    ll data,lazy;
};
struct SegmentTree
{
    /* data */
    tnode tr[N * 4];
    void init_lazy(int p){
        tr[p].lazy = 0;
    }
    // 计算维护值
    void calc_lazy(int root){
        tr[root].data += tr[root].lazy;
    }
    // 合并懒标记
    void union_lazy(int root,int ch){
        tr[ch].lazy += tr[root].lazy;
    }
    void build(int p,int l,int r){
        tr[p].l = l,tr[p].r = r;
        init_lazy(p);
        if(l != r){
            int mid = (l + r) >> 1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pushup(p);
        }else{
            tr[p].data = a[l];
        }
    }
    // 上传操作
    void pushup(int p){
        pushdown(ls);
        pushdown(rs);
        tr[p].data = min(tr[ls].data,tr[rs].data);
    }

    void pushdown(int p){
        if(tr[p].lazy != 0){
            tr[p].data += tr[p].lazy;
            if(tr[p].l != tr[p].r){
                tr[ls].lazy += tr[p].lazy;
                tr[rs].lazy += tr[p].lazy;
            }
            tr[p].lazy = 0;
        }
    }

    void update(int p,int l,int r,int val){
        pushdown(p);
        if(l == tr[p].l && r == tr[p].r){
            tr[p].lazy = val;
            return;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if(r <= mid){
            update(ls,l,r,val);
        }else if(l > mid){
            update(rs,l,r,val);
        }else{
            update(ls,l,mid,val);
            update(rs,mid+1,r,val);
        }
        pushup(p);
    }

    ll query(int p,int l,int r){
        pushdown(p);
        if(l == tr[p].l && r == tr[p].r){
            return tr[p].data;
        }
        int mid = (tr[p].l + tr[p].r) >> 1;
        if(r <= mid){
            return query(ls,l,r);
        }else if(l > mid){
            return query(rs,l,r);
        }else{
            return min(query(ls,l,mid),query(rs,mid+1,r));
        }
        
    }
};
SegmentTree ST;
int n,m;

int main(){
    IOS;
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        cin >> a[i];
    }
    ST.build(1,1,n);

    int res = 0;
    for(int i=1;i<=m;++i){
        int d,s,t;
        cin >> d >> s >> t;
        ll ans = ST.query(1,s,t);
        if(ans < d){
            res = i;
            break;
        }
        ST.update(1,s,t,-d);
    }
    if(res) cout << -1 << endl;
    cout << res << endl;
    return 0;
}
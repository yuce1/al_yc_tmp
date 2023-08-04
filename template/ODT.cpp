//ODT珂朵莉树
# include <bits/stdc++.h>
# include<numeric>
# define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PII pair<int,int>
# define sz 1000100010
#define ll long long
# define PLL pair<ll,ll>
# define x first
# define y second
using namespace std;

inline ll qpow(ll a, ll b,ll p) {
  ll ans = 1;
  a = (a % p + p) % p;
  for (; b; b >>= 1) {
    if (b & 1) ans = (a * ans) % p;
    a = (a * a) % p;
  }
  return ans;
}

const ll maxn = 100005;
struct Node {
    ll l, r;//l和r表示这一段的起点和终点
    mutable ll v;//v表示这一段上所有元素相同的值是多少  mutable表示可修改

    Node(ll l, ll r = 0, ll v = 0) : l(l), r(r), v(v) {}

    bool operator<(const Node &a) const {
        return l < a.l;//规定按照每段的左端点排序
    }
};

int n,m,a[maxn];
set<Node> s;

//以pos去做切割，找到一个包含pos的区间，把它分成[l,pos-1],[pos,r]两半
set<Node>::iterator split(ll pos){
    auto it = s.lower_bound(Node(pos));
    if(it != s.end() && it->l == pos) return it;
    it --;

    // 此时的r太小了 小于pos
    if(it->r < pos)  return s.end();
    // pos在it对应的区间中 只需要分割即可
    ll l = it->l;
    ll r = it->r;
    ll v = it->v;
    s.erase(it);
    s.insert(Node(l,pos-1,v));
    // insert返回值恰好为迭代器
    return s.insert(Node(pos,r,v)).first;
}

// assign操作  推平操作
void assign(ll l,ll r,ll x){
    auto itr = split(r + 1), itl = split(l);
    for (auto it = itl; it != itr; ++it) {
        it->v = x;
    }
}

// add操作 对一段区间进行加值操作
void assign(ll l,ll r,ll x){
    auto itr = split(r + 1), itl = split(l);
    for (auto it = itl; it != itr; ++it) {
        it->v += x;
    }
}


// 求区间第k小
ll rank(ll l,ll r,ll k){
    vector<PLL> vp;
    auto itr = split(r + 1),itl = split(l);
    for(auto it=itl;it != itr;++it){
        vp.push_back({it->v,it->r - it->l + 1});
    }

    sort(vp.begin(),vp.end());

    for(auto it = vp.begin();it!=vp.end();++it){
        k -= it->second;
        if(k <= 0) return it -> first;
    }
    return -1ll;
}

// 求区间每个数的ex次方之和 模mod的结果
ll sum(ll l,ll r,ll ex,ll mod){
	auto itl=split(l),itr=split(r+1);
    ll res=0;
	for(;itl!=itr;++itl)res=(res+(ll)(itl->r-itl->l+1)*qpow(itl->v,ex,mod))%mod;
	return res;
}

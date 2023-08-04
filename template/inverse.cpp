//逆元
# include <bits/stdc++.h>
# include<numeric>
# define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PII pair<int,int>
#define ll long long
using namespace std;


const int N = 10010;
int a[N];
int inv[N];
ll s[N],sv[N];

ll qpow(ll a,ll b,ll p){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
// 线性求1~n的逆元
void init(int n,int p){
    inv[1] = 1;
    for(int i=2;i<=n;++i){
        inv[i] = (1ll * p - p / i) * inv[p % i] % p;
    }
    
    // 求任意n个数的逆元
    s[0] = 1;
    for(int i = 1; i <= n; ++i) s[i] = s[i - 1] * a[i] % p;
    sv[n] = qpow(s[n],p - 2,p);
    for(int i = n; i >= 1; --i) sv[i - 1] = sv[i] * a[i] % p;
    for(int i = 1; i <= n; ++i) inv[i] = sv[i] * s[i - 1] % p;
}
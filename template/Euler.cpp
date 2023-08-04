//欧拉函数 线性筛
# include <bits/stdc++.h>
# include<numeric>
# define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PII pair<int,int>
#define ll long long
using namespace std;

// 筛法求欧拉函数
const int N = 1000010;
int primes[N],cnt;
int phi[N];
bool st[N];
// 单个元素求欧拉函数的值  分解质因数时计算O(sqrt(n))
ll get_phi(ll n){
    ll phi = 1;
    for(int i=2;i<=n/i;++i){
        if(n % i == 0){
            phi *= (i-1);
            n /= i;
            while(n % i == 0) phi *= i,n /= i;
        }
    }
    if(n > 1) phi *= (n-1);
}

// 线性筛
void get_Euler(int n){
    phi[1] = 1;
    for(int i=2;i<=n;++i){
        if(!st[i]){
            primes[cnt++] = i;
            phi[i] = i - 1;    // 质数的欧拉函数为n-1 除了自身以外1-n-1均互质
        }
        for(int j=0;primes[j]<=n/i;++j){
            st[primes[j]*i] = true;
            if(i % primes[j] == 0)   // 此时的primes[j]一定是i的最小质数  分类讨论证明即可
            {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j]-1);
        }
    }
}
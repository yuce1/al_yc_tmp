//树状数组
# include <bits/stdc++.h>
# include<numeric>
# define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PII pair<int,int>
#define ll long long
using namespace std;

const int N = 10010;
int A[N],C[N];

int lowbit(int x){
    return x & -x;
}

int query(int x){
    int res = 0;
    while(x){
        res += C[x];
        x -= lowbit(x);
    }
    return res;
}

void update(int x,int v){
    while(x){
        C[x] += v;
        x += lowbit(x);
    }
}
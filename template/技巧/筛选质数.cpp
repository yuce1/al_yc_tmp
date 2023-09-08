普通质数筛  O（nlogn）
const int N = 1e6 + 5;
int n,ans=0;
int prime[N];
int vis[N];
int get_prime(int n){
    int ans=0;
    for(int i=2;i<=n;i++){
        if(!vis[i])prime[ans++]=i;//把素数存到prime数组中
        for(int j=i*2;j<=n;j+=i)vis[j]=true;//不管是合数还是质数，都用来筛掉后面它的倍数
    }
    return ans;
}






埃式筛（时间复杂度O（nloglongn））
我们先用一个数组prime[]来储存每一个质数，用bool st[]来储存一个数是不是质数
const int N = 1e6+10;
int prime[N];
bool st[N];

//埃式筛
const int N = 1e6 + 5;
int n,ans=0;
int prime[N];
int vis[N];
int E_seive(int n){
    int ans=0;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            prime[ans++]=i;
            for(int j=i*2;j<=n;j+=i)vis[j]=true;//可以用质数把所有的合数筛掉
        }
    }
    return ans;
}


线性筛法（欧拉筛法）
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int N = 1e6 + 5;
int n,ans=0;
int prime[N];
int vis[N];
int get_prime(int n){
    int ans=0;
    for(int i=2;i<=n;i++){
        if(!vis[i])prime[ans++]=i;
        for(int j=0;prime[j]<=n/i;j++){
            vis[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
    return ans;
}
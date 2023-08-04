//埃氏筛
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // 求出left和right中的所有质数
        vector<int> primes;
        vector<int> check(right+1, 0);
        check[0] = check[1] = 1;
        for(int i=2;i<=right;i++) {
            if(!check[i]) {
                primes.push_back(i);
            }
            for(long long j=1ll*i*i;j<=right;j+=i) {
                check[j] = 1;
            }
        }
        int n = primes.size();
        int num = INT_MAX;
        vector<int> ans = {-1, -1};
        for(int i=0;i<n-1;i++) {
            if(primes[i] < left) continue;
            if(num > primes[i+1] - primes[i]) {
                num = primes[i+1] - primes[i];
                ans = {primes[i], primes[i+1]};
            }
        }
        return ans;
    }
};


//线性筛       任一合数只被：最小质因数 × 最大因数（非自己）
class Solution {
static const int N = 1e6 + 10;
int primes[N],cnt;
bool st[N];
public:
    void get_prime(int n){
        for(int i=2;i<=n;++i){
            if(!st[i]) primes[cnt++] = i;
            for(int j=0;primes[j]<=n/i;++j){
                st[primes[j]*i] = true;
                if(i % primes[j] == 0) break;
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        get_prime(right);
        
        int res = 0x3f3f3f3f;
        
        vector<int> ans(2);
        ans[0] = ans[1] = -1;
        for(int i=0;i<cnt;++i){
            if(i + 1 < cnt){
                if(primes[i] >= left && primes[i+1] - primes[i] < res){
                    ans[0] = primes[i],ans[1] = primes[i+1];
                    res = primes[i+1] - primes[i];
                }
            }
        }
        
        return ans;
    }
};



//超时筛
vector<int>zhishu;
for(int i = 2;i<=1000000;i++){
    int j = 2;
    bool isOK = true;
    while(j<=(int)sqrt(i)){
        if(i%j++!=0)continue;
        else{isOK = false; break;}
    }
    if(isOK){
        // cout<<i<<endl;
        zhishu.push_back(i);
    }
    
}
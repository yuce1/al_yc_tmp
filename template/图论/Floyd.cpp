# include<iostream>
# include<cstring>
# include<algorithm>
using namespace std;
const int N = 210,M = 20010,INF = 0X3f3f3f3f;
int n,m,T;
int f[N][N];

void Floyd(){
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}
// Floyd 插点法 每次增加的点看作一个桥 尝试更新那些经过新桥的最短路径
int main(){
    cin >> n >> m >> T;
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i == j){
                f[i][j] = 0;
            }else{
                f[i][j] = INF;
            }
        }
    }
    for(int i=1;i<=m;++i){
        int a,b,c;
        cin >> a >>b >> c;
        // 重边选择权值最小的保留
        f[a][b] = min(f[a][b],c);
    }
    
    Floyd();
    
    while(T -- ){
        int x,y;
        cin >> x >> y;
        // 由于存在负权边所以即使不是最短路也会发生更新
        if(f[x][y] > INF / 2){
            cout << "impossible" <<endl;
        }else{
            cout << f[x][y] <<endl;
        }
    }
    // 处理k个查询
    return 0;
}


//
void Floyd(vector<vector<int>>& distances, int n){
        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    if (distances[i][k]!=INT_MAX && distances[k][j] != INT_MAX && distances[i][k] + distances[k][j] < distances[i][j]) {
                        distances[i][j] = distances[i][k] + distances[k][j];
                    }
                }
            }
        }
    }

作者：sui-xin-yuan
链接：https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/solution/zui-duan-lu-jing-mo-ban-da-ji-he-cban-fl-gs7u/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
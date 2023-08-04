# include<iostream>
# include<algorithm>
# include<cstring>

using namespace std;
const int N = 510,M = 10010,INF = 0x3f3f3f3f;
// last是副本 用来解决单次更新可能出现的串联问题
int d[N],last[N];
// 由于Bellman_Ford算法每次循环都会遍历全部的边 与点的遍历无关 因此只需要存储每个点的边集
struct Edge{
    int a,b,w;
}edges[M];
int n,m,k;

void Bellman_Ford(){
    memset(d,INF,sizeof(d));
    d[1] = 0;
    
    // 只能经过k条边 所以遍历k次
    for(int i=0;i<k;++i){
        // last是副本 用来解决单次更新可能出现的串联问题
        memcpy(last,d,sizeof(d));
        // 遍历每一条边 更新边对应终点的最短路
        for(int j=0;j<m;++j){
            int a = edges[j].a,b = edges[j].b,w = edges[j].w;
            d[b] = min(d[b],last[a] + w);
        }
    }
}


int main(){
    cin >> n >> m >> k;
    
    for(int i=0;i<m;++i){
        int a,b,c;
        cin >> a >> b >> c;
        edges[i] = {a,b,c};
    }
    
    Bellman_Ford();
    
    // 因为不可达状态可能由于存在负权边进行了更新(d减小) 最多减小5 * 10**6
    if(d[n] > INF / 2){
        cout << "impossible" <<endl;
    }else{
        cout << d[n] <<endl;
    }
    
    return 0;
}

//
void BellmanFord(vector<Edge>& edges, vector<int>& distances, int n, int start) {
        distances[start] = 0;
        for(auto& e:edges){
            if(e.from == start) distances[e.to] = e.weight;
        }
        for(int i=0; i<n-1; ++i){
            for(auto& e:edges){
                if(distances[e.from] != INT_MAX && distances[e.to] > distances[e.from]+e.weight)
                    distances[e.to] = distances[e.from]+e.weight;
            }
        }
    }

作者：sui-xin-yuan
链接：https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/solution/zui-duan-lu-jing-mo-ban-da-ji-he-cban-fl-gs7u/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
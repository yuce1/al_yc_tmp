class Solution {
public:
    int dirs[4][2]={{0,1},{0,-1},{1,0},{-1,0}};  //四个方向
    int g[4]={1,2,3,4};
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();           //容器及变量定义
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        deque<pair<int,int>>de;

        de.push_front({0,0});  //初始化
        dist[0][0]=0;

        while(de.size()){
            auto[x,y]=de.front();  //取队列头部元素
            de.pop_front();
            if(vis[x][y])continue;
            vis[x][y]=true;

            for(int i=0;i<4;i++){
                int nx=x+dirs[i][0];  //四个方向
                int ny=y+dirs[i][1];

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int dis=dist[x][y]+(grid[x][y]!=g[i]); //根据题意计算距离
                    if(dist[nx][ny]>dis)dist[nx][ny]=dis;  //判断是否更新距离

                    grid[x][y]==g[i]?de.push_front({nx,ny}):de.push_back({nx,ny});//判断加入头部还是尾部
                }
            }



        }
    return dist[n-1][m-1];//返回答案
    }
};

作者：da-yu-bt
链接：https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/solution/by-da-yu-bt-wnot/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
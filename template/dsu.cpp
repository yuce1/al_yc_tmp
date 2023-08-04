class Solution {
public:
    //parent是记录祖先，rank是记录根节点的个数，将少的向多的那一边组合
    int Find(vector<int>& parent,int index) {
        return index == parent[index] ? index : (parent[index] = Find(parent,parent[index]));
    }
    void Union(vector<int>& parent,vector<int>& rank,int index1, int index2) {
        int x = Find(parent,index1), y = Find(parent,index2);
        if (rank[x] <= rank[y]) parent[x] = y;
        else parent[y] = x;
        if (rank[x] == rank[y] && x != y) rank[y]++;
    }
    bool isConnected(vector<int>& parent,int index1, int index2){
        return Find(parent,index1) == Find(parent,index2);
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size(),col = board[0].size();
        vector<int> parent(row*col + 1), rank(row*col + 1,1);//加一个超级节点记录靠边的O
        iota(parent.begin(),parent.end(),0);
        for(int i =0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(board[i][j] == 'O'){
                    if(i == 0 || j == 0|| i == row -1 || j == col -1) Union(parent,rank,i*col+j,row*col);
                    if(j + 1 <col && board[i][j+1] == 'O') Union(parent,rank,i*col +j,i*col+j+1);
                    if(i + 1 <row && board[i+1][j] == 'O') Union(parent,rank,i*col +j,(i+1)*col+j);
                }
            }
        }
        for(int i =0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(board[i][j] == 'O' && !isConnected(parent,i*col+j,row*col)) board[i][j] = 'X';
            }
        }
    }
};







// 并查集模板
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // 当前连通分量数目
    int setCount;
    
public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }
    
    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }
    
    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/path-with-minimum-effort/solution/zui-xiao-ti-li-xiao-hao-lu-jing-by-leetc-3q2j/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//正方形dp

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int num = 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                dp[i][j]=matrix[i][j];
                if(dp[i][j] == 0) continue;
                if(i>0&&j>0){
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
                num+=dp[i][j];
            } 
        }
        return num;
    }
};
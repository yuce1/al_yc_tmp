class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> Indegree(numCourses,0);
        vector<vector<int>> graph(numCourses);
        for(auto temp: prerequisites){
            Indegree[temp[0]]++;
            graph[temp[1]].push_back(temp[0]);
        }
        queue<int> qu;
        vector<int> res;
        for(int i = 0;i<numCourses;i++){
            if(Indegree[i] == 0){
                qu.push(i);
            }
        }

        function<void(int)> dfs = [&](int x)->void{ 
            res.push_back(x);
            // cout<<"dfs"<<x<<endl;
            for(int i = 0;i<graph[x].size();i++){
                
                Indegree[graph[x][i]]--;
                // cout<<graph[x][i]<<":"<<Indegree[graph[x][i]]<<endl;
                if(Indegree[graph[x][i]]==0){
                    // cout<<"fsdfsdafsd";
                    dfs(graph[x][i]);
                }
            }
        };

        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            dfs(node);
        }
        // cout<<res.size();
        if(res.size() == numCourses) return res;
        else return {};
    }
};
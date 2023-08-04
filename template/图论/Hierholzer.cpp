// Hierholzer  寻找欧拉回路  eulerian path

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> pq;
        for(auto &a:tickets){
            pq[a[0]].push(a[1]);
        }
        stack<string> ans;
        function<void(string)> dfs = [&](string temp){
            while(!pq[temp].empty()){
                string next = pq[temp].top();
                pq[temp].pop();
                dfs(next);
            }
            ans.push(temp);
        };
        dfs("JFK");
        vector<string> res;
        while(!ans.empty()){
            res.push_back(ans.top());
            ans.pop();
        }
        return res;

    }
};

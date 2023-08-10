class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        //小顶锥，用>
        //返回true，表示不交换顺序，认可当前顺序，否则需要交换
        //堆相当于从后面输出，队列相当于从前面输出
        auto cmp = [&](const int & a, const int & b) {
            return costs[a]>costs[b]?true:costs[a]==costs[b] && a>b;
        };
        int num = costs.size();
        //存下标
        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        
        while(k>0 && !pq.empty()){
            int x = pq.top();
            pq.pop();
        }
        return res;

    }
};

//默认，大顶堆
priority_queue<int,vector<int>,less<int>>mp;
//小顶堆
priority_queue<int,vector<int>,greater<int>>mp;

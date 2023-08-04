class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //w升序排列  h相等的降序排列
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] == b[0] ? a[1] > b[1]: a[0] < b[0];
        });
        //长度为 i+1 的地方 最小的数字
        vector<int> dp; 
        for(const auto &e: envelopes) {
            //lower_bound返回指向第一个值不小于val的位置，也就是返回第一个大于等于val值的位置
            auto p = lower_bound(dp.begin(), dp.end(), e[1]);
            if(p == dp.end()) dp.push_back(e[1]);
            else *p = e[1];
        }
        return dp.size();
    }
};
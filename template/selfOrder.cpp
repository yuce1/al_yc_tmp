//自定义排序
class Solution {
public:
    string customSortString(string order, string s) {
        sort(s.begin(),s.end(),[&](char &c1,char &c2){return order.find(c1)<order.find(c2);});
        return s;
    }
};
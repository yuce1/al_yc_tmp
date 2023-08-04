class Solution {
public:
    int countSpecialNumbers(int n) {
        auto s = to_string(n);
        //前面是长度，后面是mask可能的情况，需要记录每一位是否被用到，一共十位数字，共2^10种情况
        int m = s.length(), dp[m][1 << 10];
        memset(dp, -1, sizeof(dp));
        //i表示当前在填第几位 mask表示被用过数字情况  is_limit表示前面的数字是都都是一一对应  is_num表示前面是否填了数字
        function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit, bool is_num) -> int {
            //已经到最后了，如果is_num = true，前面全填了 那就是一个数字，前面都没填 那就是没数字
            if (i == m) return is_num;
            if (!is_limit && is_num && dp[i][mask] >= 0) return dp[i][mask];
            int res = 0;
            if (!is_num) res = f(i + 1, mask, false, false); // 可以跳过当前数位
            //is_num=0没填过数字，这里是没跳过，那从一开始  =1填过 从0开始
            for (int d = 1 - is_num, up = is_limit ? s[i] - '0' : 9; d <= up; ++d) // 枚举要填入的数字 d
                if ((mask >> d & 1) == 0) // d 不在 mask 中
                    res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
            if (!is_limit && is_num) dp[i][mask] = res;
            return res;
        };
        //true表示开始要受到约束
        return f(0, 0, true, false);
    }
};
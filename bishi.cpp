#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <bits/stdc++.h>
#include <deque>
#include <cstdlib>
#include <numeric>
#include <cmath>

using namespace std;
int main( )
{
    int n,m;
    vector<int>res;
    for(int i = 100;i<=999;i++){
        int now = i;
        int ans = 0;
        while(now){
            ans += pow(now%10,3);
            now /= 10;
        }
        if(i == ans){
            res.push_back(i);
        }
    }
    int len = res.size();
    while(cin>>m){
        vector<int>pr;
        cin>>n;
        for(int i = 0;i<len;i++){
            if(res[i]<m){
                continue;
            }
            if(res[i]>n){
                break;
            }
            pr.push_back(res[i]);
        }
        if(pr.size() == 0){
            printf("no\n");
        }else{
            for(int i =0;i<pr.size();i++){
                if(i != pr.size()-1)
                    printf("%d ",pr[i]);
                else{
                    printf("%d\n",pr[i]);
                }
            }
        }
    }
}

//cin:cin以空格、tab、换行符作为分隔符;cin从第一个非空格字符开始读取，直到遇到分隔符结束读取
//getline(cin, s); getline()函数会读取一行，读取的字符串包括空格，遇到换行符结束
//ch = getchar();函数会从缓存区中读出一个字符，经常被用于判断是否换行

// while(cin >> str) {
// 	strings.push_back(str);
// 	// 读到换行符，终止循环
// 	if(getchar() == '\n') {
// 		break;
// 	}
// }
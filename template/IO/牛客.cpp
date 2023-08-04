#include <iostream>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        cout << a + b << endl;
    }
}
// 64 位输出请用 printf("%lld")

#include<iostream>
using namespace std;
int main(){
    int sum=0;
    int a;
    while(cin>>a){
        sum+=a;
        //处理换行数据
        if(cin.get()=='\n'){
            cout<<sum<<endl;
            sum=0;
        }
    }
    return 0;
}


// a,c,bb
// f,dddd
// nowcoder


#include <iostream>
#include <sstream>        
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string str;
    while(getline(cin,str)){
        string temp;
        vector<string>v;
        istringstream ss(str);
        while(getline(ss,temp,',')){
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(i==v.size()-1)cout<<v[i]<<endl;
            else cout<<v[i]<<',';
        }
    }
}



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
#include <bits/stdc++.h>
#include <numeric>
# define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(NULL), right(NULL) {}
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;
//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}
//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
//     Node(int _val, Node* _left, Node* _right, Node* _next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };






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
#include <bits/stdc++.h>
#include <numeric>
# define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main()
{
    int total,temp,t2,now = 1,ans = 0;
    cin>>total;
    vector<bool>visit(total+1,false);
    vector<vector<int>> pic(total+1,vector<int>());
    unordered_map<int,int>mp;
    set<int>se;
    stack<int>st;
    stack<int>st1;
    while(cin>>temp){
        if(temp == 0){
            se.insert(now);
            st1.push(now);
        }
        for(int i = 0;i<temp;i++){
            cin>>t2;
            pic[t2].push_back(now);
        }
        now++;
    }
    
    for(int i = 1;i<=total;i++){
        cout<<i<<":";
        for(int j = 0;j<pic[i].size();j++){
            cout<<pic[i][j]<<"-";
        }
        cout<<endl;
    }
    
    
    while(!st1.empty()){
        while(!st1.empty()){
            st.push(st1.top());
            st1.pop();
        }
        while(!st.empty()){
            int n = st.top();
            if(visit[n] == false){
                visit[n] = true;
                for(int i = 0;i<pic[n].size();i++){
                    mp[pic[n][i]]--;
                    if(mp[pic[n][i]] == 0){
                        st1.push(n);
                        st.push(n);
                    }
                }
            }
            st.pop();
        }
        ans++;
        
    }
    if(se.size()==total){
        cout<<ans;
    }else{
        cout<<-1;
    }
}
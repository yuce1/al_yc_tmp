class Solution {
public:
struct TrieNode{
    bool isEnd;
    vector<TrieNode*> child;
    TrieNode():isEnd(false),child(26,nullptr){}
};

TrieNode* root = new TrieNode();

void insert(string& s){
    TrieNode* p = root;
    for(char& c:s){
        if(!p->child[c - 'a']){
            p->child[c - 'a'] = new TrieNode();
        }
        p = p->child[c - 'a'];
    }
    p->isEnd = true;
}

string query(string& s){
    TrieNode* p = root;
    string ans;
    for(char& c:s){
        if(p && p->isEnd){
            return ans;
        }
        if(!p->child[c - 'a']){
            return s;
        }
        ans.push_back(c);
        p = p->child[c - 'a'];
    }

    return ans;
    
}

    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = sentence.length();
        // 找sentence中每个单词的最短前缀
        string ans,s;
        int idx = 0,len = 0;
        
        for(string& s:dictionary){
            insert(s);
        }

        // 获得每一个单词
        for(int i=0;i<=n;++i){
            if(sentence[i] == ' '||i == n){
                len = i - idx;
                s = sentence.substr(idx,len);
                ans += query(s);
                ans.push_back(' ');
                idx = i + 1;
            }
        }
        ans.pop_back();
        return ans;
    }
};

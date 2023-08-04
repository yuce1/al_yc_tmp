#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//定义树节点
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
    TreeNode(int _val,TreeNode* _left,TreeNode* _right):val(0),left(_left),right(_right){}
};

//根据数组生成树
TreeNode* buildTree(const vector<int>& v)
{
    vector<TreeNode*> vTree(v.size(),nullptr);
    TreeNode* root = nullptr;
    for(int i = 0; i < v.size(); i++)
    {
        TreeNode* node = nullptr;
        if(v[i] != -1)
        {
            node = new TreeNode(v[i]);
        }
        vTree[i] = node;
    }
    root = vTree[0];
    for(int i = 0; 2 * i + 2 < v.size(); i++)
    {
        if(vTree[i] != nullptr)
        {
            vTree[i]->left = vTree[2 * i + 1];
            vTree[i]->right = vTree[2 * i + 2];
        }
    }
    return root;
}

//根据二叉树根节点层序遍历并打印
void printBinaryTree(TreeNode* root)
{
    if(root == nullptr) return;
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector<int> path;
        for(int i = 0;i<size;i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node == nullptr)
            {
                path.push_back(-1);
            }
            else
            {
                path.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }
        ans.push_back(path);
    }
    
    for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j<ans[i].size();j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

int main()
{
	// 验证
    vector<int> v = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode* root = buildTree(v);
    printBinaryTree(root);
    
    return 0;
}

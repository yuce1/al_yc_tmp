#include <iostream>
using namespace std;

// 链表定义，并给出两个有参构造函数
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int _val):val(_val),next(nullptr){}
    ListNode(int _val,ListNode* _next):val(_val),next(_next){}
};

int main()
{

	// 根据控制台的输入，创建一条单链表
    ListNode* LHead = new ListNode(-1);
    ListNode* pre = LHead;
    ListNode* cur = nullptr;
    
    int num;
    while(cin >> num)
    {
    	// 为了简单起见，设置为-1退出，后续可优化，这里只是给出一个例子
        if(num == -1) break;
        cur = new ListNode(num);
        pre->next = cur;
        pre = cur;
    }
    
    cur = LHead->next;
    
    // 输出单链表的value
    while(cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    
    cout << endl;
    
    return 0;
}
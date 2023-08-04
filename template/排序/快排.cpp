void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

作者：yxc
链接：https://www.acwing.com/blog/content/277/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




链表快排：
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<ListNode*> worker;
        ListNode temp(0), *ptr = head;
        while (ptr) worker.push_back(ptr), ptr = ptr->next;
        quickSort(worker, 0, worker.size() - 1);
        ptr = &temp;
        for (auto i : worker) ptr = ptr->next = i;
        ptr->next = nullptr;
        return temp.next;
    }

private:
    void quickSort(vector<ListNode*> &worker, int l, int r) {
        if (l >= r) return;
        int pivot = patition(worker, l, r);
        quickSort(worker, l, pivot - 1);
        quickSort(worker, pivot + 1, r);
    }

    int patition(vector<ListNode*> &worker, int l, int r) {
        for (int i = l; i < r; ++i) {
            if (worker[i]->val < worker[r]->val)
                swap(worker[l++], worker[i]);
        }
        swap(worker[l], worker[r]);
        return l;
    }
};

作者：fengziL
链接：https://leetcode.cn/problems/sort-list/solution/7fen-ji-jian-cdai-ma-zhi-wei-zheng-li-si-wqr0/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
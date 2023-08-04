void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];

    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}

作者：yxc
链接：https://www.acwing.com/blog/content/277/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




链表的归并排序：
1、断链
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto slow = head, fast = head;
        while (fast->next && fast->next->next)
            slow = slow->next, fast = fast->next->next;
        // 切链
        fast = slow->next, slow->next = nullptr;
        return merge(sortList(head), sortList(fast));
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode sub(0), *ptr = &sub;
        while (l1 && l2) {
            auto &node = l1->val < l2->val ? l1 : l2;
            ptr = ptr->next = node, node = node->next;
        }
        ptr->next = l1 ? l1 : l2;
        return sub.next;
    }
};

作者：fengziL
链接：https://leetcode.cn/problems/sort-list/solution/7fen-ji-jian-cdai-ma-zhi-wei-zheng-li-si-wqr0/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

2、不断链
class Solution {
public:
    ListNode* sortList(ListNode* head, ListNode *tail = nullptr) {
        if(!head) return nullptr;
        if(head->next == tail){
            head->next = nullptr;
            return head;
        }
        auto quick = head, slow = head;
        while (quick != tail && quick->next !=tail)
            slow = slow->next, quick = quick->next->next;
        return merge(sortList(head, slow), sortList(slow, tail));
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode sub(0), *ptr = &sub;
        while(l1 && l2) {
            auto &node = l1->val < l2->val ? l1 : l2;
            ptr = ptr->next = node, node = node->next;
        }
        ptr->next = l1 ? l1 : l2;
        return sub.next;
    }
};

作者：fengziL
链接：https://leetcode.cn/problems/sort-list/solution/7fen-ji-jian-cdai-ma-zhi-wei-zheng-li-si-wqr0/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int l, int m, int r) {
    std::vector<int> temp(r - l + 1);
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < temp.size(); p++) {
        arr[l + p] = temp[p];
    }
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    std::vector<int> arr = {3, 6, 8, 2, 4, 1, 9, 5, 7};
    mergeSort(arr, 0, arr.size() - 1);
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}

class Solution {
public:
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        } 
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        } 
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};








#include <iostream>
#include <vector>
using namespace std;


class myHeap {
public:
    int size() { return nums.size(); }
    vector<int> nums;
    int top() {
        if (nums.size() == 0) return -1;
        return nums[0];
    }
    bool empty() {
        return size() == 0 ? true : false;
    }
    myHeap() {
        
    }

    void heapSort() {
        int lastIndex = size() - 1;

        for (int i = lastIndex; i >= 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }

    void del() {
        if (nums.size() == 0) return;
        int lastIndex = nums.size() - 1;
        swap(nums[0], nums[lastIndex]); //把根节点和最右的叶子互换
        nums.pop_back();//然后heapsize - 1
        heapify(nums, nums.size(), 0);//再调整最右的叶子
    }


    void add(int num) {
        nums.push_back(num);
        int son = nums.size() - 1;
        int parent = (son - 1) / 2;
        while (parent >= 0 && nums[son] > nums[parent]) {
            swap(nums[son], nums[parent]);
            son = parent;
            parent = (son - 1) / 2;
        }
    }
    void print() {
        for (auto x : nums) cout << x << " ";
        cout << endl;
    }
private:
    void heapify(vector<int>& nums, int len, int i) {
        int l = i * 2 + 1, r = i * 2 + 2;
        int max = i;
        if (l < len && nums[max] < nums[l]) max = l;
        if (r < len && nums[max] < nums[r]) max = r;
        if (max != i) {
            swap(nums[max], nums[i]);
            heapify(nums, len, max);
        }
    }
    void buildHeap(vector<int>& nums, int len) {
        int lastIndex = len - 1;
        int lastParent = (lastIndex - 1) / 2;
        for (int i = lastParent; i >= 0; i--) {
            heapify(nums, len, i);
        }
    }
};


int main() {
    
    myHeap heap;
    cout << heap.empty() << endl;
    cout << heap.size() << endl;
    cout << heap.top() << endl;

    heap.add(5); 
    heap.del();
    heap.heapSort();
    heap.print();

    return 0;
}

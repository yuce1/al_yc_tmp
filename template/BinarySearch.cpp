//左边不是答案，右边是答案
int minimumSize(vector<int>& nums, int maxOperations) {
    sort(nums.begin(),nums.end(),[](const int a,const int b){
        return a>b;
    });
    int left = 1,right = 1e9;
    while(left<=right){
        int middle = (left+right)/2;
        if(isOK(nums,middle,maxOperations)){
            right = middle;
        }else{
            left = middle+1;
        }
    }
    return left;
}
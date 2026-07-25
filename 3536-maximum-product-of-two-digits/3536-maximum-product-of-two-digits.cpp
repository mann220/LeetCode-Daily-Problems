class Solution {
public:
    int maxProduct(int n) {
        vector<int> nums;
        while(n){
            int dgt=n%10;
            nums.push_back(dgt);
            n=n/10;
        }
        sort(nums.rbegin(),nums.rend());
        return nums[0]*nums[1];
    }
};
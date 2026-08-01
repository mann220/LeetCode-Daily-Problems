class Solution {
public:
    int f(int i,int j,vector<int> &nums){
        if(i>j) return 0;
        int take1=nums[i]-f(i+1,j,nums);
        int take2=nums[j]-f(i,j-1,nums);
        return max(take1,take2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        return f(0,n-1,nums)>=0;
    }
};
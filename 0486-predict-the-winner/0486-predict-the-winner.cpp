class Solution {
public:
    int f(int i,int j,vector<int> &nums){
        if(i>j) return 0;
        int take1=nums[i]+min(f(i+2,j,nums),f(i+1,j-1,nums));
        int take2=nums[j]+min(f(i,j-2,nums),f(i+1,j-1,nums));
        return max(take1,take2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int plyr1=f(0,n-1,nums);
        int plyr2=sum-plyr1;
        return plyr1>=plyr2;
    }
};
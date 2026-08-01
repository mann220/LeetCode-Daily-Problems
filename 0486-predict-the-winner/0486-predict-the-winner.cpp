class Solution {
public:
    bool f(int i,int j,vector<int> &nums,int a,int b,bool flag){
        if(i>j) return a>=b;
        if(flag) return f(i+1,j,nums,a+nums[i],b,false) || f(i,j-1,nums,a+nums[j],b,false);
        return f(i+1,j,nums,a,b+nums[i],true) && f(i,j-1,nums,a,b+nums[j],true);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        return f(0,n-1,nums,0,0,true);
    }
};
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        int i=k;
        for(i=k;i<=100;i+=k){
            bool flag=false;
            for(int j=0;j<n;j++){
                if(nums[j]==i){
                    flag=true;
                    break;
                }
            }
            if(!flag) return i;
        }
        return i;
    }
};
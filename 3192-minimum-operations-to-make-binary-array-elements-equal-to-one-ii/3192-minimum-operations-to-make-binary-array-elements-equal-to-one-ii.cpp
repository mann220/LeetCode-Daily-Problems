class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int times=0;
        for(int i=0;i<n;i++){
            if((nums[i]%2==0 && times%2==0) || (nums[i]%2==1 && times%2!=0)){
                times++;
            }
        }
        return times;
    }
};
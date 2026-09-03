class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int mini=*min_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(mini%2!=nums[i]%2){
                if(mini%2==0) return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=-1;
        int secmx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                secmx=maxi;
                maxi=nums[i];
            }
            else if(nums[i]>secmx){
                secmx=nums[i];
            }
        }
        return (maxi-1)*(secmx-1);
    }
};
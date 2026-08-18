class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n) return *max_element(nums.begin(),nums.end());
        vector<int> hash(51,0);
        for(int i=0;i<n;i++) hash[nums[i]]++;
        if(k==1){
            int maxi=-1;
            for(int i=0;i<n;i++){
                if(hash[nums[i]]==1) maxi=max(maxi,nums[i]); 
            }
            return maxi;
        }
        if(hash[nums[0]]==1 && hash[nums[n-1]]==1) return max(nums[0],nums[n-1]);
        else if(hash[nums[n-1]]==1) return nums[n-1];
        else if(hash[nums[0]]==1) return nums[0];
        return -1;
    }
};
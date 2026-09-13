class Solution {
public:
    #define ll long long
    long long shadowPairs(vector<int>& nums) {
        int n=nums.size();
        ll ans=0;
        vector<int> temp;
        for(int i=0;i<n;i++){
            while(!temp.empty() && temp.back()>nums[i]) temp.pop_back();
            ans+=(lower_bound(temp.begin(),temp.end(),1LL*nums[i])-temp.begin());
            temp.push_back(nums[i]);
        }
        return ans;
    }
};
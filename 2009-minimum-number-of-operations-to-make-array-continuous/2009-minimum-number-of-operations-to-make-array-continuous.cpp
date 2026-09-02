class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> v;
        for(int i=0;i<n;i++){
            if(v.empty() || v.back()!=nums[i]) v.push_back(nums[i]);
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            int j=upper_bound(v.begin(),v.end(),v[i]+n-1)-v.begin();
            int cnt=j-i;
            ans=max(ans,cnt);
        }
        return n-ans;
    }
};
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++) st.insert(nums[i]);
        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(st.find(i)==st.end()) ans.push_back(i);
        }
        return ans;
    }
};
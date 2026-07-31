class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        multiset<int> st;
        int i=0;
        int ln=0;
        for(int j=0;j<n;j++){
            st.insert(nums[j]);
            while(*prev(st.end())-*st.begin()>limit){
                st.erase(st.find(nums[i]));
                i++;
            }
            ln=max(ln,j-i+1);
        }
        return ln;
    }
};
class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n+1,0);
        for(int i=0;i<n;i++){
            if(nums[i]<=n) freq[nums[i]]++;
        }
        vector<int> res;
        int i=0;
        while(i<n){
            int mex=0;
            while(mex<=n && freq[mex]>0) mex++;
            if(mex==0){
                res.push_back(0);
                if(nums[i]<=n) freq[nums[i]]--;
                i++;
                continue;
            }
            set<int> st;
            int j=i;
            while(j<n && st.size()<mex){
                if(nums[j]<mex) st.insert(nums[j]);
                j++;
            }
            res.push_back(mex);
            for(int k=i;k<j;k++){
                if(nums[k]<=n) freq[nums[k]]--;
            }
            i=j;
        }
        return res;
    }
};
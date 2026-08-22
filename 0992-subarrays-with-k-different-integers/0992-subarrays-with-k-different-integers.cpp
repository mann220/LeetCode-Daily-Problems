class Solution {
public:
    // Logic=> Exactly K distinct = AtMost(K) − AtMost(K−1).

    // here the logic is we have to find at subarray which contains k different integers so we find here at most k different integer and then at most k-1 different integer then subtract them.
    int f(vector<int> &nums,int k){
        int n=nums.size();
        int i=0;
        int j=0;
        int cnt=0;
        unordered_map<int,int> mpp;
        while(j<n){
            if(mpp.size()<=k) mpp[nums[j]]++;
            while(i<=j && mpp.size()>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int val1=f(nums,k);
        cout<<val1<<endl;
        int val2=f(nums,k-1);
        cout<<val2<<endl;
        return val1-val2;
    }
};
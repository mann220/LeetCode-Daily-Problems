class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        int sum=0;
        mpp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int val=sum-k;
            if(mpp.find(val)!=mpp.end()){
                cnt+=mpp[val];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};
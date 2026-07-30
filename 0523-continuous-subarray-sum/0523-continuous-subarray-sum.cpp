class Solution {
public:
    #define ll long long
    // here i have to thik to find remainder of all prefix sum as when i find the remainder of prefix sum and i found the same remainder again then if i subtract it from there then i will get the number whoi is diivisble by k;
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        int pre=0;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            int rem=(pre%k);
            if(mpp.find(rem)!=mpp.end()){
                if(i-mpp[rem]>=2) return true;
            }
            else mpp[rem]=i;
        }
        return false;
    }
};
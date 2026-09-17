class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        unordered_map<int,int> mpp;
        int pre=0;
        mpp[0]=-1;
        vector<int> minIndex(n,INT_MAX);
        int ans=INT_MAX;
        int bestMin=INT_MAX;
        for(int i=0;i<n;i++){
            pre+=arr[i];
            int rem=pre-target;
            if(mpp.find(rem)!=mpp.end()){
                int len=i-mpp[rem];
                if(mpp[rem]>=0 && minIndex[mpp[rem]]!=INT_MAX){
                    ans=min(ans,len+minIndex[mpp[rem]]);
                }
                bestMin=min(bestMin,len);
            }
            minIndex[i]=bestMin;
            mpp[pre]=i;
        }
        return ans==INT_MAX ? -1:ans;
    }
};
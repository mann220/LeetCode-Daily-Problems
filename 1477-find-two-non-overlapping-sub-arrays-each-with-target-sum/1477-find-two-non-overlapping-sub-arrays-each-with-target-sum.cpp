class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int j=0;
        int pre=0;
        vector<int> minIndex(n,INT_MAX);
        int ans=INT_MAX;
        int bestMin=INT_MAX;
        while(j<n){
            pre+=arr[j];
            while(pre>target){
                pre-=arr[i];
                i++;
            }
            if(pre==target){
                int len=j-i+1;
                if(i>0 && minIndex[i-1]!=INT_MAX) ans=min(ans,len+minIndex[i-1]);
                bestMin=min(bestMin,len);
            }
            minIndex[j]=bestMin;
            j++;
        }
        return ans==INT_MAX ? -1:ans;
    }
};
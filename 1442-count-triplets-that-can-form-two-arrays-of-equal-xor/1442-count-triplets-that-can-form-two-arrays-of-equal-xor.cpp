class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            int val=arr[i];
            for(int k=i+1;k<n;k++){
                val^=arr[k];
                if(val==0) cnt+=(k-i);
            }
        }
        return cnt;
    }
};
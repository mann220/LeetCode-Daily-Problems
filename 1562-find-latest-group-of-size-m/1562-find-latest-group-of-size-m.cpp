class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();
        vector<int> len(n+2,0);
        int cnt=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            int x=arr[i];
            int left=len[x-1];
            int rght=len[x+1];
            if(left==m) cnt--;
            if(rght==m) cnt--;
            len[x]=left+1+rght;
            if(len[x]==m) cnt++;
            len[x-left]=len[x];
            len[x+rght]=len[x];
            if(cnt>0) ans=i+1;
        }
        return ans;
    }
};
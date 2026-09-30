class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> v(n);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0) cnt++;
                else break;
            }
            v[i]=cnt;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(v[i]>=n-1-i) continue;
            int j=i;
            while(j<n && v[j]<(n-1-i)) j++;
            if(j==n) return -1;
            vector<int> temp=v;
            int val=v[j];
            for(int k=i;k<j;k++) v[k+1]=temp[k];
            v[i]=val;
            ans+=(j-i);
        }
        return ans;
    }
};
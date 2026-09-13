class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size();
        int ans=0;
        for(int i=-n+1;i<n;i++){
            for(int j=-n+1;j<n;j++){
                int cnt=0;
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        if(i+k>=0 && i+k<n && j+l>=0 && j+l<n && a[k][l]==1 && b[i+k][j+l]==1) cnt++;
                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
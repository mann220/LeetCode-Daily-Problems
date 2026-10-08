class Solution {
public:
    // here the observation is if we have one mail box then i will put it on the median of that
    // i have to make states which is
    // f(i,k) ==> best way to put k mail boxes upto index i  
    vector<vector<int>> dp; 
    int f(int i,int k,vector<int> &houses,vector<vector<int>> &cost){
        int n=houses.size();
        if(i==n && k==0) return 0;
        if(k==0 || i==n) return 1e7;
        if(dp[i][k]!=-1) return dp[i][k];
        int ans=1e7;
        for(int x=i;x<n;x++) ans=min(ans,cost[i][x]+f(x+1,k-1,houses,cost));
        return dp[i][k]=ans;
    }
    int minDistance(vector<int>& houses, int k) {
        int n=houses.size();
        sort(houses.begin(),houses.end());
        vector<vector<int>> cost(n,vector<int> (n,0));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int mid=(i+j)/2;
                for(int k=i;k<=j;k++){
                    cost[i][j]+=abs(houses[k]-houses[mid]);
                }
            }
        }
        dp=vector<vector<int>> (n+1,vector<int> (k+1,-1));
        return f(0,k,houses,cost);
    }
};
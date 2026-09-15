class Solution {
public:
    vector<vector<bool>> isPalindrome;
    vector<int> dp;
    int n;
    int f(int i,int k){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=f(i+1,k);
        for(int j=i+k-1;j<n;j++){
            if(isPalindrome[i][j]){
                ans=max(ans,1+f(j+1,k));
            }
        }
        return dp[i]=ans;
    }
    int maxPalindromes(string s, int k) {
        n=s.size();
        isPalindrome=vector<vector<bool>>(n+1, vector<bool>(n+1, false));
        for(int L=1;L<=n;L++){
            for(int i=0;i+L<=n;i++){
                int j=i+L-1;
                if(i==j) isPalindrome[i][j]=true; // length 1
                else if(i+1==j) isPalindrome[i][j]=(s[i]==s[j]);
                else isPalindrome[i][j]=(s[i]==s[j] && isPalindrome[i+1][j-1]);
            }
        }
        dp=vector<int> (n,-1);
        return f(0,k);
    }
};
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.length();
        vector<vector<bool>> isPalindrome(n+1, vector<bool>(n+1, false));
        for(int L=1;L<=n;L++){
            for(int i=0;i+L<=n;i++){
                int j=i+L-1;
                if(i==j) isPalindrome[i][j]=true; // length 1
                else if(i+1==j) isPalindrome[i][j]=(s[i]==s[j]);
                else isPalindrome[i][j]=(s[i]==s[j] && isPalindrome[i+1][j-1]);
            }
        }
        vector<int> dp(n+1, 0);
        for(int L=k;L<=n;L++){
            int result=dp[L-1];
            int j=L-1;
            for(int i=0;j-i+1>=k;i++){
                if(isPalindrome[i][j]){
                    result=max(result,1+dp[i]);
                }
            }
            dp[L]=result;
        }
        return dp[n];
    }
};
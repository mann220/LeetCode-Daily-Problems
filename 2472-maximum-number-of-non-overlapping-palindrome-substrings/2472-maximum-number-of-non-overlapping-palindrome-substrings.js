/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxPalindromes = function(s, k) {
    const n=s.length;
    const isPalindrome=Array(n+1).fill(false).map(()=> Array(n+1).fill(false));
    for(let L=1;L<=n;L++){
        for(let i=0;i+L<=n;i++){
            let j=i+L-1;
            if(i===j) isPalindrome[i][j]=true; // length 1
            else if(i+1===j) isPalindrome[i][j]=(s[i]===s[j]);
            else isPalindrome[i][j]=(s[i]===s[j] && isPalindrome[i+1][j-1]); 
        }
    }
    const dp=Array(n+1).fill(0);
    for(let L=k;L<=n;L++){
        let result=dp[L-1];
        let j=L-1;
        for(let i=0;j-i+1>=k;i++){
            if(isPalindrome[i][j]){
                result=Math.max(result,1+dp[i]);
            }
        }
        dp[L]=result;
    }
    return dp[n];
};
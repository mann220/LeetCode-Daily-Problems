class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        int d=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') d++;
            else{
                d--;
                if(s[i-1]=='(') ans+=(1<<d);
            }
        }
        return ans;
    }
};
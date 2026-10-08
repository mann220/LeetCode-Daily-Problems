class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int val=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(val>0) ans+=s[i];
                val++;
            }
            else{
                val--;
                if(val>0) ans+=s[i];
            }
        }
        return ans;
    }
};
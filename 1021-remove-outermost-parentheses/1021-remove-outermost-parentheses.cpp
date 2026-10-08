class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int val=0;
        string ans="";
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
                if(st.size()>=2) ans+=s[i];
            }
            else{
                if(st.size()>=2) ans+=s[i];
                st.pop();
            }
        }
        return ans;
    }
};
class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        string ans="";
        vector<int> opn;
        for(int i=0;i<n;i++){
            if(s[i]=='(') opn.push_back(i);
            else if(s[i]==')'){
                int open=opn.back();
                opn.pop_back();
                reverse(s.begin()+open+1,s.begin()+i);
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]!='(' && s[i]!=')') ans+=s[i];
        }
        return ans;
    }
};
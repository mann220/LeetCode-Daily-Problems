class Solution {
public:
    unordered_set<string> ans;
    void f(int i,int opn,int mini,string &inp,string &s){
        if(opn<0 || mini<0) return;
        if(i==s.size()){
            if(mini==0 && opn==0) ans.insert(inp);
            return;
        }
        if(s[i]>='a' && s[i]<='z'){
            inp.push_back(s[i]);
            f(i+1,opn,mini,inp,s);
            inp.pop_back();
        }
        else if(s[i]=='('){
            inp.push_back(s[i]);
            f(i+1,opn+1,mini,inp,s);            // first option is we take it
            inp.pop_back();
            f(i+1,opn,mini-1,inp,s);                // second option we don't take it
        }
        else if(s[i]==')'){
            inp.push_back(s[i]);
            f(i+1,opn-1,mini,inp,s);
            inp.pop_back();
            f(i+1,opn,mini-1,inp,s);
        } 
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()=='(' && s[i]==')') st.pop();
            else if(s[i]=='(' || s[i]==')') st.push(s[i]);
        }
        int mini=st.size();
        string inp="";
        f(0,0,mini,inp,s);
        return vector<string>(ans.begin(),ans.end());
    }
};
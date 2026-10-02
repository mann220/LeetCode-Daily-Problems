class Solution {
public:
    vector<string> ans;
    void f(int opn,int clo,string inp){
        if(clo<opn || opn<0 || clo<0) return;
        if(opn==0 && clo==0){
            ans.push_back(inp);
            return;
        }
        // we have to option
        f(opn-1,clo,inp+"(");
        f(opn,clo-1,inp+")");
    }
    vector<string> generateParenthesis(int n) {
        string inp="(";
        f(n-1,n,inp);
        return ans;
    }  
};
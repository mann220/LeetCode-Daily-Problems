class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int opn=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') opn++;
            else if(s[i]==')') opn--;
            ans=max(ans,opn);
        }
        return ans;
    }
};
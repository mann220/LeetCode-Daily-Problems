class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // my solution is not in one pass the one pass solution is we can do by assigning alternative bracket to each A and B that is it makes it unique
        int n=seq.size();
        int opn=0;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(seq[i]=='(') opn++;
            ans[i]=opn%2;
            if(seq[i]==')') opn--;
        }
        return ans;
    }
};
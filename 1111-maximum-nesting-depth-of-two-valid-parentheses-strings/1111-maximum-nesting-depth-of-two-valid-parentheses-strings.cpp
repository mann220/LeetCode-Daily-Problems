class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        int opn=0;
        int maxi=0;
        vector<int> ind;
        for(int i=0;i<n;i++){
            if(seq[i]=='(') opn++;
            else opn--;
            if(maxi<opn) maxi=opn;
        }
        opn=0;
        int i=0;
        for(int i=0;i<n;i++){
            if(seq[i]=='(') opn++;
            else opn--;
            if((maxi/2)+1==opn) ind.push_back(i);
        }
        vector<int> ans(n,0);
        opn=0;
        int lstind=-1;
        for(int j=0;j<ind.size();j++){
            if(lstind>=ind[j]) continue;
            opn=0;
            // cout<<ind[j]<<"\n";
            for(int i=ind[j];i<n;i++){
                if(seq[i]=='(') opn++;
                else opn--;
                if(opn<0){
                    lstind=i;
                    break;
                }
                ans[i]=1;
            }
        }
        return ans;
    }
};
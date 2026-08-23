class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        set<pair<int,vector<int>>> st;
        int sum=0;
        vector<int> temp(n,0);
        for(int i=0;i<n;i++) sum+=mat[i][0];
        st.insert({sum,temp});
        k--;
        while(k--){
            sum=st.begin()->first;
            temp=st.begin()->second;
            st.erase(st.begin());
            for(int i=0;i<n;i++){
                if(temp[i]+1<m){
                    int val=sum-mat[i][temp[i]]+mat[i][temp[i]+1];
                    temp[i]++;
                    st.insert({val,temp});
                    temp[i]--;
                }
            }
        }
        return st.begin()->first;
    }
};
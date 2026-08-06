class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newi) {
        int n=v.size();
        int l=newi[0];
        int r=newi[1];
        bool flag=true;
        vector<vector<int>> ans;
        int i=0;
        while(i<n){
            if(v[i][1]<l || v[i][0]>r){
                ans.push_back({v[i][0],v[i][1]});
                i++;
                continue;
            }  
            while(i<n && v[i][1]>=l){
                if(r<v[i][0]) break;
                l=min(l,v[i][0]);
                i++;
            }
            r=max(r,v[i-1][1]);
            ans.push_back({l,r});
            flag=false;
        }
        if(flag) ans.push_back({l,r});
        sort(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newi) {
        int n=v.size();
        int i=0;
        vector<vector<int>> ans;
        while(i<n && v[i][1]<newi[0]){
            ans.push_back(v[i]);
            i++;
        }
        while(i<n && newi[1]>=v[i][0]){
            newi[0]=min(newi[0],v[i][0]);
            newi[1]=max(newi[1],v[i][1]);
            i++;
        }
        ans.push_back(newi);
        while(i<n){
            ans.push_back(v[i]);
            i++;
        }
        return ans;
    }
};
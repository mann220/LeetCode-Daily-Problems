class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,int n,int k,vector<int> temp){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<=n;j++){
            temp.push_back(j);
            f(j+1,n,k,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        f(1,n,k,temp);
        return ans;
    }
};
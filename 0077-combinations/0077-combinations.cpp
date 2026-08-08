class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        for(int mask=0;mask<(1<<n);mask++){
            if(__builtin_popcount(mask)!=k) continue;
            vector<int> temp;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    temp.push_back(i+1);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
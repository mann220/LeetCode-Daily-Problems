class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        int lst=INT_MIN;
        int ans=0;
        for(auto it:pairs){
            if(it[0]>lst){
                ans++;
                lst=it[1];
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> check(int mask,int n){
        vector<int> v;
        for(int i=0;i<n;i++){
            if(mask & (1<<i)) v.push_back((i+1));
        }
        return v;
    }
    void f(int i,int mask,int n,int k){
        if(__builtin_popcount(mask)>k) return;
        if(i==n){
            if(__builtin_popcount(mask)==k) ans.push_back(check(mask,n));
            return;
        }
        f(i+1,mask|(1<<i),n,k);
        f(i+1,mask,n,k); 
    }
    vector<vector<int>> combine(int n, int k) {
        f(0,0,n,k);
        return ans;
    }
};
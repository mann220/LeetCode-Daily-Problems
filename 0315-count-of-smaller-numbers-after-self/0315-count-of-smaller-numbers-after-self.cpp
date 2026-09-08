class Solution {
public:
    vector<int> bit;
    int n;
    void update(int id,int val){
        while(id<=n){
            bit[id]+=val;
            id+=(id&-id);
        }
    }
    int query(int id){
        int ans=0;
        while(id>0){
            ans+=bit[id];
            id-=(id&-id);
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        n=nums.size();
        bit=vector<int> (n+1,0);
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        vector<int> ans(n,0);
        for(auto [el,id]:v){
            update(id+1,1);
            ans[id]=query(n)-query(id+1);
        }
        return ans;
    }
};
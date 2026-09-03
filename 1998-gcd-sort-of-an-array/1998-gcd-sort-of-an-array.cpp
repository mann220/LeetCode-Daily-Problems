class Solution {
public:
    // this is a very good question of disjoint set union(dsu) in this we have to see numbers connected with common prime factor so dsu helps to make as ultimate parent which means if ultimate parents are same then we can swap them.
    vector<int> par;
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void uni(int u,int v){
        int ultp_u=find(u);
        int ultp_v=find(v);
        if(ultp_u!=ultp_v){
            par[ultp_u]=ultp_v;
        }
    }
    bool gcdSort(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        par.assign(mx+1,0);
        vector<int> spf(mx+1);
        for(int i=0;i<=mx;i++){
            par[i]=i;
            spf[i]=i;
        }
        for(int i=2;i*i<=mx;i++){
            if(spf[i]==i){
                for(int j=i*i;j<=mx;j+=i){
                    if(spf[j]==j) spf[j]=i;
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            while(val>1){
                int p=spf[val];
                uni(nums[i],p);
                while(val%p==0) val/=p;
            }
        }
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<nums.size();i++){
            if(find(sorted[i])!=find(nums[i])) return false;
        }
        return true;
    }
};
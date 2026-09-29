class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        unordered_map<int,vector<int>> mpp;
        int cnt=2;
        vector<int> spf(maxi+1);
        for(int i=0;i<=maxi;i++) spf[i]=i;
        for(int i=2;i*i<=maxi;i++){
            if(spf[i]==i){
                for(int j=i*i;j<=maxi;j+=i){
                    if(spf[j]==j) spf[j]=i;
                }
            }
        }
        for(int i=0;i<n;i++){
            int x=nums[i];
            while(x>1){
                int p=spf[x];
                mpp[p].push_back(i);
                while(x%p==0) x=x/p;
            }
        }
        vector<int> dist(n,INT_MAX);
        vector<bool> vis(maxi+1,false);
        queue<int> q;
        q.push(0);
        dist[0]=0;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(i==n-1) return dist[i];
            if(i-1>=0 && dist[i]+1<dist[i-1]){
                dist[i-1]=dist[i]+1;
                q.push(i-1);
            }
            if(i+1<n && dist[i]+1<dist[i+1]){
                dist[i+1]=dist[i]+1;
                q.push(i+1);
            }
            int p=nums[i];
            if(p<=maxi && spf[p]==p && !vis[p]){
                vis[p]=true;
                for(auto j:mpp[p]){
                    if(dist[i]+1<dist[j]){
                        dist[j]=1+dist[i];
                        q.push(j);
                    }
                }
            }
        }
        return -1;
    }
};
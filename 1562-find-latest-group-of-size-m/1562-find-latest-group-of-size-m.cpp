class Disjoint{
    public:
    vector<int> par;
    vector<int> size;
    Disjoint(int n){
        par=vector<int> (n+1);
        size=vector<int> (n+1,1);
        for(int i=0;i<=n;i++) par[i]=i;
    }
    int findupar(int u){
        if(u==par[u]) return u;
        return par[u]=findupar(par[u]);
    }
    int uni(int u,int v){
        int ultp_u=findupar(u);
        int ultp_v=findupar(v);
        if(ultp_u==ultp_v) return ultp_u;
        if(size[ultp_u]>size[ultp_v]){
            size[ultp_u]+=size[ultp_v];
            par[ultp_v]=ultp_u;
            return ultp_u;
        }
        else {
            size[ultp_v]+=size[ultp_u];
            par[ultp_u]=ultp_v;
            return ultp_v;
        }
    }
};
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();
        Disjoint dsu(n);
        unordered_map<int,int> mpp;
        int ans=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            mpp[arr[i]]=1;
            if(m==1) cnt++;
            if(arr[i]>1 && mpp.find(arr[i]-1)!=mpp.end()){
                int u=dsu.findupar(arr[i]);
                int v=dsu.findupar(arr[i]-1);
                if(u!=v){
                    if(dsu.size[u]==m) cnt--;
                    if(dsu.size[v]==m) cnt--;
                    int root=dsu.uni(u,v);
                    if(dsu.size[root]==m) cnt++;
                }
            }
            if(arr[i]<n && mpp.find(arr[i]+1)!=mpp.end()){
                int u=dsu.findupar(arr[i]);
                int v=dsu.findupar(arr[i]+1);
                if(u!=v){
                    if(dsu.size[u]==m) cnt--;
                    if(dsu.size[v]==m) cnt--;
                    int root=dsu.uni(u,v);
                    if(dsu.size[root]==m) cnt++; 
                }
            }
            if(cnt>0) ans=i+1;
        }
        return ans;
    }
};
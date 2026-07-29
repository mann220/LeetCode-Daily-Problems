class Solution {
public:
    int par[26],size[26];
    int findupar(int val){
        if(par[val]==val) return val;
        return par[val]=findupar(par[val]);
    }
    void unionbysize(int u,int v){
        int ultp_u=findupar(u);
        int ultp_v=findupar(v);
        if(ultp_u!=ultp_v) par[ultp_v]=ultp_u;
    }
    bool equationsPossible(vector<string>& v) {
        for(int i=0;i<26;i++) par[i]=i;
        for(int i=0;i<v.size();i++){
            if(v[i][1]=='='){
                int x=v[i][0]-'a';
                int y=v[i][3]-'a';
                unionbysize(x,y);
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i][1]=='!'){
                int x=findupar(v[i][0]-'a');
                int y=findupar(v[i][3]-'a');
                if(x==y) return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(s.size()==1) return 0;
        if(s.size()==2){
            if(s[0]>s[1]) return -1;
            return 0;
        }
        string p=s;
        sort(p.begin(),p.end());
        if(p==s) return 0;
        char maxi=p[n-1];
        char mini=p[0];
        if(maxi==mini) return 0;
        bool flg=false;
        for(int i=1;i<n-1;i++) if(s[i]==mini || s[i]==maxi) flg=true;
        if(!flg && (maxi==s[0] && mini==s[n-1])) return 3;
        if(maxi!=s[n-1] && mini!=s[0]) return 2;
        if(maxi==s[n-1] || mini==s[0]) return 1;
        return -1;
    }
};
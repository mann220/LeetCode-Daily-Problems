class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int> strt(26,-1);
        vector<int> end(26,-1);
        for(int i=0;i<n;i++){
            if(strt[s[i]-'a']==-1){
                strt[s[i]-'a']=i;
            }
            end[s[i]-'a']=i;
        }
        vector<bool> isValid(26,true);
        for(int i=0;i<26;i++){
            if(strt[i]==-1) continue;
            for(int j=strt[i];j<=end[i];j++){
                if(strt[s[j]-'a']<strt[i]){
                    isValid[i]=false;
                    break;
                }
                end[i]=max(end[i],end[s[j]-'a']);
            }
        }
        vector<string> ans;
        int st=n;
        for(int i=n-1;i>=0;i--){
            if(isValid[s[i]-'a']==false) continue;
            if(end[s[i]-'a']>=st) continue;
            if(strt[s[i]-'a']==i){
                int len=end[s[i]-'a']-strt[s[i]-'a']+1;
                ans.push_back(s.substr(strt[s[i]-'a'],len));
                st=strt[s[i]-'a'];
            }
        }
        return ans;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int cnt=0,sInd=-1,minLen=1e9;
        unordered_map<char,int> mpp;
        for(int i=0;i<m;i++) mpp[t[i]]++;
        int i=0,j=0;
        while(j<n){
            if(mpp[s[j]]>0) cnt++;
            mpp[s[j]]--;
            while(cnt==m){
                if(j-i+1<minLen){
                    minLen=j-i+1;
                    sInd=i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0) cnt--;
                i++;
            }
            j++;
        }
        return sInd==-1 ? "": s.substr(sInd,minLen); 
    }
};
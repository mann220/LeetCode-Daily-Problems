class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int minLen=1e9;
        int sIndex=-1;
        int cnt=0;
        unordered_map<char,int> mpp;
        for(int i=0;i<m;i++) mpp[t[i]]++;
        int i=0,j=0;
        while(j<n){
            if(mpp[s[j]]>0) cnt++;
            mpp[s[j]]--;
            while(cnt==m){
                if(j-i+1<minLen){
                    minLen=j-i+1;
                    sIndex=i; 
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0) cnt=cnt-1;
                i++;
            }
            j++;
        }
        return sIndex==-1 ? "":s.substr(sIndex,minLen);
    }
};
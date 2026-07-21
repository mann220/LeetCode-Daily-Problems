class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') ans++;
        }
        vector<int> block;
        int i=0;
        while(i<s.size()){
            if(s[i]=='0'){
                int j=i;
                while(i<s.size() && s[i]=='0') i++;
                block.push_back(i-j);
            }
            else i++;
        }
        int maxi=0;
        for(int i=1;i<block.size();i++) maxi=max(maxi,block[i-1]+block[i]);
        return ans+maxi;
    }
};
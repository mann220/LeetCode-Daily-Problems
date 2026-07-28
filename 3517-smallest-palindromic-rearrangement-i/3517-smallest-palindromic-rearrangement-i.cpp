class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> hash(26,0);
        for(int i=0;i<s.size();i++) hash[s[i]-'a']++;
        string ans="";
        string t="";
        char p='@';
        for(int i=0;i<26;i++){
            if(hash[i]==0) continue;
            char c=(char)(i+'a');
            int val=hash[i];
            int half=val/2;
            while(half--) t+=c;
            if(val%2!=0) p=c;
        }
        ans+=t;
        if(p!='@') ans+=p;
        reverse(t.begin(),t.end());
        ans=ans+t;
        return ans;
    }
};
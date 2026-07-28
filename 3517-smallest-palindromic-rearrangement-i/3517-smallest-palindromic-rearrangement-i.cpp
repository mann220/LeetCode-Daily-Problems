class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> hash;
        for(int i=0;i<s.size();i++) hash[s[i]]++;
        int odd=0;
        string ans="";
        string t="";
        char p='@';
        for(auto it:hash){
            char c=it.first;
            int val=it.second;
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
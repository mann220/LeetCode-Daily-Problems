class Solution {
public:
    #define ll long long
    ll nCr(int n,int r,int k){
        if(r==0) return 1;
        ll ans=1;
        for(int i=1;i<=r;i++){
            ans=(ans*(n-r+i)/i);
            if(ans>=k) return k;
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
        int n=s.size();
        char mid='@';
        if(n%2!=0) mid=s[n/2];
        map<char,int> mpp;
        for(int i=0;i<n;i++) mpp[s[i]]++;
        if(mid!='@') mpp[mid]--;
        int half=n/2;
        string t="";
        for(int i=0;i<half;i++){
            bool flag=false;
            for(char c='a';c<='z';c++){
                if(mpp.find(c)==mpp.end() || mpp[c]==0) continue;
                int total=half-i-1;
                mpp[c]-=2;
                ll ways=1;
                for(auto it:mpp){
                    if(total>0){
                        int val=(it.second)/2;
                        ways*=nCr(total,val,k);
                        total-=val;
                    }
                    if(ways>=k) break;
                }  
                if(ways>=k){
                    t+=c;
                    flag=true;
                    break;
                }
                else {
                    k=k-ways;
                    mpp[c]+=2;
                }
            }
            if(!flag) return "";
        }
        string ans=t;
        if(ans.size()==(s.size()/2) && mid!='@') ans+=mid;
        reverse(t.begin(),t.end());
        ans+=t;
        return ans;
    }
};
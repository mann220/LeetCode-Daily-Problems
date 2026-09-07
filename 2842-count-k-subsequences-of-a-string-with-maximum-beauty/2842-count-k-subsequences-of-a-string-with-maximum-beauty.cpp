class Solution {
public:
    int mod=1e9+7;
    #define ll long long
    ll power(ll x,ll a){
        ll ans=1;
        x=x%mod;
        while(a>0){
            if(a%2==1) ans=(ans*x)%mod;
            x=(x*x)%mod;
            a=a/2;
        }
        return ans;
    }
    ll modInv(int val){
        return power(val,mod-2);
    }
    ll nCr(int n,int r){
        ll ans=1;
        for(int i=1;i<=n;i++) ans=(ans*i)%mod;
        for(int i=1;i<=r;i++){
            ans*=modInv(i);
            ans=ans%mod;
        }
        for(int i=1;i<=n-r;i++){
            ans*=modInv(i);
            ans=ans%mod;
        }
        return ans;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        if(k>26) return 0;
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++) freq[s[i]-'a']++;
        sort(freq.rbegin(),freq.rend());
        ll ans=1;
        int req=0;
        int tot=0;
        for(int i=0;i<k;i++){
            ans=(ans*freq[i])%mod;
            if(freq[i]==freq[k-1]) req++;
        }
        for(int i=0;i<26;i++) if(freq[i]==freq[k-1]) tot++;
        int val=nCr(tot,req);
        ans=(ans*val)%mod;
        return (int)ans;
    }
};
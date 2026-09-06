class Solution {
public:
    // String View method

    // string f(int len,string &s){
    //     int n=s.size();
    //     int i=0;
    //     int j=len;
    //     unordered_map<string_view,int> mpp;
    //     string_view p(s.data(),len);
    //     while(j<=n){
    //         mpp[p]++;
    //         if(mpp[p]>=2) return string(p);
    //         p=string_view(s.data()+i+1,len);
    //         i++;
    //         j++;
    //     }
    //     return "";
    // }

    // Rabin Karp
    #define ll long long
    ll mod=1e9+7;
    ll radix=26;
    ll hashValue(string s,int len){
        ll ans=0,factor=1;
        for(int i=len-1;i>=0;i--){
            ans+=((s[i]-'a')*factor)%mod;
            factor=(factor*radix)%mod;
        }
        return ans%mod;
    }
    bool checkMatch(const string &s, int idx1, int idx2, int len) {
        for (int k=0;k<len;k++) {
            if(s[idx1+k]!=s[idx2+k]){
                return false;
            }
        }
        return true;
    }
    string f(int len,string &s){
        int n=s.size();
        ll max_weight=1;
        unordered_map<ll,ll> mpp;
        for(int i=0;i<len;i++) max_weight=(max_weight*radix)%mod;
        ll hash1=hashValue(s,len);
        ll hash2=0;
        for(int i=0;i<=s.size()-len;i++){
            if(i==0) hash2=hash1;
            else hash2=((hash2*radix)%mod-((s[i-1]-'a')*max_weight)%mod+(s[i+len-1]-'a')+mod)%mod;
            if (mpp.find(hash2) != mpp.end()) {
                // Check if the current string matches the string at the stored index
                if (checkMatch(s, mpp[hash2], i, len)) {
                    return s.substr(i, len);
                }
            } else {
                // Only insert if it's a new hash. If it's a false collision, 
                // we just keep the old index in the map.
                mpp[hash2] = i;
            }
        }
        return "";
    }
    string longestDupSubstring(string s) {
        int n=s.size();
        int lo=1;
        int hi=s.size();
        string ans;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            string temp=f(mid,s);
            if(temp.size()!=0){
                ans=temp;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};
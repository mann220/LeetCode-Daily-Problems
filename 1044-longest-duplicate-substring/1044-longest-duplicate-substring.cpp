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
    // best way to prevent leetcode antihash is unsigned long long
    #define ull unsigned long long 

    // ll mod=1e9+7;
    ull radix=131;
    ull hashValue(string &s,int len){
        ull ans=0,factor=1;
        for(int i=len-1;i>=0;i--){
            ans+=((s[i]-'a')*factor);
            factor=(factor*radix);
        }
        return ans;
    }
    string f(int len,string &s){
        int n=s.size();
        ull max_weight=1;
        unordered_map<ull,int> mpp;
        for(int i=0;i<len;i++) max_weight=max_weight*radix;
        ull hash1=hashValue(s,len);
        ull hash2=0;
        for(int i=0;i<=s.size()-len;i++){
            if(i==0) hash2=hash1;
            else hash2=((hash2*radix)-((s[i-1]-'a')*max_weight)+(s[i+len-1]-'a'));
            mpp[hash2]++;
            if(mpp[hash2]>=2) return s.substr(i,len);
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
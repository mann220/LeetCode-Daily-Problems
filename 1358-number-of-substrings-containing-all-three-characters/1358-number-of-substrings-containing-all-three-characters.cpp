class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> mpp;
        int i=0;
        int j=0;
        int n=s.size();
        int ans=0;
        while(j<n){
            mpp[s[j]]++;
            while(mpp['a']>0 && mpp['b']>0 && mpp['c']>0){
                ans+=(n-j);
                mpp[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mpp;
        int i=0;
        int j=0;
        int maxi=0;
        int ans=0;
        while(j<n){
            mpp[s[j]]++;
            maxi=max(maxi,mpp[s[j]]);
            if(maxi>2){
                while(s[i]!=s[j]){
                    mpp[s[i]]--;
                    i++;
                }
                mpp[s[i]]--;
                i++;
                maxi--;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
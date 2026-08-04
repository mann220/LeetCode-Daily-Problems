class Solution {
public:
    long long wonderfulSubstrings(string s) {
        int n=s.size();
        int mask=0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        long long ans=0;
        for(int i=0;i<n;i++){
            mask^=(1<<(s[i]-'a'));
            ans+=mpp[mask];
            for(char ch='a';ch<='j';ch++){
                int xr=(mask ^ (1<<(ch-'a')));
                ans+=mpp[xr];
            }
            mpp[mask]++;
        }
        return ans;
    }
};
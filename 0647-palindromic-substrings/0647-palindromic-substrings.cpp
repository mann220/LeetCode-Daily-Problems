class Solution {
public:
    int ans;
    int n;
    void check(int i,int j,string &s){
        while(i>=0 && j<n && s[i]==s[j]){
            ans++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        n=s.size();
        ans=0;
        for(int i=0;i<n;i++){
            check(i,i,s);
            check(i,i+1,s);
        }
        return ans;
    }
};
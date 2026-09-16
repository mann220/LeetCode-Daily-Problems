class Solution {
public:
    // [ => 0 , ] => 1 
    int minSwaps(string s) {
        int n=s.size();
        int cnt1=0,cnt0=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='[') cnt0++;
            else cnt0--;
            if(cnt0<0){
                ans++;
                cnt0=1;
            }
        }
        return ans;
    }
};
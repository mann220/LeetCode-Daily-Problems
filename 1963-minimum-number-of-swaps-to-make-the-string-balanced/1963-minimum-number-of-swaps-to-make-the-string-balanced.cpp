class Solution {
public:
    // [ => 0 , ] => 1 
    int minSwaps(string s) {
        int n=s.size();
        int cnt1=0,cnt0=0;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(s[i]=='[') v.push_back(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='[') cnt0++;
            else cnt1++;
            if(cnt1>cnt0){
                ans++;
                swap(s[i],s[v.back()]);
                v.pop_back();
                cnt1--;
                cnt0++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    #define ll long long
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        int ans=1;
        for(auto [x,y]:mpp){
            if(x==1) continue;
            if(y>=2){
                ll t=1LL*x*x;
                int cnt=1;
                while(t<INT_MAX && mpp.find((int)t)!=mpp.end()){
                    if(t<INT_MAX && mpp[(int)t]>=2){
                        t=1LL*t*t;
                        cnt++;
                        ans=max(ans,cnt);
                        if(t>INT_MAX) break;
                    }
                    else{
                        cnt++;
                        ans=max(ans,cnt);
                        break;
                    }
                }
            }
        }
        ans=2*ans-1;
        if(mpp.find(1)!=mpp.end()) ans=max(ans,(mpp[1]%2==0 ? mpp[1]-1:mpp[1]));
        return ans;
    }
};
class Solution {
public:
    # define ll long long
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        ll ans=0;
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i]=abs(nums[i]);
        sort(v.begin(),v.end(),greater<>());
        for(int i=0;i<n;i++){
            if(n%2==0){
                if(i<n/2) ans+=v[i]*v[i];
                else ans-=v[i]*v[i];
            }
            else{
                if(i<=n/2) ans+=v[i]*v[i];
                else ans-=v[i]*v[i];
            }
        }
        return ans;
    }
};
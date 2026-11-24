class Solution {
public:
    #define ll long long
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        ll g=nums[0];
        ll l=nums[0];
        int ans=0;
        for(int i=0;i<n;i++){
            ll g=nums[i];
            ll l=nums[i];
            ll prod=nums[i];
            if(prod==g*l) ans=max(ans,1);
            for(int j=i+1;j<n;j++){
                if(prod>1e6) break;
                g=__gcd(g,(ll)nums[j]);
                l=(l/(__gcd(l,(ll)nums[j])))*nums[j];
                prod*=nums[j];
                if(prod==l*g){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans; 
        
    }
};
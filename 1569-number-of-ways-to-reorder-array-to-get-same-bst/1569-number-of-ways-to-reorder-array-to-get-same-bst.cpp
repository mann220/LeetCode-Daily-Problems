class Solution {
public:
    #define ll long long
    int mod=1e9+7;
    vector<vector<ll>> pt; // pascals triangle
    // for calculating ncr we will use pascal triangle ---> imp --> aryan mittal goat
    ll f(vector<int> &nums){
        int n=nums.size();
        if(n<3) return 1;
        int root=nums[0];
        vector<int> lft,rgt;
        for(int i=1;i<n;i++){
            if(nums[i]<root) lft.push_back(nums[i]);
            else rgt.push_back(nums[i]);
        }
        ll z=pt[n-1][lft.size()];         // r is here left length or right length
        ll l=f(lft);
        ll r=f(rgt);
        return (((z*l)%mod)*r%mod);
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        pt=vector<vector<ll>> (n+1);
        for(int i=0;i<=n;i++){
            pt[i]=vector<ll> (i+1,1);
            for(int j=1;j<i;j++){
                pt[i][j]=(pt[i-1][j-1]+pt[i-1][j])%mod;
            }
        }
        return (int)f(nums)-1;
    }
};
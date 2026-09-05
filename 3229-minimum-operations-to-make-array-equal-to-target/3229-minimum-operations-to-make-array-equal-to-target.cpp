class Solution {
public:
    #define ll long long
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        ll ans=0;
        int curr=0;
        int prev=0;
        for(int i=0;i<n;i++){
            curr=target[i]-nums[i];
            // sign change
            if((curr>0 && prev<0) || (curr<0 && prev>0)) ans+=abs(curr);
            else if(abs(prev)<abs(curr)) ans+=(abs(curr)-abs(prev));
            prev=curr;
        }
        return ans;
    }
};
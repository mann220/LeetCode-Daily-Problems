class Solution {
public:
    #define ll long long
    ll f(vector<ll> temp){
        ll prev=abs(temp[0]);
        ll ans=abs(temp[0]);
        ll curr=0;
        for(int i=1;i<temp.size();i++){
            curr=abs(temp[i]);
            if(curr>prev) ans+=(curr-prev);
            prev=curr;
        }
        return ans;
    }
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        vector<ll> diff(n);
        for(int i=0;i<n;i++) diff[i]=target[i]-nums[i];
        ll ans=0;
        int i=0,j=0;
        while(i<n){
            vector<ll> temp;
            if(diff[i]==0){
                i++;
                continue;
            }
            if(diff[i]>=0){
                while(j<n && diff[j]>=0){
                    temp.push_back(diff[j]);
                    j++;
                }
                ans+=f(temp);
            }
            else{
                while(j<n && diff[j]<=0){
                    temp.push_back(diff[j]);
                    j++;
                }
                ans+=f(temp);
            }
            i=j;
        }
        return ans;
    }
};
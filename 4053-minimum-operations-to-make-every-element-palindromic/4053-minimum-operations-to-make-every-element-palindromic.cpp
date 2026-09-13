#define ll long long
    vector<ll> eve,odd;
    void generate(){
        if(!eve.empty() || !odd.empty()) return;
        for(int i=1;i<=1e5;i++){
            // odd length
            ll num=i;
            ll x=i;
            x/=10;
            while(x>0){
                num=num*10+(x%10);
                x/=10;
            }
            if(num<=2e10){
                if(num%2!=0) odd.push_back(num);
                else eve.push_back(num);
            }
            // eve lenght
            x=i;
            num=i;
            while(x>0){
                num=num*10+(x%10);
                x/=10;
            }
            if(num<=2e10){
                if(num%2!=0) odd.push_back(num);
                else eve.push_back(num);
            }
        }
        sort(eve.begin(),eve.end());
        sort(odd.begin(),odd.end());
    }
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n=nums.size();
        generate();
        ll ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                int lb=lower_bound(eve.begin(),eve.end(),nums[i])-eve.begin();
                ll mini=1e9;
                if(lb!=eve.size()) mini=min(mini,(eve[lb]-nums[i])/2LL);
                if(lb!=0) mini=min(mini,(nums[i]-eve[lb-1])/2LL);
                ans+=mini;
            }
            else{
                int lb=lower_bound(odd.begin(),odd.end(),nums[i])-odd.begin();
                ll mini=1e9;
                if(lb!=odd.size()) mini=min(mini,(odd[lb]-nums[i])/2LL);
                if(lb!=0) mini=min(mini,(nums[i]-odd[lb-1])/2LL);
                ans+=mini;
            }
        }
        return ans;
    }
};
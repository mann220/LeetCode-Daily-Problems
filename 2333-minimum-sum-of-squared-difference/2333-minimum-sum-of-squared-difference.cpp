class Solution {
public:
    // lets do it with binary search
    #define ll long long
    bool f(int mid,vector<ll>&diff,ll &k){
        ll cnt=0;
        for(int i=0;i<diff.size();i++){
            if(diff[i]<=mid) continue; 
            cnt+=(diff[i]-mid);
        }
        return cnt<=k;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        ll k=1LL*k1+k2;
        vector<ll> diff(n);
        ll sum=0;
        for(int i=0;i<n;i++){
            diff[i]=abs(nums1[i]-nums2[i]);
            sum+=diff[i];
        }
        if(sum<=k) return 0;
        int lo=0;
        int hi=*max_element(diff.begin(),diff.end());
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(mid,diff,k)) hi=mid-1;
            else lo=mid+1;
        }
        // cout<<val<<" "<<lo<<"\n";
        cout<<lo<<"\n";
        ll ans=0;
        ll opn=0;
        for(int i=0;i<n;i++){ 
            if(diff[i]<=lo){
                ans+=(diff[i]*diff[i]);
                continue;
            }
            ans+=(1LL*lo*lo);
            opn+=(diff[i]-lo);
        }
        ll rem=k-opn;
        ans-=rem*(2LL*lo-1); 
        //this is the rem operation and this formula comes from x^2-(x-1)^2=2*x-1;
        return ans; 
    }
};
class Solution {
public:
    #define ll long long
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        int k=k1+k2;
        vector<ll> diff(n);
        ll sum=0;
        unordered_map<ll,int> mpp;
        for(int i=0;i<n;i++){
            diff[i]=abs(nums1[i]-nums2[i]);
            mpp[diff[i]]++;
            sum+=diff[i];
        }
        if(sum<=k) return 0;
        priority_queue<pair<ll,ll>> pq;
        for(auto [val,freq]:mpp) pq.push({val,freq});
        while(k>0){
            auto [val,freq]=pq.top();
            pq.pop();
            if(val>0 && k>=freq){
                mpp.erase(val);
                k-=freq;
                mpp[val-1]+=freq;
                if(!pq.empty()) pq.pop();
                pq.push({val-1,mpp[val-1]});
            }
            else if(val>0 && k<freq){
                mpp[val]-=k;
                mpp[val-1]+=k;
                k=0;
            }
        }
        ll ans=0;
        for(auto [val,freq]:mpp) ans+=(freq*(val*val));
        return ans;
    }
};
class Solution {
public:
    int mod=1e9+7;
    #define ll long long
    int totalStrength(vector<int>& nums) {
        int n=nums.size();
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        stack<int> st;
        // one important thing is that we have to make in pse or nse --> nums[st.top()]>=nums[i] in one we have to apply = sign either in pse or nse as we have to consider that element also which are equal in one of them
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
        vector<int> pre(n,0);
        ll sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%mod;
            pre[i]=sum;
        }
        vector<int> preOfpre(n,0);
        sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+pre[i])%mod;
            preOfpre[i]=sum;
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            int l=pse[i]; 
            int r=nse[i]; 
            int before=i-l; 
            int after=r-i;
            ll pre_right=(r-1>=0) ? preOfpre[r-1]:0;
            ll pre_i=(i-1>=0) ? preOfpre[i-1]:0;
            ll pre_left=(l-1>=0) ? preOfpre[l-1]:0;
            ll right_sum=(pre_right-pre_i+mod)%mod;
            ll left_sum=(pre_i-pre_left+mod)%mod;
            ll total=(before*right_sum%mod-after*left_sum%mod+mod)%mod;
            ans=(ans+nums[i]*total%mod)%mod;
        }
        return ans;
    }
};
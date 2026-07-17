class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<int> gcd(mx+1);
        for(int i=0;i<n;i++){
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    gcd[j]++;
                    if(nums[i]/j!=j){
                        gcd[nums[i]/j]++;
                    }
                }

            }
        }
        vector<long long> pairs(mx+1,0);
        for(int i=mx;i>=1;i--){
            long long cnt=gcd[i];
            pairs[i]=cnt*(cnt-1)/2;
            for(int j=2*i;j<=mx;j+=i){
                pairs[i]-=pairs[j];
            }
        }
        vector<long long> pre(mx+1,0);
        for(int i=1;i<=mx;i++){
            pre[i]=pre[i-1]+pairs[i];
        }
        vector<int> ans;
        for(auto it:queries){
            int l=1;
            int r=mx;
            int temp=1;
            while(l<=r){
                int mid=(l+r)/2;
                if(pre[mid]>it){
                    temp=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
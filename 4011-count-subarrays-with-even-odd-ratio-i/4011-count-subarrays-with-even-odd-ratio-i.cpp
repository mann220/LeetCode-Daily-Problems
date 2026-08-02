class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        vector<int> prefeve(n,0);
        vector<int> prefodd(n,0);
        int cnteve=0,cntodd=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) cnteve++;
            else cntodd++;
            prefeve[i]=cnteve;
            prefodd[i]=cntodd;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int odd=0,eve=0;
                if(i-1>=0) odd=prefodd[j]-prefodd[i-1];
                else odd=prefodd[j];
                if(i-1>=0) eve=prefeve[j]-prefeve[i-1];
                else eve=prefeve[j];
                if(odd>0){
                    if(1LL*a*odd>=1LL*b*eve) cnt++;
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
    // i think we have to check here dip in the array for every possible divisor
    // also we have to see the maximum number we get in front of array 
    void divisor(int n,vector<int> &div){
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                div.push_back(i);
                if(i!=(n/i)) div.push_back(n/i);
            }
        }
    }
    bool check(int l,int r,vector<int> &nums){
        if((r-l)<=2) return true;
        int cnt=0;
        int n=nums.size();
        for(int i=l;i<r-1;i++){
            if(nums[i]>nums[i+1]) cnt++;
        }
        if(nums[r-1]>nums[l]) cnt++;
        return cnt<=1;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> div;
        divisor(n,div);
        int ans=0;
        sort(div.begin(),div.end());
        for(int i=0;i<div.size();i++){
            int maxi=0;
            int k=div[i];
            bool flg=true;
            for(int j=0;j<n;j+=k){
                int v=*max_element(nums.begin()+j,nums.begin()+j+k);
                // cout<<k<<" "<<maxi<<" "<<v<<" "<<check(j,j+k,nums)<<" "<<j<<" "<<j+k<<"\n";
                int mini=*min_element(nums.begin()+j,nums.begin()+j+k);
                if(maxi>mini || !check(j,j+k,nums)){
                    flg=false;
                    break;
                }
                maxi=max(maxi,v);
            }
            if(flg){
                ans+=k;
                // cout<<k<<"\n";
            }
        }
        return ans;
    }
};
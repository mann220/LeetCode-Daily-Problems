class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxi(n+1,0);
        for(int i=0;i<ranges.size();i++){
            int left=max(0,i-ranges[i]);
            int right=min(i+ranges[i],n);
            maxi[left]=max(maxi[left],right);
        }
        int ans=0;
        int maxend=0;
        int currend=0;
        for(int i=0;i<=n;i++){
            if(i>maxend) return -1;
            if(i>currend){
                ans++;
                currend=maxend;
            }
            maxend=max(maxend,maxi[i]);
        }  
        return ans;
    }
};
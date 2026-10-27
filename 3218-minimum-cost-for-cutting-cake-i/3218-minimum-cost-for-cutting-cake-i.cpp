class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.rbegin(),h.rend());
        sort(v.rbegin(),v.rend());
        int i=0;
        int j=0;
        int vcnt=1;
        int hcnt=1;
        int ans=0;
        while(i<m-1 && j<n-1){
            if(h[i]<v[j]){
                ans+=(v[j]*hcnt);
                vcnt+=1;
                j++;
            }
            else{
                ans+=(h[i]*vcnt);
                hcnt+=1;
                i++;
            }
        }
        while(i<m-1){
            ans+=(h[i]*vcnt);
            hcnt+=1;
            i++;
        }
        while(j<n-1){
            ans+=(v[j]*hcnt);
            vcnt+=1;
            j++;
        }
        return ans;
    }
};
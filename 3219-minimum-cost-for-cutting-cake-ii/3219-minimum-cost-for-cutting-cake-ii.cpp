class Solution {
public:
    #define ll long long
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.rbegin(),h.rend());
        sort(v.rbegin(),v.rend());
        int i=0;
        int j=0;
        ll vcnt=1;
        ll hcnt=1;
        ll ans=0;
        while(i<m-1 && j<n-1){
            if(h[i]<v[j]){
                ans+=(1LL*v[j]*hcnt);
                vcnt+=1;
                j++;
            }
            else{
                ans+=(1LL*h[i]*vcnt);
                hcnt+=1;
                i++;
            }
        }
        while(i<m-1){
            ans+=(1LL*h[i]*vcnt);
            hcnt+=1;
            i++;
        }
        while(j<n-1){
            ans+=(1LL*v[j]*hcnt);
            vcnt+=1;
            j++;
        }
        return ans;
    }
};
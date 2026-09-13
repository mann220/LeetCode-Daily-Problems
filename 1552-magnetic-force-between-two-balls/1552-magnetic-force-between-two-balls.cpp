class Solution {
public:
    // This problem is basically binary search on answer just we have to see the possibility that how many distances are possible 
    bool f(int mid,int m,vector<int> &position){
        int n=position.size();
        int i=0;
        int j=1;
        while(i<n && j<n){
            while(j<n && (position[j]-position[i])<mid) j++;
            if(j==n) break;
            m--;
            if(m==1) return true;
            i=j;
            j=i+1;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int lo=1;
        int hi=position[n-1]-position[0];
        int ans=1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(mid,m,position)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};
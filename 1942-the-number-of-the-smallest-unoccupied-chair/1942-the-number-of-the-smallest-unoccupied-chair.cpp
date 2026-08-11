class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++) v.push_back({times[i][0],times[i][1],i});
        sort(v.begin(),v.end());
        vector<int> occ(n,0);
        for(int i=0;i<n;i++){
            int j=0;
            while(occ[j]>v[i][0]) j++;
            occ[j]=v[i][1];
            if(v[i][2]==targetFriend) return j;
        }
        return 0;
    }
};
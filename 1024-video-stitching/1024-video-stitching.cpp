class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n=clips.size();
        sort(clips.begin(),clips.end());
        int i=0;
        int strt=0;
        int end=0;
        int ans=0;
        while(strt<time){
            while(i<n && clips[i][0]<=strt){
                end=max(end,clips[i][1]);
                i++;
            }
            if(strt==end) return -1;
            strt=end;
            ans++;
        }
        return ans;
    }
};
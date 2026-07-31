class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        unordered_map<char,int> mpp;
        vector<pair<int,char>> v;
        for(int i=0;i<n;i++) mpp[word[i]]++;
        for(auto it:mpp){
            char c=it.first;
            int val=it.second;
            v.push_back({val,c});
        }
        int val;
        int ans=0;
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();i++){
            if(i<8) val=1;
            else if(i>=8 && i<16) val=2;
            else if(i>=16 && i<24) val=3;
            else val=4;
            int freq=v[i].first;
            ans+=(val*freq);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();
        vector<int> cnt(k,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> busy;
        set<int> available;
        for(int i=0;i<k;i++) available.insert(i);
        for(int i=0;i<n;i++){
            int time=arrival[i]+load[i];
            while(!busy.empty() && busy.top().first<=arrival[i]){
                int ind=busy.top().second;
                busy.pop();
                available.insert(ind);
            }
            if(available.empty()) continue;
            auto it=available.lower_bound(i%k);
            if(it==available.end()) it=available.begin();
            int server=*it;
            available.erase(it);
            cnt[server]++;
            busy.push({time,server});
        }
        int ans=0;
        vector<int> ind;
        for(auto it:cnt) ans=max(ans,it);
        for(int i=0;i<k;i++){
            if(ans==cnt[i]) ind.push_back(i);
        }
        return ind;
    }
};
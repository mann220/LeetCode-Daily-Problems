class Solution {
public:
    #define ll long long
    // i cant think of the two min heap use we have to store two things available and busy
    vector<int> assignTasks(vector<int>& servers, vector<int>& task) {
        int n=task.size();
        int m=servers.size();
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> available;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> busy;
        for(int i=0;i<m;i++) available.push({servers[i],i});
        vector<int> ans(n);
        ll time=0;
        for(int i=0;i<n;i++){
            time=max(time,(long long)i);
            while(!busy.empty() && busy.top().first<=time){
                int ind=busy.top().second;
                busy.pop();
                available.push({servers[ind],ind});
            }
            if(available.empty()){
                time=busy.top().first;
                while(!busy.empty() && busy.top().first<=time){
                    int ind=busy.top().second;
                    busy.pop();
                    available.push({servers[ind],ind});
                }
            }
            int ind=available.top().second;
            ans[i]=ind;
            busy.push({time+task[i],available.top().second});
            available.pop();
        }
        return ans;
    }
};
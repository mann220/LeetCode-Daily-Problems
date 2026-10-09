class Solution {
public:
    // according to my observation it is min heap question as i have done this kind of many questions-- i am right

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) v[i]={capital[i],profits[i]};
        sort(v.begin(),v.end());
        priority_queue<int> pq;
        int i=0;
        while(i<n && k>0){
            if(v[i].first<=w){
                pq.push(v[i].second);
                i++;
                continue;
            }
            if(pq.empty()) break;
            w+=pq.top();
            pq.pop();
            k--;
        }
        while(!pq.empty() && k>0){
            w+=pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};
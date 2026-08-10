class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        int n=b.size();
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[b[i]]++;
        priority_queue<pair<int,int>> pq;
        for(auto [el,f]:mpp) pq.push({f,el});
        while(!pq.empty()){
            auto [f,el]=pq.top();
            pq.pop();
            if(!ans.empty() && ans.back()==el){
                auto [f1,el1]=pq.top();
                pq.pop();
                ans.push_back(el1);
                f1--;
                if(f1>0) pq.push({f1,el1});
                pq.push({f,el});
            }
            else{
                ans.push_back(el);
                f--;
                if(f>0) pq.push({f,el});
            }
        }
        return ans;
    }
};
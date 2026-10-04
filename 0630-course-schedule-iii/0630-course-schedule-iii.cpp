class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        sort(courses.begin(),courses.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        int sum=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            sum+=courses[i][0];
            pq.push(courses[i][0]);
            if(sum>courses[i][1]){
                sum-=pq.top();
                pq.pop();
            }
        }   
        return pq.size();
    }
};
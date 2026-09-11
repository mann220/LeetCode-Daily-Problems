class Solution {
public:
    // very very important
    int areaOfHistogram(vector<int>& arr){
        int n=arr.size();
        int maxi=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int el=arr[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()? -1:st.top();
                maxi=max(maxi,el*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int el=arr[st.top()];
            st.pop();
            int nse=n;
            int pse=st.empty()? -1:st.top();
            maxi=max(maxi,el*(nse-pse-1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> height(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]=height[j]+1;
                }
                else height[j]=0;
            }
            ans=max(ans,areaOfHistogram(height));
        }
        return ans;
    }
};
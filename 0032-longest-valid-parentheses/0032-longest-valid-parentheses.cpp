class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<pair<char,int>> st;
        st.push({'a',-1});
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top().first=='(' && s[i]==')') st.pop();
            else st.push({s[i],i});
        }
        int ans=0;
        if(st.empty()) ans=n;
        int lst=n;
        while(!st.empty()){
            int strt=st.top().second;
            st.pop();
            ans=max(ans,lst-strt-1);
            lst=strt;
        }
        return ans;
    }
};
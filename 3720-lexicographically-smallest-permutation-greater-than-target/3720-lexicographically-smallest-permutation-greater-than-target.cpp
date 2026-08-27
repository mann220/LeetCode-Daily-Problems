class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        string ans="";
        string p=s;
        sort(p.rbegin(),p.rend());
        if(p<=target) return "";
        multiset<char> st;
        for(int i=0;i<s.size();i++) st.insert(s[i]);
        for(int i=0;i<s.size();i++){
            auto it=(st.lower_bound(target[i]));
            if(it==st.end()) break;
            if(it!=st.end() && *it>target[i]){
                ans+=*it;
                st.erase(it);
                while(!st.empty()){
                    auto c=st.begin();
                    ans+=*c;
                    st.erase(c);
                }
                return ans;
            }
            ans+=*it;
            st.erase(it);
        }
        for(int i=ans.size()-1;i>=0;i--){
            st.insert(ans[i]);
            ans.pop_back();
            auto it=st.upper_bound(target[i]);
            if(it!=st.end() && *it>target[i]){
                ans+=*it;
                st.erase(it);
                while(!st.empty()){
                    auto c=st.begin();
                    ans+=*c;
                    st.erase(c);
                }
                return ans;
            }
        }
        return "";
    }
};
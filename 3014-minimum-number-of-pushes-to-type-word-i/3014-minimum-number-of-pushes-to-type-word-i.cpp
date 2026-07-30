class Solution {
public:
    int minimumPushes(string s) {
        int n=s.size();
        int cnt=0;
        unordered_set<char> st;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
            if(st.size()<=8) cnt++;
            else if(st.size()>8 && st.size()<=16) cnt+=2;
            else if(st.size()>16 && st.size()<=24) cnt+=3;
            else cnt+=4;
        }
        return cnt;
    }
};
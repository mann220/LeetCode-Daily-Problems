class Solution {
public:
    string f(int len,string &s){
        int n=s.size();
        int i=0;
        int j=len;
        unordered_map<string_view,int> mpp;
        string_view p(s.data(),len);
        while(j<=n){
            mpp[p]++;
            if(mpp[p]>=2) return string(p);
            p=string_view(s.data()+i+1,len);
            i++;
            j++;
        }
        return "";
    }
    string longestDupSubstring(string s) {
        int n=s.size();
        int lo=1;
        int hi=s.size();
        string ans;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            string temp=f(mid,s);
            if(temp.size()!=0){
                ans=temp;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};
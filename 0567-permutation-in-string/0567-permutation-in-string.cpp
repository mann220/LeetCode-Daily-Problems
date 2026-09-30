class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(m<n) return false;
        vector<int> hash1(26,0),hash2(26,0);
        for(int i=0;i<n;i++){
            hash1[s1[i]-'a']++;
            hash2[s2[i]-'a']++;
        }
        int i=0;
        int j=n;
        if(hash1==hash2) return true;
        while(j<m){
            hash2[s2[i]-'a']--;
            hash2[s2[j]-'a']++;
            if(hash1==hash2) return true;
            i++;
            j++;
        }
        return false;
    }
};
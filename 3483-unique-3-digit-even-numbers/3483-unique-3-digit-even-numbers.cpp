class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        for(int i=0;i<digits.size();i++) freq[digits[i]]++;
        int ans=0;
        for(int i=1;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int k=0;k<=9;k+=2){
                    freq[i]--;
                    freq[k]--;
                    freq[j]--;
                    if(freq[i]>=0 && freq[j]>=0 && freq[k]>=0) ans++;
                    freq[i]++;
                    freq[k]++;
                    freq[j]++;
                }
            }
        }
        return ans;
    }
};
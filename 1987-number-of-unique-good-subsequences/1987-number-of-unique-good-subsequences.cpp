class Solution {
public:
    int mod=1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        int ends0=0;
        int ends1=0;
        int isZero=0;
        for(char c:binary){
            if(c=='1'){
                ends1=(ends0+ends1+1)%mod;
            }
            else{
                isZero=1;
                ends0=(ends0+ends1)%mod;
            }
        }
        return (ends0+ends1+isZero)%mod;
    }
};
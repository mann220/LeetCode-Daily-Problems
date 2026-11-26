class Solution {
public:
    bool canAliceWin(int n) {
        int val=10;
        bool flg=true;
        for(int i=0;i<50;i++){
            if(n-val<0) return !flg;
            flg=!flg;
            n=n-val;
            val--;
        }
        return false;
    }
};
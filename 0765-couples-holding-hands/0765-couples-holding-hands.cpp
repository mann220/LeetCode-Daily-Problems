class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        int cnt=0;
        for(int i=0;i<n;i+=2){
            if(row[i]%2==0){
                if(row[i+1]==row[i]+1) continue;
                for(int j=i+1;j<n;j++){
                    if((row[i]+1)==row[j]){
                        cnt++;
                        swap(row[i+1],row[j]);
                        break;
                    }
                }
            }
            else{
                if(row[i+1]==(row[i]-1)) continue;
                for(int j=i+1;j<n;j++){
                    if(row[i]-1==row[j]){
                        cnt++;
                        swap(row[i+1],row[j]);
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};
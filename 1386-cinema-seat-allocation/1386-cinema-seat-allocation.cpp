class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int sz=rs.size();
        sort(rs.begin(),rs.end());
        int tot=2*n;
        int i=0;
        while(i<sz){
            int row=rs[i][0];
            int j=i;
            vector<bool> temp(3,true);
            while(j<sz && rs[j][0]==row){
                if(rs[j][1]>=2 && rs[j][1]<=5) temp[0]=false;
                if(rs[j][1]>=4 && rs[j][1]<=7) temp[1]=false;
                if(rs[j][1]>=6 && rs[j][1]<=9) temp[2]=false;
                j++;
            }
            if(temp[0]==false && temp[1]==false && temp[2]==false) tot-=2;
            else if(temp[0]==false && temp[2]==false) tot-=1;
            else if(temp[0]==false) tot-=1;
            else if(temp[2]==false) tot-=1;
            i=j;
        }
        return tot;
    }   
};
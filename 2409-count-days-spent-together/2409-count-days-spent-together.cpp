class Solution {
public:
    int f(string s,vector<int> &pre){
        int month=stoi(s.substr(0,2));
        int day=stoi(s.substr(3,5));
        return day+pre[month-1];
    }
    vector<int> arr={31,28,31,30,31,30,31,31,30,31,30,31};
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> pre(13,0);
        for(int i=1;i<13;i++) pre[i]=pre[i-1]+arr[i-1];
        int aa=f(arriveAlice,pre);
        int la=f(leaveAlice,pre);
        int ab=f(arriveBob,pre);
        int lb=f(leaveBob,pre);
        vector<int> yr(366,0);
        for(int i=aa;i<=la;i++) yr[i]+=1;
        for(int i=ab;i<=lb;i++) yr[i]+=1;
        int cnt=0;
        for(int i=1;i<=365;i++){
            if(yr[i]==2) cnt++;
        }
        return cnt;
    }
};
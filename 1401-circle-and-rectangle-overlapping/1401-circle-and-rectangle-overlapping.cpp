class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xi,yi;
        // if(xCenter<x1) xi=x1;
        // else if(xCenter>x2) xi=x2;
        // else xi=xCenter;
        // if(yCenter<y1) yi=y1;
        // else if(yCenter>y2) yi=y2;
        // else yi=yCenter;
        // for this above condition c++ 17 provides a feature called clamp 
        // clamp(value,lo,hi); => if value is less than lo it returns lo, if value is greater 
        // than hi then it return hi else returns value
        xi=clamp(xCenter,x1,x2);
        yi=clamp(yCenter,y1,y2);
        return ((xi-xCenter)*(xi-xCenter))+((yi-yCenter)*(yi-yCenter))<=(radius*radius);
    }
};
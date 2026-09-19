class Solution {
public:
    bool checkOverlap(int r, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        int xClosest, yClosest;

        if(x1 > xCenter){
            xClosest = x1;
        }else if(xCenter > x2){
            xClosest = x2;
        }else{
            xClosest = xCenter;
        }

        if(y1 > yCenter){
            yClosest = y1;
        }else if(yCenter > y2){
            yClosest = y2;
        }else{
            yClosest = yCenter;
        }

        long long d = (xCenter -  xClosest)*(xCenter - xClosest) + (yCenter - yClosest)*(yCenter - yClosest);

        return d > r*r ? false : true;
    }
};
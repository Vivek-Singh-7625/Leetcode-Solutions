class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int r = radius;
        int a = (x1 - xCenter) , b = (x2 - xCenter) , c = (y1 - yCenter) , d = (y2 - yCenter);
        int e = (r + xCenter) , f = (-r + xCenter) , g = (r + yCenter) , h = (-r + yCenter);
        if(yCenter >= y1 and yCenter <= y2){
            if(e >= x1 and e <= x2)   return true;
            if(f >= x1 and f <= x2)   return true;
        }
        if(xCenter >= x1 and xCenter <= x2){
            if(g >= y1 and g <= y2)   return true;
            if(h >= y1 and h <= y2)   return true;
        }
        if(xCenter <= x1 && e >= x2 && yCenter >= y1 && yCenter <= y2)  return true;
        if(xCenter >= x2 && f <= x1 && yCenter >= y1 && yCenter <= y2)  return true;
        if(yCenter <= y1 && g >= y2 && xCenter >= x1 && xCenter <= x2)  return true;
        if(yCenter >= y2 && h <= y1 && xCenter >= x1 && xCenter <= x2)  return true;
        if(a*a + c*c - r*r <= 0 || a*a + d*d - r*r <= 0 || b*b + c*c - r*r <= 0 || b*b + d*d - r*r <= 0)    return true;
        return false;
    }
};
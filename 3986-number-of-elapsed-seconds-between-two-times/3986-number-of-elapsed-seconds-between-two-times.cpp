class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int  h = (endTime[0]-startTime[0])*10 + (endTime[1]-startTime[1]);
        int  m = (endTime[3]-startTime[3])*10 + (endTime[4]-startTime[4]);
        int  s = (endTime[6]-startTime[6])*10 + (endTime[7]-startTime[7]);
        return s + m*60 + h*3600;
    }
};
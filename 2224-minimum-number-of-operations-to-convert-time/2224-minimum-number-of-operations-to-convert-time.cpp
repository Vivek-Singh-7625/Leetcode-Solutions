class Solution {
public:
    int convertTime(string current, string correct) {
        int curr = stoi(current.substr(0,2))*60 + stoi(current.substr(3,2));
        int corr = stoi(correct.substr(0,2))*60 + stoi(correct.substr(3,2));
        int ops = 0;
        while(corr != curr){
            if(curr < corr){
                if(curr + 60 <= corr)   curr += 60;
                else if(curr + 15 <= corr)  curr += 15;
                else if(curr + 5 <= corr)   curr += 5;
                else    curr++;
            }
            else    curr = (curr + 60)%1440;
            ops++;
        }
        return ops;
    }
};
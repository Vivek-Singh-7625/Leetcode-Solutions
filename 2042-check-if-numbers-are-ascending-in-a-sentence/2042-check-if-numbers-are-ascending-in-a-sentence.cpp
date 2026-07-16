class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string temp;
        int prev = INT_MIN , num;
        while(ss >> temp){
            if(temp[0] >= '0' and temp[0] <= '9'){
                num = stoi(temp);
                if(prev >= num)  return false;
                prev = num;
            }
        }
        return true;
    }
};
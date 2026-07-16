class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string temp;
        long long x , num = 0;
        int n1 = to_string(low).length() , n2 = to_string(high).length() , t ;
        for(int i = n1 ; i <= n2 ; i++){
            x = pow(10,i);
            num = 0;
            for(int j = 1 ; j <= 9 ; j++){
                num = (num*10 + j) % x;
                t = num;
                if(t >= low and t <= high)  ans.push_back(t);
            }
            low = x;
        }
        return ans;
    }
};
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum < 1 || sum > 9*num) return "";
        string ans; 
        ans.reserve(num);
        int n = sum / 9, r = sum % 9;
        ans.append(n, '9'); num -= n;
        if (r){
            ans += '0' + r; 
            num--;
        }
        ans.append(num, '0');
        return ans;
    }
};
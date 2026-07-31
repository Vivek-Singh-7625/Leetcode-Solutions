class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int n = num1.length() , m = num2.length() , carry = 0;
        int l = max(m,n) , x;
        for(int i = 0 ; i < l ; i++){
            x = (n > 0 ?  num1[--n]-'0' : 0) + (m > 0 ? num2[--m] - '0' : 0) + carry;
            carry = x/10;
            ans += ('0'+x%10);
        }
        if (carry == 1) ans += '1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
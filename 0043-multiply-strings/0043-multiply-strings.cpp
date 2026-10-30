
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int m = num1.length(), n = num2.length();
        vector<int> a(m + n, 0);
        for(int i = m - 1; i >= 0; i--) {
            int num = num1[i] - '0';
            for(int j = n - 1; j >= 0; j--) {
                int idx = m + n - i - j - 2;
                a[idx] += num * (num2[j] - '0');
            }
        }
        int carry = 0;
        for(int i = 0; i < m + n; i++) {
            int num = a[i] + carry;
            a[i] = num % 10;
            carry = num / 10;
        }

        string ans;

        for(int i = m + n - 1; i >= 0; i--) {
            if(ans.empty() && a[i] == 0) continue;
            ans += char('0' + a[i]);
        }
        return ans;
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        int m = num1.length() , n = num2.length();
        int carry = 0 , num = 0 , idx;
        char x = '0';
        if(num1 == "0" or num2 == "0")  return "0";
        vector<int> a(m + n + 1);
        for(int i = m-1 ; i >= 0 ; i--){
            num = num1[i] - '0';
            for(int j = n-1 ; j >= 0 ; j--){
                idx = m+n-i-j-2;
                a[idx] += (num*(num2[j]-'0')) ;
            }
        }
        for(int i = m + n ; i >= 0 ; i--){
            if(a[i] == 0)   idx = i;
            else    break;
        }
        idx = min(idx + 1, m + n + 1);
        for(int i = 0 ; i < idx ; i++){
            num = a[i] + carry;
            a[i] = num%10;
            carry = num/10;
            ans += (x + a[i]);
        }
        while(ans.size() and ans[idx-1] == '0')  ans.pop_back() , cout << ans << endl;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
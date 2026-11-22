class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();
        vector<string> ans(n);
        int a = 0, b = 0;
        bool alice , bob;
        for (int i = 0; i < n; i++) {
            bob = rain[i] == 1;
            alice = (i < n - 1) && rain[i] == 1 && rain[i + 1] == 1;
            if (alice && bob) {
                if (a <= b) {
                    ans[i] = "Alice";
                    a++;
                } 
                else {
                    ans[i] = "Bob";
                    b++;
                }
            } 
            else if (bob) {
                ans[i] = "Bob";
                b++;
            } 
            else if (alice) {
                ans[i] = "Alice";
                a++;
            } 
            else {
                ans[i] = "None";
            }
        }
        return ans;
    }
};
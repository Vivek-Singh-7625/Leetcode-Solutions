class Solution {
public:
    string numberToWords(int num) {
        if(num == 0)    return "Zero";
        vector<string> ones = {"", "One", "Two", "Three", "Four","Five", "Six", "Seven", "Eight", "Nine","Ten", "Eleven", "Twelve", "Thirteen", "Fourteen","Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty","Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> hundreds = { "", "Hundred"};
        vector<string> scales = {"", "Thousand", "Million", "Billion"};

        string ans = "";
        vector<int> nums;
        while(num){
            nums.push_back(num%10);
            num = num/10;
        }
        int n = nums.size() , t = 0 ;
        for(int i = n - 1; i >= 0; i--) {
            if(i % 3 == 2) {
                if(nums[i] != 0) {
                    ans += ones[nums[i]] + " " + hundreds[1] + " ";
                }
            }
            else if(i % 3 == 1) {
                if(nums[i] == 1) {
                    ans += ones[10 + nums[i - 1]] + " ";
                    if(i / 3 > 0) {
                        ans += scales[i / 3] + " ";
                    }
                    i--;
                }
                else if(nums[i] != 0) {
                    ans += tens[nums[i]] + " ";
                }
            }
            else {
                if(nums[i] != 0) {
                    ans += ones[nums[i]] + " ";
                }
                bool groupNonZero = false;
                for(int j = i; j <= min(n - 1, i + 2); j++) {
                    if(nums[j] != 0) {
                        groupNonZero = true;
                        break;
                    }
                }
                if(groupNonZero && i / 3 > 0) {
                    ans += scales[i / 3] + " ";
                }
            }
        }
        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};
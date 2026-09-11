class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size() , ans = 0 , x , y , z;
        vector<int> a(10);
        for(int i = 0 ; i < n ; i++)    a[digits[i]]++;
        for(int i = 100 ; i < 1000 ; i += 2){
            x = i%10;
            y = (i/10)%10;
            z = (i)/100;
            a[x]-- , a[y]-- , a[z]--;
            if(a[x] >= 0 and a[y] >= 0 and a[z] >= 0)   ans++;
            a[x]++ , a[y]++ , a[z]++;
        }
        return ans;
    }
};
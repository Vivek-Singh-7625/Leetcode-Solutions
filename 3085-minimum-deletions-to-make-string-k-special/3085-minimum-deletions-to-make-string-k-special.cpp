class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);

        for(char c : word)  freq[c - 'a']++;

        vector<int> arr;
        for(int x : freq){
            if(x) arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        int ans = word.size();

        for(int i : arr) {
            int del = 0;
            for(int x : arr) {
                if(x < i)   del += x;
                else if(x > i + k)  del += x - i - k;
                if(del >= ans)  break;
            }
            ans = min(ans, del);
        }
        return ans;
    }
};
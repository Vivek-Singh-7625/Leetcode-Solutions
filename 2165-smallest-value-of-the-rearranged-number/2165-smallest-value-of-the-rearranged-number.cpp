class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(num) , ans;
        vector<int> freq(10,0);
        int idx , n = s.length();
        for(int i = 0 ; i < n ; i++){
            idx = s[i] - '0';
            if(idx >= 0 and idx < 10)   freq[idx]++;
        }

        if(s[0] == '-'){
            for(int i = 9 ; i >= 0 ; i--){
                ans.append(freq[i], '0' + i);
            }
            ans.insert(ans.begin(), '-');
        }
        else{
            if(freq[0]){
                for(int i = 1 ; i < 10 ; i++){
                    if(freq[i]){
                        ans.push_back('0' + i);
                        freq[i]--;
                        break;
                    }
                }
            }
            for(int i = 0 ; i < 10 ; i++){
                ans.append(freq[i], '0' + i);
            }
        }
        return stoll(ans);
    }
};
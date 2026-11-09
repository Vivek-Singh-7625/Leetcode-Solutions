class Solution {
public:
    int maxProduct(vector<string>& words) {
        bool valid = true;
        int n = words.size() , ans = 0 , t;
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                valid = true;
                t = words[i].size() * words[j].size();
                if(t <= ans) continue;
                for(char a : words[i]){
                    for(char b : words[j]){
                        if((a^b) == 0)    valid = false;
                    }
                    if(!valid)  break;
                }
                if(valid)   ans = t;
            }
        }
        return ans;
    }
};
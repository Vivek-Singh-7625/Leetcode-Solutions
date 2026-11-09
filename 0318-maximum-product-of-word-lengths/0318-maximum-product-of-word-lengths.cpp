class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size() , ans = 0 , t;
        vector<int> a(n);
        for(int i = 0 ; i < n ; i++){
            for(char c : words[i])   a[i] = a[i] | ( 1 << (c-'a') );
            for(int j = 0 ; j < i ; j++){
                t = words[i].size()*words[j].size();
                if(!(a[i]&a[j]))    ans = max(ans,t);
            }
        }
        return ans;
    }
};
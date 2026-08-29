class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> mpp;
        string x ;
        char y;
        int len = paragraph.length();
        for(int i = 0 ; i < len ; i++){ 
            y = tolower(paragraph[i]);
            if(y >= 'a' and y <= 'z'){
                x += y;
            }
            else{
                if(x.length() > 0)    mpp[x]++;
                x = "";
            }
        }
        if(x.length() > 0)    mpp[x]++;
        int ans = 0 , n = banned.size() ;
        bool consider = false;
        for(auto& [key,value] : mpp){
            consider = true;
            for(int i = 0 ; i < n ; i++){
                if(banned[i] == key){
                    consider = false;
                    break;
                }
            }
            if(consider){
                if(ans < value){
                    ans = value;
                    x = key;
                }
            }
        }
        return x;
    }
};
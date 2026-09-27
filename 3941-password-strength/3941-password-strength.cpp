class Solution {
public:
    int passwordStrength(string password) {
        vector<bool> mpp(66,false);
        int n = password.length() , ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(password[i] >= 'a' and password[i] <= 'z' and !mpp[password[i]-'a']) ans++ , mpp[password[i]-'a'] = true;
            else if(password[i] >= 'A' and password[i] <= 'Z' and !mpp[password[i]-'A'+26]) ans += 2 , mpp[password[i]-'A'+26] = true;
            else if(password[i] >= '0' and password[i] <= '9' and !mpp[password[i]-'0'+52]) ans += 3 , mpp[password[i]-'0'+52] = true;
            else{
                if(password[i] == '!' and !mpp[62])  ans += 5 , mpp[62] = true;
                else if(password[i] == '@' and !mpp[63])  ans += 5 , mpp[63] = true;
                else if(password[i] == '#' and !mpp[64])  ans += 5 , mpp[64] = true;
                else if(password[i] == '$' and !mpp[65])  ans += 5 , mpp[65] = true;
            }
        }
        return ans;
    }
};
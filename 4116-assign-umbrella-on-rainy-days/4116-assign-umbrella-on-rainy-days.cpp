class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        vector<string> ans;
        int a = 0 , b = 0 , n = rain.size();
        for(int i = 0 ; i < n ; i++){
            if(i < n-1){
                if(rain[i] == 0) ans.push_back("None");
                else if(rain[i] == rain[i+1]){
                    if(a > b){
                        ans.push_back("Bob");
                        b++;
                    }
                    else{
                        ans.push_back("Alice");
                        a++;
                    }
                }
                else if(rain[i] == 1){
                    ans.push_back("Bob");
                    b++;
                }
            }
            else{
                if(rain[i] == 0) ans.push_back("None");
                else    ans.push_back("Bob");
            }
        }
        return ans;
    }
};
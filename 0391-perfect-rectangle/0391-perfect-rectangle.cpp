class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int m = rectangles.size() ;
        long long ans = 0 ;
        vector<int> id(4,INT_MAX);
        id[2] = INT_MIN;
        id[3] = INT_MIN;
        set<string> s;
        string a , b , c , d;
        if(m == 1)  return true;
        for(int i = 0 ; i < m ; i++){    
            ans += abs(1LL*(rectangles[i][0]-rectangles[i][2])*(rectangles[i][1]-rectangles[i][3]));
            id[0] = min(id[0],rectangles[i][0]);
            id[1] = min(id[1],rectangles[i][1]);
            id[2] = max(id[2],rectangles[i][2]);
            id[3] = max(id[3],rectangles[i][3]);

            a = to_string(rectangles[i][0]) + " " + to_string(rectangles[i][1]);
            b = to_string(rectangles[i][2]) + " " + to_string(rectangles[i][3]);
            c = to_string(rectangles[i][0]) + " " + to_string(rectangles[i][3]);
            d = to_string(rectangles[i][2]) + " " + to_string(rectangles[i][1]);

            if(s.erase(a) == 0) s.insert(a);
            if(s.erase(b) == 0) s.insert(b);
            if(s.erase(c) == 0) s.insert(c);
            if(s.erase(d) == 0) s.insert(d);
        }
        a = to_string(id[0]) + " " + to_string(id[1]);
        b = to_string(id[2]) + " " + to_string(id[3]);
        c = to_string(id[0]) + " " + to_string(id[3]);
        d = to_string(id[2]) + " " + to_string(id[1]);
        if(s.size() != 4)   return false;
        for(auto& v : s){
            if(v == a || v == b || v == c || v == d)   continue;
            return false;
        }
        return ans == abs((id[0]-id[2])*(id[1]-id[3]));
    }
};
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        long long target = 0 , mx = 0;
        for(int x : matchsticks){    
            target += x;
            mx = max(mx,1ll*x);
        }
        if(target%4 or mx > target/4)    return false;
        sort(matchsticks.begin(), matchsticks.end(),greater<int>());
        return solver(matchsticks,0,0,0,0,0,target/4);
    }
    bool solver(vector<int>& m , long long a , long long b , long long c , long long d , int idx , long long target){
        if(idx == m.size()) return ((a == b) && (b == c) && (c == d));
        if(a > target or b > target or c > target or d > target)    return false;
        return solver(m , a + m[idx], b , c , d , idx + 1 , target) || solver(m , a , b + m[idx], c , d , idx + 1 , target) || solver(m , a , b , c + m[idx], d , idx + 1 , target) || solver(m , a , b , c , d + m[idx] , idx + 1 , target);
    }
};
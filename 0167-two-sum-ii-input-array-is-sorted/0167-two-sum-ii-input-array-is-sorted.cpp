class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int x = 0 , n = numbers.size();
        int y = n-1;
        for(int i = 0 ; i < n ; i++){
            if(numbers[x] + numbers[y] == target)   return {x+1,y+1};
            else if(numbers[x] + numbers[y] < target)   x++;
            else    y--;
        }
        return {0,0};
    }
};
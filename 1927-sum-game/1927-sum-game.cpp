class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftSum = 0, rightSum = 0;
        int leftAlice = 0, leftBob = 0;
        int rightAlice = 0, rightBob = 0;
        bool aliceTurn = true;

        for (int i = 0; i < n; i++) {
            if (num[i] >= '0' && num[i] <= '9') {
                if (i < n / 2)  leftSum += num[i] - '0';
                else    rightSum += num[i] - '0';
            }
            else {
                if (i < n / 2) {
                    if (aliceTurn)  leftAlice++;
                    else    leftBob++;
                }
                else {
                    if (aliceTurn)  rightAlice++;
                    else    rightBob++;
                }
                aliceTurn = !aliceTurn;
            }
        }
        return (leftSum + leftAlice * 9 != rightSum + rightBob * 9) ||
               (leftSum + leftBob * 9 != rightSum + rightAlice * 9);
    }
};
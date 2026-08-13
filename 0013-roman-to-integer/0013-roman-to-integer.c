int value(char c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
    return 0;
}

int romanToInt(char *s) {
    int ans = 0, i = 0;
    while (s[i]) {
        int curr = value(s[i]);
        int next = value(s[i + 1]);
        if (curr < next) {
            ans += (next - curr);
            i += 2;
        } else {
            ans += curr;
            i++;
        }
    }
    return ans;
}
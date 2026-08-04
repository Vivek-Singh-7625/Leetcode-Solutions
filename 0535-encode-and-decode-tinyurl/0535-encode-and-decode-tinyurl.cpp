class Solution {
public:
    // Encodes a URL to a shortened URL.
    int n = 0;
    unordered_map<string,string> mpp;
    string encode(string longUrl) {
        string ans = "http://tinyurl.com/" + to_string(n);
        n++;
        mpp[ans] = longUrl;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
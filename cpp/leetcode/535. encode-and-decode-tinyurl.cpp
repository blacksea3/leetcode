#include "public.h"

//12ms, 40.25%
//直接unordered_map存, 键为计数器, 值为url

class Solution {
private:
	int count = 0;
	unordered_map<int, string> um;

public:
	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		string returnUrl = "http://tinyurl.com/" + to_string(count);
		um[count++] = longUrl;
		return returnUrl;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		string sCount = shortUrl.substr(19);
		int rawCount = atoi(sCount.c_str());
		return um[rawCount];
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

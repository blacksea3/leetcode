#include "public.h"

//8ms, 21.26%
//Ä£Äâ

class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		//È¥µôÄ©Î²i
		a.pop_back();
		b.pop_back();

		int realA, realB, imagA, imagB;

		int indexAdda = a.find("+");
		realA = atoi(a.substr(0, indexAdda).c_str());
		imagA = atoi(a.substr(indexAdda + 1).c_str());

		int indexAddb = b.find("+");
		realB = atoi(b.substr(0, indexAddb).c_str());
		imagB = atoi(b.substr(indexAddb + 1).c_str());

		int realRes = realA * realB - imagA * imagB;
		int imagRes = realA * imagB + imagA * realB;

		return to_string(realRes) + "+" + to_string(imagRes) + "i";
	}
};

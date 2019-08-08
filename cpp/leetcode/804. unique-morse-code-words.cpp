#include "public.h"

//8ms, 75.89%
//Ä£Äâ

class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		unordered_set<string> us;
		vector<string> convert = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

		for (auto& word : words)
		{
			string temp = "";
			for (auto& iiw : word)
			{
				temp += convert[iiw - 'a'];
			}
			us.insert(temp);
		}
		return us.size();
	}
};

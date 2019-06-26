#include "public.h"

//12ms, 79.46%
//easy problem, but the code may be complicated!
//从低位到高位
//连续两次遍历

class Solution {
public:
	string numberToWords(int num) {
		vector<string> tens = { "dump", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };
		vector<string> ones = { "dump", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine " };
		vector<string> sp11_19 = {"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", 
			"Seventeen ", "Eighteen ", "Nineteen "};
		if (num == 0) return "Zero";

		string res = "";
		int loc = 0;

		vector<int> nums = {};  //
		bool isthousand = false;
		bool ismillion = false;
		bool isfirst_11_19 = false;
		bool issecond_11_19 = false;
		bool isthird_11_19 = false;
		while (num > 0)
		{
			int temp = num % 10;
			nums.push_back(temp);
			loc++;
			if ((loc == 2) && (temp == 1)) isfirst_11_19 = true;
			else if ((loc == 5) && (temp == 1)) issecond_11_19 = true;
			else if ((loc == 8) && (temp == 1)) isthird_11_19 = true;
			if ((loc >= 4) && (loc <= 6) && (temp > 0)) isthousand = true;
			else if ((loc >= 7) && (loc <= 9) && (temp > 0)) ismillion = true;
			num /= 10;
		}

		loc = 1;
		for (auto& n:nums)
		{
			switch (loc++)
			{
			case 1:
			{
				if ((n > 0) && (!isfirst_11_19)) res = ones[n] + res;
				break;
			}
			case 2:
			{
				if (n > 1) res = tens[n] + res;
				else if (isfirst_11_19) res = sp11_19[nums[loc - 3]] + res;
				break;
			}
			case 3:
			{
				if (n > 0) res = ones[n] + "Hundred " + res;
				break;
			}
			case 4:
			{
				if ((n > 0) && (!issecond_11_19)) res = ones[n] + "Thousand " + res;
				else if (isthousand) res = "Thousand " + res;
				break;
			}
			case 5:
			{
				if (n > 1) res = tens[n] + res;
				else if (issecond_11_19) res = sp11_19[nums[loc - 3]] + res;
				break;
			}
			case 6:
			{
				if (n > 0) res = ones[n] + "Hundred " + res;
				break;
			}
			case 7:
			{
				if ((n > 0) && (!isthird_11_19)) res = ones[n] + "Million " + res;
				else if (ismillion) res = "Million " + res;
				break;
			}
			case 8:
			{
				if (n > 1) res = tens[n] + res;
				else if (isthird_11_19) res = sp11_19[nums[loc - 3]] + res;
				break;
			}
			case 9:
			{
				if (n > 0) res = ones[n] + "Hundred " + res;
				break;
			}
			case 10:
			{
				if (n > 0) res = ones[n] + "Billion " + res;
				break;
			}
			default:
			{
				break;
			}
			}
		}
		res.pop_back();
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	//string res = s->numberToWords(12345);
	string res = s->numberToWords(1000000);
	return 0;
}

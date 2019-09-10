#include "public.h"

//��ch�ָ�raw, ���һ��string�б�
vector<string> mStringSplit(string raw, char ch)
{
	int loc = 0;
	string s = "";
	vector<string> res;

	while (loc < raw.size())
	{
		if (raw[loc] == ch)
		{
			res.emplace_back(s);
			s = "";
		}
		else
		{
			s.push_back(raw[loc]);
		}
		loc++;
	}
	res.emplace_back(s);
	return res;
}

//ʵ��һ��������
class Fraction {
private:
	int mother;
	int son;
public:
	//�ⲿע����ӿ����ɸ���0, ��ĸ����������
	Fraction(int inputSon = 0, int inputMother = 1)
	{
		mother = inputMother;
		son = inputSon;
	}

	//�ⲿע����ӵ�ʱ������һ������Ϊ0
	//֧�ַ����Ǹ���
	void add(Fraction& inputF)
	{
		int newMother = inputF.mother * this->mother;
		int newSon = inputF.son * this->mother + inputF.mother * this->son;
		int publicMulFactor = gcd(abs(newMother), abs(newSon));
		this->mother = newMother / publicMulFactor;
		this->son = newSon / publicMulFactor;
	}

	int getSon()
	{
		return this->son;
	}

	int getMother()
	{
		return this->mother;
	}
};

//�Զ���շת���
//�ر�ע��gcd������Ǹ��⺯��??
int gcd(int x, int y)
{
	if (!y)
		return x;
	else
		return gcd(y, x%y);
}

//��ȡ����<n������vector, ����true, ����false
vector<int> primes(const size_t n) {
	vector<bool> prime(n, true);
	prime[0] = false;
	prime[1] = false;
	for (size_t i = 2; i < n; ++i)
		prime[i] = true;
	for (size_t i = 2; i < n; ++i) {
		if (prime[i])
			for (size_t j = i * i; j < n; j += i)
				prime[j] = false;
	}
	vector<int> res;
	for (size_t i = 2; i < n; ++i) {
		if (prime[i])
			res.push_back(i);
	}
	return res;
}

//����������, ����Ƿ�������, �Ǿ�true
bool isPrime(int n)
{
	if (n == 1) return false;
	else if (n == 2) return true;
	else
	{
		if (n % 2 == 0) return false;

		for (int val = 3; val <= (int)sqrt(n); val += 2)
		{
			if (n%val == 0) return false;
		}
		return true;
	}
}

//��a���������ֽ�
unordered_set<int> getprimes(int a)
{
	unordered_set<int> res;
	int d = 2;
	int x = a;
	while (d * d <= x) {
		if (x % d == 0) {
			while (x % d == 0)
				x /= d;
			res.insert(d);
		}
		d++;
	}
	if (x > 1 || res.empty())
		res.insert(x);
	return res;
}

//���鼯ģ��, ��int��ΪԪ��
class Solution {
private:
	unordered_map<int, int> um;

	void init(vector<int>& vals)
	{
		for (auto& s : vals)
		{
			um[s] = s;
		}
	}

	int GetFather(int x) {
		return (um[x] == x ? x : um[x] = GetFather(um[x]));
	}

	void Merge(int x, int y) {
		int a = GetFather(x);
		int b = GetFather(y);
		if (a != b)
		{
			um[b] = a;
		}
	}
};

//����:s�Ƿ�Ϊt��������
bool isSubsequence(string s, string t) {
	int sloc = 0;
	int tloc = 0;

	while (sloc < s.size() && tloc < t.size())
	{
		if (t[tloc] == s[sloc])
		{
			tloc++;
			sloc++;
		}
		else tloc++;
	}
	if (sloc == s.size()) return true;
	else return false;
}


#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_31_40
void Solution::nextPermutation(vector<int>& nums)
{
	//...... 4   76554321

	bool is_all_reverse_sort = true;
	int keyloc = -1;
	int nsize = nums.size();
	if (nsize <= 1) return;
	else
	{
		int old_num = nums[nsize - 1];
		for (int i = nsize - 2; i >= 0; i--)
		{
			if (nums[i] < old_num)
			{
				is_all_reverse_sort = false;
				keyloc = i;
				break;
			}
			old_num = nums[i];
		}

		if (is_all_reverse_sort)  //ȫ����
			sort(nums.begin(), nums.end());
		else
		{
			int j;
			//�ҳ���С�ı�nums[keyloc]�����
			for (j = keyloc + 2; j < nsize; j++)
			{
				if (nums[j] <= nums[keyloc]) break;
			}

			//���ַ���,[keyloc+1, nsize-1]�Ƿ��򲿷�,�ȵ���Ԫ��,�󲿷�����(����)
			int temp = nums[keyloc];
			nums[keyloc] = nums[j - 1];
			nums[j - 1] = temp;
			sort(nums.begin() + keyloc + 1, nums.end());
		}
	}
}

int Solution::longestValidParentheses(string s)
{
	//stack��¼(���±� // -1 0 

	vector<int> stack = { -1 };
	int ssize = s.size();
	int res = 0;
	for (int i = 0; i < ssize; i++)
	{
		if (s[i] == '(') stack.push_back(i);
		else
		{
			// -1 (0 (12) 3)

			if (stack.size() == 1) stack[0] = i;
			else
			{
				stack.pop_back();
				if (res < (i - stack[stack.size() - 1]))
					res = i - stack[stack.size() - 1];
			}
		}
	}
	return res;
}

//nums[startloc, endloc]��������������,Ҳ���ܲ��ǵ�,���涼�д���,����������������������
//�ҷ�����Ŀ�涨
int Solution::iter_search(vector<int>& nums, int target, int startloc, int endloc)
{
	//���ֲ��
	int nsize = endloc - startloc;
	if (nsize < 0) return -1;
	if (nsize == 0)
	{
		if (nums[startloc] == target) return startloc;
		else return -1;
	}
	else
	{
		int mid = (startloc + endloc) / 2;   //here mid must < endloc
		//��ʽ�ָ����[startloc,mid],  [mid+1,endloc]
		if (nums[startloc] <= nums[mid])  //[0,mid]Ϊ������������
		{
			if (nums[startloc] <= target)
				if (target <= nums[mid])
					return binary_search(nums, target, startloc, endloc);
				else //�����ں���
					if (nums[mid + 1] <= nums[endloc]) //[mid+1,endloc]Ϊ������������
						return binary_search(nums, target, mid + 1, endloc);
					else
						return iter_search(nums, target, mid + 1, endloc);
			else
				return iter_search(nums, target, mid + 1, endloc);
		}
		else //[0,mid]����������������,��[mid+1,endloc]��Ϊ������������
		{
			if (nums[mid + 1] <= target)
				if (target <= nums[endloc])
					return binary_search(nums, target, mid + 1, endloc);
				else
					return iter_search(nums, target, startloc, mid);
			else
				return iter_search(nums, target, startloc, mid);
		}
	}
}

int Solution::binary_search(vector<int>& nums, int target, int startloc, int endloc)
{
	int left = startloc;
	int right = endloc;
	if (right < left) return -1;
	if (right == left)
	{
		if (nums[left] == target) return left;
		else return -1;
	}
	else
	{
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] < target) left = mid + 1;
			else if (nums[mid] > target) right = mid - 1;
			else return mid;
		}
	}
	return -1;
}

int Solution::search(vector<int>& nums, int target)
{
	int nsize = nums.size();
	if (nsize == 0) return -1;
	if (nsize == 1)
	{
		if (nums[0] == target) return 0;
		else return -1;
	}

	//����Ϊnsize >= 2����,�ݹ�
	return iter_search(nums, target, 0, nsize - 1);
}

int Solution::search_fix_right_border(vector<int>& nums, int target, int startloc, int endloc)
{
	int left = startloc;
	int right = endloc;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] < target) left = mid + 1;
		else
		{
			if (mid == left) return left;
			else if (nums[mid - 1] != target) return mid;
			else right = mid - 1;
		}
	}
	return -999;   //�߼��ϵ��������Ӧ�ó���
}

int Solution::search_fix_left_border(vector<int>& nums, int target, int startloc, int endloc)
{
	int left = startloc;
	int right = endloc;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] > target) right = mid - 1;
		else
		{
			if (mid == right) return right;
			else if (nums[mid + 1] != target) return mid;
			else left = mid + 1;
		}
	}
	return -999;   //�߼��ϵ��������Ӧ�ó���
}

vector<int> Solution::searchRange(vector<int>& nums, int target)
{
	//�ȴֶ��ֲ���
	int nsize = nums.size();
	if (nsize == 0) return vector<int> {-1, -1};
	else if (nsize == 1) return (target == nums[0]) ? vector<int> {0, 0} : vector<int>{ -1, -1 };
	else
	{
		int left = 0;
		int right = nsize - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] < target) left = mid + 1;
			else if (nums[mid] > target) right = mid - 1;
			else  //�ҵ���,����ڶ�����,������չ����
			{
				//[left, mid-1], [mid + 1, right], here mid+-1���ܳ����߽�
				if (mid == left)
				{
					if (mid == right) return vector<int> {mid, mid};
					else
					{
						if (nums[mid + 1] != target) return vector<int> {mid, mid};
						else
						{
							vector<int> returnv = { mid };
							returnv.push_back(search_fix_left_border(nums, target, mid + 1, right));
							return returnv;
						}
					}
				}
				else
				{
					if (mid == right)
					{
						if (nums[mid - 1] != target) return vector<int> {mid, mid};
						else
						{
							vector<int> returnv = {};
							returnv.push_back(search_fix_right_border(nums, target, left, mid - 1));
							returnv.push_back(mid);
							return returnv;
						}
					}
					else
					{
						vector<int> returnv = {};
						if (nums[mid - 1] != target) returnv.push_back(mid);
						else returnv.push_back(search_fix_right_border(nums, target, left, mid - 1));
						if (nums[mid + 1] != target) returnv.push_back(mid);
						else returnv.push_back(search_fix_left_border(nums, target, mid + 1, right));
						return returnv;
					}
				}
			}
		}
		return vector<int> {-1, -1};
	}
}

int Solution::searchInsert(vector<int>& nums, int target)
{
	//�������
	int nsize = nums.size();
	if (nsize == 0) return 0;
	if (nsize == 1) return (nums[0] >= target) ? 0 : 1;

	//ȥ���߽����
	if (nums[0] > target) return 0;
	if (nums[nsize - 1] < target) return nsize;

	//���ֲ���
	int left = 0;
	int right = nsize - 1;

	while (left < right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] < target) left = mid + 1;
		else if (nums[mid] > target) right = mid - 1;
		else
			return mid;
	}

	if (left != right)  //��ʱright = left - 1��
	{
		if (nums[right] > target) return right;
		else if (nums[left] > target) return left;
		else return left + 1;
	}
	else
	{
		return (nums[left] >= target) ? left : left + 1;
	}
}

bool Solution::isValidSudoku(vector<vector<char>>& board)
{
	//һ�ֱ����ж�
	vector<vector<char>> rows(9);
	vector<vector<char>> columns(9);
	vector<vector<char>> groups(9);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.') continue;
			if (find(rows[i].begin(), rows[i].end(), board[i][j]) == rows[i].end())
				rows[i].push_back(board[i][j]);
			else
				return false;
			if (find(columns[j].begin(), columns[j].end(), board[i][j]) == columns[j].end())
				columns[j].push_back(board[i][j]);
			else
				return false;
			if (find(groups[3 * (i / 3) + j / 3].begin(), groups[3 * (i / 3) + j / 3].end(), board[i][j]) == groups[3 * (i / 3) + j / 3].end())
				groups[3 * (i / 3) + j / 3].push_back(board[i][j]);
			else
				return false;
		}
	}
	return true;
}

void Solution::solveSudoku(vector<vector<char>>& board)
{
	//����,�������
	//��Ŀ��Ϊһ���н�,��ΪΨһ��
	vector<SudokuInfo> stack;

	//һ�ֱ���,��ȡ������֪��Ϣ
	vector<vector<char>> rows(9);
	vector<vector<char>> columns(9);
	vector<vector<char>> groups(9);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.') continue;
			rows[i].push_back(board[i][j]);
			columns[j].push_back(board[i][j]);
			groups[3 * (i / 3) + j / 3].push_back(board[i][j]);
		}
	}

	//init row and column
	int i = 0;         //valid:[0,8]
	int j = 0;      //valid:[0,8]
	while (i < 9)
	{
		if (board[i][j] == '.')
		{
			//Ѱ�ҵ�ǰ��������
			vector<char> fullnum = { '1','2','3','4','5','6','7','8','9' };
			for (int k = 0; k < rows[i].size(); k++)
			{
				vector<char>::iterator iterc = find(fullnum.begin(), fullnum.end(), rows[i][k]);
				if (iterc != fullnum.end()) fullnum.erase(iterc);
			}
			for (int k = 0; k < columns[j].size(); k++)
			{
				vector<char>::iterator iterc = find(fullnum.begin(), fullnum.end(), columns[j][k]);
				if (iterc != fullnum.end()) fullnum.erase(iterc);
			}
			int groupindex = 3 * (i / 3) + j / 3;
			for (int k = 0; k < groups[groupindex].size(); k++)
			{
				vector<char>::iterator iterc = find(fullnum.begin(), fullnum.end(), groups[groupindex][k]);
				if (iterc != fullnum.end()) fullnum.erase(iterc);
			}
			if (fullnum.size() > 0)
			{
				SudokuInfo tempsi;
				tempsi.row = i;
				tempsi.column = j;
				tempsi.remaining_numbers = fullnum;
				stack.push_back(tempsi);

				//ȡ��stack���һ��λ��struct�����б��еĵ�һ�����ֲ����
				char prenum = stack[stack.size() - 1].remaining_numbers[0];
				stack[stack.size() - 1].remaining_numbers.erase(stack[stack.size() - 1].remaining_numbers.begin());
				//��������
				board[i][j] = prenum;
				rows[i].push_back(prenum);
				columns[j].push_back(prenum);
				groups[groupindex].push_back(prenum);
			}
			else  //����
			{
				while (true)
				{
					SudokuInfo tempsi;
					tempsi = stack[stack.size() - 1];
					//���ָ��λ��Ԫ��
					int temprow = tempsi.row;
					int tempcolumn = tempsi.column;
					board[temprow][tempcolumn] = '.';
					rows[temprow].pop_back();
					columns[tempcolumn].pop_back();
					groups[3 * (temprow / 3) + tempcolumn / 3].pop_back();
					if (tempsi.remaining_numbers.size() != 0)
					{
						char prenum = tempsi.remaining_numbers[0];
						stack[stack.size() - 1].remaining_numbers.erase(stack[stack.size() - 1].remaining_numbers.begin());
						//��������
						board[temprow][tempcolumn] = prenum;
						rows[temprow].push_back(prenum);
						columns[tempcolumn].push_back(prenum);
						groups[3 * (temprow / 3) + tempcolumn / 3].push_back(prenum);
						//����i��j
						i = temprow;
						j = tempcolumn;
						break;
					}
					else
					{
						stack.pop_back();  //ɾ���Ǹ�remaining_numbers�ǿյ�stackԪ��
					}
				}
			}
		}
		if (j < 8) j++;
		else
		{
			j = 0;
			i++;
		}
	}
}

string Solution::countAndSay(int n)
{
	//ѭ����
	string laststr = "1";
	for (int i = 1; i < n; i++)
	{
		string prestr = "";
		char oldchar = laststr[0];
		int charnums = 1;
		for (int j = 1; j < laststr.size(); j++)
		{
			if (laststr[j] != oldchar)
			{
				string s1;
				s1.push_back(oldchar);
				prestr += to_string(charnums) + s1;
				oldchar = laststr[j];
				charnums = 1;
			}
			else charnums++;
		}
		//��������һ��prestr
		string s1;
		s1.push_back(oldchar);
		prestr += to_string(charnums) + s1;
		laststr = prestr;
	}
	return laststr;
}

//����pair<bool, int>, bool:true:�ҵ��������, int���±�
//bool:false:û�ҵ���, int�ǰ�˳�����ʱ���±�
//�ⲿ���뱣֤nums�������������ظ�Ԫ��,nums������һ��Ԫ��
//max_end_loc����ֹloc,֮���Ԫ�ز���Ҫ����, target��Ŀ��
pair<bool, int> Solution::searchInsert_exam39(vector<int>& nums, int max_end_loc, int target)
{
	//�������
	int nsize = max_end_loc + 1;
	if (nsize == 1)
	{
		if (nums[0] > target) return pair<bool, int> {false, 0};
		else if (nums[0] < target) return pair<bool, int> {false, 1};
		else return pair<bool, int> {true, 0};
	}

	//ȥ���߽����
	if (nums[0] > target) return pair<bool, int> {false, 0};
	if (nums[max_end_loc] < target) return pair<bool, int> {false, max_end_loc + 1};

	//���ֲ���
	int left = 0;
	int right = max_end_loc;

	while (left < right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] < target) left = mid + 1;
		else if (nums[mid] > target) right = mid - 1;
		else
			return pair<bool, int> {true, mid};
	}

	if (left != right)  //��ʱright = left - 1��
	{
		if (nums[right] > target) return pair<bool, int> {false, right};
		else if (nums[left] > target) return pair<bool, int> {false, left};
		else return pair<bool, int> {false, left + 1};
	}
	else
	{
		if (nums[left] > target) return pair<bool, int> {false, left};
		else if (nums[left] < target) return pair<bool, int> {false, left + 1};
		else return pair<bool, int> {true, left};
	}
}

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target)
{
	//�������,����
	//�ȵ�����һ������ʱ��,���ж��ֲ���

	//�������
	int csize = candidates.size();
	if (csize == 0) return vector<vector<int>> {};

	sort(candidates.begin(), candidates.end());

	//����һ�����ֲ���,�����������������ҳ���
	vector<vector<int>> returnvv = {};
	pair<bool, int> res;
	res = searchInsert_exam39(candidates, candidates.size() - 1, target);
	if (res.first == true)
		returnvv.push_back(vector<int> {candidates[res.second]});

	if (target <= candidates[0]) //��������,target̫С��
		return returnvv;

	int gbl_candidates_maxloc = res.second - 1;

	/*Ȼ���������,����
	����"��˳��"�������ֵĵ���,��������������е���:
	target-���Ӻ��ֵ < min(���Ŀ�������),����
	target-���Ӻ��ֵ > max(���Ŀ�������),���ż�������
	����ת���ֲ���,�ҵ���ʹ�ö�Ӧ���ֲ���¼,���򲻲���;���������Ż���
	*/

	vector<vector<pair<int, int>>> stack = { {} }; //���list,��¼��Ӧ�±�Ĵ������ʹ�õ�����
	for (int i = gbl_candidates_maxloc; i >= 0; i--)
		stack[0].push_back(pair<int, int> {i, candidates[i]});

	vector<int> pre_num;
	int pre_sum = 0;

	while (true)
	{
		if (stack.size() == 0) break;
		pair<int, int> temp = stack[stack.size() - 1][stack[stack.size() - 1].size() - 1]; //�����㷨,������һ��ȡ�ó�����
		int index = temp.first;
		int num = temp.second;
		pre_sum += num;
		pre_num.push_back(num);

		if ((target - pre_sum) < num)
			while (true)
			{
				if (stack.size() == 0) break;
				pair<int, int> itemp = stack[stack.size() - 1][stack[stack.size() - 1].size() - 1];
				stack[stack.size() - 1].pop_back();
				pre_sum -= itemp.second;
				pre_num.pop_back();
				if (stack[stack.size() - 1].size() == 0) stack.pop_back();
				else break;
			}
		else if ((target - pre_sum) > candidates[gbl_candidates_maxloc])
		{
			stack.push_back(vector<pair<int, int>> {});
			for (int i = gbl_candidates_maxloc; i > index - 1; i--)
				stack[stack.size() - 1].push_back(pair<int, int> {i, candidates[i]});
		}
		else
		{
			res = searchInsert_exam39(candidates, gbl_candidates_maxloc, target - pre_sum);
			if (res.first)
			{
				pre_num.push_back(candidates[res.second]);
				returnvv.push_back(pre_num);
				pre_num.pop_back();
				if ((res.second != 0) && (index < res.second))
				{
					stack.push_back(vector<pair<int, int>> {});
					for (int i = res.second - 1; i > index - 1; i--)
						stack[stack.size() - 1].push_back(pair<int, int> {i, candidates[i]});
				}
				else
					while (true)
					{
						if (stack.size() == 0) break;
						pair<int, int> itemp = stack[stack.size() - 1][stack[stack.size() - 1].size() - 1];
						stack[stack.size() - 1].pop_back();
						pre_sum -= itemp.second;
						pre_num.pop_back();
						if (stack[stack.size() - 1].size() == 0) 
							stack.pop_back();
						else break;
					}
			}
			else  //������res.second>=1,��Ϊ����0˵��target-pre_sumһ����candidates[0]С,����numС��֮ǰ���Ѿ�if��׽��
			{
				if (index < res.second)
				{
					stack.push_back(vector<pair<int, int>> {});
					for (int i = res.second - 1; i > index - 1; i--)
						stack[stack.size() - 1].push_back(pair<int, int> {i, candidates[i]});
				}
				else
					while (true)
					{
						if (stack.size() == 0) break;
						pair<int, int> itemp = stack[stack.size() - 1][stack[stack.size() - 1].size() - 1];
						stack[stack.size() - 1].pop_back();
						pre_sum -= itemp.second;
						pre_num.pop_back();
						if (stack[stack.size() - 1].size() == 0)
							stack.pop_back();
						else break;
					}
			}
		}
	}

	return returnvv;
}

vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target)
{
	//�������,����
	//�ȵ�����һ������ʱ��,���ж��ֲ���

	//�������
	int csize = candidates.size();
	if (csize == 0) return vector<vector<int>> {};
	
	//��¼candidates����,���ظ���ɸ��,����
	unordered_map<int, int> candidates_dict = {};
	for (int i = 0; i < candidates.size(); i++)
		candidates_dict[candidates[i]] += 1;
	vector<int> candidates_no_duplicate = {};
	for (unordered_map<int, int>::const_iterator iter = candidates_dict.cbegin(); iter != candidates_dict.cend(); ++iter)
		candidates_no_duplicate.push_back(iter->first);

	sort(candidates_no_duplicate.begin(), candidates_no_duplicate.end());

	//����һ�����ֲ���,�����������������ҳ���
	vector<vector<int>> returnvv = {};
	pair<bool, int> res;
	res = searchInsert_exam39(candidates_no_duplicate, candidates_no_duplicate.size() - 1, target);
	if (res.first == true)
		returnvv.push_back(vector<int> {candidates_no_duplicate[res.second]});

	if (target <= candidates_no_duplicate[0]) //��������,target̫С��
		return returnvv;

	int gbl_candidates_maxloc = res.second - 1;
	

	/*Ȼ���������,����
	����"��˳��"�������ֵĵ���,��������������е���:
	target-���Ӻ��ֵ < min(���Ŀ�������),����
	target-���Ӻ��ֵ > max(���Ŀ�������),���ż�������
	����ת���ֲ���,�ҵ���ʹ�ö�Ӧ���ֲ���¼,���򲻲���;���������Ż���
	*/

	vector<vector<pair<int, int>>> stack = { {} }; //���list,��¼��Ӧ�±�Ĵ������ʹ�õ�����
	for (int i = gbl_candidates_maxloc; i >= 0; i--)
		stack[0].push_back(pair<int, int> {i, candidates_no_duplicate[i]});

	unordered_map<int, int> pre_num_dict = {};
	vector<int> pre_num;
	int pre_sum = 0;

	while (true)
	{
		if (stack.size() == 0) break;
		pair<int, int> temp = stack[stack.size() - 1][stack[stack.size() - 1].size() - 1]; //�����㷨,������һ��ȡ�ó�����
		int index = temp.first;
		int num = temp.second;
		pre_sum += num;
		pre_num.push_back(num);
		pre_num_dict[num] += 1;

		if (pre_num_dict.find(num) != pre_num_dict.end())
		{
			if (pre_num_dict[num] > candidates_dict[num])  //num���꿩
			{
				while (true)
				{
					if (stack.size() == 0) break;
					pair<int, int> itemp = stack[stack.size() - 1][stack[stack.size() - 1].size() - 1];
					stack[stack.size() - 1].pop_back();
					pre_sum -= itemp.second;
					pre_num.pop_back();
					pre_num_dict[itemp.second]--;
					if (stack[stack.size() - 1].size() == 0) stack.pop_back();
					else break;
				}
				continue;   //���µ���
			}
		}


		if ((target - pre_sum) < num)
			while (true)
			{
				if (stack.size() == 0) break;
				pair<int, int> itemp = stack[stack.size() - 1][stack[stack.size() - 1].size() - 1];
				stack[stack.size() - 1].pop_back();
				pre_sum -= itemp.second;
				pre_num.pop_back();
				pre_num_dict[itemp.second]--;
				if (stack[stack.size() - 1].size() == 0) stack.pop_back();
				else break;
			}
		else if ((target - pre_sum) > candidates_no_duplicate[gbl_candidates_maxloc])
		{
			stack.push_back(vector<pair<int, int>> {});
			for (int i = gbl_candidates_maxloc; i > index - 1; i--)
				stack[stack.size() - 1].push_back(pair<int, int> {i, candidates_no_duplicate[i]});
		}
		else
		{
			res = searchInsert_exam39(candidates_no_duplicate, gbl_candidates_maxloc, target - pre_sum);
			if (res.first)
			{
				//candidates_no_duplicate[res.second]������
				if (pre_num_dict[candidates_no_duplicate[res.second]] < candidates_dict[candidates_no_duplicate[res.second]])
				{
					pre_num.push_back(candidates_no_duplicate[res.second]);
					returnvv.push_back(pre_num);
					pre_num.pop_back();
				}

				if ((res.second != 0) && (index < res.second))
				{
					stack.push_back(vector<pair<int, int>> {});
					for (int i = res.second - 1; i > index - 1; i--)
						stack[stack.size() - 1].push_back(pair<int, int> {i, candidates_no_duplicate[i]});
				}
				else
					while (true)
					{
						if (stack.size() == 0) break;
						pair<int, int> itemp = stack[stack.size() - 1][stack[stack.size() - 1].size() - 1];
						stack[stack.size() - 1].pop_back();
						pre_sum -= itemp.second;
						pre_num.pop_back();
						pre_num_dict[itemp.second]--;
						if (stack[stack.size() - 1].size() == 0)
							stack.pop_back();
						else break;
					}
			}
			else  //������res.second>=1,��Ϊ����0˵��target-pre_sumһ����candidates[0]С,����numС��֮ǰ���Ѿ�if��׽��
			{
				if (index < res.second)
				{
					stack.push_back(vector<pair<int, int>> {});
					for (int i = res.second - 1; i > index - 1; i--)
						stack[stack.size() - 1].push_back(pair<int, int> {i, candidates_no_duplicate[i]});
				}
				else
					while (true)
					{
						if (stack.size() == 0) break;
						pair<int, int> itemp = stack[stack.size() - 1][stack[stack.size() - 1].size() - 1];
						stack[stack.size() - 1].pop_back();
						pre_sum -= itemp.second;
						pre_num.pop_back();
						pre_num_dict[itemp.second]--;
						if (stack[stack.size() - 1].size() == 0)
							stack.pop_back();
						else break;
					}
			}
		}
	}

	return returnvv;
}
#else
#endif

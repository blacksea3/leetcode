#include "BinaryTree.h"
#include "listnode.h"

//��������֦�Ļ���

class Solution {
private:
    int gblRes;
    /*
     * ���±�i��ʼ����ʽ����s, �ο�:https://leetcode-cn.com/problems/zuma-game/solution/c-hui-su-fa-by-da-li-wang-3/
     */
    string boom(string s, int i) {
        if (s.empty()) return "";
        int left = i, right = i;
        while (left > 0 && s[left - 1] == s[left]) --left;
        while (right < s.size() - 1 && s[right + 1] == s[right]) ++right;
        if (right - left + 1 >= 3) {
            s = s.substr(0, left) + s.substr(right + 1);
            return boom(s, max(left - 1, 0));
        }
        return s;
    }

    /*
     * pB:��ǰboard, mhand:��ǰhand�ַ�ͳ������, usedCount:�����ַ�����, remainCount:ʣ���ַ�����
     */
    void DFS(string pB, map<char, int>& handCount, int usedCount, int remainCount) {
        if (pB.empty()) gblRes = min(gblRes, usedCount);
        else {
            if ((remainCount == 0) || (usedCount + 1) >= gblRes) {  //û���ַ���, ���߲������ٻ��ݳ���С������·����, ��֦
                return;
            }
            else {
                //�������������Ҫ���ַ�����
                map<char, int> pBcount;
                for (const auto& pc : pB) pBcount[pc]++;
                int nextAtLeastCount = 0;

                for (auto& p : pBcount) {
                    if (p.second < 3) {
                        nextAtLeastCount += 3 - p.second;
                    }
                    if ((3 - p.second) > handCount[p.first]) //mhand��ĳ���ַ���������, ��֦
                        return;
                }
                if ((nextAtLeastCount + usedCount) >= gblRes) {  //�������ٻ��ݳ���С������·����, ��֦
                    return;
                }

                //��ʼ����
                string temps;
                for (auto& h : handCount) {
                    if (h.second == 0) continue;  //mhandĳ���ַ�û��, ����
                    char choose = h.first;
                    if (pBcount.find(choose) == pBcount.end()) continue;   //pBû��choose����, ����
                    for (int index = 0; index < pB.size(); ++index) {    //
                        if (index > 0 && choose == pB[index - 1])
                            continue;  //��ǰ���board�ϴ���׼���Ĳ���λ��ǰ������ɫһ��, ������ͬ�������, ����
                        temps = pB;
                        temps.insert(temps.begin() + index, choose);
                        temps = this->boom(temps, index);
                        handCount[choose]--;
                        DFS(temps, handCount, usedCount + 1, remainCount - 1);
                        handCount[choose]++;
                    }

                    //��ͼ��pB����
                    if (choose == pB.back())
                        continue;  //��ǰ���board�ϴ���׼���Ĳ���λ��ǰ������ɫһ��, ������ͬ�������, ����
                    temps = pB;
                    temps.push_back(choose);
                    //����Ҫ����boom, ��Ϊһ������boom!
                    handCount[choose]--;
                    DFS(temps, handCount, usedCount + 1, remainCount - 1);
                    handCount[choose]++;
                }

            }
        }

    }
public:
    int findMinStep(string board, string hand) {
        gblRes = INT_MAX;
        map<char, int> handCount;
        for (const auto& h : hand) handCount[h]++;

        DFS(board, handCount, 0, hand.size());
        return (gblRes == INT_MAX) ? -1 : gblRes;
    }
};

/*
int main() {
    Solution* s = new Solution();
    cout << s->findMinStep("WRRBBW", "RB") << endl;
    cout << s->findMinStep("RRWWRRW", "RR") << endl;
    cout << s->findMinStep("WWRRBBWW", "WRBRW") << endl;
    cout << s->findMinStep("G", "GGGGG") << endl;
    cout << s->findMinStep("RBYYBBRRB", "YRBGB") << endl;
    cout << s->findMinStep("BGGRRYY", "BBYRG") << endl;

    cout << s->findMinStep("WBGGRRYYR", "BBYRGWW") << endl;
    
    cout << s->findMinStep("RRWWRRBBRR", "WB") << endl;

    return 0;
}
*/

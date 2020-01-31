#include "BinaryTree.h"
#include "listnode.h"

//带大量剪枝的回溯

class Solution {
private:
    int gblRes;
    /*
     * 从下标i开始迭代式消除s, 参考:https://leetcode-cn.com/problems/zuma-game/solution/c-hui-su-fa-by-da-li-wang-3/
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
     * pB:当前board, mhand:当前hand字符统计数量, usedCount:已用字符数量, remainCount:剩余字符数量
     */
    void DFS(string pB, map<char, int>& handCount, int usedCount, int remainCount) {
        if (pB.empty()) gblRes = min(gblRes, usedCount);
        else {
            if ((remainCount == 0) || (usedCount + 1) >= gblRes) {  //没有字符了, 或者不可能再回溯出更小的消除路径了, 剪枝
                return;
            }
            else {
                //计算接下来至少要的字符数量
                map<char, int> pBcount;
                for (const auto& pc : pB) pBcount[pc]++;
                int nextAtLeastCount = 0;

                for (auto& p : pBcount) {
                    if (p.second < 3) {
                        nextAtLeastCount += 3 - p.second;
                    }
                    if ((3 - p.second) > handCount[p.first]) //mhand的某个字符数量不够, 剪枝
                        return;
                }
                if ((nextAtLeastCount + usedCount) >= gblRes) {  //不可能再回溯出更小的消除路径了, 剪枝
                    return;
                }

                //开始迭代
                string temps;
                for (auto& h : handCount) {
                    if (h.second == 0) continue;  //mhand某个字符没了, 跳过
                    char choose = h.first;
                    if (pBcount.find(choose) == pBcount.end()) continue;   //pB没有choose符号, 跳过
                    for (int index = 0; index < pB.size(); ++index) {    //
                        if (index > 0 && choose == pB[index - 1])
                            continue;  //当前球和board上此球准备的插入位置前的球颜色一样, 已有相同情况讨论, 跳过
                        temps = pB;
                        temps.insert(temps.begin() + index, choose);
                        temps = this->boom(temps, index);
                        handCount[choose]--;
                        DFS(temps, handCount, usedCount + 1, remainCount - 1);
                        handCount[choose]++;
                    }

                    //试图往pB最后插
                    if (choose == pB.back())
                        continue;  //当前球和board上此球准备的插入位置前的球颜色一样, 已有相同情况讨论, 跳过
                    temps = pB;
                    temps.push_back(choose);
                    //不需要调用boom, 因为一定不会boom!
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

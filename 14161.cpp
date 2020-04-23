#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void go(vector<string> user_id, vector<string> banned_id, bool* check, int cnt, int bIndex, int& answer) {
    if (cnt == banned_id.size()) { //종료조건
        answer += 1;
        return;
    }

    int u = user_id.size();
    for (int i = 0; i < u; i++) {
        int uSize = user_id[i].size(); int bSize = banned_id[bIndex].size();
        if (uSize == bSize) { //u크기 b크기 같을 때
            bool c = false;
            bool checkAllStar = true;
            for (int k = 0; k < uSize; k++) {
                if (banned_id[bIndex][k] == '*') continue;
                checkAllStar = false;
                if (user_id[i][k] != banned_id[bIndex][k]) {
                    c = true;
                    break;
                }
            }
            if (checkAllStar == true) {
                if (check[i] == false) {
                    check[i] = true;
                    go(user_id, banned_id, check, cnt + 1, bIndex + 1, answer);

                }
                else {
                    continue;
                }
            }
            else {
                if (c == false) { //u와 b가 일치
                    if (check[i] == false) {
                        check[i] = true;
                        go(user_id, banned_id, check, cnt + 1, bIndex + 1, answer);
                        check[i] = false;
                    }
                    continue;
                }
                else { //u와 b가 불일치
                    continue;
                }
            }
        }
        else { //u크기 b크기 다를 때
            continue;
        }
    }
}

void allStarFirstSort(vector<string>& banned_id) {
    int bSize = banned_id.size();
    bool* allStarCheck = new bool[bSize];
    for (int i = 0; i < bSize; i++) {
        allStarCheck[i] = true;
        int size = banned_id[i].size();
        for (int j = 0; j < size; j++) {
            if (banned_id[i][j] == '*') continue;
            allStarCheck[i] = false;
            break;
        }
        if (allStarCheck[i] == false) continue;
        else {
            for (int j = 0; j <= i; j++) {
                if (allStarCheck[j] == true) continue;
                allStarCheck[i] = false;
                allStarCheck[j] = true;
                swap(banned_id[i], banned_id[j]);
                break;
            }
        }
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int n = user_id.size();
    bool* check = new bool[n];
    for (int i = 0; i < n; i++) {
        check[i] = false;
    }
    allStarFirstSort(banned_id);
    go(user_id, banned_id, check, 0, 0, answer);
    return answer;
}

int main() {
    vector<string> user_id;
    vector<string> banned_id;
    user_id.push_back("frodo");
    user_id.push_back("fradi");
    user_id.push_back("crodo");
    user_id.push_back("abc123");
    user_id.push_back("frodoc");
    banned_id.push_back("*rodo");
    banned_id.push_back("*rodo");
    banned_id.push_back("******");
    /*
    banned_id.push_back("fr*d*");
    banned_id.push_back("*rodo");
    banned_id.push_back("******");
    banned_id.push_back("******");
    //banned_id.push_back("fr*d*");
    //banned_id.push_back("abc1**");
    */
    int r = solution(user_id, banned_id);
    cout << r << "\n";
    return 0;
}
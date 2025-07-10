#include <string>
#include <vector>
#define ll long long

using namespace std;
ll i, j;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    ll leftd = left / n + 1;
    ll leftm = left % n + 1;
    ll rightd = right / n + 1;
    ll rightm = right % n + 1;
    
    if (leftd == rightd) {
        for (i = leftm; i <= rightm; ++i) {
            if (i <= leftd) answer.push_back(leftd);
            else answer.push_back(i);
        }
        return answer;
    }
    
    for (i = leftm; i <= n; ++i) {
        if (i <= leftd) answer.push_back(leftd);
        else answer.push_back(i);
    }
    
    for (i = leftd + 1; i < rightd; ++i) {
        for (j = 1; j <= n; ++j) {
            if (j < i) answer.push_back(i);
            else answer.push_back(j);
        }
    }
    
    for (i = 1; i <= rightm; ++i) {
        if (i <= rightd) answer.push_back(rightd);
        else answer.push_back(i);
    }
    
    return answer;
}
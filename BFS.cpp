#include <string>
#include <vector>

using namespace std;
vector<int> n;
int t;
int answer;

void dfs(int index, int sum){
    if(index == n.size()){
        if(sum == t) answer++;
        return;
    }
    dfs(index + 1, sum + n[index]);
    dfs(index + 1, sum - n[index]);
}

int solution(vector<int> numbers, int target) {
    t = target;
    for(int num : numbers)
        n.push_back(num);
    dfs(0, 0);
    
    return answer;
}

// 다시 풀어볼 것!

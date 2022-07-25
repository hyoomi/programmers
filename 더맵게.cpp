#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int s1; // 가장 작은 수
    int s2; // 두번째로 작은 수
    
    while(pq.top() < K){
        if(pq.size() == 1) return -1;
        s1 = pq.top(); pq.pop();
        s2 = pq.top(); pq.pop();
        pq.push(s1 + s2 * 2);
        answer++;
    }
    return answer;        
}

#include <string>
#include <stack>

using namespace std;

// 아스키코드 ()는 하나 차이. 나머지는 두개 차이
int solution(string s) {
    int answer = 0;    
    int k = 0;
    int tmp = 0;
    
    for(int i = 0; i < s.size(); i++){
        stack<int> st;
        for(int j = 0; j < s.size(); j++){
            k = i + j < s.size() ? i + j : i + j - s.size();
            tmp = s[k] - st.top();
            if(tmp == 2 || tmp == 1) st.pop();   
            else st.push(s[k]);
        }
        if(st.empty()) answer++;
    }        
    return answer;
}

// [참고] 이중 for문이 아닌 algorithm의 rotate함수를 활용할 수도 있다

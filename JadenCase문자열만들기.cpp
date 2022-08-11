#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    bool upper = true;
    
    for(auto str : s){
        if(upper){
            answer += toupper(str);
            upper = str == ' ' ? true : false;
            continue;
        }
        
        if(str == ' '){
            upper = true;
            answer += str;
        }else if('A' <= str && str <= 'Z'){
            answer += tolower(str);
        }else{
            answer += str;
        }
    }
    
    return answer;
}

/* 위 for문을 3줄로 줄이는 방법이 있다.
answer += toupper(s[0]);
for (int i = 1; i < s.size(); i++)
    s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

*/

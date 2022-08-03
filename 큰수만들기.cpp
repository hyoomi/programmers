#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";     
    char max_num;
    
    for(int i = 0; i < number.size(); i++){
        if(answer.size() == number.size() - k) break;
        if(i == k + answer.size()){
            answer += number.substr(i);
            break;
        }
        max_num = number[i];
        for(int j = i; j <= k + answer.size(); j++){
            if(max_num < number[j]){
                max_num = number[j];
                i = j;
            } 
        }            
        answer += max_num;
    }
    
    return answer;
}

// 이중포문을 돌지 않게 개선하는 방법이 있다.

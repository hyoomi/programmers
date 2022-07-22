#include <string>
#include <vector>
using namespace std;

string s;

int calculate(int uLen){ // uLen: 문자열을 자르는 단위의 수. 1부터 s.size()까지 
    int result = 0; // 압축된 문자열의 길이
    int unitNum = 1; //단위의 반복 수(ex."2ab"의 unitNum = 2)
    
    for(int i = 0; i < s.size(); i += uLen){
        if(i + uLen > s.size()){
            result += s.size() - i;
            break;
        }
        string unit = s.substr(i, uLen);      
        int next = s.find(unit, i + uLen);
        if(next == i + uLen){
            unitNum++;
        }
        else{
            if(unitNum != 1)
                result += to_string(unitNum).size(); // 앞 문자가 반복됐다면 숫자 길이만큼 더해주기                
           
            result += uLen; // 문자 단위 길이만큼 더해주기                        
            unitNum = 1; //변수 초기화           
        }                    
    }
    return result;
}

int solution(string st) {
    int answer = st.size();
    s = st;
    int an;
    for(int i = 1; i < st.size(); i++){
        an = calculate(i);
        if(an < answer)
            answer = an;
    }    
    return answer;
}

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> types;
    
    for(auto c : clothes)
        types[c[1]]++;
    
    for(auto t : types)
        answer *= (t.second + 1);     

    return --answer;
}

/*
옷 종류가 3가지이고 각 종류별 옷의 개수가 a, b, c개라고 할 때
조합의 개수는 (a+b+c) + (ab+bc+ca) + (abc) 이다.
이것은 x^3 + (a+b+c)x^2 + (ab+bc+ca)x + (abc)의 계수임을 확인 할 수 있다.
위 식이 (a+x)(b+x)(c+x)임을 이용하여 x에 1을 대입한 (a+1)(b+1)(c+1) 값을 구한 뒤 x^3의 1을 빼준다. 
*/

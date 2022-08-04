#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num1) {
    int answer = 0;
    int one1 = 0;
    int one2 = 0;
    int buff = num1;
    
    while (buff != 0){
        one1 += ( buff % 2 == 0 ? 0 : 1 );
        buff /= 2;
    }

    for(int num2 = num1 + 1; ; num2++){
        buff = num2;
        one2 = 0;
        while (buff != 0){
            one2 += ( buff % 2 == 0 ? 0 : 1 );
            buff /= 2;
        }
        if(one1 == one2){
            answer = num2; break;
        }        
    }
        
    return answer;
}

/* 다른 사람의 풀이이다. bitset을 활용한 방법도 있다.
#include <bitset>

using namespace std;

int solution(int n) {
    int num = bitset<20>(n).count();

    while (bitset<20>(++n).count() != num);
    return n;
}
*/

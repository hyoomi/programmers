#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    int mul = brown + yellow;
    int sum = brown / 2 + 2;

    for(int i = 3; i < 2000; i++){
        if((sum - i) * i == mul){
            answer[1] = i;
            break;
        }
    }
    answer[0] = sum - answer[1];
    return answer;
}

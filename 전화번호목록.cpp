#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for(int i = 0; i < phone_book.size() - 1; i++){
        if(phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
            return false;   
    }
    return true;
}

// vector<string>은 사전 순 정렬이 된다는 점을 이용함.

// unordered_map을 사용하는 방법도 있다.
// 다른 사람의 코드 참조. 다시 풀어볼 것

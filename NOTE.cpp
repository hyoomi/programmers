// 코딩 테스트를 준비하면서 공부한 내용 정리
// #include<iostream> 과 using namespace std;는 생략함

// 2022.07.29
// # vector 원소 찾는법
#include<algorithm> // std::find_if(), find()
#include<veector>   // std::vector

bool IsOdd(int i) { return ((i % 2) == 1); }

int main() {
    vector<int> v;
    v.push_back(10);
    
    auto it = find(v.begin(), v.end(), 10);
    if(it != v.end()) cout << "index: " << it - v.begin(); // vector iterator로 index 알아내기
    
    vector<int>::iterator it = find_if(v.begin(), v.end(), IsOdd);    
    while (it != v.end()) {
        cout << *it << "\n";
        it = find_if(it + 1, v.end(), isOdd);
    }
}

// # vector 최대 최소값 찾기
// - max_element()는 문자열, 배열 등에도 사용가능하다
#include<algorithm> // std::max_element()
int max = *max_element(v.begin(), v.end());
int min = *min_element(v.begin(), v.end());

// # vector pair로 find하는 방법 
// - pair는 operator==가 정의되어있지 않기 때문에 find_if를 사용해야 한다.
vector<pair<char, int>> words;
auto it = find_if(words.begin(), words.end(), 
            [&ch](const pair<char, int>& elem){ return elem.first == ch; });

// # vector를 queue처럼 사용하기
// - queue를 순회 하고 싶을 때, 원소 검색을 하고 싶은 때 등
vector<int> v;
v.push_back(1);
v.push_back(2);
v.erase(v.begin()); // 단, 시간복잡도 O(N)

// # queue 사용법
// - queue는 순회 할 수 없다!
#include<queue> // std::queue

queue<int> q;   // 선언
q.push(1); q.pop();     // 삽입, 삭제
q.front(); q.back();    // 맨 앞, 맨 뒤 원소 참조
q.empty();      // 비어있으면 1, 아니면 0 출력
q.size();       // 원소 개수



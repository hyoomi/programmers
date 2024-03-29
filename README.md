# programmers
programmers 문제풀이 및 코딩테스트를 위한 C++ 스킬 정리

</br>

---

</br>

## 💠 컨테이너
### 🌳 set
<details><summary>특징</summary>
<p>

- 노드 기반 컨테이너.

- 균형 이진트리.

- 중복을 허용하지 않은 key로 구성.

- key값을 삽입하면 자동 정렬되며 default는 오름차순이다.

[참고](https://blockdmask.tistory.com/79)

</p>
</details>

```cpp
#include <set>

set<int> s;   // 비교연산자 사용가능
s.insert(k);  // 자동 정렬하여 k 삽입. 중복시 삽입 실패 
s.erase(iter);  // 반복자 위치 key 삭제. 다음 반복자 반환
s.erase(start, end);  // [start,end) 범위의 key 모두 삭제
s.find(k);  // k 위치 반복자 반환. 탐색 실패시 s.end()반환
s.size();
s.empty();
s.clear();
```

</br>

### :deciduous_tree: map
#### :blossom: 특징

- set과 같은 associative 컨테이너.

- map은 <key, value>의 쌍(pair)으로 저장.

- 중복 저장되지 않는다.

- [] 연산자로 key에 해당하는 원소의 value 값에 접근 할 수 있다.

```cpp
#include <iostream>
#include <map>
using namespace std;

int main(){
    // 초기화
    map<int, string> m;
    
    // 삽입 (key, value)
    m.insert(pair<int, string>(1, "a"));
    
    pair<int, string> p(2, "b");     
    m.insert(p);    
    
    m[3] = "c";            

    // 접근
    map<int, string>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter)
        cout << "<" << (*iter).first << "," << (*iter).second << ">" << " ";

    m[1] = "f";   
```

</br>

### 🌳 vector
#### 🌼 중복제거하기
`unique`는 중복이 되는 원소를 쓰레기 값으로 처리한 뒤 `vector`의 맨 뒤로 보낸다. 이때 쓰레기 값을 가진 첫번째 원소의 iterator를 반환한다. 따라서 이 위치부터 `vec.end()`까지의 원소를 `erase`를 통해 삭제해준다. \
_근데 이걸 쓸 바에 자동으로 중복제거와 정렬까지 해주는 `set`이나 `map`을 사용하자..!_

```cpp
#include <algorithm> // sort, unique
vec.sort(vec.begin(), vec.end());
vec.erase(unique(vec.begin(), vec.end()), vec.end());
```

</br>

---

</br>

## 🌳 algorithm
### 🌼 find
범위 안 (first 부터 last 전 까지) 의 원소들 중 val 과 일치하는 첫 번째 원소를 가리키는 반복자를 리턴한다. 만일 일치하는 원소를 찾지 못할 경우 last 를 리턴한다. 이 때 val 의 타입 T 의 경우 operator== 가 정의되어 있어야만 한다. [참고](https://modoocode.com/261)
```cpp
// 정의
InputIterator find(InputIterator first, InputIterator last, const T& val);
```
```cpp
// 예시
  std::vector<int> myvector(5, 1);
  std::vector<int>::iterator it;
  std::vector<int>::iterator mid = myvector.begin() + 2;

  it = find(myvector.begin(), mid, 30);
  if (it != mid)
    std::cout << "Element found in myvector: " << *it << '\n';
  else
    std::cout << "Element not found in myvector\n";
```


</br>

---

</br>

## 🌳 string
### 🌼 substr
문자열의 pos 번째 문자 부터 count 길이 만큼의 문자열을 리턴한다. count의 default값은 npos 이고, 자동으로 pos 부터 원래 문자열의 끝 까지 리턴한다.
```cpp
// 정의
basic_string substr(size_type pos = 0, size_type count = npos) const;
```
```cpp
// 예시
string a = "0123456789abcde";
string sub1 = a.substr(10); // "abcde"
string sub2 = a.substr(5, 3);   // "567"
```

</br>

### 🌼 대문자, 소문자 변환
#### 1. 아스키코드 이용하기
대문자 A의 아스키코드는 65, 소문자 a의 아스키코드는 97이다. 아스키코드 값의 차이가 32가 나는 것을 이용하여 변환할 수 있다. 
[참고](https://hoho325.tistory.com/314)
```cpp
string str = "ABCabc"
for(auto s : str){
    if('A' <= s && s <= 'Z')
        s += 32;    // 대문자 -> 소문자
    else
        s -= 32;    // 소문자 -> 대문자
}
```

#### 2. tolower(), toupper()함수 이용하기
```cpp
string str = "ABCabc"
for(auto s : str){
    if('A' <= s && s <= 'Z')
        s = tolower(s);    // 대문자 -> 소문자
    else
        s = toupper(s);    // 소문자 -> 대문자
}
```

</br>

---

</br>

## 🌳 stringstream
문자열에서 특정 자료형에 해당하는 정보만 추출할 때 유용하게 사용된다. 또한 공백과 엔터 기준으로 문자를 자를 수 있다. 
[공식문서](https://cplusplus.com/reference/sstream/stringstream/) , [참고](https://life-with-coding.tistory.com/403) , [참고](https://m.blog.naver.com/kks227/220245263973)
```cpp
#include <sstream>

int num;
string str = "123 456 789";
stringstream stream; 
stream.str(str);
while(stream >> num) cout << num << endl;
stream.str(""); // 초기화
```


</br>

---

</br>

## 💠 스킬
### 🌳 소수
에라토스테네스의 체를 이용하여 효율적으로 소수를 구할 수 있다.</br> 
에라토스테네스의 체의 원리는 이러하다. 2의 제곱부터 범위 내 2의 배수를 소수가 아닌 것으로 전부 체크하고, 3의 제곱부터 범위 내 3의 배수를 전부 체크한다. 이러한 방식으로 i의 제곱부터 범위 내 i의 배수를 전부 체크한다.</br> 
이때 i의 2배수부터 체크하는 것이 아닌 i의 제곱부터 체크하는 이유는 `2 * i`는 이미 2의 배수를 체크할 때 확인되었고 `3 * i`는 3의 배수를 체크할 때 확인되었기 때문에 이러한 방식으로 `(i - 1) * i`까지는 이미 이전 단계에서 체크되었기 때문에 `i * i`부터 새로이 체크하는 것이다.</br> 
i의 범위는 2부터 max값의 양의 제곱근(루트 max)까지이다. 전 범위를 탐색하지 않는 이유를 간단하게 설명해보겠다. `max = a * b`라고 나타냈을 때, a와 b중 작은 값은 반드시 max의 제곱근보다 작거나 같다. 따라서 max의 제곱근까지만 검사하면 max의 약수가 될 수 있는 모든 수를 검사할 수 있게 된다. 이해하기 쉽게 예시를 들어보겠다. 36을 (a \* b)꼴로 나타내면 (2 \* 18), (3 \* 12), (4 \* 9), (6 \* 6)으로 나타낼 수 있고 (9 \* 4), (12 \* 3), (18 \* 2)는 이미 검사된 것과 동일하기 때문에 굳이 검사하지 않아도 된다. 즉 36의 약수(2, 3, 4, 6, 9, 12, 18)를 찾기 위한 a의 범위는 2부터 36의 제곱근인 6까지이다.

```cpp
int max = 100;
vector<int> prime(max + 1, 1);
prime[0] = 0; prime[1] = 0;
for(int i = 2; i * i < prime.size(); i++){
    if(!prime[i]) continue;
    for(int j = i * i; j < prime.size(); j += i) prime[j] = 0;
}
```

</br>

### 🌳 순열
순열은 n개의 원소에서 r개의 원소를 뽑아 배치시키는 경우의 수를 의미한다. </br>
`next_permutation`를 사용하기 위해서 컨테이너는 반드시 오름차순으로 정렬되어 있어야한다. 중복을 제거하고 순열이 생성된다.</br>
아래코드는 nP1부터 nPn까지 전부 구하는 과정이다. `set`은 중복을 허용하지 않기 때문에 유용하다.</br>
`for문`을 추가하지 않고 각 `do문`에서 `numbers`를 `numset`에 삽입하면 nPn만 구할 수 있다.</br>
string과 int를 적절히 사용하여 문제를 풀어보자. </br>
`set`과 같은 associative container는 `next_permutation` 함수를 사용할 수 없다.

```cpp
string numbers = "730";
set<int> numset;
sort(numbers.begin(), numbers.end()); // "037"

do{
    string buff = "";
    for(int i = 0; i < numbers.size(); i++)
    {
        buff += numbers[i];
        numset.insert(stoi(buff));
    }
}while(next_permutation(numbers.begin(), numbers.end()));

```

</br>

### 🌳 조합 
조합은 n개의 원소에서 r개의 원소를 뽑는 경우의 수를 의미한다.</br>
`prev_permutation`를 사용하기 위해서 컨테이너는 반드시 내림차순으로 정렬되어 있어야한다.</br>
[참고](https://mjmjmj98.tistory.com/38)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    vector<int> s{ 1, 2, 3, 4 };
    vector<int> temp{ 1, 1, 0, 0 };
 
    do {
        for (int i = 0; i < s.size(); ++i) {
            if (temp[i] == 1)
                cout << s[i] << ' ';
        }
        cout << endl;
    } while (prev_permutation(temp.begin(), temp.end()));
}
```

</br>

### 🌳 최대공약수와 최소공배수
[참고](https://dnf-lover.tistory.com/entry/C-%EC%95%BD%EC%88%98%EB%A5%BC-%EA%B5%AC%ED%95%98%EB%8A%94-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%95%BD%EC%88%98%EB%A5%BC-%EA%B5%AC%ED%95%98%EB%8A%94-%EB%8B%A4%EC%96%91%ED%95%9C-%EB%B0%A9%EB%B2%95%EA%B3%BC-%EC%86%8C%EC%9D%B8%EC%88%98%EB%B6%84%ED%95%B4)
```cpp
#include <vector>

using namespace std;

int gcd(int x, int y) { return x % y == 0 ? y : gcd(y, x % y); }
int lcm(int x, int y) { return x * y / gcd(x, y); }
int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++)
        answer = lcm(answer, arr[i]);
    return answer;
}
```

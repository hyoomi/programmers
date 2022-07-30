# programmers
programmers 문제풀이 및 코딩테스트를 위한 C++ 스킬 정리

</br>

---

</br>

## 컨테이너
### set
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

---

</br>

## 스킬
### 소수
에라토스테네스의 체를 이용하여 효율적으로 소수를 구할 수 있다. 에라토스테네스의 체의 원리는 이러하다. 2의 제곱부터 범위 내 2의 배수를 소수가 아닌 것으로 전부 체크하고, 3의 제곱부터 범위 내 3의 배수를 전부 체크한다. 이러한 방식으로 i의 제곱부터 범위 내 i의 배수를 전부 체크한다. 이때 i의 2배수부터 체크하는 것이 아닌 i의 제곱부터 체크하는 이유는 2*i는 이미 2의 배수를 체크할 때 확인되었고 3*i는 3의 배수를 체크할 때 확인되었기 때문에 이러한 방식으로 (i-1)*i까지는 이미 이전 단계에서 체크되었기 때문에 i*i부터 새로이 체크하는 것이다. i의 범위는 2부터 max값의 양의 제곱근(루트 max)까지이다. 전 범위를 탐색하지 않는 이유를 간단하게 설명해보겠다. max = a * b라고 나타냈을 때, a와 b중 작은 값은 반드시 max의 제곱근보다 작거나 같다. 따라서 max의 제곱근까지만 검사하면 max의 약수가 될 수 있는 모든 수를 검사할 수 있게 된다. 이해하기 쉽게 예시를 들어보겠다. 36을 (a * b)꼴로 나타내면 (2 * 18), (3 * 12), (4 * 9), (6 * 6)으로 나타낼 수 있고 (9 * 4), (12 * 3), (18 * 2)는 이미 검사된 것과 동일하기 때문에 굳이 검사하지 않아도 된다. 즉 36의 약수(2, 3, 4, 6, 9, 12, 18)를 찾기 위한 a의 범위는 2부터 36의 제곱근인 6까지이다.

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

### 순열
next_permutation함수를 사용하기 위해서 컨테이너는 반드시 오름차순으로 정렬되어 있어야한다.</br>
아래코드는 nP1부터 nPn까지 전부 구하는 과정이다. set은 중복을 허용하지 않기 때문에 유용하다.

```cpp
string numbers = "220730";
set<int> numset;
sort(numbers.begin(), numbers.end()); // "002237"

do{
    string buff = "";
    for(int i = 0; i < numbers.size(); i++)
    {
        buff += numbers[i];
        numset.insert(stoi(buff));
    }
}while(next_permutation(numbers.begin(), numbers.end()));
```

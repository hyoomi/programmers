# programmers
programmers 문제풀이 및 코딩테스트를 위한 C++ 스킬 정리

# 컨테이너
## set
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

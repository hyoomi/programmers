#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0; 
    int small = 0; 
    
    sort(people.begin(), people.end());

    while(true){
        if(people.size() < small + 1)
            break;
        
        if(*(people.end() - 1) + people[small] <= limit)
            small++;           
        
        people.pop_back(); 
        answer++;
    }
    
    return answer;
}


/*
위 반복문을 이렇게 간단하게 표현 할 수 있다.
아래 people은 내림차순 정렬이 되어있다.

for (int i = 0, j = N - 1; i <= j; i++) {
        if (people[i] + people[j] <= limit)
            j--;
        answer++;
}
*/

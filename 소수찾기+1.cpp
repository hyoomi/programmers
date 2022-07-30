#include <string>
#include <vector>
#include <algorithm>
#include <set>      

using namespace std;

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<char>());
    vector<int> prime(stoi(numbers) + 1, 1);
    set<int> numset;
    
    // 에라토스테네스의 체를 이용하여 소수 찾기
    prime[0] = 0; prime[1] = 0;
    for(int i = 2; i * i < prime.size(); i++){
        if(!prime[i]) continue;
        for(int j = i * i; j < prime.size(); j += i) prime[j] = 0;
    }
    
    // 순열 구하기
    sort(numbers.begin(), numbers.end());
    
    do{
        string buff = "";
        for(int i = 0; i < numbers.size(); i++)
        {
            buff += numbers[i];
            numset.insert(stoi(buff));
        }
    }while(next_permutation(numbers.begin(), numbers.end())); 

    for(int n: numset)
        if(prime[n]) answer++;

    return answer;
}

// 코드 개선

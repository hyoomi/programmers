#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

bool isPrime(int num){
    if (num < 2) return false;
	int a = (int)sqrt(num);
	for (int i = 2; i <= a; i++) if (num % i == 0) return false;
	return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> number;
    vector<string> strings;
    vector<int> integers;
    
    for(auto n : numbers){
        number.push_back(n - '0');
    }
    
    sort(number.begin(), number.end());
    for(int r = 1; r <= number.size(); r++){
        do
	    {
            string buff = "";
            for(int i = 0; i < r; i++)
            {
                buff += to_string(number[i]);
            }
        strings.push_back(buff);
        reverse(number.begin() + r, number.end());
	    }while(next_permutation(number.begin(),number.end())); 
    }
    
    for(auto s : strings)
        integers.push_back(stoi(s));
    
     sort(integers.begin(), integers.end());
    integers.erase(unique(integers.begin(), integers.end()), integers.end());
    
    for(auto i : integers)
        if(isPrime(i)) answer++;
          
    return answer;
}

// 사용된 스킬
// 소수구하기 (반복문 이외 훨씬 빠른 방법도 존재)
// nPr 순열 구하는 방법
// vector에서 중복된 값 없애는 방법

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;    
    bool div = false;    
    sort(arr.begin(), arr.end());
    int max = arr.back();
    
    for(int i = 2;i <= max;){
        for(int& num : arr){
            if(num % i) continue;
            num /= i;
            div = true;            
        }
        if(div) answer *= i;
        else i++; 
        div = false;
    }
    
    return answer;
}

// 아주 간단하게 최소공배수를 구하는 방법이 있다.

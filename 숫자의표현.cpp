#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum = 0;
    int low = 1;

    for(int i = 1; i <= n; i++){
        sum += i;        
        while(sum > n){
            sum -= low;
            low++;
        } 
        if(sum == n) answer++;
    }
    
    return answer;
}

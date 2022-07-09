#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int right = 12;
    int left = 10;
    
    for(int n : numbers){
        
        if(n == 0)
            n = 11;
        
        if(n % 3 == 0){
            answer += "R";
            right = n;
        }
        
        else if(n % 3 == 1){
            answer += "L";
            left = n;
        }
        
        else{
            
            int r = (right % 3 == 2) ? abs(right - n) / 3 - 1 : abs((right-1) / 3 - (n-1) / 3);
            int l = (left % 3 == 2) ? abs(left - n) / 3 - 1: abs((left-1) / 3 - (n-1) / 3);
            
            //cout << "오른손거리: " << r << " 왼손거리: " << l << endl;
            
            if(l == r){
                if(hand.compare("right")==0){
                    answer += "R";
                    right = n;
                }
                else{
                    answer += "L";
                    left = n;
                }
            }
            
            else if(r > l){
                answer += "L";
                left = n;
            }
            
            else{
                answer += "R";
                right = n;
            }                
        }
        //cout << "오른손: " << right << " 왼손: " << left << endl;
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; // 타이머
    queue<pair<int, int>> trucks; // <트럭 weight, 다리에 들어온 순간 time>
    int bridge = 0;

    for(const int& truck : truck_weights){      
        // 다리에 들어갈 수 있는지 검사
        if(weight >= bridge + truck){ 
            answer++;
            if(bridge_length == answer - trucks.front().second){
                bridge -= trucks.front().first;
                trucks.pop();
            }
            bridge += truck;
            trucks.push(pair<int, int>(truck, answer));
            continue;
        }
        // 트럭이 다리에서 나올 수 있는지 검사
        while(weight < bridge + truck){
            answer++;            
            if(bridge_length == answer - trucks.front().second){
                bridge -= trucks.front().first;
                trucks.pop();
            }
        }
        bridge += truck;
        trucks.push(pair<int, int>(truck, answer));    
    }
    
    while(!trucks.empty()){
        answer++;
        if(bridge_length == answer - trucks.front().second){
            bridge -= trucks.front().first;
            trucks.pop();
        }
    }
    
    return answer;
}

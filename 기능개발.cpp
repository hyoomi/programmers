#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> progress;
    queue<int> speed;
    
    for(int i = 0; i < progresses.size(); i++){
        progress.push(progresses[i]);
        speed.push(speeds[i]);
    }

    int buff;
    for(int day = 1; day < 100; day++){ 
        buff = 0;
        while(!progress.empty() && speed.front() * day >= 100 - progress.front()){
            buff++;
            progress.pop();
            speed.pop();           
        }
        if(buff) answer.push_back(buff);
        if(progress.empty()) break;
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int me;

bool IsBigger(const pair<int, int>& element){
    return me < element.first;
}

int solution(vector<int> priorities, int location) {
    vector<int> orders(priorities.size());     
    vector<pair<int, int>> queue;
        
    int order = 1; int order2;
    
    for(int i = 0; i < priorities.size(); i++){
        queue.push_back(pair<int, int>(priorities[i], i));
    }

    while(!queue.empty()){
        auto it = queue.begin();
        me = it->first;
        auto p = find_if(it, queue.end(), IsBigger);
        if(p != queue.end()){
            order2 = order + queue.end() - p;
            while(it != p){
                queue.push_back(queue[0]); 
                orders[it->second] = order2; 
                ++it; ++order2;
                queue.erase(queue.begin());
            }                        
        }else{
            orders[it->second] = order;            
            ++order; ++it;
            queue.erase(queue.begin());
        }               
    }
    return orders[location];
}

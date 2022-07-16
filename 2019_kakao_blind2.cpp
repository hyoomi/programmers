#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string s1; string s2;
    map<string, string> user;
    
    for(int i = 0; i < record.size(); i++){
        istringstream ss(record[i]);
        getline(ss, s1, ' ');
        if(s1 == "Enter"){
            getline(ss, s1, ' ');
            getline(ss, s2, ' ');
            
            user.insert({s1, s2});
            user.find(s1)->second = s2;
            
            answer.push_back(s1 + "님이 들어왔습니다.");
        }
        else if(s1 == "Leave"){
            getline(ss, s1, ' ');
            answer.push_back(s1 + "님이 나갔습니다.");
        }
        else if(s1 == "Change"){
            getline(ss, s1, ' ');
            getline(ss, s2, ' ');
            user.find(s1)->second = s2;
        }
    }
    
    for(auto it = answer.begin(); it != answer.end(); it++){
        string id = it->substr(0, it->find("님"));
        it->replace(0, it->find("님"), user[id]);
    }
    
    return answer;
}

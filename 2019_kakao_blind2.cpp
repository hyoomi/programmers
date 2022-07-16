#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string command;
    string uid; string uname;
    map<string, string> user;
    
    for(auto line: record){
        istringstream ss(line);
        getline(ss, command, ' ');

        if(command == "Leave"){
            getline(ss, uid, ' ');
            answer.push_back(uid + "님이 나갔습니다.");
        }
        else{
            getline(ss, uid, ' ');
            getline(ss, uname, ' ');
            user.find(uid)->second = uname;
            if(command == "Enter"){
                user.insert({uid, uname});
                answer.push_back(uid + "님이 들어왔습니다.");
            }
        }
    }
    
    for(auto it = answer.begin(); it != answer.end(); it++){
        string id = it->substr(0, it->find("님"));
        it->replace(0, it->find("님"), user[id]);
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> numbers;
    int num;
    stringstream stream;
    stream.str(s);
    while(stream >> num) numbers.push_back(num);

    sort(numbers.begin(), numbers.end());
    
    answer += to_string(numbers.front());
    answer += " ";
    answer += to_string(numbers.back());

    return answer;
}

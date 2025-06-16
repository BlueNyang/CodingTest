#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // 참가자와 완주자 sort
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    // 미완주 선수를 1명이므로, 달라진 부분 찾기
    for(int i = 0; i < completion.capacity(); i++){
        if ( completion[i] != participant[i])
            return participant[i];
    }
    return participant[participant.capacity() -1];
    
    
    
    //answer = participant[0];
    return answer;
}
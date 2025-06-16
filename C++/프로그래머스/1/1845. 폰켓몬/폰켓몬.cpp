#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


int solution(vector<int> nums)
{
    // size와 max를 지정
    int size = nums.size();
    int max = (int)(size / 2);
    
    // 순서 없는 map
    unordered_map<int,bool> m;
    
    // 우선 모두 true로 초기화
    for(int i = 0; i < size; i++){
        m.insert({nums[i], true});
    }
    
    // map 사이즈
    int answer = m.size();
    // map 사이즈가 max보다 크면 max값을 반환
    if(max < answer) answer = max;
    
    return answer;
}
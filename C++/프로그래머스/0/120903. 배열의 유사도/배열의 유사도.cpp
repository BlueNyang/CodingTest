#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int idx1 = 0, idx2 = 0;
    int count = 0;
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    while(idx1 < s1.size() && idx2 < s2.size()) {
        if(s1[idx1] == s2[idx2]) {
            count++;
            idx1++; 
            idx2++;
            continue;
        }
        
        if (s1[idx1] < s2[idx2]) idx1++;
        else idx2++;
    }
    
    return count;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    //bool answer = true;
    // 원본 vector 훼손을 방지하기 위해 복사
    vector<string> copied_phone_book(phone_book);
    
    // 순서대로 정렬
    sort(copied_phone_book.begin(), copied_phone_book.end());
    
    // 순서대로 정렬되었으므로, 현재 전화번호가 다음 전화번호로 시작하는지 확인
    // 현재 전화번호로 시작하지 않으면 접두사가 없는 것임.
    for (int i = 0; i < copied_phone_book.size() - 1; i++) {
        if (copied_phone_book[i + 1].find(copied_phone_book[i]) == 0) {
            return false;
        }
    }
    
    return true;
    //return answer;
}
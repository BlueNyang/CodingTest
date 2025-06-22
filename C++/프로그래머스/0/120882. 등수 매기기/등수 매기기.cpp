#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 학생 정보를 저장하는 구조체
typedef struct StudentInfo {
    // 원래 인덱스 값
    int s_index;
    // 평균값
    double avg_score;
    // 순위
    int rank;
    
    // 생성자
    StudentInfo(int idx, const vector<int>& scores)
        : s_index(idx), avg_score(0.0f), rank(0) {
        // 평균 점수 계산
        for(const auto& s: scores) {
            avg_score += s;
        }
        avg_score /= scores.size();
    }
};

// StudentInfo 타입 sort 비교함수
bool compare_student(const StudentInfo& a, const StudentInfo& b) {
    return a.avg_score > b.avg_score;
}

vector<int> solution(vector<vector<int>> score) {
    // 학생 vector
    vector<StudentInfo> students;
    
    // 점수 및 인덱스 값을 포함한 vector로 변환
    for (int i = 0; i < score.size(); i++) {
        students.emplace_back(i, score[i]);
    }
    
    // 점수로 정렬
    sort(students.begin(), students.end(), compare_student);
    
    // 1번째 학생을 1등
    students[0].rank = 1;
    // 순위 체크
    for(int i = 1; i < students.size(); i++) {
        // 이전 학생과 점수가 같으면 공동 순위
        if(students[i].avg_score == students[i - 1].avg_score)
            students[i].rank = students[i - 1].rank;
        // 아니면 현재 순회 중인 인덱스 값 + 1
        else
            students[i].rank = i + 1;
    }
    
    // 순위만 가져오는 vector. 미리 크기 지정
    vector<int> answer(students.size());
    // 학생 인덱스 값에 순위 할당
    for (const auto s: students) {
        answer[s.s_index] = s.rank;
    }
    
    return answer;
}
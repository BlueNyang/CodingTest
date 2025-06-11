#include <vector>
#include <algorithm>

using namespace std;

// dfs 알고리즘 사용.
// dfs 함수 하나만 사용할 수 있으나, 학습을 위한 Class 정의
// 특히, 재귀함 dfs의 이중 vector(2차원 배열)의 복사로 인한 메모리 오버헤드 방지
// 또한, 각 메서드의 인자를 줄여 가독성 향상을 꾀함
class AreaInfo {
public:
    // 생성자. 이미지 size를 받음.
    AreaInfo(int x, int y, vector<vector<int>> source): x_size(x), y_size(y), picture(source) {}
    // area(영역)의 크기들을 계산
    void cal_area_extent();
    // area 갯수와 가장 큰 영역의 칸 수를 return 해주는 메서드
    int get_number_of_area() const;
    int get_max_size_of_one_area() const;

private:
    int x_size;
    int y_size;
    // picture를 class에서 관리
    vector<vector<int>> picture;
    // 영역의 크기를 저장
    vector<int> area_extent;
    // 깊이 우선 탐색 알고리즘
    int dfs(int x, int y, int std_value);
};

// 1번 실행되므로, inline 함수로 구현.
// picture의 각 area의 크기를 탐색
inline void AreaInfo::cal_area_extent() {
    for (int y = 0; y < y_size; y++) {
        for (int x = 0; x < x_size; x++) {
            // 만약 이미 탐색했거나(-1), 비어있으면(0) pass(continue)
            if (picture[y][x] == 0 || picture[y][x] == -1) continue;
            area_extent.push_back(dfs(x, y, picture[y][x]));
        }
    }
}

// area의 갯수를 반환하는 메서드. inline 함수.
inline int AreaInfo::get_number_of_area() const {
    return area_extent.size();
}

// 가장 큰 area의 넓이(칸 수)를 반환하는 메서드. inline 함수
inline int AreaInfo::get_max_size_of_one_area() const {
    // algorithm.h의 max_element 사용.
    auto max_it = max_element(area_extent.begin(), area_extent.end());
    // iterator를 반환하므로 역참조하여 반환
    return *max_it;
}

// dfs 알고리즘을 수행하는 메서드.
// class에 data가 있으므로, parameter가 많이 필요하지 않음.
int AreaInfo::dfs(int x, int y, int std_value) {
    // 연결된 구역이 아니거나 이미 탐색했으면 탐색하지 않음.
    if (picture[y][x] != std_value) return 0;
    if (picture[y][x] == -1) return 0;
    
    // 탐색 처리
    picture[y][x] = -1;
    
    // 구역의 크기 구하기
    int count = 1;
    // picture를 벗어나지 않으면 탐색해보기
    if (x > 0) count += dfs(x - 1, y, std_value);
    if (y > 0) count += dfs(x, y - 1, std_value);
    if (x < x_size - 1) count += dfs(x + 1, y, std_value);
    if (y < y_size - 1) count += dfs(x, y + 1, std_value);
    
    // 구역의 크기 반환
    return count;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    // instance 생성
    AreaInfo area(m, n, picture);
    // 구역 탐색 실행
    area.cal_area_extent();
    
    // 정답 가져오기
    vector<int> answer(2);
    answer[0] = area.get_number_of_area();
    answer[1] = area.get_max_size_of_one_area();
    return answer;
}
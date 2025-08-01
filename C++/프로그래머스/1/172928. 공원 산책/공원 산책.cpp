#include <string>
#include <vector>
#include <algorithm>


using namespace std;

// 좌표 구조체
struct Pos {
    int x;
    int y;
    // 컴파일 타임 생성자
    constexpr Pos(int x = 0, int y = 0) noexcept : x(x), y(y) {}
    // 예외 없음(noexcept), 예상되는 이동 좌표 반환
    Pos move(const string& route) const noexcept {
        // direction 및 이동량 파싱
        char direction = route[0];
        int amount = stoi(route.substr(2));

        // 이동 결과를 반환
        switch(direction) {
            case 'N': return {x, y - amount};
            case 'S': return {x, y + amount};
            case 'W': return {x - amount, y};
            case 'E': return {x + amount, y};
            default: return *this;
        }
    }
};

/// 이동 유효성 검증
bool check_valid(Pos& curr, Pos& target, vector<string>& park) {
    // 맵 높이 및 폭
    const int park_h = static_cast<int>(park.size());
    const int park_w = static_cast<int>(park[0].size());
    
    // 경계 검증
    if (target.x < 0 || target.y < 0
        || target.x >= park_w || target.y >= park_h) {
        return false;
    }
    
    // 목표 지점 검증
    if (park[target.y][target.x] == 'X') {
        return false;
    }
    
    // 경로 검증
    if (curr.x == target.x) {
        const int from = min(curr.y, target.y);
        const int to = max(curr.y, target.y);
        for (int y = from; y <= to; ++y) {
            if (park[y][curr.x] == 'X') return false;
        }
    } else {
        const int from = min(curr.x, target.x);
        const int to = max(curr.x, target.x);
        for (int x = from; x <= to; ++x) {
            if (park[curr.y][x] == 'X') return false;
        }
    }
    
    return true;
}

// 시작 좌표 탐색
Pos find_start_pos(const vector<string>& park) noexcept {
    for (size_t y = 0; y < park.size(); y++) {
        for (size_t x = 0; x < park[y].size(); x++) {
            if (park[y][x] == 'S') {
                return {static_cast<int>(x), static_cast<int>(y)};
            }
        }
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    // 시작 좌표
    Pos curr = find_start_pos(park);
    
    for (const auto& r: routes) {
        Pos target = curr.move(r);
        if (check_valid(curr, target, park)) {
            curr = target;
        }
    }
    
    return {curr.y, curr.x};
}
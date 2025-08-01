#include <string>
#include <vector>

using namespace std;

// Point 구조체
struct Point {
    int x, y;
    constexpr Point(int x = 0, int y = 0) noexcept : x(x), y(y) {}
};

// 계산
vector<int> solution(vector<string> wallpaper) {
    // lu(left/up)은 최소값을 구해야 하므로, 최대값으로 초기화
    Point lu = {static_cast<int>(wallpaper.size()),
                static_cast<int>(wallpaper[0].size())};
    // rd(right/down)은 최대갓ㅂ을 구해야 하므로, (0, 0)으로 초기화
    Point rd;
    
    for (int x = 0; x < static_cast<int>(wallpaper.size()); x++) {
        for (int y = 0; y < static_cast<int>(wallpaper[0].size()); y++) {
            // 파일이 있는 곳만 체크
            if (wallpaper[x][y] == '#') {
                if (x < lu.x) lu.x = x;
                if (y < lu.y) lu.y = y;
                if (x > rd.x) rd.x = x;
                if (y > rd.y) rd.y = y;
            }
        }
    }
    
    // rd는 마지막 파일의 위치. 이를 포함해야 하므로 +1
    return {lu.x, lu.y, ++rd.x, ++rd.y};
}
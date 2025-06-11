import java.util.ArrayList;
import java.util.Collections;

class Solution {
    // 클래스 내 data
    private int[][] source;
    private int x_size, y_size;
    // 가변 크기 List
    private ArrayList<Integer> areaExtent;
    
    // 영역(area) 계산 메서드
    private void calculateAreaEntent() {
        for (int y = 0; y < y_size; y++) {
            for (int x = 0; x < x_size; x++) {
                // 이미 탐색(-1), 없음(0) == continue
                if (source[y][x] == -1 || source[y][x] == 0) continue;
                // 탐색이 된 경우 영역의 크기를 추가
                areaExtent.add(dfs(x, y, source[y][x]));
            }
        }
    }
    
    //DFS 알고리즘
    private int dfs(int x, int y, int stdValue) {
        // 이미 탐색했거나, 다른 색상(영역)이면 0 반환
        if (source[y][x] == -1) return 0;
        if (source[y][x] != stdValue) return 0;
        
        // 탐색 처리
        source [y][x] = -1;
        
        // 영역 크기 계산
        int count = 1;
        
        // 이어진 영역을 탐색
        if(x > 0) count += dfs(x - 1, y, stdValue);
        if(y > 0) count += dfs(x, y - 1, stdValue);
        if(x < x_size - 1) count += dfs(x + 1, y, stdValue);
        if(y < y_size - 1) count += dfs(x, y + 1, stdValue);
        
        // 크기 return
        return count;
    }
    
    public int[] solution(int m, int n, int[][] picture) {
        // class data에 적재
        source = picture;
        x_size = n;
        y_size = m;
        areaExtent = new ArrayList<>();
        
        // 계산
        calculateAreaEntent();

        int[] answer = new int[2];
        answer[0] = areaExtent.size();
        answer[1] = Collections.max(areaExtent);
        return answer;
    }
}
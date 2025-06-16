#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 음악을 struct로 선언
typedef struct song{
    int index;
    int play_num;
}Song;

// 편하게 사용하기 위해 typedef
typedef std::vector<Song> Songs;

// 정렬을 위한 compare 함수
bool cmpTP(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

// 정렬을 위한 compare 함수
bool cmpSL(Song& a, Song& b){
    return a.play_num > b.play_num;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // total_play는 string으로 찾고, int로 정렬해야하기 때문에
    // 나중에 정렬을 하고, 지금은 unordered_map 사용
    unordered_map<string, int> total_play;
    unordered_map<string,Songs> song_list;
    
    for(int i = 0; i < genres.size(); i++){
        Song song = {i, plays[i]};
        string g = genres[i];
        
        // total_play 카운트
        if(total_play.count(g) == 0) total_play.insert({g, 0});
        total_play[g] += song.play_num;
        
        // song_list 업데이트
        if(song_list.count(g) == 0) song_list.insert({g, {}});
        song_list[g].push_back(song);
    }
    
    // total_play를 vector로 전환하고 재생 수로 정렬
    vector<pair<string, int>> vec(total_play.begin(), total_play.end());
    sort(vec.begin(), vec.end(), cmpTP);
    
    // vector 순환
    for(const auto& v : vec){
        string g = v.first;
        // song_list
        vector<Song> s = song_list[g];
        // song_list 정렬(고유번호로 정렬)
        sort(s.begin(), s.end(), cmpSL);
        
        // 고유번호가 낮은(1번째) 노래 수록
        answer.push_back(s[0].index);
        if(s.size() > 1) answer.push_back(s[1].index);
    }
    
    return answer;
}
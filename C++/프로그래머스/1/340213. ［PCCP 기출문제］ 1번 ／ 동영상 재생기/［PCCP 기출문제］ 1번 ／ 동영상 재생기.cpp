#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

string formatting(int s) {
    if (s <= 0) return "00:00";
    
    int min = s / 60;
    
    int sec = s % 60;
    
    ostringstream oss;
    oss << setfill('0');
    oss << setw(2) << min << ":" << setw(2) << sec;
    
    return oss.str();
}

int get_seconds(string time) {
    size_t colons = 2;
    
    if (colons != string::npos) {
        try {
            int min = stoi(time.substr(0, colons));
            int sec = stoi(time.substr(colons+1));
            return min * 60 + sec;
        } catch (const invalid_argument& e) {
            return 0;
        } catch (const out_of_range& e) {
            return 0;
        }
    } else {
        return 0;
    }
}

int skip_op(int s_pos, int e_pos, int c_pos) {
    if (c_pos >= s_pos && c_pos <= e_pos) {
            return e_pos;
    }
    return c_pos;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int t_pos = get_seconds(pos);
    int t_op_start = get_seconds(op_start);
    int t_op_end = get_seconds(op_end);
    int t_video = get_seconds(video_len);
    
    
    t_pos = skip_op(t_op_start, t_op_end, t_pos);
    
    for (const string& command: commands) {
        if (command == "next") t_pos += 10;
        else if (command == "prev") t_pos -= 10;
        
        if (t_pos < 0) {
            t_pos = 0;
        }
        
        if (t_pos > t_video) {
            t_pos = t_video;
        }
        
        t_pos = skip_op(t_op_start, t_op_end, t_pos);
    }
    
    return formatting(t_pos);
}
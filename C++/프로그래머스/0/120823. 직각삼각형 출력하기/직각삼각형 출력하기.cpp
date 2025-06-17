#include <iostream>
#include <cstdio>
#include <cctype>
#include <type_traits>
#include <string>
#include <vector>

using namespace std;

// buffer 사이즈 (1MB)
constexpr int BUF_SIZE = 1 << 20;

class FastIO {
private:
    char input_buffer[BUF_SIZE];
    int read_idx, next_idx;
    bool __END_FLAG__;
    bool __GETLINE_FLAG__;

    char output_buffer[BUF_SIZE];
    int write_idx;

    inline char _read_char() {
        if (read_idx == next_idx) {
            next_idx = fread(input_buffer, 1, BUF_SIZE, stdin);
            if (next_idx == 0) {
                __END_FLAG__ = true;
                return 0;
            }
            read_idx = 0;
        }
        return input_buffer[read_idx++];
    }

    inline bool _is_blank(char c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t';
    }

    inline void _write_char(char c) {
        if (write_idx == BUF_SIZE) {
            _flush_output();
        }
        output_buffer[write_idx++] = c;
    }

    inline void _flush_output() {
        if (write_idx > 0) {
            fwrite(output_buffer, 1, write_idx, stdout);
            write_idx = 0;
        }
    }

    template<typename T>
    inline int _get_size(T n) {
        int ret = 1;
        
        for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
        return ret;
    }

public:
    FastIO() : read_idx(0), next_idx(0), __END_FLAG__(false), __GETLINE_FLAG__(false), write_idx(0) {}
    
    ~FastIO() {
        _flush_output();
    }
    explicit operator bool() const {
        return !__END_FLAG__;
    }
    
    inline char ReadChar() {
        char ret = _read_char();
        while (_is_blank(ret) && !__END_FLAG__) {
            ret = _read_char();
        }
        return ret;
    }

    template<typename T, typename std::enable_if_t<std::is_integral_v<T>>* = nullptr>
    inline T ReadInt() {
        T ret = 0;
        char cur = _read_char();
        bool is_negative = false;

        while (_is_blank(cur) && !__END_FLAG__) {
            cur = _read_char();
        }

        if (cur == '-') {
            is_negative = true;
            cur = _read_char();
        } else if (cur == '+') {
            cur = _read_char();
        }

        while (cur >= '0' && cur <= '9' && !__END_FLAG__) {
            ret = ret * 10 + (cur - '0');
            cur = _read_char();
        }
        
        if (__END_FLAG__) return is_negative ? -ret : ret;


        return is_negative ? -ret : ret;
    }

    inline std::string ReadString() {
        std::string ret;
        char cur = _read_char();
        while (_is_blank(cur) && !__END_FLAG__) {
            cur = _read_char();
        }
        while (!_is_blank(cur) && !__END_FLAG__ && cur != 0) {
            ret.push_back(cur);
            cur = _read_char();
        }
        
        if (cur == 0) __END_FLAG__ = true;
        return ret;
    }

    inline double ReadDouble() {
        return std::stod(ReadString());
    }

    inline std::string ReadLine() {
        std::string ret;
        char cur = _read_char();
        
        while (cur == '\n' && !__END_FLAG__) {
             cur = _read_char();
        }

        while (cur != '\n' && !__END_FLAG__ && cur != 0) {
            ret.push_back(cur);
            cur = _read_char();
        }

        if (cur == 0) __GETLINE_FLAG__ = true;
        return ret;
    }

    inline void WriteChar(char c) {
        _write_char(c);
    }

    template<typename T, typename std::enable_if_t<std::is_integral_v<T>>* = nullptr>
    inline void WriteInt(T n) {
        int sz = _get_size(n);
        if (write_idx + sz + (n < 0 ? 1 : 0) >= BUF_SIZE) {
            _flush_output();
        }
        if (n < 0) {
            _write_char('-');
            n = -n;
        }
        
        if (n == 0) {
            _write_char('0');
            return;
        }

        char temp_buffer[20];
        int temp_idx = 0;
        while (n > 0) {
            temp_buffer[temp_idx++] = (n % 10) + '0';
            n /= 10;
        }
        while (temp_idx > 0) {
            _write_char(temp_buffer[--temp_idx]);
        }
    }

    inline void WriteString(const std::string& s) {
        for (char c : s) {
            _write_char(c);
        }
    }

    inline void WriteDouble(double d) {
        WriteString(std::to_string(d));
    }

    FastIO& operator>>(char& i) {
        i = ReadChar();
        return *this;
    }

    FastIO& operator>>(std::string& i) {
        i = ReadString();
        return *this;
    }

    template<typename T, typename std::enable_if_t<std::is_arithmetic_v<T>>* = nullptr>
    FastIO& operator>>(T& i) {
        if constexpr (std::is_floating_point_v<T>) {
            i = ReadDouble();
        } else if constexpr (std::is_integral_v<T>) {
            i = ReadInt<T>();
        }
        return *this;
    }

    FastIO& operator<<(char i) {
        WriteChar(i);
        return *this;
    }

    FastIO& operator<<(const std::string& i) {
        WriteString(i);
        return *this;
    }

    FastIO& operator<<(const char* i) {
        WriteString(std::string(i));
        return *this;
    }

    template<typename T, typename std::enable_if_t<std::is_arithmetic_v<T>>* = nullptr>
    FastIO& operator<<(T i) {
        if constexpr (std::is_floating_point_v<T>) {
            WriteDouble(i);
        } else if constexpr (std::is_integral_v<T>) {
            WriteInt<T>(i);
        }
        return *this;
    }
};


int main(void) {
    // FastIO
    FastIO fio;
    
    int n;
    fio >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            fio << "*";
        }
        fio << "\n";
    }
    
    return 0;
}
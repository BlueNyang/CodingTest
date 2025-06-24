#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    // length of common
    int len = static_cast<int>(common.size());
    
    // check is arithmethical squence
    bool is_seq = common[2] - common[1] == common[1] - common[0];
    
    // Common Defference/Ratio
    int  c = is_seq ? common[1] - common[0] : common[1] / common[0];
    
    // return
    if (is_seq) return common[len - 1] + c;
    else        return common[len - 1] * c;
}
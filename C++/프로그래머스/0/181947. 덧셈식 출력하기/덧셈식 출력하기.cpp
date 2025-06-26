#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a;
    int b;
    cin >> a >> b;
    
    cout << a << " + " << b << " = " << (a + b) << endl;
    return 0;
}
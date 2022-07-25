#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<string> si;
    char buf[1024];
    for (int i = 0; i < 10; ++i) {
        sprintf(buf, "abc-%d", i);
        si.push(buf);
    }

    while (!si.empty()) {
        cout << si.top() << endl;
        si.pop();
    }
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Stack {
    int a[1000]; // 충분히 큰 배열 (정적)
    int top = 0;
public:
    void push(int x) { a[top++] = x; }
    int pop() { return a[--top]; }
};

int main() {
    string s; getline(cin, s);
    Stack st;
    int id = 1, out = 0;

    for (char c : s) {
        if (c == '(') {
            st.push(id);
            if (out++) cout << ' ';
            cout << id++;
        }
        else if (c == ')') {
            if (out++) cout << ' ';
            cout << st.pop();
        }
    }
    cout << '\n';
}

#include <iostream>
using namespace std;

class Stack {
    int a[100000];  // N 최대에 맞게 충분히 크게
    int top = 0;
public:
    void push(int x) { a[top++] = x; }
    int pop() { return a[--top]; }
    int peek() { return a[top - 1]; }
    bool empty() { return top == 0; }
    int size() { return top; }
};

int main() {
    int N; cin >> N;

    Stack st;
    int out = 0;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;

        while (!st.empty() && st.peek() <= x)
            st.pop();

        st.push(x);

        if (out++) cout << ' ';
        cout << st.size();
    }
    cout << '\n';
}

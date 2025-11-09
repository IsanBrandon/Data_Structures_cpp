#include <iostream>
using namespace std;

class Stack {
    int a[100000];
    int topIdx;
public:
    Stack() { topIdx = 0; }
    void push(int x) { a[topIdx++] = x; }
    int pop() { return a[--topIdx]; }
    int top() { return a[topIdx - 1]; }
    bool empty() { return topIdx == 0; }
    int size() { return topIdx; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, x;
    cin >> N;
    Stack st;

    for (int i = 0; i < N; i++) {
        cin >> x;
        while (!st.empty() && st.top() <= x)
            st.pop();
        st.push(x);
        cout << st.size();
        if (i != N - 1) cout << ' ';
    }
    cout << '\n';
}

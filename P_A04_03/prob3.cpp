#include <iostream>
#include <string>
using namespace std;

class Stack {
    char a[1000000];
    int top = 0;
public:
    void push(char x) { a[top++] = x; }
    void pop() { top--; }
    char peek() { return a[top - 1]; }
    int size() { return top; }
    char get(int i) { return a[i]; }
};

int main() {
    string N;
    int K;
    cin >> N >> K;

    Stack st;

    for (char d : N) {
        while (st.size() > 0 && K > 0 && st.peek() < d) {
            st.pop();
            K--;
        }
        st.push(d);
    }

    // 아직 K가 남았다면 뒤에서 제거
    while (K--) st.pop();

    for (int i = 0; i < st.size(); i++)
        cout << st.get(i);
    cout << '\n';
}

#include <iostream>
#include <string>
using namespace std;

class Stack {
    // 숫자(문자) 스택: 최대 자릿수만큼 할당
    char* a;
    int topIdx, cap;
public:
    Stack(int n) : a(new char[n]), topIdx(0), cap(n) {}
    ~Stack() { delete[] a; }
    void push(char c) { a[topIdx++] = c; }
    char top() const { return a[topIdx - 1]; }
    void pop() { --topIdx; }
    bool empty() const { return topIdx == 0; }
    int size() const { return topIdx; }
    const char* data() const { return a; }
    void shrink_by(int k) { topIdx -= k; } // 뒤에서 k개 잘라내기
};

int main() {
    string N;            // 예: "442311"
    int K;               // 예: 2
    if (!(cin >> N)) return 0;
    if (!(cin >> K)) return 0;

    Stack st((int)N.size());
    int removeLeft = K;

    for (char d : N) {
        while (!st.empty() && removeLeft > 0 && st.top() < d) {
            st.pop();
            --removeLeft;
        }
        st.push(d);
    }
    // 아직 덜 지웠으면 뒤에서 잘라냄
    if (removeLeft > 0) st.shrink_by(removeLeft);

    // 출력
    for (int i = 0; i < st.size(); ++i) cout << st.data()[i];
    cout << '\n';
    return 0;
}

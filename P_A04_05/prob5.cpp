#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

/* ---- 최소 스택 템플릿 (배열 기반) ---- */
template<typename T>
class Stack {
    T* a; int topIdx, cap;
    void grow() {
        int ncap = cap ? cap * 2 : 64;
        T* b = new T[ncap];
        for (int i = 0; i < topIdx; i++) b[i] = a[i];
        delete[] a; a = b; cap = ncap;
    }
public:
    Stack() : a(nullptr), topIdx(0), cap(0) {}
    ~Stack() { delete[] a; }
    bool empty() const { return topIdx == 0; }
    int  size()  const { return topIdx; }
    void push(const T& v) { if (topIdx == cap) grow(); a[topIdx++] = v; }
    T    top()   const { return a[topIdx - 1]; }
    T    pop() { return a[--topIdx]; }
};

/* ---- 유틸 ---- */
static inline bool is_number(const string& tk) {
    if (tk.empty()) return false;
    int i = 0; if (tk[0] == '-' && tk.size() > 1) i = 1; // 단항 마이너스(토큰으로 이미 결합된 경우)
    for (; i < (int)tk.size(); ++i) if (!isdigit((unsigned char)tk[i])) return false;
    return true;
}
static inline int precedence(char op) { // +,- :1,  *,/ :2
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1; // '(' 등
}

/* ---- (1) 중위 → 후위 변환 (공백 토큰 가정, 괄호 지원) ----
   규칙: 피연산자는 즉시 출력, 연산자는 스택 우선순위에 따라 pop 후 push,
   '('는 무조건 push, ')'가 오면 '('까지 pop하여 출력. :contentReference[oaicite:4]{index=4}
*/
string infix_to_postfix(const string& infix) {
    Stack<char> op;                 // 연산자 스택
    stringstream in(infix), out;    // 후위표기 출력
    string tk;
    while (in >> tk) {
        if (is_number(tk)) { out << tk << ' '; }                       // 피연산자 출력 :contentReference[oaicite:5]{index=5}
        else if (tk.size() == 1) {
            char c = tk[0];
            if (c == '(') { op.push(c); }
            else if (c == ')') {                                         // '('까지 pop 출력 :contentReference[oaicite:6]{index=6}
                while (!op.empty() && op.top() != '(') {
                    out << op.pop() << ' ';
                }
                if (op.empty()) throw runtime_error("Unmatched ')'");
                op.pop(); // '(' 버림
            }
            else { // 연산자
                while (!op.empty() && op.top() != '(' &&
                    precedence(op.top()) >= precedence(c)) {          // 우선순위 낮거나 같으면 pop 출력 :contentReference[oaicite:7]{index=7}
                    out << op.pop() << ' ';
                }
                op.push(c);
            }
        }
        else {
            throw runtime_error("Invalid token: " + tk);
        }
    }
    while (!op.empty()) {
        char c = op.pop();
        if (c == '(') throw runtime_error("Unmatched '('");
        out << c << ' ';
    }
    return out.str();
}

/* ---- (2) 후위표기 계산 ----
   알고리즘: 숫자는 push, 연산자를 만나면 rhs,lhs 순서로 pop하여 계산 후 push. :contentReference[oaicite:8]{index=8} */
long long eval_postfix(const string& postfix) {
    Stack<long long> st;
    stringstream in(postfix);
    string tk;
    while (in >> tk) {
        if (is_number(tk)) { st.push(stoll(tk)); }                      // 피연산자 push :contentReference[oaicite:9]{index=9}
        else if (tk.size() == 1) {
            if (st.size() < 2) throw runtime_error("Syntax Error");
            long long rhs = st.pop(), lhs = st.pop();                  // rhs 먼저 pop, 그 다음 lhs :contentReference[oaicite:10]{index=10}
            char op = tk[0];
            long long r = 0;
            switch (op) {
            case '+': r = lhs + rhs; break;
            case '-': r = lhs - rhs; break;
            case '*': r = lhs * rhs; break;
            case '/': r = lhs / rhs; break;                        // 정수 나눗셈 (수업 코드와 동일 제약) :contentReference[oaicite:11]{index=11}
            default: throw runtime_error("Unknown operator");
            }
            st.push(r);
        }
        else {
            throw runtime_error("Invalid token");
        }
    }
    if (st.size() != 1) throw runtime_error("Syntax Error: stack not singleton");
    return st.pop();
}

int main() {
    // 한 줄 입력: (1) 후위표기식 그대로 입력하거나 (2) 중위표기식 입력
    // 예1(후위): "12 3 + 4 *"        → 60
    // 예2(중위): "1 + 2 * ( 10 - 2 )" → 17  (먼저 후위로 변환)  :contentReference[oaicite:12]{index=12}
    string line;
    if (!getline(cin, line)) return 0;

    // 간단한 판별: 연산자/피연산자가 공백으로 구분되었다는 수업 가정에 맞춤. :contentReference[oaicite:13]{index=13}
    bool looks_infix = (line.find('(') != string::npos) || (line.find(')') != string::npos);

    string postfix = looks_infix ? infix_to_postfix(line) : line;
    cout << eval_postfix(postfix) << '\n';
}

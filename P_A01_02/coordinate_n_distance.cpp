#include <iostream>   // 입출력을 위한 헤더
#include <fstream>    // 파일 입출력을 위한 헤더
#include <cmath>      // sqrt 등 수학 함수를 위한 헤더
#include <iomanip>    // 출력 자리수 제어(fixed, setprecision)
using namespace std;

// 1) 점을 표현하는 구조체 정의
struct Point2D {
    int x;  // x 좌표
    int y;  // y 좌표
};

// 2) 두 점 사이의 거리 제곱을 계산하는 함수
//    비교할 때 sqrt를 매번 하지 않고 제곱 값으로만 비교 → 효율성↑
static inline long long dist2(const Point2D& a, const Point2D& b) {
    long long dx = static_cast<long long>(a.x) - static_cast<long long>(b.x);
    long long dy = static_cast<long long>(a.y) - static_cast<long long>(b.y);
    return dx * dx + dy * dy;  // 거리^2 = dx^2 + dy^2
}

int main() {
    // 3) 입력 파일 열기
    ifstream fin("input2.txt");     // input2.txt 파일에서 데이터 읽음
    if (!fin) {                     // 파일 열기 실패 시
        cerr << "input2.txt 파일을 열 수 없습니다.\n";
        return 1;                   // 비정상 종료
    }

    int n;                          // 점의 개수
    if (!(fin >> n) || n < 2) {     // 파일에서 n을 읽지 못하거나 n<2라면
        cerr << "유효하지 않은 점 개수입니다.\n";
        return 1;
    }

    // 4) 동적 배열 생성 (처음 용량은 4로 시작)
    int capacity = 4;
    Point2D* pts = new(nothrow) Point2D[capacity];  // new 실패 시 nullptr 반환
    if (!pts) {                   // 메모리 할당 실패
        cerr << "메모리 할당 실패\n";
        return 1;
    }

    // 5) 점들을 하나씩 입력받으면서 배열에 저장
    for (int i = 0; i < n; ++i) {
        // 만약 배열이 꽉 찼다면 용량(capacity)을 2배로 늘림
        if (i >= capacity) {
            int newCap = capacity * 2;
            Point2D* newArr = new(nothrow) Point2D[newCap];  // 새 배열 생성
            if (!newArr) {     // 메모리 재할당 실패 시
                cerr << "메모리 재할당 실패\n";
                delete[] pts;  // 기존 메모리 해제
                return 1;
            }
            // 기존 배열의 데이터를 새 배열로 복사 (포인터 산술 사용)
            for (int k = 0; k < capacity; ++k) {
                *(newArr + k) = *(pts + k);
            }
            delete[] pts;      // 기존 배열 메모리 해제 (garbage 방지)
            pts = newArr;      // 포인터를 새 배열로 교체
            capacity = newCap; // 용량 갱신
        }

        // 좌표 읽기
        Point2D p{};
        fin >> p.x >> p.y;     // 점의 (x, y) 입력
        if (!fin) {            // 입력 실패 시
            cerr << "점 좌표 입력 형식이 올바르지 않습니다.\n";
            delete[] pts;      // 메모리 해제 후 종료
            return 1;
        }
        *(pts + i) = p;        // pts[i] 대신 포인터 산술로 저장
    }
    fin.close();                // 파일 닫기

    // 6) 가장 멀리 떨어진 두 점 찾기 (모든 쌍 비교, O(n^2))
    long long bestD2 = -1;      // 현재까지의 최장 거리 제곱
    Point2D a{}, b{};           // 가장 멀리 떨어진 두 점
    for (int i = 0; i < n; ++i) {
        const Point2D& pi = *(pts + i);  // i번째 점
        for (int j = i + 1; j < n; ++j) {
            const Point2D& pj = *(pts + j); // j번째 점
            long long d2 = dist2(pi, pj);   // 거리 제곱 계산
            if (d2 > bestD2) {              // 더 먼 거리라면 갱신
                bestD2 = d2;
                a = pi;
                b = pj;
            }
        }
    }

    // 7) 결과 출력
    cout << a.x << ' ' << a.y << '\n';  // 첫 번째 점 좌표
    cout << b.x << ' ' << b.y << '\n';  // 두 번째 점 좌표
    cout << fixed << setprecision(3)    // 소수점 이하 3자리 고정
        << sqrt(static_cast<long double>(bestD2)) << '\n'; // 거리

    // 8) 동적 메모리 해제
    delete[] pts;
    return 0;   // 정상 종료
}

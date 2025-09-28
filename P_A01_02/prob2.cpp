#include <iostream>   // 입출력을 위한 헤더
#include <fstream>    // 파일 입출력을 위한 헤더
#include <cmath>      // sqrt 등 수학 함수를 위한 헤더
#include <iomanip>    // 출력 자리수 제어(fixed, setprecision)
using namespace std;

// 1) Structure representing a point (새로운 사용자 정의 자료형, 일종의 type을 만든 것)
struct Point2D {
    int x;  // 내부 멤버1
    int y;  // 내부 멤버2 
};

double dist2(const Point2D& a, const Point2D& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    ifstream fin("input2.txt");
    int n;
    fin >> n;       // read first line
    int capacity = 4;
    Point2D* pts = new Point2D[capacity];

    for (int i = 0; i < n; ++i) {

        if (i >= capacity) {
            int newCap = capacity * 2;
            Point2D* newArr = new Point2D[newCap];
            for (int k = 0; k < capacity; ++k) {
                *(newArr + k) = *(pts + k);
            }
            delete[] pts;       // Deallocate old array memory (avoid garbage)
            // pts가 가리키던 메모리 블록이 해제됨. 
            // 하지만 포인터 변수 pts 자체는 그냥 지역 변수라서 여전히 살아있음
            pts = newArr;       // 포인터 변수 newArr에 담겨있는 주소가 pts에 복사됨
            capacity = newCap;  // Update capacity
        }

        Point2D p{};
        fin >> p.x >> p.y;  // 점의 (x, y) 입력
        *(pts + i) = p;
    }

    fin.close();

    double bestD2 = -1.0;
    Point2D a{}, b{};

    for (int i = 0; i < n; ++i) {
        const Point2D& pi = *(pts + i);     // i번째 점
        for (int j = i + 1; j < n; ++j) {
            const Point2D& pj = *(pts + j); // j번째 점
            double d = dist2(pi, pj);        // 거리 제곱 계산
            if (d > bestD2) {
                bestD2 = d;
                a = pi;
                b = pj;
            }
        }
    }

    // 결과 출력
    cout << a.x << ' ' << a.y << '\n';
    cout << b.x << ' ' << b.y << '\n';
    cout << fixed << setprecision(3) << sqrt(bestD2) << '\n';

    delete[] pts;
    return 0;   // 정상 종료
}

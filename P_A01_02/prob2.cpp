#include <iostream>   // ������� ���� ���
#include <fstream>    // ���� ������� ���� ���
#include <cmath>      // sqrt �� ���� �Լ��� ���� ���
#include <iomanip>    // ��� �ڸ��� ����(fixed, setprecision)
using namespace std;

// 1) Structure representing a point (���ο� ����� ���� �ڷ���, ������ type�� ���� ��)
struct Point2D {
    int x;  // ���� ���1
    int y;  // ���� ���2 
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
            // pts�� ����Ű�� �޸� ����� ������. 
            // ������ ������ ���� pts ��ü�� �׳� ���� ������ ������ �������
            pts = newArr;       // ������ ���� newArr�� ����ִ� �ּҰ� pts�� �����
            capacity = newCap;  // Update capacity
        }

        Point2D p{};
        fin >> p.x >> p.y;  // ���� (x, y) �Է�
        *(pts + i) = p;
    }

    fin.close();

    double bestD2 = -1.0;
    Point2D a{}, b{};

    for (int i = 0; i < n; ++i) {
        const Point2D& pi = *(pts + i);     // i��° ��
        for (int j = i + 1; j < n; ++j) {
            const Point2D& pj = *(pts + j); // j��° ��
            double d = dist2(pi, pj);        // �Ÿ� ���� ���
            if (d > bestD2) {
                bestD2 = d;
                a = pi;
                b = pj;
            }
        }
    }

    // ��� ���
    cout << a.x << ' ' << a.y << '\n';
    cout << b.x << ' ' << b.y << '\n';
    cout << fixed << setprecision(3) << sqrt(bestD2) << '\n';

    delete[] pts;
    return 0;   // ���� ����
}

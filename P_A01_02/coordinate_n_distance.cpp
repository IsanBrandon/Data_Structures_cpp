#include <iostream>   // ������� ���� ���
#include <fstream>    // ���� ������� ���� ���
#include <cmath>      // sqrt �� ���� �Լ��� ���� ���
#include <iomanip>    // ��� �ڸ��� ����(fixed, setprecision)
using namespace std;

// 1) ���� ǥ���ϴ� ����ü ����
struct Point2D {
    int x;  // x ��ǥ
    int y;  // y ��ǥ
};

// 2) �� �� ������ �Ÿ� ������ ����ϴ� �Լ�
//    ���� �� sqrt�� �Ź� ���� �ʰ� ���� �����θ� �� �� ȿ������
static inline long long dist2(const Point2D& a, const Point2D& b) {
    long long dx = static_cast<long long>(a.x) - static_cast<long long>(b.x);
    long long dy = static_cast<long long>(a.y) - static_cast<long long>(b.y);
    return dx * dx + dy * dy;  // �Ÿ�^2 = dx^2 + dy^2
}

int main() {
    // 3) �Է� ���� ����
    ifstream fin("input2.txt");     // input2.txt ���Ͽ��� ������ ����
    if (!fin) {                     // ���� ���� ���� ��
        cerr << "input2.txt ������ �� �� �����ϴ�.\n";
        return 1;                   // ������ ����
    }

    int n;                          // ���� ����
    if (!(fin >> n) || n < 2) {     // ���Ͽ��� n�� ���� ���ϰų� n<2���
        cerr << "��ȿ���� ���� �� �����Դϴ�.\n";
        return 1;
    }

    // 4) ���� �迭 ���� (ó�� �뷮�� 4�� ����)
    int capacity = 4;
    Point2D* pts = new(nothrow) Point2D[capacity];  // new ���� �� nullptr ��ȯ
    if (!pts) {                   // �޸� �Ҵ� ����
        cerr << "�޸� �Ҵ� ����\n";
        return 1;
    }

    // 5) ������ �ϳ��� �Է¹����鼭 �迭�� ����
    for (int i = 0; i < n; ++i) {
        // ���� �迭�� �� á�ٸ� �뷮(capacity)�� 2��� �ø�
        if (i >= capacity) {
            int newCap = capacity * 2;
            Point2D* newArr = new(nothrow) Point2D[newCap];  // �� �迭 ����
            if (!newArr) {     // �޸� ���Ҵ� ���� ��
                cerr << "�޸� ���Ҵ� ����\n";
                delete[] pts;  // ���� �޸� ����
                return 1;
            }
            // ���� �迭�� �����͸� �� �迭�� ���� (������ ��� ���)
            for (int k = 0; k < capacity; ++k) {
                *(newArr + k) = *(pts + k);
            }
            delete[] pts;      // ���� �迭 �޸� ���� (garbage ����)
            pts = newArr;      // �����͸� �� �迭�� ��ü
            capacity = newCap; // �뷮 ����
        }

        // ��ǥ �б�
        Point2D p{};
        fin >> p.x >> p.y;     // ���� (x, y) �Է�
        if (!fin) {            // �Է� ���� ��
            cerr << "�� ��ǥ �Է� ������ �ùٸ��� �ʽ��ϴ�.\n";
            delete[] pts;      // �޸� ���� �� ����
            return 1;
        }
        *(pts + i) = p;        // pts[i] ��� ������ ����� ����
    }
    fin.close();                // ���� �ݱ�

    // 6) ���� �ָ� ������ �� �� ã�� (��� �� ��, O(n^2))
    long long bestD2 = -1;      // ��������� ���� �Ÿ� ����
    Point2D a{}, b{};           // ���� �ָ� ������ �� ��
    for (int i = 0; i < n; ++i) {
        const Point2D& pi = *(pts + i);  // i��° ��
        for (int j = i + 1; j < n; ++j) {
            const Point2D& pj = *(pts + j); // j��° ��
            long long d2 = dist2(pi, pj);   // �Ÿ� ���� ���
            if (d2 > bestD2) {              // �� �� �Ÿ���� ����
                bestD2 = d2;
                a = pi;
                b = pj;
            }
        }
    }

    // 7) ��� ���
    cout << a.x << ' ' << a.y << '\n';  // ù ��° �� ��ǥ
    cout << b.x << ' ' << b.y << '\n';  // �� ��° �� ��ǥ
    cout << fixed << setprecision(3)    // �Ҽ��� ���� 3�ڸ� ����
        << sqrt(static_cast<long double>(bestD2)) << '\n'; // �Ÿ�

    // 8) ���� �޸� ����
    delete[] pts;
    return 0;   // ���� ����
}

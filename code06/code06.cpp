#include <iostream>
using namespace std;

struct Point2D {
	double x, y;
};

Point2D computeCenter(Point2D* pts, int k);

int main() {
	Point2D points[10];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> points[i].x >> points[i].y;

	Point2D center = computeCenter(points, n);
	cout << center.x << " " << center.y << endl;
	return 0;
}

Point2D computeCenter(Point2D* pts, int k) {
	Point2D c;
	c.x = c.y = 0;
	for (int i = 0; i < k; i++) {
		c.x += (*(pts + i)).x;
		c.y += (pts + i)->y;
	}
	c.x /= k;
	c.y /= k;
	return c;
}
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n;
    cin >> n;

    ifstream fin("lucky_numbers.txt");
    int x;
    while (fin >> x) {
        if (x == n) {
            cout << "yes";
            return 0;
        }
    }
    cout << "no";
    return 0;
}

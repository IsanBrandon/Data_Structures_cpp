#include <iostream>      // ǥ�� �����
#include <fstream>       // ���� �����
#include <string>        // std::string
#include <unordered_set> // ���� �ߺ� üũ
#include <vector>        // ��� ���� ����
using namespace std;

// read files -> extract each words -> checking length and is_overlap -> append -> print (top first print)

int main() {
    // read input4.txt file
    ifstream fin("C:\\Users\\82107\\OneDrive\\Desktop\\Cpp\\data_structures\\input4.txt");
    if (!fin) {
        cerr << "Couldn't read the file" << endl;
        return 1;
    }

    // 2) �ܾ� �ߺ� ���θ� üũ�� ���� + ���� ������ ����
	unordered_set<string> seen; // �ߺ� üũ�� ����
	vector<string> ordered;     // �ּ� ���� ���� �����

    // 3) ���� ������ �ܾ� �б�
    string token;
    while (fin >> token) {
        // 4) ���̰� 2 �̸��̸� ����
        if (token.size() < 2) continue;

		// 5) ó�� ���� �ܾ��� ���հ� ���Ϳ� ����
        if (seen.find(token) == seen.end()) {
			// ���տ� ������
            seen.insert(token);   // ���տ� �߰�
			ordered.push_back(token); // ���Ϳ� �߰�
        }
    }
    
    fin.close();

	// 6) ���: �Է� ������� �� �ٿ� �ϳ��� ���
    for (const string& w : ordered) {   // auto: compiler�� type�� �ڵ� �߷� (words�� vector<string>�̹Ƿ� ���� Ÿ���� string�Դϴ�. ���� w�� Ÿ���� const string&���� �߷е˴ϴ�.)
        cout << w << '\n';          // ���Ҹ� �������� �ʰ� ������ �����մϴ�. �� ���������� �����մϴ�.
    }

    // words ������ ��� ����(string)�� �ϳ��� �����ͼ� ������ ���� w�� ���, �� ���� ����Ѵ�.
    // ���� ��� ����(&)�� ����, ���� ������ ���� const�� ���� �ڵ�� �����ϰ� ȿ�����Դϴ�.

    return 0; 
}
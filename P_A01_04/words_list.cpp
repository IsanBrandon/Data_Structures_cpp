#include <iostream>   // ������� ���� ���
#include <fstream>    // ���� ������� ���� ���
#include <string>     // ���ڿ�
#include <vector>     // ���� �迭
#include <set>        // �ߺ� üũ��
#include <iomanip>    // ��� �ڸ��� ����(fixed, setprecision)
using namespace std;

// read files -> extract each words -> checking length and is_overlap -> append -> print (top first print)

int main() {
    // read input4.txt file
    ifstream fin("C:\\Users\\82107\\OneDrive\\Desktop\\Cpp\\data_structures\\input4.txt");
    if (!fin.is_open()) {
        cerr << "Couldn't read the file" << endl;
        return 1;
    }

    vector<string> words;   // �ܾ� ���� �迭
    set<string> seen;
    string word;

    while (fin >> word) {   // ���Ͽ��� �ܾ� �ϳ��� �б�
        if (word.length() >= 2) {                   // ���̰� 2 �̻��� ���� ����
            if (seen.find(word) == seen.end()) {    // �ߺ��� �ƴϸ�
                // ���� �������� ���� �ܾ���
                words.push_back(word);              // �迭�� ����
                seen.insert(word);                  // ���տ� ���
            }
        }
    }
    
    fin.close();

    // ����� �ܾ� ���
    cout << "����� �ܾ��:" << endl;
    for (const auto& w : words) {   // auto: compiler�� type�� �ڵ� �߷� (words�� vector<string>�̹Ƿ� ���� Ÿ���� string�Դϴ�. ���� w�� Ÿ���� const string&���� �߷е˴ϴ�.)
        cout << w << endl;          // ���Ҹ� �������� �ʰ� ������ �����մϴ�. �� ���������� �����մϴ�.
    }

    // words ������ ��� ����(string)�� �ϳ��� �����ͼ� ������ ���� w�� ���, �� ���� ����Ѵ�.
    // ���� ��� ����(&)�� ����, ���� ������ ���� const�� ���� �ڵ�� �����ϰ� ȿ�����Դϴ�.

    return 0; 
}
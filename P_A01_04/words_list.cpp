#include <iostream>   // 입출력을 위한 헤더
#include <fstream>    // 파일 입출력을 위한 헤더
#include <string>     // 문자열
#include <vector>     // 동적 배열
#include <set>        // 중복 체크용
#include <iomanip>    // 출력 자리수 제어(fixed, setprecision)
using namespace std;

// read files -> extract each words -> checking length and is_overlap -> append -> print (top first print)

int main() {
    // read input4.txt file
    ifstream fin("C:\\Users\\82107\\OneDrive\\Desktop\\Cpp\\data_structures\\input4.txt");
    if (!fin.is_open()) {
        cerr << "Couldn't read the file" << endl;
        return 1;
    }

    vector<string> words;   // 단어 저장 배열
    set<string> seen;
    string word;

    while (fin >> word) {   // 파일에서 단어 하나씩 읽기
        if (word.length() >= 2) {                   // 길이가 2 이상일 때만 저장
            if (seen.find(word) == seen.end()) {    // 중복이 아니면
                // 아직 등장하지 않은 단어라면
                words.push_back(word);              // 배열에 저장
                seen.insert(word);                  // 집합에 기록
            }
        }
    }
    
    fin.close();

    // 저장된 단어 출력
    cout << "저장된 단어들:" << endl;
    for (const auto& w : words) {   // auto: compiler가 type을 자동 추론 (words는 vector<string>이므로 원소 타입은 string입니다. 따라서 w의 타입은 const string&으로 추론됩니다.)
        cout << w << endl;          // 원소를 복사하지 않고 참조로 접근합니다. → 성능적으로 유리합니다.
    }

    // words 벡터의 모든 원소(string)를 하나씩 꺼내와서 참조로 변수 w에 담고, 그 값을 출력한다.
    // 복사 대신 참조(&)를 쓰고, 수정 방지를 위해 const를 붙인 코드라서 안전하고 효율적입니다.

    return 0; 
}
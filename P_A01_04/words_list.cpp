#include <iostream>      // 표준 입출력
#include <fstream>       // 파일 입출력
#include <string>        // std::string
#include <unordered_set> // 빠른 중복 체크
#include <vector>        // 출력 순서 유지
using namespace std;

// read files -> extract each words -> checking length and is_overlap -> append -> print (top first print)

int main() {
    // read input4.txt file
    ifstream fin("C:\\Users\\82107\\OneDrive\\Desktop\\Cpp\\data_structures\\input4.txt");
    if (!fin) {
        cerr << "Couldn't read the file" << endl;
        return 1;
    }

    // 2) 단어 중복 여부를 체크할 집합 + 순서 저장할 벡터
	unordered_set<string> seen; // 중복 체크용 집합
	vector<string> ordered;     // 최소 등장 순서 저장용

    // 3) 공백 단위로 단어 읽기
    string token;
    while (fin >> token) {
        // 4) 길이가 2 미만이면 무시
        if (token.size() < 2) continue;

		// 5) 처음 나온 단어라면 집합과 벡터에 저장
        if (seen.find(token) == seen.end()) {
			// 집합에 없으면
            seen.insert(token);   // 집합에 추가
			ordered.push_back(token); // 벡터에 추가
        }
    }
    
    fin.close();

	// 6) 출력: 입력 순서대로 한 줄에 하나씩 출력
    for (const string& w : ordered) {   // auto: compiler가 type을 자동 추론 (words는 vector<string>이므로 원소 타입은 string입니다. 따라서 w의 타입은 const string&으로 추론됩니다.)
        cout << w << '\n';          // 원소를 복사하지 않고 참조로 접근합니다. → 성능적으로 유리합니다.
    }

    // words 벡터의 모든 원소(string)를 하나씩 꺼내와서 참조로 변수 w에 담고, 그 값을 출력한다.
    // 복사 대신 참조(&)를 쓰고, 수정 방지를 위해 const를 붙인 코드라서 안전하고 효율적입니다.

    return 0; 
}
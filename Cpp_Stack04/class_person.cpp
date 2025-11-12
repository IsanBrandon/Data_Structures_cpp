#include <iostream>
#include <string>
using namespace std;

// 클래스는 사용자 정의 데이터 유형으로, 데이터 멤버와 멤버 함수를 가짐
class Person {
public:
	string name;
	int age;

	void print() {
		cout << "Hi, my name is " << name << " and I am " << age << " years old." << endl;
	}
};

int main() {
	Person person1;
	person1.name = "Alice";
	person1.age = 30;

	person1.print();

	Person* ptr_person = new Person;
	ptr_person->name = "Bob";
	ptr_person->age = 24;

	ptr_person->print();

	return 0;
}


// 생성자
class Person {
public:
	string name;
	int age;

	Person() {}	// default 생성자
	Person(string name, int age) : name(name), age(age) {}

	void print() {
		cout << "Hi, my name is " << name << " and I am " << age << " years old." << endl;
	}
};

int main() {
	Person person1("Alice", 30);
	person1.print();

	Person* ptr_person = new Person("Bob", 24);
	ptr_person->print();

	return 0; 
}

// 접근 지정자: public, private
class Person {
private:
	string name;
	int age;

public:
	Person() {}
	Person(string name, int age) : name(name), age(age) {}

	void print() {
		cout << "Hi, my name is " << name << " and I am " << age << " years old." << endl;
	}
};

int main() {
	Person person1("Alice", 30);
	person1.age = 20; // 오류: 'age'는 private 멤버이므로 접근 불가
	person1.print();

	Person* ptr_person = new Person("Bob", 24);
	ptr_person->name = "Henry"; // 오류: 'name'은 private 멤버이므로 접근 불가
	ptr_person->print();

	return 0;
}
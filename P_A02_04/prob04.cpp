#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

struct Person {
    string name;
    string address;
    string phone;
    string email;
    string web;
};

vector<Person> directory;

// ������ 1���� �ܼ� �и�
vector<string> split_line(string& line, char delimiter) {
    vector<string> tokens;
    stringstream sstream(line);
    string str;
    while (getline(sstream, str, delimiter)) tokens.push_back(str);
    return tokens;
}

// �յ� ���� ���� (���� ����)
string trim(string s) {
    int L = (int)s.size();
    int i = 0, j = L - 1;
    while (i < L && isspace((unsigned char)s[i])) ++i;
    while (j >= 0 && isspace((unsigned char)s[j])) --j;
    if (i <= j) return s.substr(i, j - i + 1);
    return "";
}

// TSV �ε�: address.tsv (�� ��: name \t address \t phone \t email \t web)
void load_data(const string& file_name) {
    ifstream infile(file_name);
    string line;
    while (getline(infile, line)) {
        string tmp = line; // split_line�� ��-const ������ �����Ƿ� ���纻 ���
        vector<string> t = split_line(tmp, '\t');
        if (t.size() < 5) continue; // �ּ� 5�ʵ� ���
        Person p;
        p.name = t[0];
        p.address = t[1];
        p.phone = t[2];
        p.email = t[3];
        p.web = t[4];
        directory.push_back(p);
    }
}

// TSV ����
void save_data(const string& file_name) {
    ofstream out(file_name);
    for (auto& p : directory) {
        out << p.name << '\t'
            << p.address << '\t'
            << p.phone << '\t'
            << p.email << '\t'
            << p.web << '\n';
    }
}

// �� ��� ��� (���� ���� ����)
void print_person(const Person& p) {
    cout << p.name << ":\n";
    cout << "    Address: " << p.address << ":\n";
    cout << "    Phone: " << p.phone << ":\n";
    cout << "    Email: " << p.email << ":\n";
    cout << "    Web: " << p.web << ":\n";
}

// ��ü ���
void list_directory() {
    for (auto& p : directory) print_person(p);
}

// �̸����� ù ��ġ �ε���(�κ� ����)
int find_index_by_name(const string& key) {
    for (int i = 0; i < (int)directory.size(); ++i) {
        if (directory[i].name.find(key) != string::npos) return i;
    }
    return -1;
}

// �߰�: �μ��� ������ 5�ʵ� �����Ѵٰ� ���� (name \t address \t phone \t email \t web)
void add_person(const string& args) {
    string tmp = args;
    vector<string> t = split_line(tmp, '\t');
    if (t.size() < 5) return;
    Person p;
    p.name = trim(t[0]);
    p.address = trim(t[1]);
    p.phone = trim(t[2]);
    p.email = trim(t[3]);
    p.web = trim(t[4]);
    directory.push_back(p);
}

// ����: �̸� �κ� �������� ù �׸� ����
void delete_person(const string& key) {
    int idx = find_index_by_name(key);
    if (idx != -1) directory.erase(directory.begin() + idx);
}

// �� ��� ã�� ���
void find_person(const string& key) {
    int idx = find_index_by_name(key);
    if (idx != -1) print_person(directory[idx]);
}

// AND �˻�: ��� term�� (�̸�/�ּ�/��ȭ/�̸���/�� ��) ��򰡿� ���ԵǾ�� ��
bool matches_all_terms(const Person& p, const vector<string>& terms) {
    for (auto& t : terms) {
        if (t.empty()) continue;
        bool hit =
            (p.name.find(t) != string::npos) ||
            (p.address.find(t) != string::npos) ||
            (p.phone.find(t) != string::npos) ||
            (p.email.find(t) != string::npos) ||
            (p.web.find(t) != string::npos);
        if (!hit) return false;
    }
    return true;
}

void search_directory_and(const vector<string>& terms) {
    for (auto& p : directory) {
        if (matches_all_terms(p, terms)) print_person(p);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    load_data("address.tsv");

    string line;
    while (true) {
        cout << "$ ";
        if (!getline(cin, line)) break;
        string cmdline = trim(line);
        if (cmdline.empty()) continue;

        // command ����
        int sp = (int)cmdline.find(' ');
        string command = (sp == -1) ? cmdline : cmdline.substr(0, sp);
        string arguments = (sp == -1) ? "" : cmdline.substr(sp + 1);

        if (command == "exit") {
            break;
        }
        else if (command == "list") {
            list_directory();
        }
        else if (command == "find") {
            string key = trim(arguments);
            if (!key.empty()) find_person(key);
        }
        else if (command == "add") {
            // add ������ ��ü ���ڿ��� �� ���� 5�ʵ�� ����
            add_person(arguments);
        }
        else if (command == "delete") {
            string key = trim(arguments);
            if (!key.empty()) delete_person(key);
        }
        else if (command == "save") {
            string path = trim(arguments);
            if (path.empty()) path = "address.tsv";
            save_data(path);
        }
        else if (command == "search") {
            // ��: search Cor & com & CA
            string q = trim(arguments);
            if (q.empty()) continue;
            string tmp = q;
            vector<string> raw = split_line(tmp, '&');
            vector<string> terms;
            for (auto& t : raw) {
                string tt = trim(t);
                if (!tt.empty()) terms.push_back(tt);
            }
            if (!terms.empty()) search_directory_and(terms);
        }
        // �� �� ����� ����
    }
    return 0;
}

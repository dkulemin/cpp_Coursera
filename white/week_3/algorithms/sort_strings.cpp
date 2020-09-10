#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool LowStringCompare(string str1, string str2) {
    for (auto& c : str1) {
        c = tolower(c);
    }
    for (auto& c : str2) {
        c = tolower(c);
    }
    return (str1 < str2);
}

void Print(const vector<string>& vec) {
    for (const auto& v : vec) {
        cout << v << ' ';
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> strings(n);
    for (auto& str : strings) {
        cin >> str;
    }
    sort(begin(strings), end(strings), LowStringCompare);
    Print(strings);
    cout << endl;

    return 0;
}
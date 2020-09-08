#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    set<string> str_set;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        str_set.insert(s);
    }
    cout << str_set.size() << endl;

    return 0;
}
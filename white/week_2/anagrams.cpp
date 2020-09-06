#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& s) {
    map<char, int> result;
    for (auto i : s) {
        ++result[i];        
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    while (n > 0)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (BuildCharCounters(s1) == BuildCharCounters(s2)) {
            cout << "YES" << endl;
        } else
        {
            cout << "NO" << endl;
        }
        n--;
    }
    return 0;
}
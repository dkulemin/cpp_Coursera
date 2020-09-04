#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int first = -1;
    int second = -1;
    int count = 0;
    int i = 0;
    for (auto c: s) {
        if (c == 'f') 
        {
            count++;
            if (count == 1) 
            {
                first = i;
            } else if (count == 2) {
                second = i;
                break;
            }
        }
        i++;
    }
    if (second != -1) {
        cout << second << endl;
    } else if (first != -1)
    {
        cout << -1 << endl;
    } else
    {
        cout << -2 << endl;
    }   
    return 0;
}
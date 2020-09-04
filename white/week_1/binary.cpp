#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> b;
    cin >> n;
    while (n > 0)
    {
        b.push_back(n % 2);
        n /= 2;
    }
    for (int i = b.size() - 1; i >= 0; --i) {
        cout << b[i];
    }
    return 0;
}
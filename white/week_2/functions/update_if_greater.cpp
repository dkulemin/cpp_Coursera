#include <iostream>

using namespace std;

void UpdateIfGreater(int first, int& second) {
    if (first > second) {
        second = first;
    }
}

int main() {
    int x, y;
    cin >> x >> y;
    UpdateIfGreater(x, y);
    //cout << y << endl;
    return 0;
}
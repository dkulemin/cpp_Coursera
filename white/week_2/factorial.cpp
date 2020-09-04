#include <iostream>

using namespace std;

int Factorial(int n) {
    int result = 1;
    if (n < 0) {
        return 1;
    }
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << Factorial(n) << endl;
    return 0;
}
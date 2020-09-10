#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void Print(const vector<int>& vec) {
    for (const auto& v : vec) {
        cout << v << ' ';
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (auto& num : numbers) {
        cin >> num;
    }
    sort(begin(numbers), end(numbers), [](int i, int j){ return abs(i) < abs(j); });
    Print(numbers);
    return 0;
}
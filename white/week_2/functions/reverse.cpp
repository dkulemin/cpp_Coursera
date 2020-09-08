#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
    for (size_t i = 0; i < v.size() /2; ++i) {
        int tmp = v[i];
        v[i] = v[v.size() - i - 1];
        v[v.size() - i - 1] = tmp;
    }
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2, 7};
    Reverse(numbers);
    for (auto n : numbers) {
        cout << n << ' ';
    }
    cout << endl;
    return 0;
}
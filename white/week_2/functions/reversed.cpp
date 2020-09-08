#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
    int n = v.size();
    vector<int> v_copy;
    for (int i = n - 1; i >= 0; --i) {
        v_copy.push_back(v[i]);
    }
    return v_copy;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    numbers = Reversed(numbers);
    for (auto n : numbers) {
        cout << n << ' ';
    }
    cout << endl;
    return 0;
}
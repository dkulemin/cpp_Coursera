#include <iostream>
#include <vector>

using namespace std;

int Mean(const vector<int>& v) {
    int result = 0;
    for (auto i : v) {
        result += i;
    }
    result /= v.size();
    return result;
}

void PrintVector(const vector<int>& v) {
    for (auto i : v) {
        cout << i << ' ';
    }
}

void PrintHighTemps(const vector<int>& temps) {
    int mean = Mean(temps);
    int count_days = 0;
    vector<int> result;
    for (size_t i = 0; i < temps.size(); ++i) {
        if (temps[i] > mean) {
            count_days++;
            result.push_back(i);
        }
    }
    cout << count_days << endl;
    PrintVector(result);
}

int main() {
    int n;
    cin >> n;
    vector<int> temps(n);
    for (auto& t : temps) {
        cin >> t;
    }
    PrintHighTemps(temps);
    return 0;
}
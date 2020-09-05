#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintVector(const vector<string>& v) {
    cout << v.size() << ' ';
    for (auto i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    const vector<int> DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //days_in_month.insert(end(days_in_month), begin(days_in_month), end(days_in_month));
    //PrintIntVector(days_in_month);
    int current_month = 0;
    vector<vector<string>> duty_list(31);
    int q;
    cin >> q;
    while (q > 0)
    {
        string command;
        cin >> command;
        if (command == "NEXT") {
            current_month++;
            if (current_month > 11) {
                current_month = 0;
            }
            int tmp = DAYS_IN_MONTH[current_month];
            for (int day = tmp; day < duty_list.size(); ++day) {
                duty_list[tmp - 1].insert(end(duty_list[tmp - 1]), begin(duty_list[day]), end(duty_list[day]));
            }
            duty_list.resize(tmp);
        } else if (command == "DUMP")
        {
            int i;
            cin >> i;
            PrintVector(duty_list[i - 1]);
        } else if (command == "ADD")
        {
            int i;
            string s;
            cin >> i >> s;
            duty_list[i - 1].push_back(s);
        }
        q--;
    }
    
    return 0;
}
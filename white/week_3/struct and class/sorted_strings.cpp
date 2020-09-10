#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
    public:
        void AddString(const string& s) {
            sorted_str.push_back(s);
            sort(begin(sorted_str), end(sorted_str));
        }
        vector<string> GetSortedStrings() {
            return sorted_str;
        }
    private:
        vector<string> sorted_str;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;
  
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);
  
    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
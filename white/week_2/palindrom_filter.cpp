#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - (i + 1)]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> palindromWords;
    for (auto word : words) {
        if (word.size() >= minLength && IsPalindrom(word)) {
            palindromWords.push_back(word);
        }
    }
    return palindromWords;
}

int main() {
    /*vector<string> words = {"abacaba", "aba", "bro", "code"};
    vector<string> result = PalindromFilter(words, 4);
    for (auto word : result) {
        cout << word << ' ';
    }
    cout << endl;*/
    return 0;
}
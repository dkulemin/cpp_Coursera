#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

/*
8
ADD program code
COUNT cipher
ADD code cipher
COUNT code
COUNT program
CHECK code program
CHECK program cipher
CHECK cpp java

0
2
1
YES
NO
NO
*/

int main() {
    map<string, set<string>> synonyms;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string operation;
        cin >> operation;
        if (operation == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        } else if (operation == "COUNT") {
            string word;
            cin >> word;
            cout << synonyms[word].size() << endl;
        } else if (operation == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (synonyms[word1].count(word2) > 0 || synonyms[word2].count(word1) > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }      
    }
    
    return 0;
}
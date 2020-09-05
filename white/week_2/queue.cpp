#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> queue(0, "QUIET");
    while (n > 0) {
        string operation;
        int i;
        cin >> operation;
        if (operation == "WORRY_COUNT") {
            int worry_count = 0;
            for (auto man : queue) {
                if (man == "WORRY") {
                    worry_count++;
                }
            }
            cout << worry_count << endl;
        } else if (operation == "COME") {
            cin >> i;
            queue.resize(queue.size() + i, "QUIET");
        } else if (operation == "WORRY")
        {
            cin >> i;
            queue[i] = "WORRY";
        } else if (operation == "QUIET")
        {
            cin >> i;
            queue[i] = "QUIET";
        } 
        n--;
    }
    return 0;
}
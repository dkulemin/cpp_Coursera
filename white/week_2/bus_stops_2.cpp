#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void UpdateAndPrintMap(map<vector<string>, int>& stops_to_bus, const vector<string>& stops) {
    if (stops_to_bus.count(stops) == 0) {
        const int bus_number = stops_to_bus.size() + 1;
        stops_to_bus[stops] = bus_number;
        cout << "New bus " << bus_number << endl;
    } else
    {
        cout << "Already exists for " << stops_to_bus[stops] << endl;
        return; 
    }
}

int main() {
    map<vector<string>, int> stops_to_bus;

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int n;
        cin >> n;
        vector<string> stops(n);
        for (string& stop : stops)
        {
            cin >> stop;
        }
        UpdateAndPrintMap(stops_to_bus, stops);
    }
    
    return 0;
}
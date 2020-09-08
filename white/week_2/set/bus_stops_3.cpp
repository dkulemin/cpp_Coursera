#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

void UpdateAndPrintMap(map<set<string>, int>& stops_to_bus, const set<string>& stops) {
    if (stops_to_bus.count(stops) == 0) {
        const int bus_number = stops_to_bus.size() + 1;
        stops_to_bus[stops] = bus_number;
        cout << "New bus " << bus_number << endl;
    } else
    {
        cout << "Already exists for " << stops_to_bus[stops] << endl;
    }
}

int main() {
    map<set<string>, int> stops_to_bus;

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int n;
        cin >> n;
        set<string> stops;
        for (int k = 0; k < n; k++)
        {
            string stop;
            cin >> stop;
            stops.insert(stop);
        }
        UpdateAndPrintMap(stops_to_bus, stops);
    }
    
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/*
4
NEW_BUS 32 3 qwe rty uio
NEW_BUS 41 2 qwe uio
BUSES_FOR_STOP qwe
STOPS_FOR_BUS 32

10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES

No buses
No stop
No bus
32 32K
Stop Vnukovo: 32 32K 950
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950
Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
Bus 32: Tolstopaltsevo Marushkino Vnukovo
Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo


*/


void PrintMap(const map<string, vector<string>>& m, const string& name) {
    for (const auto& item : m) {
        cout << name << item.first << ": ";
        for (const auto& i : item.second) {
            cout << i << ' ';
        }
        cout << endl;
    }  
}

void ModifyStops(const map<string, vector<string>>& bus_stops, map<string, vector<string>>& stop_buses) {
    for (const auto& item : bus_stops) {
        for (const auto& stop : item.second) {
            stop_buses[stop].push_back(item.first);
        }
    }
}

int main() {
    map<string, vector<string>> bus_stops;
    map<string, vector<string>> stop_buses;

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        string operation;
        cin >> operation;
        if (operation == "NEW_BUS")
        {
            string bus; 
            int stop_count;
            cin >> bus >> stop_count;
            for (int k = 0; k < stop_count; ++k)
            {
                string stop;
                cin >> stop;
                bus_stops[bus].push_back(stop);
                stop_buses[stop].push_back(bus);
            }
            //ModifyStops(bus_stops, stop_buses);
            /*PrintMap(stop_buses, "Stop ");
            cout << endl;
            PrintMap(bus_stops, "Bus ");*/
        } else if (operation == "BUSES_FOR_STOP")
        {
            string stop;
            cin >> stop;
            if (stop_buses.count(stop) == 0) 
            {
                cout << "No stop" << endl;
            } else
            {
                //cout << "Stop " << stop << ": ";
                for (const auto& bus : stop_buses[stop]) {
                    cout << bus << " ";
                }
                cout << endl;
            }
        } else if (operation == "STOPS_FOR_BUS")
        {
            string bus;
            cin >> bus;
            if (bus_stops.count(bus) == 0) 
            {
                cout << "No bus" << endl;
            } else
            {
                for (const auto& stop : bus_stops[bus]) {
                    if (stop_buses[stop].size() == 1) {
                        cout << "Stop " << stop << ": no interchange" << endl;
                    } else
                    {
                        cout << "Stop "<< stop << ": ";
                        for (const auto& b : stop_buses[stop]) {    
                            if (b != bus) {
                                cout << b << " ";
                            }
                        }
                        cout << endl;
                    }
                    
                }
            }
        } else if (operation == "ALL_BUSES")
        {
            if (bus_stops.empty()) {
                cout << "No buses" << endl;
            } else
            {
                PrintMap(bus_stops, "Bus ");
            }
        }  
    }
    return 0;
}
#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
10
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME USSR RussianEmpire
DUMP
ABOUT USSR
DUMP
RENAME RussianEmpire RussianEmpire
DUMP
CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
RENAME RussianEmpire UnitedStatesOfBrazil
DUMP

Introduce new country RussianEmpire with capital Petrograd
Incorrect rename, skip
RussianEmpire/Petrograd
Country USSR doesn't exist
RussianEmpire/Petrograd
Incorrect rename, skip
RussianEmpire/Petrograd
Introduce new country UnitedStatesOfBrazil with capital Brasilia
Incorrect rename, skip
RussianEmpire/Petrograd UnitedStatesOfBrazil/Brasilia

*/

void PrintMap(const map<string, string>& m) {
    for (const auto& item : m) {
        cout << item.first << '/' << item.second << ' ';
    }
    cout << endl;
}

int main() {
    map<string, string> capital_dict;
    int q;
    cin >> q;
    while (q > 0)
    {
        string operation;
        cin >> operation;
        if (operation == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            if (capital_dict.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
                capital_dict[country] = new_capital;
            } else if (capital_dict[country] == new_capital)
            {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            } else
            {
                cout << "Country " << country << " has changed its capital from " << 
                    capital_dict[country] << " to " << new_capital << endl;
                capital_dict[country] = new_capital;
            } 
        } else if (operation == "RENAME")
        {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (old_country_name == new_country_name) 
            {
                cout << "Incorrect rename, skip" << endl;
            } else if (capital_dict.count(new_country_name) == 1) 
            {
                cout << "Incorrect rename, skip" << endl;
            } else if (capital_dict.count(old_country_name) == 0) 
            {
                cout << "Incorrect rename, skip" << endl;
            } else
            {
                cout << "Country " << old_country_name << " with capital " << capital_dict[old_country_name] << 
                    " has been renamed to " << new_country_name << endl;
                capital_dict[new_country_name] = capital_dict[old_country_name];
                capital_dict.erase(old_country_name);
            }
        } else if (operation == "ABOUT")
        {
            string country;
            cin >> country;
            if (capital_dict.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else
            {
                cout << "Country " << country << " has capital " << capital_dict[country] << endl;
            }
        } else if (operation == "DUMP")
        {
            if (capital_dict.empty()) {
                cout << "There are no countries in the world" << endl; 
            } else
            {
                PrintMap(capital_dict);
            }
        }
        q--;
    }
    
    return 0;
}
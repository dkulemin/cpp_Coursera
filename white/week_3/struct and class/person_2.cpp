#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string> &names, int year, int& get_year)
{
    string name; // изначально имя неизвестно

    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    for (const auto &item : names) {
        // если очередной год не больше данного, обновляем имя
        if (item.first <= year) {
            get_year = item.first;
            name = item.second;
        } else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
        }
    }

    return name;
}

class Person {
public:
    void ChangeFirstName(int year, const string &first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string &last_name) {
        last_names[year] = last_name;
    }
    string GetFullName(int year) {
        // получаем имя и фамилию по состоянию на год year
        int get_name_year = year;
        int get_surname_year = year;
        const string first_name = FindNameByYear(first_names, year, get_name_year);
        const string last_name = FindNameByYear(last_names, year, get_surname_year);

        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // если неизвестно только имя
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";

            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";

            // если известны и имя, и фамилия
        } else {
            return first_name + " " + last_name;
        }
    }

    void PrintVec(const vector<string>& vec) {
        for (const auto& v : vec) {
            cout << v << ", ";
        }
    }

    string FormResult(const vector<string>& names) {
        string result_str;
        if (!names.empty()) {
            result_str += " (";
            for (const auto& n : names) {
                result_str += n;
                result_str += ", ";
            }
            result_str = result_str.substr(0, result_str.size() - 2);
            result_str += ")";
        }
        return result_str;
    }

    string GetFullNameWithHistory(int year) {
    // получить все имена и фамилии по состоянию на конец года year
        int get_name_year = year;
        int get_surname_year = year;
        const string first_name = FindNameByYear(first_names, year, get_name_year);
        const string last_name = FindNameByYear(last_names, year, get_surname_year);
        vector<string> names, surnames;

        int last_name_key = get_name_year;
        for (int i = get_name_year - 1; i >= first_names.begin()->first; --i) {
            //if ((first_names.count(i) == 1) && find(begin(names), end(names), first_names[i]) == names.end()) {
            if ((first_names.count(i) == 1) && first_names[i] != first_names[last_name_key]) {
                //if (first_names[i] != first_name) {
                    last_name_key = i;
                    names.push_back(first_names[i]);
                //}
            }
        }
        //PrintVec(names);
        int last_surname_key = get_surname_year;
        for (int i = get_surname_year - 1; i >= last_names.begin()->first; --i) {
            //if ((last_names.count(i) == 1) && find(begin(surnames), end(surnames), last_names[i]) == surnames.end()) {
            if ((last_names.count(i) == 1) && last_names[i] != last_names[last_surname_key]) {
                //if (last_names[i] != last_name) {
                    last_surname_key = i;
                    surnames.push_back(last_names[i]);
                //}
            }
        }
        //PrintVec(surnames);
        // если и имя, и фамилия неизвестны
        string result_str;
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // если неизвестно только имя
        } else if (first_name.empty()) {
            result_str = last_name;
            result_str += FormResult(surnames);
            return result_str + " with unknown first name";

            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            result_str = first_name;
            result_str += FormResult(names);
            return result_str + " with unknown last name";

            // если известны и имя, и фамилия
        } else {
            result_str = first_name;
            result_str += FormResult(names);
            result_str += " ";
            result_str += last_name;
            result_str += FormResult(surnames);
            return result_str;
        }
    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main()
{
    Person person;
  
    /*person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
  
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
  
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
  
    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;
  
    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;
  
    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
  
    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;*/

    /*person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;*/

    person.ChangeFirstName(1965, "Polina");
    person.ChangeFirstName(1965, "Appolinaria");

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeLastName(1965, "Volkova");
    person.ChangeLastName(1965, "Volkova-Sergeeva");

    for (int year : {1964, 1965, 1966}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
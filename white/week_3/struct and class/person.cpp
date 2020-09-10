#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
    public: 
        void ChangeFirstName(int year, const string& first_name) {
            if (name_history.count(year) == 0) {
                name_history[year].push_back(first_name);
                string tmp_last_name = "";
                name_history[year].push_back(tmp_last_name);
            } else {
                name_history[year][0] = first_name;
            }  
        }

        void ChangeLastName(int year, const string& last_name) {
            if (name_history.count(year) == 0) {
                string tmp_first_name = "";
                name_history[year].push_back(tmp_first_name);
                name_history[year].push_back(last_name);
            } else {
                name_history[year][1] = last_name;
            }
        }

        string GetFullName(int year) {
            string name = "";
            string lastname = "";
            for (int i = year; i >= name_history.begin()->first; --i)
            {
                if (name_history.count(i) == 1) {
                    if (name_history[i][0] != "") {
                        name = name_history[i][0];
                        break;
                    }
                }
            }
            for (int i = year; i >= name_history.begin()->first; --i)
            {
                if (name_history.count(i) == 1) {
                    if (name_history[i][1] != "") {
                        lastname = name_history[i][1];
                        break;
                    }
                }
            }
            string answer = ReturnAnswer(name, lastname);
            return answer;
        }
    private:
        string ReturnAnswer(string name, string lastname) {
            if (name != "" && lastname != "") {
                return name + " " + lastname;
            } else {
                if (lastname != "") {
                    return lastname + " with unknown first name";
                } else  if (name != "") {
                    return name + " with unknown last name";
                } else {
                    return "Incognito";
                }
            }
        }
        map<int, vector<string>> name_history;
};

int main() {
    
    Person person;
  
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }
  
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
  
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
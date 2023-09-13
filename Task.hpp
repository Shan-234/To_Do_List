#include <sstream>
using std::stringstream;
#include <string>
using std::string;
#include <chrono>
using std::time_t;

class Task {
    private:
    string name;
    string description;
    time_t due_date;
    bool is_done = false;
    time_t GetDate(string date) {   // date: (DD/MM/YYYY)
        int day;
        int month;
        int year;
        int cnt = 0;
        while (cnt < 3) {
            stringstream ss;
            if (cnt == 0) {
                ss << date.substr(0, 2);
                ss >> day;
            } else if (cnt == 1) {
                ss << date.substr(3, 2);
                ss >> month;
            } else {
                ss << date.substr(6, 4);
                ss >> year;
            }
            cnt++;
        }
        std::tm tm = {};
        tm.tm_year = (year - 1900);
        tm.tm_mon = (month - 1);
        tm.tm_mday = day;
        tm.tm_hour = 0;
        tm.tm_min = 0;
        tm.tm_sec = 0;
        return(std::mktime(&tm));
    }

    public:
    Task(string n, string d) {
        name = n;
        description = d;
        if (n == "") {
            name = "(Untitled)";
        } if (d == "") {
            description = "(No Description Provided)";
        }
    }
    void AddDueDate(string date) {
        due_date = GetDate(date);
    }
    string GetDueDate() {
        string date_str = std::ctime(&due_date);
        return(date_str);
    }
    void ChangeName(string n) {
        name = n;
    }
    string GetName() {
        return(name);
    }
    void ChangeDescription(string d) {
        description = d;
    }
    string GetDescription() {
        return(description);
    }
    bool IsDone() {
        return(is_done);
    }
    void MarkAsDone() {
        is_done = true;
    }
};
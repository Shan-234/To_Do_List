#include "Task.hpp"
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

class List {
    private:
    string list_name;
    vector<Task*> tasks;

    public:
    List() = default;
    bool AddTask(Task* ptr) {
        tasks.push_back(ptr);
        return(true);
    }
    int TasksCount() {
        return(tasks.size());
    }
    Task* GetTask(string task_name) {
        for (Task* ptr : tasks) {
            if (ptr->GetName() == task_name) {
                return(ptr);
            }
        }
        return(nullptr);
    }
    bool DeleteTask(string task_name) {
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i]->GetName() == task_name) {
                tasks.erase(tasks.begin() + i);
                return(true);
            }
        }
        return(false);
    }
    void ShowTasks() {
        int cnt = 1;
        for (Task* ptr : tasks) {
            string done;
            if (ptr->IsDone()) {
                done = "Done";
            } else {
                done = "Pending";
            }
            cout << endl;
            cout << cnt << ". " << ptr->GetName() << ": (" << done << ")" << endl;
            cout << ptr->GetDescription() << endl;
            if (ptr->GetDueDate() == "") {
                cout << "Due Date: None";
            } else {
                cout << "Due Date: " << ptr->GetDueDate();
            }
            cout << endl;
            cnt++;
        }
    }
    void ShowDoneTasks() {
        int cnt = 1;
        for (Task* ptr : tasks) {
            if (ptr->IsDone()) {
                cout << endl;
                cout << cnt << ". " << ptr->GetName() << ": (Done)" << endl;
                cout << ptr->GetDescription() << endl;
                cout << endl;
            }
            cnt++;
        }
    }
    void ShowPendingTasks() {
        int cnt = 1;
        for (Task* ptr : tasks) {
            if (!(ptr->IsDone())) {
                cout << endl;
                cout << cnt << ". " << ptr->GetName() << ": (Pending)" << endl;
                cout << ptr->GetDescription() << endl;
                cout << endl;
            }
            cnt++;
        }
    }
};
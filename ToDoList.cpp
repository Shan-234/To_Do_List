#include "List.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::getline;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

int main() {
    cout << "TO DO LIST" << endl;
    cout << endl;
    List* list = new List();
    cout << "Your Tasks:" << endl;
    list->ShowTasks();
    cout << "Total Number of Tasks: " << list->TasksCount() << endl;
    cout << endl;
    cout << endl;
    // Loop Starts From Here:
    while (true) {
        cout << "********************************************************************************" << endl << endl;
        string option;
        cout << "A - Add New Task" << endl;
        cout << "U - Update a Task" << endl;
        cout << "D - Delete a Task" << endl;
        cout << "V - View Tasks" << endl;
        cout << "E - Exit" << endl;
        cout << "Enter Option: ";
        cin >> option;
        cout << endl;
        if (option == "A") {
            cout << "Add New Task:" << endl;
            string name;
            string description;
            cout << "Enter Task Name: ";
            if (getline(cin, name)) {
                getline(cin, name);
                cout << "Enter Task Description: ";
                getline(cin, description);
                list->AddTask(new Task(name, description));
            }
        } else if (option == "U") {
            string option_a;
            cout << "Update a Task:" << endl;
            cout << "C - Change Name of a Task" << endl;
            cout << "B - Change Description of a Task" << endl;
            cout << "D - Add or Change Due Date For a Task" << endl;
            cout << "M - Mark a Task as Done" << endl;
            cout << "Enter option: ";
            cin >> option_a;
            if (option_a == "C") {
                string original_name;
                string new_name;
                cout << "Enter Original Name of Task: ";
                if (getline(cin, original_name)) {
                    getline(cin, original_name);
                    cout << "Enter New Name of Task: ";
                    getline(cin, new_name);
                    Task* ptr = list->GetTask(original_name);
                    ptr->ChangeName(new_name);
                }
            } else if (option_a == "B") {
                string task_name;
                string new_description;
                cout << "Enter Name of Task: ";
                if (getline(cin, task_name)) {
                    getline(cin, task_name);
                    cout << "Enter New Description For the Task: ";
                    getline(cin, new_description);
                    Task* ptr = list->GetTask(task_name);
                    ptr->ChangeDescription(new_description);
                }
            } else if (option_a == "D") {
                string task_name;
                string due_date;
                cout << "Enter Name of Task: ";
                if (getline(cin, task_name)) {
                    getline(cin, task_name);
                    cout << "Enter the Due Date (DD/MM/YYYY): ";
                    cin >> due_date;
                    Task* ptr = list->GetTask(task_name);
                    ptr->AddDueDate(due_date);
                }
            } else if (option_a == "M") {
                string task_name;
                cout << "Enter Name of Task: ";
                if (getline(cin, task_name)) {
                    getline(cin, task_name);
                    Task* ptr = list->GetTask(task_name);
                    ptr->MarkAsDone();
                }
            }
        } else if (option == "D") {
            string task_name;
            cout << "Delete a Task:" << endl;
            cout << "Enter Name of Task to Delete: ";
            if (getline(cin, task_name)) {
                getline(cin, task_name);
                list->DeleteTask(task_name);
            }
        } else if (option == "V") {
            cout << "View Tasks:" << endl;
            string option_b;
            cout << "A - View All Tasks" << endl;
            cout << "D - View Done Tasks" << endl;
            cout << "P - View Pending Tasks" << endl;
            cout << "Enter Option: ";
            cin >> option_b;
            cout << endl;
            if (option_b == "A") {
                cout << "All Tasks:" << endl;
                list->ShowTasks();
            } else if (option_b == "D") {
                cout << "Done Tasks:" << endl;
                list->ShowDoneTasks();
            } else if (option_b == "P") {
                cout << "Pending Tasks:" << endl;
                list->ShowPendingTasks();
            }
        } else if (option == "E") {
            break;
        }
        cout << endl << endl;
    }
    return(0);
}
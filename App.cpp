#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <chrono>
#include "ToDoList.h"
#include "ToDoListItem.h"
class APP
{
private:
    ToDoList list;

public:
    void run()
    {
        std::cout << "====================To Do List Application=====================" << std::endl;
        int choice;
        do
        {
            displayMenu();
            choice = getUserChoice();

            switch (choice)
            {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                editItem();
                break;
            case 4:
                displayItems();
                break;
            case 5:
                std::cout << "Exiting the application. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }

            std::cout << std::endl;
            std::cout << "_______________________________________________________________________" << std::endl;
            std::cout << "NOTIFICATIONS" << std::endl;
            alert(list.reachingDeadlineTasks());
        } while (choice != 5);
    }

private:
    int getUserChoice() const
    {
        int choice;
        std::cin >> choice;
        return choice;
    }
    void displayMenu() const
    {
        std::cout << "===== Menu =====" << std::endl;
        std::cout << "1. Add item" << std::endl;
        std::cout << "2. Remove item" << std::endl;
        std::cout << "3. Edit item" << std::endl;
        std::cout << "4. Display items" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "===============================" << std::endl;
        std::cout << "Enter your choice: ";
    }
    void addItem()
    {
        std::string task;
        std::cout << "Enter the task" << std::endl;
        do
        {
            std::getline(std::cin, task);
        } while (task == "");
        std::cout << "If you want to set Deadline please press 'y' button" << std::endl;
        std::string setDeadline;
        std::getline(std::cin, setDeadline);
        if (setDeadline == "y")
        {
            int year = 0;
            int month = 0;
            int day = 0;
            int hour = 0;
            int minute = 0;
            std::cout << "Enter the Year of Deadline\n";
            std::cin >> year;
            std::cout << "Enter the month of Deadline\n";
            std::cin >> month;
            std::cout << "Enter the day of the Deadline\n";
            std::cin >> day;
            std::cout << "Enter the hour of the Deadline\n";
            std::cin >> hour;
            std::cout << "Enter the minute of the Deadline\n";
            std::cin >> minute;
            ToDoListItem *newItem = new ToDoListItem(task, year, month, day, hour, minute);
            if (list.add(newItem))
            {
                std::cout << "The new task is created! See the info Below\n";
                newItem->showTask();
            }
            else
            {
                std::cout << "Failed to add\n";
            }
            return;
        }
        else
        {
            ToDoListItem *newItem = new ToDoListItem(task);
            if (list.add(newItem))
            {
                std::cout << "The new task is created! See the info Below\n";
                newItem->showTask();
                std::cout << "This task will not have Deadline" << std::endl;
            }
            else
            {
                std::cout << "Failed to add\n";
            }
        }
    }
    void removeItem()
    {
        std::cout << "Enter the ID of the task you want to remove" << std::endl;
        list.showAllTasks();
        int ID;
        std::cin >> ID;
        if (list.remove(ID))
        {
            std::cout << "Successfully Removed" << std::endl;
        }
        else
        {
            std::cout << "Failed to remove" << std::endl;
        }
    }
    void editItem()
    {
        std::cout << "Enter the ID of the task you want to Edit" << std::endl;
        list.showAllTasks();
        int ID;
        std::cin >> ID;
        ToDoListItem *itemToEdit = list.find(ID);
        itemToEdit->editTask();
    }
    void displayItems()
    {
        list.showAllTasks();
    }
    void alert(int id)
    {
        ToDoListItem *taskclosetodeadline = list.find(id);
        taskclosetodeadline->showTask();
        std::cout << "THIS TASK DEADLINE WILL BE FINISHED IN LESS THAN 1 HOUR" << std::endl;
    }
};
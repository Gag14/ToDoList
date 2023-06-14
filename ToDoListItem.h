#ifndef __ToDoListItem__
#define __ToDoListItem__
#include <iostream>
#include <string>
#include <chrono>
class ToDoListItem
{
private:
    int id;
    std::string task;
    std::chrono::system_clock::time_point finishtime;
    bool done;

public:
    ToDoListItem();
    ToDoListItem(const std::string &);
    ToDoListItem(const std::string &todoitem, int year, int month, int day, int hour, int minute);
    void setId(int number);
    int getId() const;
    void setTask(const std::string &todoitem);
    const std::string &getTask() const;
    void editTask();
    void setFinishTime(int year, int month, int day, int hour, int minute);
    auto getFinishTime() const;
    bool isDone() const;
    void markAsDone();
    bool deadline();
    void showTask();
};
#include "ToDoListItem.cpp"
#endif
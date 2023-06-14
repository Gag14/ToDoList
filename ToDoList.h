#ifndef __ToDoList__
#define __ToDoList__
#include <iostream>
#include <string>
#include <chrono>
#include <list>
#include "ToDoListItem.h"
class ToDoList
{
private:
    std::list<ToDoListItem *> ToDoListItems;
    int count;
public:
    ToDoList();
    ToDoList(const std::list<ToDoListItem *> &items);
    ~ToDoList();
    bool add(ToDoListItem *item);
    bool remove(int id); 
    ToDoListItem* find(int id);
    int reachingDeadlineTasks();
    void showAllTasks();
};
#include "ToDoList.cpp"
#endif
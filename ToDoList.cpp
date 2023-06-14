#ifndef __ToDoListCPP__
#define __ToDoListCPP__
#include <iostream>
#include <string>
#include <chrono>
#include <list>
#include <algorithm>
#include "ToDoList.h"
ToDoList::ToDoList() : count(0) {}
ToDoList::ToDoList(const std::list<ToDoListItem *> &items) : ToDoListItems(items), count(items.size()) {}
ToDoList::~ToDoList()
{
    for (auto elem : ToDoListItems)
    {
        delete elem;
    }
}
bool ToDoList::add(ToDoListItem *item)
{
    ToDoListItems.push_back(item);
    item->setId(++count);
    return 1;
}
bool ToDoList::remove(int id)
{
    bool success = 0;
    for (auto it = ToDoListItems.begin(); it != ToDoListItems.end();)
    {
        if (id == (*it)->getId())
        {
            it = ToDoListItems.erase(it);
            success = 1;
        }
        else
        {
            ++it;
        }
    }
    return success;
}
ToDoListItem *ToDoList::find(int id)
{
    for (auto it = ToDoListItems.begin(); it != ToDoListItems.end(); ++it)
    {
        if (id == (*it)->getId())
        {
            return *it;
        }
    }
    return nullptr;
}
void ToDoList::showAllTasks()
{
    for (auto elem : ToDoListItems)
    {
        elem->showTask();
    }
}
int ToDoList::reachingDeadlineTasks()
{
    while (1)
    {
        for (auto it = ToDoListItems.begin(); it != ToDoListItems.end();)
        {
            if ((*it)->deadline() && !(*it)->isDone())
            {
                return (*it)->getId();
            }
        }
    }
}
#endif
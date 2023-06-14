#ifndef __ToDoListItemCPP__
#define __ToDoListItemCPP__
#include <iostream>
#include <string>
#include <chrono>
#include "ToDoListItem.h"
ToDoListItem::ToDoListItem() : done(0) {}
ToDoListItem::ToDoListItem(const std::string &todoitem) { task = todoitem; }
ToDoListItem::ToDoListItem(const std::string &todoitem, int year, int month, int day, int hour, int minute)
{
    task = todoitem;
    setFinishTime(year, month, day, hour, minute);
}
void ToDoListItem::setId(int number) { id = number; }
int ToDoListItem::getId() const { return id; }
void ToDoListItem::setTask(const std::string &todoitem) { task = todoitem; }
const std::string &ToDoListItem::getTask() const { return task; }
void ToDoListItem::editTask()
{
    std::cout << "The task is : " << task << std::endl;
    std::cout << "Please Enter the edited task" << std::endl;
    std::string editedTask;
    do
    {
        std::getline(std::cin, editedTask);
    } while (editedTask == "");
    task = editedTask;
}
void ToDoListItem::setFinishTime(int year, int month, int day, int hour, int minute)
{
    std::tm localTime{};
    localTime.tm_year = year - 1900;
    localTime.tm_mon = month - 1;
    localTime.tm_mday = day;
    localTime.tm_hour = hour;
    localTime.tm_min = minute;
    localTime.tm_sec = 0;
    std::time_t timeT = std::mktime(&localTime);
    finishtime = std::chrono::system_clock::from_time_t(std::mktime(&localTime));
}
auto ToDoListItem::getFinishTime() const
{
    return finishtime;
}
bool ToDoListItem::isDone() const { return done; }
void ToDoListItem::markAsDone() { done = 1; }
bool ToDoListItem::deadline()
{
    std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
    return currentTime > finishtime - std::chrono::hours(1);
}
void ToDoListItem::showTask()
{
    std::cout << "ID : " << id << " The task is : " << this->getTask() <<  " | ";
    if (finishtime != std::chrono::system_clock::time_point{})
    {
        std::time_t finishtime_t = std::chrono::system_clock::to_time_t(finishtime);
        std::tm *localTime = std::localtime(&finishtime_t);
        int year = localTime->tm_year + 1900;
        int month = localTime->tm_mon + 1;
        int day = localTime->tm_mday;
        int hour = localTime->tm_hour;
        int minute = localTime->tm_min;
        std::cout << "Finish Time: " << year << "-" << month << "-" << day << " " << hour << ":" << minute << std::endl;
    }
}
#endif
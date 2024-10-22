#ifndef SJF_H
#define SJF_H
#include <list>

#include "task.h"

Task pickNextTask(list<Task> &taskList);
void schedule(list<Task> &taskList);
bool burstSort(const Task& a, const Task& b);

void calculateAverages(list<Task> processInfo);
#endif

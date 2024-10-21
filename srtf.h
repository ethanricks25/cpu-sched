#ifndef SRTF_H
#define SRTF_H
#include <list>

#include "task.h"

void schedule(list<Task> &taskList);
Task pickNextTask(list<Task> &taskList);
bool burstSort(const Task& a, const Task& b);

#endif

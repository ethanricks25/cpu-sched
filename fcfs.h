#ifndef FCFS_H
#define FCFS_H
#include <list>

#include "task.h"

void schedule(list<Task> &taskList);
Task pickNextTask(list<Task> &taskList);

#endif

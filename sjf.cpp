#include <list>
#include <iostream>
#include "task.h"
#include "sjf.h"
#include "CPU.h"


Task pickNextTask(list<Task> &taskList){ 
	Task selectedTask = taskList.front();
	taskList.erase(taskList.begin());
	return selectedTask;
}

bool burstSort(const Task &a, const Task &b){
	return a.burst < b.burst;
}

void schedule(list<Task>& taskList) {
	cout << "SCHEDULING TASK FOR SJF" << endl;
    taskList.sort(burstSort);
	while(!taskList.empty()) {
		Task selectedTask = pickNextTask(taskList);
		run(selectedTask, selectedTask.burst);
	}
}

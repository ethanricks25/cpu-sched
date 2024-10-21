#include <iostream>
#include <list>
#include "fcfs.h"
#include "task.h"
#include "CPU.h"

Task pickNextTask(list<Task> &taskList){ 
	Task selectedTask = taskList.front();
	taskList.erase(taskList.begin());
	return selectedTask;
}

void schedule(list<Task> &taskList){
	cout << "SCHEDULING TASK FOR FCFS" << endl;
	while(!taskList.empty()) {
		Task selectedTask = pickNextTask(taskList);
		run(selectedTask, selectedTask.burst);
	}
}



#include <iostream>
#include <list>
#include "fcfs.h"
#include "task.h"
#include "CPU.h"

void calculateAverages(list<Task> processInfo);

Task pickNextTask(list<Task> &taskList){ 
	Task selectedTask = taskList.front();
	taskList.erase(taskList.begin());
	return selectedTask;
}

void schedule(list<Task> &taskList){
	cout << "SCHEDULING TASK FOR FCFS" << endl;
	list<Task> completedTaskInfo;
	int currentTime = 0;
	while(!taskList.empty()) {
		Task selectedTask = pickNextTask(taskList);
		run(selectedTask, selectedTask.burst);
		currentTime += selectedTask.burst;
		selectedTask.completionTime = currentTime - 0;
		selectedTask.waitingTime = selectedTask.completionTime - selectedTask.burst;
		selectedTask.responseTime = (currentTime - selectedTask.burst) - 0;
		completedTaskInfo.push_back(selectedTask);
	}

	calculateAverages(completedTaskInfo);
	
}

void calculateAverages(list<Task> processInfo){
	int totalWT = 0, totalTAT = 0, totalRT = 0;
	
	for (Task process : processInfo){
		totalWT += process.waitingTime;
		totalTAT += process.completionTime;
		totalRT += process.responseTime;
	}

	cout << "Average Waiting Time: " << (float)totalWT / processInfo.size() << "milliseconds" << endl;
    cout << "Average Turnaround Time: " << (float)totalTAT / processInfo.size() <<  "milliseconds" << endl;
    cout << "Average Response Time: " << (float)totalRT / processInfo.size() <<  "milliseconds" << endl;
}


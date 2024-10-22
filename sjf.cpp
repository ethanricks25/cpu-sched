#include <list>
#include <iostream>
#include "task.h"
#include "sjf.h"
#include "CPU.h"


void calculateAverages(list<Task> processInfo);
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
	list<Task> completedTaskInfo;
	int currentTime = 0;
    taskList.sort(burstSort);
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

	cout << "Average Waiting Time: " << (float)totalWT / processInfo.size() <<  "milliseconds" << endl;
    cout << "Average Turnaround Time: " << (float)totalTAT / processInfo.size() <<  "milliseconds" << endl;
    cout << "Average Response Time: " << (float)totalRT / processInfo.size() <<  "milliseconds" << endl;
}

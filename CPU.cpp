#include "CPU.h"

#include <iostream>
#include <thread>
#include <chrono>
#include "task.h"

void run(Task currentTask, int burst){
	cout << "Running task: " << currentTask.name << endl;
	this_thread::sleep_for(chrono::milliseconds(burst));
	cout << "Task " << currentTask.name << " completed." << endl;
}

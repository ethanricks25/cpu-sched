#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <sstream>
#include "task.h"
#include "fcfs.h"
#include "rr.h"
#include "sjf.h"
#include "srtf.h"

using namespace std;

void readTaskFile(const string filename, list<Task> &taskList);
	
int main(int argc, char *argv[]) {
	cout << "BEGINNING PROGRAM " << endl;

	if (argc != 2) {
		cerr << "Invalid args: " << argv[0] << "<tasks file" << endl;
		return 2;
	}

	list<Task> taskList;

	readTaskFile(argv[1], taskList);

	schedule(taskList);

	return 0;
}

void readTaskFile(const string filename, list<Task> &taskList){
	ifstream file(filename);
	if (!file.is_open()){
		cerr << "Error: Could not open file " << filename << endl;
	exit(1);
	}
	cout << "READING TASKS" << endl;

	string taskName, line;
	int priority, burst;
	char delim = ',';

	while (getline(file, line)) {
		stringstream ss(line);
		
		if (getline(ss, taskName, delim) && 
				ss >> priority >> delim &&
				ss >> burst) {
				
				Task newTask = Task(taskName, priority, burst);

				cout << "NEW TASK = TASKNAME: " << taskName << ", PRIORITY: " << priority << ", BURST: " << burst << endl;
				taskList.push_back(newTask);
		}
	}

	file.close();
}


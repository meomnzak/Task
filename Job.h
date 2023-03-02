
#ifndef TASK_JOB_H
#define TASK_JOB_H

#include <functional>
#include <thread>
using namespace std;

class Job {
private:
    int id;
    int interval;
    int frequency;
    function<void()> implementation;
public:
    Job(int id, int interval, int frequency, function<void()> implementation);
    Job();
    int getFrequency();
    function<void()> func();
};


#endif

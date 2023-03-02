
#include "Job.h"
#include <functional>


Job::Job(int id, int interval, int frequency, function<void()> implementation) {
    this->id = id;
    this->interval = interval;
    this->frequency = frequency;
    this->implementation = implementation;
}

Job::Job() {}

int Job::getFrequency(){
    return frequency;
}

function<void()> Job::func(){
    return implementation;
}

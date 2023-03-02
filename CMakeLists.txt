cmake_minimum_required(VERSION 3.24)
project(Task)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task main.cpp Job.cpp Job.h Scheduler.cpp Scheduler.h)

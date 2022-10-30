cmake_minimum_required(VERSION 3.23)
project(schedule)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjetoAED main.cpp ClassPerUC.cpp Lecture.cpp Student.cpp Menu.cpp Menu.h ScheduleManagement.cpp ScheduleManagement.h)

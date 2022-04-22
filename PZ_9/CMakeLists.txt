cmake_minimum_required (VERSION 3.0) 
 
set (PROJECT danrom_task) 
 
project (${PROJECT}) 
 
set (HEADERS 
	taskheader.h)
 
set (SOURCES 
	maintask.cpp) 
 
add_executable (${PROJECT} ${HEADERS} ${SOURCES})
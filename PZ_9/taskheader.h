#ifndef TASKHEADER_H_INCLUDED
#define TASKHEADER_H_INCLUDED

#pragma once

#include <iostream>

#include <string>

using namespace std;

enum Robot_State {
    OFF,
    ON
};
enum Action_State {
    AWAITING,
    MANUAL,
    ROTATING,
    MOVING,
    CLEANING
};

class CommandStrategy {
public:
    virtual~CommandStrategy() {}

    virtual string getCommand() = 0;
};

class ConsoleCommandStrategy : public CommandStrategy {
public: string getCommand() {
    string reply;
    cin >> reply;
    return reply;
};
};

#endif // TASKHEADER_H_INCLUDED

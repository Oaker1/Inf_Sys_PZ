#include <iostream>
#include "taskheader.h"
#include <string>

class Robot {
  Robot_State robstate = OFF;
  Action_State actstate = AWAITING;
  CommandStrategy * p;

  public:
    Robot(CommandStrategy * comp): p(comp) {}~Robot() {
      delete p;
    }

  virtual void showState(Robot_State robstat, Action_State actstat) {
    cout<< " \n"<<
    "\n1. Turn on"<<
    "\n2. Turn off"<<
    "\n3. Move forward"<<
    "\n4. Move back"<<
    "\n5. Turn right"<<
    "\n6. Turn left"<<
    "\n7. Start Cleaning";

    switch (robstat) {
    case 0:
      cout<< "\nRobot is OFF";
      break;
    case 1:
      cout<< "\nRobot is ON";
      break;
    }

    switch (actstat) {
    case 0:
      cout<< " and is AWAITING\n";
      break;
    case 1:
      cout<< " and is MANUAL\n";
      break;
    case 2:
      cout<< " and is ROTATING\n";
      break;
    case 3:
      cout<< " and is MOVING\n";
      break;
    case 4:
      cout<< " and is CLEANING\n";
      break;
    }
  }

  virtual void AnswerCheck(string answer) {
    if (answer == "1")
      Turn_On();
    if (answer == "2")
      Turn_Off();
    if (answer == "3")
      Go_Manual();
    if (answer == "4")
      Clean(5);
    if (answer == "5")
      Turn_Right(5);
    if (answer == "6")
      Turn_Left(5);
    if (answer == "7")
      Move_Forward(5);
    if (answer == "8")
      Move_Back(5);
  }

  virtual void Turn_On() {
    if (robstate == OFF) {
      robstate = ON;
      cout<< "\nfunction Turn On was a success";
    }
  }

  virtual void Turn_Off() {
    if (robstate == ON) {
      robstate = OFF;
      cout<< "\nfunction Turn Off was a success";
    }
  }

  virtual void Go_Manual() {
    if (robstate == ON) {
      actstate = MANUAL;
      cout<< "\nfunction Go_Manual was a success\n";
    }
  }

  virtual void Move_Forward(float length) {
    if (robstate == ON) {
      actstate = MOVING;
      cout<< "\nfunction Move was a success\n";
    }
  }

  virtual void Move_Back(float length) {
    if (robstate == ON) {
      actstate = MOVING;
      cout<< "\nfunction Move was a success\n";
    }
  }

  virtual void Turn_Left(float angle) {
    if (robstate == ON) {
      actstate = ROTATING;
      cout<< "\nfunction Turn was a success\n";
    }
  }

  virtual void Turn_Right(float angle) {
    if (robstate == ON) {
      actstate = ROTATING;
      cout<< "\nfunction Turn was a success\n";
    }
  }

  virtual void Clean(float Wamount) {
    if (robstate == ON) {
      actstate = CLEANING;
      cout<< "\nfunction Clean was a success\n";
    }
  }

  string getCommand() {
    string command = p -> getCommand();
    return command;
  }

  void handle() {
    string response {};
    cout<< " \n"<<
    "\n1. Turn on"<<
    "\n2. Turn off"<<
    "\n3. Move forward"<<
    "\n4. Move back"<<
    "\n5. Turn right"<<
    "\n6. Turn left"<<
    "\n7. Start Cleaning";
    while (response != "stop") {
      response = getCommand();
      AnswerCheck(response);
      showState(robstate, actstate);
    }
  }
};

int main() {
  Robot * p = new Robot(new ConsoleCommandStrategy);
  p -> handle();
  delete p;
  return 0;
}

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
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
int sock;
  struct sockaddr_in addr;
  char reply[1024];
  int bytes_read;
  sock = socket(AF_INET, SOCK_DGRAM, 0);
  
  addr.sin_family = AF_INET;
  addr.sin_port = htons(3425);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bytes_read = recvfrom(sock, reply, 1024, 0, NULL, NULL);
    reply[bytes_read] = '\0';
    cin >> reply;
    return reply;
};
};

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
sendServerMessage("Robot is on");
    }
  }

  virtual void Turn_Off() {
    if (robstate == ON) {
      robstate = OFF;
      cout<< "\nfunction Turn Off was a success";
sendServerMessage("Robot is off");
    }
  }

  virtual void Go_Manual() {
    if (robstate == ON) {
      actstate = MANUAL;
      cout<< "\nfunction Go_Manual was a success\n";
sendServerMessage("Robot is manual");
    }
  }

  virtual void Move_Forward(float length) {
    if (robstate == ON) {
      actstate = MOVING;
      cout<< "\nfunction Move was a success\n";
sendServerMessage("Robot is moving");
    }
  }

  virtual void Move_Back(float length) {
    if (robstate == ON) {
      actstate = MOVING;
      cout<< "\nfunction Move was a success\n";
sendServerMessage("Robot is moving");
    }
  }

  virtual void Turn_Left(float angle) {
    if (robstate == ON) {
      actstate = ROTATING;
      cout<< "\nfunction Turn was a success\n";
sendServerMessage("Robot is turning");
    }
  }

  virtual void Turn_Right(float angle) {
    if (robstate == ON) {
      actstate = ROTATING;
      cout<< "\nfunction Turn was a success\n";
sendServerMessage("Robot is turning");
    }
  }

  virtual void Clean(float Wamount) {
    if (robstate == ON) {
      actstate = CLEANING;
      cout<< "\nfunction Clean was a success\n";
sendServerMessage("Robot is cleaning");
    }
  }

  string getCommand() {
    string command = p -> getCommand();
    return command;
  }

  void sendServerMessage(string replyy)
{
  int sock;
  struct sockaddr_in addr;
  sock = socket(AF_INET, SOCK_DGRAM, 0);

  addr.sin_family = AF_INET;
  addr.sin_port = htons(3425);
  addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  sendto(sock, replyy.c_str(), sizeof(replyy), 0, (struct sockaddr *)&addr, sizeof(addr));
close(sock);
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
  int sock;
  struct sockaddr_in addr;
  char buf[1024];
  int bytes_read;
  sock = socket(AF_INET, SOCK_DGRAM, 0);
  
  addr.sin_family = AF_INET;
  addr.sin_port = htons(3425);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    return 1;
  }
Robot * p = new Robot(new ConsoleCommandStrategy);
p -> handle();
  while(1) {
    bytes_read = recvfrom(sock, buf, 1024, 0, NULL, NULL);
    buf[bytes_read] = '\0';
    printf("%s\n", buf);
  }
delete p;

}

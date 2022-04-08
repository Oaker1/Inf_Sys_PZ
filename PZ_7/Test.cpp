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
    CLEANING,
};

class RobotHandler {
public:
    virtual ~RobotHandler() {}
    virtual void handle() = 0;
};

class Robot : public RobotHandler {

    Robot_State robstate = OFF;
    Action_State actstate = AWAITING;

public:
    void AnswerCheck(string answer)
    {
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
    void Turn_On()
    {
        robstate = ON;
    }

    void Turn_Off()
    {
        robstate = OFF;
    }

    void Go_Manual()
    {
        if (robstate == ON)
            actstate = MANUAL;
    }

    void Move_Forward(float length)
    {
        if (robstate == ON)
            actstate = MOVING;
    }

    void Move_Back(float length)
    {
        if (robstate == ON)
            actstate = MOVING;
    }

    void Turn_Left(float angle)
    {
        if (robstate == ON)
            actstate = ROTATING;
    }

    void Turn_Right(float angle)
    {
        if (robstate == ON)
            actstate = ROTATING;
    }

    void Clean(float Wamount)
    {
        if (robstate == ON)
            actstate = CLEANING;
    }

    void handle()
    {
        string response{};
        while (response != "stop") {
            cout << "Robot is " << robstate << " and is " << actstate << "\n";
            if (robstate == ON) {
                system("CLS");
                cout << "Robot is " << robstate << " and is " << actstate << "\n";
                cout << "\nEnter number. \n"
                     << "\n2 = turn OFF \n3 = manual \n4 = clean \n5 = rotateR \n6 = rotateL \n7 = move forward \n8 = move back \nType 'stop' to stop. \n";
                cin >> response;
                AnswerCheck(response);
                system("CLS");
            }
            else {
                system("CLS");
                cout << "Robot is " << robstate << " and is " << actstate << "\n";
                cout << "\nEnter number. \n"
                     << "\n2 = turn OFF \n3 = manual \n4 = clean \n5 = rotateR \n6 = rotateL \n7 = move forward \n8 = move back \nType 'stop' to stop. \n";
                cin >> response;
                AnswerCheck(response);
                system("CLS");
            }
        }
    }
};

class ResponseHandler {
    RobotHandler* p;
public:
    ResponseHandler(RobotHandler* comp)
        : p(comp)
    {
    }
    ~ResponseHandler()
    {
        delete p;
    }

    void handle()
    {
        p->handle();
    }
};

int main()
{
    ResponseHandler* p = new ResponseHandler(new Robot);
    p->handle();
    delete p;
    return 0;
}

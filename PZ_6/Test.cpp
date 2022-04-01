#include <string>
#include <iostream>

using namespace std;

enum Robot_State {ON, OFF};
enum Action_State {ROTATING, MOVING, CLEANING, MANUAL, AWAITING};

class Robot
{
public:

    Robot_State robstate = OFF;
    Action_State actstate = AWAITING;

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
            if (robstate == ON) actstate = MANUAL;
        }

        void Move_Forward(float length)
        {
            if (robstate == ON) actstate = MOVING;
        }

        void Move_Back(float length)
        {
            if (robstate == ON) actstate = MOVING;
        }

        void Turn_Left(float angle)
        {
            if (robstate == ON) actstate = ROTATING;
        }

        void Turn_Right(float angle)
        {
            if (robstate == ON) actstate = ROTATING;
        }

        void Clean(float Wamount)
        {
            if (robstate == ON) actstate = CLEANING;
        }


};

void AnswerCheck(Robot &rob, string answer)
{
    if (answer == "1") rob.Turn_On();
    if (answer == "2") rob.Turn_Off();
    if (answer == "3") rob.Go_Manual();
    if (answer == "4") rob.Clean(5);
    if (answer == "5") rob.Turn_Right(5);
    if (answer == "6") rob.Turn_Left(5);
    if (answer == "7") rob.Move_Forward(5);
    if (answer == "8") rob.Move_Back(5);
};

int main()
{
    Robot rob1;
    string lol{};
    while (lol != "stop")
    {
        if (rob1.robstate == ON)
        {
            system("CLS");
            switch(rob1.actstate)
            {
                case AWAITING:
                cout << "Robot is ON and is AWAITING \n";
                break;
                case ROTATING:
                cout << "Robot is ON and is ROTATING \n";
                break;
                case MOVING:
                cout << "Robot is ON and is MOVING \n";
                break;
                case CLEANING:
                cout << "Robot is ON and is CLEANING \n";
                break;
                case MANUAL:
                cout << "Robot is ON and is MANUAL \n";
                break;
            }

            cout << "\nEnter number. \n" << "\n2 = turn OFF \n3 = manual \n4 = clean \n5 = rotateR \n6 = rotateL \n7 = move forward \n8 = move back \nType 'stop' to stop. \n";
            cin >> lol;
            AnswerCheck(rob1, lol);
            system("CLS");
        }
        else
        {
            system("CLS");
            cout << "\nRobot is OFF. Enter number. \n" << "1 = turn ON \nType 'stop' to stop. \n";
            cin >> lol;
            AnswerCheck(rob1, lol);
            system("CLS");
        }
    }
}

#include <iostream>
#include <string>

using namespace std;

/*enum Robot_State {
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
*/

class CommandStrategy
{
  public:
    virtual ~CommandStrategy() {}
    virtual string getCommand(int robstat, int actstat) = 0;
};

class ConsoleCommandStrategy  : public CommandStrategy
{
  public:
        string getCommand(int robstat, int actstat)
        {
        string reply;
                cout << "Robot is " << robstat << " and is " << actstat << "\n"
                <<"\n1 = turn ON " << "\n2 = turn OFF \n3 = manual \n4 = clean \n5 = rotateR \n6 = rotateL \n7 = move forward \n8 = move back \nType 'stop' to stop. \n";
                cin >> reply;
                return reply;
        };
};

// Класс для использования
class Robot
{
    int robstate = 0;
    int actstate = 0;
    CommandStrategy *p;

  public:
    Robot( CommandStrategy* comp): p(comp) {}
   ~Robot() { delete p; }

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
        robstate = 1;
    }

    void Turn_Off()
    {
        robstate = 0;
    }

    void Go_Manual()
    {
        if (robstate == 1)
            actstate = 1;
    }

    void Move_Forward(float length)
    {
        if (robstate == 1)
            actstate = 2;
    }

    void Move_Back(float length)
    {
        if (robstate == 1)
            actstate = 2;
    }

    void Turn_Left(float angle)
    {
        if (robstate == 1)
            actstate = 3;
    }

    void Turn_Right(float angle)
    {
        if (robstate == 1)
            actstate = 3;
    }

    void Clean(float Wamount)
    {
        if (robstate == 1)
            actstate = 4;
    }

    string getCommand() {
        string command = p->getCommand(robstate, actstate);
        return command;
    }

    void handle()
    {
        string response{};
        while (response != "stop") {
            response = getCommand();
            AnswerCheck(response);
            system("CLS");
        }
    }
};


int main()
{
  Robot* p = new Robot( new ConsoleCommandStrategy );
  p->handle();
  delete p;
  return 0;
}

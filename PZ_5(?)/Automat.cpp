enum Robot_State {ON, OFF};
enum Action_State {ROTATING, MOVING, CLEANING, MANUAL, AWAITING };

class Robot
{
    Robot_State robstate = OFF;
    Action_State actstate = AWAITING;

    public:

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

int main(){
    Robot rob1;
    rob1.Turn_On();
    rob1.Move_Forward(50);
    rob1.Turn_Right(50);
    rob1.Clean(50);
    rob1.Go_Manual();
    rob1.Turn_Off();
}

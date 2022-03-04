class pos{
    public:
    int x;
    int y;
};

class Robot
{
    public:
        pos Find_Graffity(){
        }
        void Move_Forward(float length){
        }
        void Turn_Right(float angle){
        }
};

class Camera 
{
    Robot rob1;
    public:
    void Send_Signal(Robot robo){
    }
    void Detect_Graffity(){
    }
};

int main(){
    Camera cam1;
    Robot rob1;
    cam1.Detect_Graffity();
    cam1.Send_Signal(rob1);
    rob1.Move_Forward(50);
    rob1.Turn_Right(50);
}

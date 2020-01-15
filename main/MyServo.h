#include <Servo.h>

class MyServo
{
  public:
    MyServo(int _pin)
    {
        servo.attach(_pin);
        servo.write(0);
        plus = true;
    }

    void attack()
    {
      if (angle > 90 || angle < 0)
        plus = !plus;
      
      if (plus)
        angle += 1;
      else
        angle -= 1;
      servo.write(angle);
    }

    void stopAttack()
    {
      if (angle != 0)
      {
        angle = 0;
        servo.write(0);
      }
    }

    private:
    Servo servo;
    int angle;
    bool plus;
};

# Modular Libraries for Cytron and L298n

Cytron.h Example

>Cytron motor1(directionPin,pwmPin);   //initializing object for a motor where "motor1" is user defined object, you must pass the direction pin and pwm pin

>motor1.direction(direction)   //specify the direction in which you want to rotate the motor (pass 1 or 0)

>motor1.drive(pwm)   //specify the pwm value it will accelerate or decelerate accordingly

>motor1.step=5;  //specify the step width for acceleration and decelaration

>motor1.interval=10    //specify delay between two steps

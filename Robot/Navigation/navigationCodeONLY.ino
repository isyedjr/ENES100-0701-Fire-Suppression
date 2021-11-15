#include <Enes100.h>
#include <Tank.h>
#include <math.h> 

void setup() {
  
   //Team Name, Mission Type, Marker ID, TX Pin, RX Pin
   Enes100.begin("SWAT", FIRE, 3, 8, 9);
   Tank.begin();

   //set destination
   Enes100.destination.x=3.5;
   Enes100.destination.y=1.5;
  
   Enes100.print("Destination is at (");
   Enes100.print(Enes100.destination.x);
   Enes100.print(", ");
   Enes100.print(Enes100.destination.y);
   Enes100.println(")");

   Enes100.updateLocation();
   
   //orient to mission site
   //if starting point is in lower half
   if (Enes100.location.y<1){
    rotateTo(1.5);
   }
   //if starting point is in upper half
   else{
    rotateTo(-1.5);
   }
   
   //travel to mission site. 
   //move foward about 1 meter
   float startingY= Enes100.location.y;
   while(fabs(Enes100.location.y-startingY)<1){
    setBothMotors(200);
    Enes100.updateLocation();
   }

   Tank.turnOffMotors();

   //complete mission. Mission code here ig
   //...
}

void loop() {
  
  //need to orient towards goal
  float differenceX= Enes100.destination.x- Enes100.location.x;
  float differenceY= Enes100.destination.y- Enes100.location.y;
  rotateTo(atan(differenceY/differenceX));
  setBothMotors(200);

  Enes100.updateLocation();

      //avoid obstacles
      //turn right
      if(Tank.readDistanceSensor(0)<.1){

       do{
          //back up 1 sec
            setBothMotors(-100);
            delay(1000);
          //45 degrees turn
            rotateBy(.78);
            Enes100.updateLocation();
            
       }while(Tank.readDistanceSensor(0)<.1);

        //move foward 1 sec before orienting towards goal again
        setBothMotors(200);
        delay(1000);
        Enes100.updateLocation();
       
      }
      //turn left
      else if(Tank.readDistanceSensor(2)<.1){
        
          do{
           //back up 1 sec
             setBothMotors(-100);
             delay(1000);
           //45 degrees turn
             rotateBy(-.78);
             Enes100.updateLocation();
             
          }while(Tank.readDistanceSensor(2)<.1);

           //move foward 1 sec before orienting towards goal again
            setBothMotors(200);
            delay(1000);
            Enes100.updateLocation();
       }

  //stop at a point before the limbo
  if (fabs(Enes100.location.x-Enes100.destination.x)<.1 && fabs(Enes100.location.y-Enes100.destination.y)<.1){
    rotateTo(0);
    Tank.turnOffMotors();
    exit(0);
  }
  
}


//rotate to specified theta
void rotateTo(float goal){
  
    Enes100.updateLocation();
    float current= Enes100.location.theta;
    float difference= current- goal;

    if (fabs(difference)>.2){
    
      rotateBy(difference);
    }
  
 }

void rotateBy(float radians){
  
  Enes100.updateLocation();
  float current= Enes100.location.theta;
  
  //rotate left
        if (radians<0){
        //(Alternate code) Enes100.location.theta>goal+.01 ||Enes100.location.theta<goal-.01
          while(fabs(Enes100.location.theta-current)<fabs(radians)){
             Tank.setLeftMotorPWM(-200);
             Tank.setRightMotorPWM(200);
             Enes100.updateLocation();
          }
        }
  //rotate right
       else{
         while(fabs(Enes100.location.theta-current)<radians){
            Tank.setRightMotorPWM(-200);
            Tank.setLeftMotorPWM(200);
            Enes100.updateLocation();
          }
       }

      Tank.turnOffMotors();
  
}


 void setBothMotors(int speed){
  Tank.setLeftMotorPWM(speed);
  Tank.setRightMotorPWM(speed);
}

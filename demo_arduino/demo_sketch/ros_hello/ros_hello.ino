/*
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/String.h>

#include <Wire.h>   // standardowa biblioteka Arduino
#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD

ros::NodeHandle nh;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

std_msgs::String str_msg;
ros::Publisher pub("message_size", &str_msg);


void messageCb( const std_msgs::String& msg){
  digitalWrite(13, !digitalRead(13));
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(msg.data);

  char buff[16]={};
  str_msg.data = itoa(strlen(msg.data), buff, 10);
  pub.publish( &str_msg );
}

ros::Subscriber<std_msgs::String> sub("message", &messageCb );

void setup()
{
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(pub);

  lcd.begin(16,2);
      
  lcd.backlight();
  
  lcd.print("Hello, world!");
  delay(500);
}

void loop()
{
  nh.spinOnce();
  
  lcd.setCursor(0, 0);
  
  

}

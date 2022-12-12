#include "esphome.h"
int load = 13;
int dataIn = 5;
int clockIn = 4;

class shift_register : public PollingComponent{
 public:
 
  BinarySensor *bit_0_sensor = new BinarySensor();
  BinarySensor *bit_1_sensor = new BinarySensor();
  BinarySensor *bit_2_sensor = new BinarySensor();
  BinarySensor *bit_3_sensor = new BinarySensor();
  BinarySensor *bit_4_sensor = new BinarySensor();
  BinarySensor *bit_5_sensor = new BinarySensor();
  BinarySensor *bit_6_sensor = new BinarySensor();
  BinarySensor *bit_7_sensor = new BinarySensor();
 
  shift_register() : PollingComponent(150) { }

  void setup() override {
  pinMode(load, OUTPUT);
  pinMode(clockIn, OUTPUT);
  pinMode(dataIn, INPUT);
    
  }

  void update() override {
    //get new data from inputs
      digitalWrite(clockIn, HIGH);
      digitalWrite(load, LOW);
      delayMicroseconds(6);
      digitalWrite(load, HIGH);
      delayMicroseconds(6);
    //clock it in
      byte incoming = shiftIn(dataIn, clockIn, LSBFIRST);
      incoming = ~incoming; //invert bits
    //write outputs
    


    bit_0_sensor->publish_state(((incoming>>0) & 1));
    bit_1_sensor->publish_state(((incoming>>1) & 1));
    bit_2_sensor->publish_state(((incoming>>2) & 1));
    bit_3_sensor->publish_state(((incoming>>3) & 1));
    bit_4_sensor->publish_state(((incoming>>4) & 1));
    bit_5_sensor->publish_state(((incoming>>5) & 1));
    bit_6_sensor->publish_state(((incoming>>6) & 1));
    bit_7_sensor->publish_state(((incoming>>7) & 1));
    
  }
};
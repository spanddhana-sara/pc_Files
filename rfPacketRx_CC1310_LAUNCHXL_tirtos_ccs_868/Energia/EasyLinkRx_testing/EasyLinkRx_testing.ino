/*
  EasyLinkRx
  
  A basic EasyLink Receive example..
  Receive a packet and print the 16-bit value stored in the payload.
  This Sketch is the counterpart of teh EasyLinkTx example.
  
  Hardware Required:
  * CC1310 LaunchPad
  
  This example code is in the public domain.
*/

#include "EasyLink.h"

EasyLink_RxPacket rxPacket;
EasyLink myLink;

uint16_t value;
uint8_t i;
uint32_t freq[] ={ 868000000};
uint32_t freq_rx;

bool check(uint32_t freq){
  EasyLink_setFrequency(freq);
  if (myLink.receive(&rxPacket) == EasyLink_Status_Success)
    return true;
  else return false;}
    
uint32_t set_frequency(uint32_t freq[], int len){
  for(int i=0;i<len; i++){
    if(check(freq[i])) return freq[i]; }
  }
  
void setup() {
  Serial.begin(115200);
  // begin defaults to EasyLink_Phy_50kbps2gfsk
  myLink.begin();
  Serial.println(myLink.version());
  freq_rx = set_frequency(freq, 1);  
}
    
void loop() {
  // Wait / block for 2 second to receive a packet.
  // rxTimeout is in Radio time and needs to be converted from miliseconds to Radio Time
  rxPacket.rxTimeout = EasyLink_ms_To_RadioTime(2000);
  // Turn the receiver on immediately
  rxPacket.absTime = EasyLink_ms_To_RadioTime(0);
  while(myLink.receive(&rxPacket) == EasyLink_Status_Success){
    //Serial.print("Packet received on the frequency: ");
   // Serial.print(EasyLink_getFrequency());
    //Serial.print("    ");
    //Serial.print(rxPacket.payload[0]);
    //Serial.println("start");
    //Serial.print("  Data:  ");
    for(int i = 1; i<rxPacket.len; i++){
       Serial.print(rxPacket.payload[i],HEX);
       //Serial.print(" "); 
       }
    Serial.println();
    }   
    //Serial.println("End");
  freq_rx = set_frequency(freq, 1);  
}

//  EasyLink_Status status;
//  for(int j = 0; j<3; j++){
//    EasyLink_setFrequency(freq[j]);
//    status = myLink.receive(&rxPacket);
//    if (status == EasyLink_Status_Success) {
//    memcpy(&value, &rxPacket.payload, sizeof(uint16_t));
//    Serial.print("Data at Freqency\n");
//    Serial.println(EasyLink_getFrequency());
//    for(i = 0; i<rxPacket.len; i++)
//      { Serial.println(rxPacket.payload[i]);
//      }
//      break;
//    }
//    else{

//    Serial.print("Error receiving packet with status code: ");
//    Serial.print(status);
//    Serial.print(" (");
//    Serial.print(myLink.getStatusString(status));
//    Serial.println(")");
//    Serial.print("No data found at the freqency\n");
//    Serial.println(EasyLink_getFrequency());
    
//    }
 
    
//  }
  
  
  
//}

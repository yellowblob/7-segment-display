#include <SPI.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

EthernetUDP Udp; 
char address[] = "/CountDown";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initializeOSC();
}

void loop() {
  OSCMessage msg;
   int size;
 
   if( (size = Udp.parsePacket())>0)
   {
     
     while(size--){
       msg.fill(Udp.read());
     }

    //Serial.println(msg.hasError());
      if(!msg.hasError()){
        
        
        msg.route("/ping", pingback);
        msg.route("/clear", clearDisplay);
        msg.route("/countdown", characterModeFrame);
        msg.route("/segmentControl", segmentControl);
      }
   }
  
}

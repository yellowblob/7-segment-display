
                              // A UDP instance to let us send and receive packets over UDP
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xE1
};
const IPAddress ip(10,100,51,12);   // IP of your board
const IPAddress outIp(10,100,51,100);   // IP of Control PC
const unsigned int outPort = 9001;          // remote port to receive OSC
const unsigned int localPort = 9000;        // local port to listen for OSC packets (actually not used for sending)

void initializeOSC() {

    // Connect to WiFi network
    //Serial.println();
    //Serial.println();
    //WiFi.config(ip);
    //Serial.print("Connecting to ");
    //Serial.println(ssid);
    Ethernet.init(10); 
    Ethernet.begin(mac, ip);

   // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  while (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // start UDP
  Udp.begin(localPort);
}

void pingback(OSCMessage &msg){
   OSCMessage outMsg("/CountDown/ping");
   outMsg.add(true);
   Udp.beginPacket(outIp, outPort);
   outMsg.send(Udp); // send the bytes to the SLIP stream
   Udp.endPacket(); // mark the end of the OSC Packet
   outMsg.empty(); // free space occupied by message
}

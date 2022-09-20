void characterModeFrame(OSCMessage &msg){
    char digits[3];
    if (msg.isString(0)){
      msg.getString(0,digits,3);
    }
    byte one = digits[0];
    byte two = digits[1];
    
    byte checksum = (one + two) % 0x100;
    byte message[] = {0xAA, 0x56, 0x01, 0x00, 0x00, one, two, checksum };
    Serial.write(message, sizeof(message));
    
}

void segmentControl(OSCMessage &msg){
    Serial.println("correct function");
    if (msg.isInt(0) && msg.isInt(1)){
      byte one = msg.getInt(0);
      byte two = msg.getInt(1);
      Serial.println(one);
      Serial.println(two);
      segmentModeFrame(one, two);    
    }    
}

void segmentModeFrame(byte one, byte two){
  byte checksum = (one + two) % 0x100;
  byte message[] = {0xAA, 0x55, 0x01, 0x00, 0x00, one, two, checksum };
  Serial.write(message, sizeof(message));
}

void clearDisplay(OSCMessage &msg){
  segmentModeFrame(0, 0);
}

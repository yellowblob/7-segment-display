# 7-Segment Display

This code is running on an arduino with an ethernet shield. It translates incoming OSC messages to RS-485 messages for the display controller.

OSC messages:  
/countdown [two-digit number with leading zeros]  
/segmentControl [data byte 1] [data byte 2]  
/clear 1  
/ping 1

For ip and port setting check /Countdown/OSC.ino lines 6 to 9.
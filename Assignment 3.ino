/*
Write a sketch that allows a user to access data in EEPROM using the serial monitor.

Write a sketch that allows a user to access data in EEPROM using the serial monitor. 
In the serial monitor the user should be able to type one of two commands: “read” and “write. 
"Read" takes one argument, an EEPROM address. 
"Write" takes two arguments, an EEPROM address and a value.

For example, if the user types “read 3” then the contents of EEPROM address 3 should be printed to the serial monitor. 
If the user types “write 3 10” then the value 10 should be written into address 3 of the EEPROM.

*/


#include <EEPROM.h>
void setup() 
{
  Serial.begin(9600);
}
int address;
int dataToWrite;

void loop() 
{
  String buffer = "";
  buffer = Serial.readString();
  if(buffer.startsWith("read")) {
    address = buffer.substring(buffer.indexOf(' ') +1).toInt();
    Serial.print("Data from the Address : ");
    Serial.print(address);
    Serial.println();
    Serial.println(EEPROM.read(address)); 
  } else if(buffer.startsWith("write")) {
    address = buffer.substring(6,7).toInt();
    dataToWrite = buffer.substring(8).toInt();
    Serial.print("Written ");
    Serial.print(dataToWrite);
    Serial.println();
    Serial.print("to the Address: ");
    Serial.print(address);
    Serial.println();
    EEPROM.write(address,dataToWrite); 
  }
}
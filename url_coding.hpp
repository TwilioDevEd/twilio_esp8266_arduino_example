#ifndef URL_CODING_HPP
#define URL_CODING_HPP

/*
 
 From: https://github.com/zenmanenergy/ESP8266-Arduino-Examples/blob/master/helloWorld_urlencoded/urlencode.ino
 
*/
#include <Arduino.h>

unsigned char h2int(char c);
String urldecode(String str);
String urlencode(String str);

#endif // URL_CODING_HPP

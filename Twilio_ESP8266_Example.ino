/*
 * Twilio SMS and MMS on ESP8266 Example.
 */

#include <ESP8266WiFi.h>
#include "twilio.hpp"

// Use software serial for debugging?
#define USE_SOFTWARE_SERIAL 0

// Your network SSID and password
const char* ssid = "YOUR_NETWORK_SSID";
const char* password = "NETWORK_PASSWORD";

// Find the api.twilio.com SHA1 fingerprint, this one was valid as 
// of January 2017.
const char* fingerprint = "47 18 D6 BE F5 D0 BF CE 01 B7 AD BD 96 3A AA 46 F1 8C F1 A5";

// Twilio account specific details, from https://twilio.com/console
const char* account_sid = "ACXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
const char* auth_token = "AUTH_TOKEN_HERE";

// Details for the SMS we'll send with Twilio.  Should be a number you own 
// (check the console, link above).
String to_number   = "+18005551212";
String from_number = "+18005551212";
String message_body    = "Hello from Twilio and the ESP8266!";

// Optional - a url to an image.  See 'MediaUrl' here: 
// https://www.twilio.com/docs/api/rest/sending-messages
String media_url = "";

// Global twilio object
Twilio *twilio;

//  Optional software serial debugging
#if USE_SOFTWARE_SERIAL == 1
#include <SoftwareSerial.h>
extern SoftwareSerial swSer(14, 4, false, 256);
#endif


/*
 * Setup function for ESP8266 Twilio Example.
 * 
 * Here we connect to a friendly wireless network, instantiate our twilio 
 * object, optionally set up software serial, then send a SMS or MMS message.
 */
void setup() {
  WiFi.begin(ssid, password);
  twilio = new Twilio(account_sid, auth_token, fingerprint);

  #if USE_SOFTWARE_SERIAL == 1
  swSer.begin(115200);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    swSer.print(".");
  }
  swSer.println("");
  swSer.println("Connected to WiFi, IP address: ");
  swSer.println(WiFi.localIP());
  #else
  while (WiFi.status() != WL_CONNECTED) delay(1000);
  #endif

  // Response will be filled with connection info and Twilio API responses
  String response;
  bool success = twilio->send_message(
        to_number,
        from_number,
        message_body,
        response,
        media_url
  );
  
  #if USE_SOFTWARE_SERIAL == 1
  swSer.println(response);
  #endif
}


/* Loop is the common Arduino loop; it'll run until power is cut. */
void loop() {
  // Insert more code in here!
}

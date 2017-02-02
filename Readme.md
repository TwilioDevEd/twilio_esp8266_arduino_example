# Twilio Messaging Example on the ESP8266 (C++, Arduino IDE)

An example application that demonstrates how to send SMS or MMS messages with an ESP8266 connected to a friendly WiFi network, as well as hosts a basic server to receive and respond to SMS and MMS messages.

Please read [our full article]() for more information.

## Build example:

In Arduino IDE, first ensure your ESP8266 is burned with the Arduino bootloader and connected.  Then, merely adjust the globals at the top of the .ino file and hit the 'Upload' button.

You'll then want to edit the following variables in twilio_esp8266_arduino_example.ino:
* ssid: Your network SSID
* password: Network's password
* fingerprint (maybe): The SHA1 Fingerprint of api/twilio.com, you
    can check with a web browser
* account_sid: from twilio.com/console
* auth_token: from twilio.com/console
* to_number: A number to send the test SMS (or MMS) to
* from_number: An number from twilio.com/console authorized to send SMS and/or MMSes
* message_body: Message body to send
* master_number: 'Authorized' number for this ESP8266 example
* media_url (optional): Url to an image to send a test MMS

## Run example:

Will run automatically once uploaded to the board.  If you do not get a message, enable serial debugging.

Either serial debugging or perhaps a peek at your router screen will reveal the assigned IP address of the ESP8266.  <that ip>:8000/message is the webhook of interest; use ngrok or another means to espose it to Twilio.  Note that you'll need to provide a https endpoint!

## Motivations

Hopefully you can use this as the base of your ESP8266 project with Twilio!

## Meta & Licensing

* [MIT License](http://www.opensource.org/licenses/mit-license.html)
* Lovingly crafted by Twilio Developer Education.

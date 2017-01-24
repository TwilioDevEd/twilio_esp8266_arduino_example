#ifndef TWILIO_HPP
#define TWILIO_HPP
#include <Arduino.h>
#include <WiFiClientSecure.h>
#include "base64.h"
#include "url_coding.hpp"

class Twilio {
public:
        Twilio(
                const char* accound_sid_in, 
                const char* auth_token_in,
                const char* fingerprint_in
        );
        // Empty destructor
        ~Twilio() { }; 

        void set_account_sid(const String& accound_sid_in);
        void set_auth_token(const String& auth_token_in);
        bool send_message(
                const String& to_number,
                const String& from_number,
                const String& message_body,
                String& response,
                const String& picture_url = ""
        );

private:
        // Account SID and Auth Token come from the Twilio console.
        // See: https://twilio.com/console for more.

        // Used for the username of the auth header
        String account_sid;
        // Used for the password of the auth header
        String auth_token;
        // To store the Twilio API SHA1 Fingerprint (get it from a trusted browser)
        String fingerprint;

        // Utilities for now and future expansion
        static String _get_auth_header(const String& user, const String& password);
        
};

#endif // TWILIO_HPP

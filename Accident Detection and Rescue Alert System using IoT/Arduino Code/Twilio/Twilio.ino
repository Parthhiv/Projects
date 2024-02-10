#include "twilio.hpp"
static const char *ssid = "Net-Ledha";
static const char *password = "321703321703";
static const char *account_sid = "ACe8004b9507ac32a30cb9ff3a5cb4873f";
static const char *auth_token = "99f331074d93e11bde966305067c59cb";
static const char *from_number = "+15803660855";
static const char *to_number = "+919032321703";
static const char *message = "Sent from my ESP32";
Twilio *twilio;
void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to WiFi network..");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){ 
    Serial.print("..");
    delay(500);
  }
  Serial.println("Connected!");
  twilio = new Twilio(account_sid, auth_token);
  delay(1000);
  String response;
  bool success = twilio->send_message(to_number, from_number, message, response);
  if (success){
    Serial.println("Sent message successfully!");
  }
  else{
    Serial.println(response);
  }
}
void loop() {

}

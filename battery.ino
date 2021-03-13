#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include "config.h"

WiFiClient espClient;
PubSubClient client(espClient);
const float PIN_RESOLUTION = 4095.0;
const float VOLTAGE_DIVIDED = 2.0;
const char *BATTERY_STATUS_QUEUE = "battery/status";
const int ONE_MINUTE = 60000;

void setup()
{
  while (!Serial)
    ;
  Serial.begin(9600);
  wifiConnect();
  mqttConnect();
}

void loop()
{
  const int capacity = JSON_OBJECT_SIZE(2);
  StaticJsonDocument<capacity> doc;
  doc["voltage"] = voltage();
  doc["millis"] = millis();
  while (!client.publish(BATTERY_STATUS_QUEUE, doc.as<String>().c_str()))
  {
    wifiConnect();
    mqttConnect();
  }
  Serial.printf("DEBUG: Battery Voltage is %s\n", doc.as<String>().c_str());
  delay(ONE_MINUTE);
}

float voltage()
{
  float percentage = analogRead(A13) / PIN_RESOLUTION;
  return (percentage * VOLTAGE_DIVIDED * 3.3 * 1.1);
}

void wifiConnect()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.println("Connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }

    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
  }
}

void mqttConnect()
{
  client.setServer(MQTT_SERVER, MQTT_PORT);
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    if (client.connect(clientId().c_str(), MQTT_USER, MQTT_PASSWORD))
    {
      Serial.println("connected");
      return;
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.println(client.state());
      delay(1000);
    }
  }
}

String clientId()
{
  String clientId = "ESP32_CLIENT-";
  clientId += String(random(0xffff), HEX);
  return clientId;
}
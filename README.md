# Battery
ESP32 project for calculating battery health

You will need to add a config.h header file to get things going:

```C
/* config.h */

#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

#define MQTT_SERVER "YOUR_MQQT_HOST"     /* Ex. "driver.cloudmqtt.com" */
#define MQTT_PORT YOUR_MQQT_PORT         /* Ex. 18846 */
#define MQTT_USER "YOUR_MQQT_USERNAME"
#define MQTT_PASSWORD "YOUR_MQQT_PASSWORD"
```

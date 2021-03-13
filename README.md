# Battery
ESP32 project for calculating battery health

## Research
Most of the source material I got for this project is from the Adafruit site:

If you’re running off of a battery, chances are you wanna know what the voltage is at! That way you can tell when the battery needs recharging. Lipoly batteries are ‘maxed out’ at 4.2V and stick around 3.7V for much of the battery life, then slowly sink down to 3.2V or so before the protection circuitry cuts it off. By measuring the voltage you can quickly tell when you’re heading below 3.7V

Since the ESP32 has tons of ADC pins, we ‘sacrifice’ one for Lipoly battery monitoring. You can read half of the battery voltage off of A13. Don’t forget to double the voltage you read, since there is a divider.

## Running the project

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



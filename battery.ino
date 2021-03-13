
const float PIN_RESOLUTION = 4095.0;
const float VOLTAGE_DIVIDED = 2.0;

void setup()
{
  while (!Serial)
    ;
  Serial.begin(9600);
}

void loop()
{
  float percentage = analogRead(A13) / PIN_RESOLUTION;
  Serial.printf("DEBUG: Battery Voltage is %f V\n", percentage * VOLTAGE_DIVIDED * 3.3 * 1.1);
  delay(5000);
}
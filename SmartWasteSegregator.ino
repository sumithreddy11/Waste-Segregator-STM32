#include <Servo.h>


// Smart Waste Segregation using STM32 ARM Cortex-M4


//  Pin Configuration 
#define SERVO_PIN PA8      // PWM Pin
#define SOIL_PIN  PA0      // Analog Input

Servo servo;

//  Servo Positions 
const int REST_POS  = 90;      // Neutral Position
const int LEFT_POS  = 120;     // Wet Bin
const int RIGHT_POS = 60;      // Dry Bin

// Predefined  Moisture Threshold 
// Dry  : 100 - 380
// Wet  : 650 - 720
const int moistureThreshold = 500;

int moistureValue = 0;

void setup()
{
    Serial.begin(9600);

    servo.attach(SERVO_PIN);
    servo.write(REST_POS);

    delay(500);

    Serial.println("--------------------------------");
    Serial.println("STM32 Smart Waste Segregator");
    Serial.println("--------------------------------");
}

void loop()
{
    // Read Moisture Sensor
    moistureValue = analogRead(SOIL_PIN);

    Serial.print("Current Moisture Value : ");
    Serial.println(moistureValue);


    // Wet Waste

    if (moistureValue > moistureThreshold)
    {
        Serial.println("Wet Waste Detected");
        Serial.println("Tilting LEFT");

        servo.write(LEFT_POS);

        delay(1000);

        servo.write(REST_POS);

        Serial.println("Servo Returned to Rest");
    }


    // Dry Waste

    else
    {
        Serial.println("Dry Waste Detected");
        Serial.println("Tilting RIGHT");

        servo.write(RIGHT_POS);

        delay(1000);

        servo.write(REST_POS);

        Serial.println("Servo Returned to Rest");
    }

    Serial.println("------------------------------");

    delay(1500);
}

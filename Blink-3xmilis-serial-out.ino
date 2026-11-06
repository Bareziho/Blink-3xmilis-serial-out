const unsigned long interval1 = 500;
const unsigned long interval2 = 1300;
const unsigned long interval3 = 2300;
const unsigned long interval4 = 3700;

unsigned long timer1 = 0;
unsigned long timer2 = 0;
unsigned long timer3 = 0;
unsigned long timer4 = 0;

bool ledState = false;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);
    Serial.println("Multi-timer experiment");
}

void loop()
{
    unsigned long now = millis();

    // Timer 1: LED každých 500 ms
    if (now - timer1 >= interval1)
    {
        timer1 = now;
        ledState = !ledState;
        digitalWrite(LED_BUILTIN, ledState);
        Serial.print("LED: ");
        Serial.println(ledState ? "ON" : "OFF");
    }

    // Timer 2: výpis každých 1300 ms
    if (now - timer2 >= interval2)
    {
        timer2 = now;
        Serial.println("Timer 2");
    }

    // Timer 3: výpis každých 2300 ms
    if (now - timer3 >= interval3)
    {
        timer3 = now;
        Serial.println("Timer 3");
    }
    // Timer 4: výpis každých 3700 ms
    if (now - timer4 >= interval4)
    {
        timer4 = now;
        Serial.println("Timer 4");
    }
}

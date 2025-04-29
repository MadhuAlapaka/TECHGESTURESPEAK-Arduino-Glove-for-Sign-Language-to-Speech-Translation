#include <Wire.h>
#include <LiquidCrystal_I2C.h>   // Library for I2C LCD display
#include "mp3tf16p.h"            // Include the MP3 player library

MP3Player mp3(10, 11);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize with I2C address 0x27 and 16x2 display

int flexSensorPin = A0;          // Define the flex sensor input pin

void setup() {
    Serial.begin(9600);
    mp3.initialize();

    lcd.begin(16, 2);             // Initialize the LCD with 16 columns and 2 rows
    lcd.backlight();              // Turn on the LCD backlight
    lcd.print("System Ready!");   // Display initial message
    delay(2000);                  // Delay to allow reading initial message
    lcd.clear();                  // Clear display

    Serial.println("Starting flex sensor check...");
}

void loop() {
    int flexSensorValue = analogRead(flexSensorPin); // Read flex sensor value

    if (flexSensorValue > 500) {
        lcd.clear();
        lcd.print("I need food");        // Display "I need food"
        mp3.playTrackNumber(2, 25);      // Play audio track 1
    } 
    else if (flexSensorValue < 300) {
        lcd.clear();
        lcd.print("I need water");       // Display "I need water"
        mp3.playTrackNumber(3, 25);      // Play audio track 2
    } 

    delay(500);  // Short delay to avoid rapid switching between messages
}	

#include "SoftwareSerial.h”
#include "DFRobotDFPlayerMini.h"

#define MP3_ERROR_ONLY 1
#define MP3_ALL_MESSAGE 2

class MP3Player
{
private:
    SoftwareSerial *mySoftwareSerial;
    void statusOnSerial(uint8_t type, int value);
    void waitPlayIsTerminated(void);
    int p_RX;
    int p_TX;

public:
    DFRobotDFPlayerMini player;
    MP3Player(int RX, int TX);
    ~MP3Player();
    void playTrackNumber(int trackNumber, int volume, boolean waitPlayTerminated = true);
    boolean playCompleted(void);
    void initialize(void);
    int serialPrintStatus(int errorOnly);
};

MP3Player::MP3Player(int RX, int TX)
{
    p_TX = TX;
    p_RX = RX;
}

MP3Player::~MP3Player()
{
}

void MP3Player::initialize(void)
{
    mySoftwareSerial = new SoftwareSerial(p_RX, p_TX);

    mySoftwareSerial->begin(9600);
    Serial.println(F("Initializing MP3Player ..."));

    if (!player.begin(*mySoftwareSerial,true,false))
    {
        Serial.println(F("Unable to begin:"));
        Serial.println(F("1.Please recheck the connection!"));
        Serial.println(F("2.Please insert the SD card!"));
        while (true)
            ;
    }
    player.volume(10);
    Serial.println(F("MP3Player online."));
}

void MP3Player::playTrackNumber(int trackNumber, int volume, boolean waitPlayTerminated)
{
    player.volume(volume);
    player.play(trackNumber);
    if (waitPlayTerminated)
    {
        waitPlayIsTerminated();
    }
}

void MP3Player::waitPlayIsTerminated(void)
{
    while (!playCompleted())
    {
    }
}

boolean MP3Player::playCompleted(void)
{
    if (player.available())
    {
        return player.readType() == DFPlayerPlayFinished;
    }
    return false;
}

// Print the detail message from DFPlayer to handle different errors and states.
// 
int MP3Player::serialPrintStatus(int verbose)
{
    if (player.available())
    {
        uint8_t type = player.readType();
        int value = player.read();
        if (verbose == MP3_ERROR_ONLY)
        {
            if (type == DFPlayerError)
            {
                statusOnSerial(type, value);
            }
        }
        else
        {
            statusOnSerial(type, value);
        }
        if(type == DFPlayerError) {
            return value;
        } else {
            return 0;
        }
    }
}

void MP3Player::statusOnSerial(uint8_t type, int value)
{
    switch (type)
    {
    case TimeOut:
        Serial.println(F("Time Out!"));
        break;
    case WrongStack:
        Serial.println(F("Stack Wrong!"));
        break;
    case DFPlayerCardInserted:
        Serial.println(F("Card Inserted!"));
        break;
    case DFPlayerCardRemoved:
        Serial.println(F("Card Removed!"));
        break;
    case DFPlayerCardOnline:
        Serial.println(F("Card Online!"));
        break;
    case DFPlayerPlayFinished:
        Serial.print(F("Number:"));
        Serial.print(value);
        Serial.println(F(" Play Finished!"));
        break;
    case DFPlayerError:
        Serial.print(F("DFPlayerError:"));
        switch (value)
        {
        case Busy:
            Serial.println(F("Card not found"));
            break;
        case Sleeping:
            Serial.println(F("Sleeping"));
            break;
        case SerialWrongStack:
            Serial.println(F("Get Wrong Stack"));
            break;
        case CheckSumNotMatch:
            Serial.println(F("Check Sum Not Match"));
            break;
        case FileIndexOut:
            Serial.println(F("File Index Out of Bound"));
            break;
        case FileMismatch:
            Serial.println(F("Cannot Find File"));
            break;
        case Advertise:
            Serial.println(F("In Advertise"));
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

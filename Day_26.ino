
Adventure Kit: 30 Days In Space
Introduction
Welcome To A Strange New World
How to be successful with this course (Ignore only if you hate learning)
Daily Broadcasts
Day 1: Incoming Broadcast From InventrCorp
2 Topics
Day 2: It’s really dark in here…
Day 3: I’m worried about your battery levels
Day 4: Cabin lighting
Day 5: Creative Day 1
1 Quiz
Day 6: Time to fix the battery
Day 7: We still need to keep an eye on this
Day 8: Adding some color to this dark place
Day 9: A better way to do things
Day 10: Creative Day 2
1 Quiz
Day 11: Starting Your Control Panel
Day 12: Can you hear us?
1 Topic
Day 13: HERO Security 101
Day 14: Advanced Security Panel
Day 15: Creative Day 3
1 Quiz
Day 16: A Fancy New Display
Day 17: H jyfwapj tlzzhnl
Day 18: The surface seems so much closer
Day 19: New Horizons
Day 20: Creative Day 4
1 Quiz
Day 21: Hello New World
Day 22: Display Panel Details
Day 23: Launch System
Day 24: Back to orbit
Day 25: Creative Day 5
1 Quiz
Day 26: HERO_AUTOPILOT.EXE (Fun W/Bitmaps)
DAY 27: HERO_AUTOPILOT.EXE PT 2
DAY 28: Landing Gear Part 1
DAY 29: Landing Gear Part 2
Day 30: Home Sweet Home! (Mission Complete!)
1 Quiz
Bonus Training!
Ready for more projects? (E-Books And Intense Training Video)
Breadboard Explained
How to NOT Break Your HERO Board
HERO Board Anatomy
Voltage, Amperes, Wattage
Make A Suggestion or Report A Bug
Leave Your Feedback
70% COMPLETE
29/41 Steps
Previous Lesson
Next Lesson
Hello, ryantgott!
Day 26: HERO_AUTOPILOT.EXE (Fun W/Bitmaps)
Adventure Kit: 30 Days In Space  Day 26: HERO_AUTOPILOT.EXE (Fun W/Bitmaps)
COMPLETE



// DEFINES
#define SW A3 // RotaryEncoder SW Pin
#define DT A2 // RotaryEncoder DT Pin
#define CLK A1 // RotaryEncoder CLK Pin
#define SuccessfulLandingIndicator 5 // LED
#define LandingInitLever 4 // Dip 1 Pin
#define LandingConfigLever 3 // Dip 2 Pin
#define LandingFinalLever 2 // Dip 3 Pin
 
// LIBRARIES
#include "U8glib.h"
 
// MANDADTORY OLED CONFIGURATION
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI
 
// OLED CONSTANTS
const uint8_t OFF[] = {0, 0, 0, 0};
 
static unsigned char canvasToConvert [] U8G_PROGMEM= {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0xe0, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00,
   0x00, 0xf0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xc0, 0x1f, 0x00, 0x00, 0xf8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfc, 0x07, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x7f, 0x00,
   0x00, 0xfc, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf0, 0x7f, 0x00, 0x00, 0xfe, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xfe, 0x0f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00,
   0x00, 0xfe, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf0, 0x7f, 0x00, 0x00, 0xfe, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x00, 0x00, 0xfe, 0x0f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00,
   0x00, 0xfe, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf0, 0x7f, 0x00, 0x00, 0xfe, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xfe, 0x0f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00,
   0x00, 0xfe, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xe0, 0x7f, 0x00, 0x00, 0xfe, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfc, 0x07, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00,
   0x00, 0xfc, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xc0, 0x1f, 0x00, 0x00, 0xf8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0f, 0x00, 0x00, 0xf0, 0x01, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0,
   0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xde, 0x07, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xe0, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f,
   0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xf0, 0x01, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00,
   0x00, 0x00, 0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xc0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00,
   0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x00, 0x80, 0x3f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x03, 0x00,
   0x00, 0xe0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf0, 0x0f, 0x00, 0x00, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x7f, 0x00, 0x00, 0xfe, 0x03, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x07,
   0xf0, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff,
   0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x0f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00 };
 
 
// INVENTR LOGO', 128x64px
static unsigned char Inventr [] U8G_PROGMEM = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf0, 0x01, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x07, 0x00, 0x00, 0x00, 0x00, 0xf8,
   0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x07, 0x00,
   0x00, 0x00, 0x00, 0xfc, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xff, 0x0f, 0x00, 0x00, 0x07, 0x00, 0xfe, 0x3f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x0f, 0x00, 0xc0, 0x1f, 0x00, 0xfe,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x0f, 0x00,
   0xe0, 0x3f, 0x00, 0xfe, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xe0, 0xff, 0x0f, 0x00, 0xf0, 0x7f, 0x00, 0xfe, 0xff, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x0f, 0x00, 0xf0, 0x7f, 0x00, 0xfe,
   0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0x07, 0x00,
   0xf0, 0x7f, 0x00, 0xfc, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xfc, 0xff, 0x07, 0x00, 0xf8, 0x7f, 0x00, 0xfc, 0xff, 0x7f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0x03, 0x00, 0xf8, 0x7f, 0x38, 0xf0,
   0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x00,
   0xfc, 0x7f, 0x78, 0xe0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80,
   0xff, 0xff, 0x00, 0x00, 0xfc, 0x3f, 0xfc, 0xc1, 0xff, 0xff, 0x07, 0x00,
   0x00, 0x00, 0x00, 0xc0, 0xff, 0x7f, 0x00, 0x00, 0xfe, 0x3f, 0xfc, 0x03,
   0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x1f, 0x00, 0x03,
   0xfe, 0x1f, 0xfe, 0x0f, 0xfe, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xf0,
   0xff, 0x0f, 0x80, 0x03, 0xfe, 0x1f, 0xfe, 0x1f, 0xf8, 0xff, 0x7f, 0x00,
   0x00, 0x00, 0x00, 0xf8, 0xff, 0x07, 0x8c, 0x03, 0xff, 0x1f, 0xff, 0x7f,
   0xf0, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x07, 0x1f, 0x00,
   0xff, 0x0f, 0xff, 0xff, 0xc0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0xfe,
   0xff, 0x03, 0x1f, 0x80, 0xff, 0x8f, 0xff, 0xff, 0x83, 0xff, 0xff, 0x03,
   0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x1f, 0x80, 0xff, 0x87, 0xff, 0xff,
   0x07, 0xfe, 0xff, 0x07, 0x00, 0x00, 0x80, 0xff, 0xff, 0x00, 0x1e, 0xc0,
   0xff, 0x87, 0xff, 0xff, 0x1f, 0xfc, 0xff, 0x07, 0x00, 0x00, 0xc0, 0xff,
   0x7f, 0x38, 0xc0, 0xc0, 0xff, 0xc3, 0xff, 0xff, 0x3f, 0xf0, 0xff, 0x07,
   0x00, 0x00, 0xe0, 0xff, 0x3f, 0xfc, 0xc0, 0xc0, 0xff, 0xc3, 0xff, 0xff,
   0x7f, 0xf8, 0xff, 0x03, 0x00, 0x00, 0xf0, 0xff, 0x1f, 0xfe, 0x01, 0xe0,
   0xff, 0xe3, 0xff, 0xff, 0x3f, 0xfc, 0xff, 0x03, 0x00, 0x00, 0xf0, 0xff,
   0x0f, 0xff, 0x03, 0xe0, 0xff, 0xe1, 0xff, 0xf3, 0x1f, 0xfe, 0xff, 0x01,
   0x00, 0x00, 0xfc, 0xff, 0x87, 0xff, 0x03, 0xf0, 0xff, 0xf1, 0xc3, 0xe3,
   0x0f, 0xff, 0xff, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xc3, 0xff, 0x07, 0xf0,
   0xff, 0xf0, 0xc1, 0xe3, 0x87, 0xff, 0x7f, 0x00, 0x00, 0x00, 0xff, 0xff,
   0xe1, 0xe7, 0x0f, 0xf8, 0xff, 0xf8, 0xc1, 0xf3, 0xc3, 0xff, 0x3f, 0x00,
   0x00, 0x80, 0xff, 0xff, 0xf0, 0xe7, 0xff, 0xf8, 0x7f, 0xf8, 0xe3, 0xff,
   0xe1, 0xff, 0x1f, 0x00, 0x00, 0xc0, 0xff, 0x7f, 0xf8, 0xff, 0x7f, 0xfc,
   0x7f, 0xfc, 0xff, 0xff, 0xf0, 0xff, 0x0f, 0x00, 0x00, 0xe0, 0xff, 0x3f,
   0xfc, 0xff, 0x7f, 0xfc, 0x7f, 0xfc, 0xff, 0x7f, 0xf8, 0xff, 0x07, 0x00,
   0x00, 0xf0, 0xff, 0x1f, 0xfe, 0xff, 0x3f, 0xfc, 0x3f, 0xfc, 0xff, 0x3f,
   0xfc, 0xff, 0x03, 0x00, 0x00, 0xf8, 0xff, 0x0f, 0xff, 0xcf, 0x3f, 0xfe,
   0x3f, 0xfe, 0xff, 0x1f, 0xfe, 0xff, 0x01, 0x00, 0x00, 0xf8, 0xff, 0x87,
   0xff, 0x87, 0x1f, 0xfe, 0x1f, 0xfa, 0xcf, 0x0f, 0xff, 0xff, 0x00, 0x00,
   0x00, 0xfc, 0xff, 0xc3, 0x8f, 0x87, 0x1f, 0xff, 0x1f, 0xe0, 0xcf, 0x87,
   0xff, 0x7f, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xe1, 0x87, 0x87, 0x1f, 0xff,
   0x0f, 0xc0, 0xff, 0xc3, 0xff, 0x3f, 0x00, 0x00, 0x80, 0xff, 0xff, 0xf0,
   0x8f, 0xcf, 0x8f, 0xff, 0x0f, 0x80, 0xff, 0xe1, 0xff, 0x1f, 0x00, 0x00,
   0x80, 0xff, 0x7f, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0x07, 0x80, 0xff, 0xf0,
   0xff, 0x0f, 0x00, 0x00, 0xc0, 0xff, 0x3f, 0xfc, 0xff, 0xff, 0xc7, 0xff,
   0x07, 0x02, 0x7f, 0xf8, 0xff, 0x07, 0x00, 0x00, 0xc0, 0xff, 0x1f, 0xfe,
   0xff, 0xff, 0xc7, 0xff, 0x07, 0x07, 0x3e, 0xfc, 0xff, 0x03, 0x00, 0x00,
   0xc0, 0xff, 0x3f, 0xf8, 0xff, 0xff, 0xc3, 0xff, 0x03, 0x72, 0x00, 0xfe,
   0xff, 0x01, 0x00, 0x00, 0xc0, 0xff, 0x7f, 0xf0, 0xff, 0xff, 0xe3, 0xff,
   0x03, 0xf0, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xc1,
   0xff, 0xff, 0xe1, 0xff, 0x01, 0xf8, 0x81, 0xff, 0x7f, 0x00, 0x00, 0x00,
   0x80, 0xff, 0xff, 0x83, 0xff, 0xff, 0xf1, 0xff, 0x01, 0xf8, 0xc0, 0xff,
   0x3f, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x0f, 0xfe, 0xff, 0xf0, 0xff,
   0x80, 0xf1, 0xe0, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x1f,
   0xfc, 0xff, 0xf0, 0xff, 0xc0, 0x01, 0xf0, 0xff, 0x1f, 0x00, 0x00, 0x00,
   0x00, 0xfc, 0xff, 0x3f, 0xf0, 0x7f, 0xf8, 0xff, 0xc0, 0x01, 0xf8, 0xff,
   0x07, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xc0, 0x7f, 0xf8, 0x7f,
   0x00, 0x00, 0xfc, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff,
   0x81, 0x7f, 0xfc, 0x7f, 0x00, 0x00, 0xfe, 0xff, 0x01, 0x00, 0x00, 0x00,
   0x00, 0xc0, 0xff, 0xff, 0x07, 0x3e, 0xfc, 0x3f, 0x00, 0x00, 0xff, 0xff,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x0f, 0x3c, 0xfe, 0x3f,
   0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff,
   0x3f, 0x18, 0xfe, 0x1f, 0x00, 0xc0, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xf8, 0xff, 0x7f, 0x00, 0xff, 0x1f, 0x00, 0xe0, 0xff, 0x3f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x7f, 0x00, 0xff, 0x1f,
   0x00, 0xe0, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff,
   0x7f, 0x00, 0xff, 0x0f, 0x00, 0xf0, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0xff, 0xff, 0x00, 0xff, 0x0f, 0x00, 0xf0, 0xff, 0x07,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0x00, 0xff, 0x07,
   0x00, 0xf0, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
   0x7f, 0x00, 0xfe, 0x07, 0x00, 0xe0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0xfc, 0x03, 0x00, 0xe0, 0x7f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0xf8, 0x00,
   0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x1f, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
   0x00, 0x00, 0x00, 0x00 };
 
static unsigned char defaultFace [] U8G_PROGMEM = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x3e, 0x00, 0xf8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0xf0, 0x0f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x0f, 0x00,
   0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf8, 0x07, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00,
   0x00, 0xf0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x06, 0x00, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x80, 0x7f, 0x00, 0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x00, 0xf0, 0x0f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x01,
   0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf0, 0xe1, 0x03, 0x1c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xc0, 0x03, 0x1c, 0x78, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x86, 0x03,
   0x8c, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x70, 0x87, 0x03, 0x8e, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x86, 0x03, 0x0c, 0x71, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x80, 0x03,
   0x1c, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x60, 0xc0, 0x03, 0x1c, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe1, 0x01, 0x3c, 0x3c, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x01,
   0xf8, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x80, 0xff, 0x00, 0xf0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0xe0, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x80, 0x01, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17,
   0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xff, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x80, 0x01, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x7e,
   0x00, 0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x06, 0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x01,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00,
   0x00, 0xf0, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x3c, 0x00, 0x00, 0x00, 0xf8, 0xfd, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x00,
   0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xe0, 0x07, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0xc0, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x01,
   0xf8, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xfe, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff,
   0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe7, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60,
   0xe6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x60, 0xe4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe4, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
   0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x73, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00 };
 
 
 
// OLED Display output
void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  //u8g.drawStr( 0, 22, "Hello World");
  u8g.drawXBMP( 0, 0, 128, 64, canvasToConvert);
}
 
void setup(){
  Serial.begin(9600);
 
  pinMode(LandingInitLever, INPUT);
  pinMode(LandingConfigLever, INPUT);
  pinMode(LandingFinalLever, INPUT);
  pinMode(SuccessfulLandingIndicator, OUTPUT);
 
  u8g.setColorIndex(1); // pixel on
}
 
 
void loop(){
 u8g.firstPage();
  do {
    draw();
  } while( u8g.nextPage() );
 
  delay(5000);
}
 
LIBRARIES, DRIVERS, ETC: CLICK HERE

Previous Lesson
Back to Course
Next Lesson
29 Comments
Collapse Comments
Gabrielle Melton
February 25, 2021 at 11:41 pm
The diagram for the wiring is incorrect which caused me a lot of headache. The SCL and SCA on the u8g should be wired differently – SCL needs to be in A5 and SCA needs to be in A4. If you’re having issues working the display, that is likely the reason.

Reply
Rick Patterson
March 4, 2021 at 9:53 pm
See Stephanie Clay’s comments on Day 21 about these pins.

Reply
Theodore Volkert
March 16, 2021 at 3:19 pm
Thank you! I was just about to go hunting for that…

Reply
Henry Kafton
November 11, 2021 at 9:39 pm
And the Dip switch wiring is wrong to! In the diagram it says to connect the 3 switch to 1 on the HERO bored. But in the code it says that it’s connected to 2 on the HERO board.

Reply
Dave Litle
April 7, 2021 at 4:14 pm
why is SDA and SCL pins connected to A4 & A5 and not the SDA & SCL pins on the board??

Reply
Kevin Hilferty
April 15, 2021 at 3:40 pm
I keep getting the following error message when trying to upload:

Arduino: 1.8.13 (Windows 10), Board: “Arduino Uno”

C:\Users\khilf\AppData\Local\Temp\cc4Ievlg.s: Assembler messages:

C:\Users\khilf\AppData\Local\Temp\cc4Ievlg.s:6309: Warning: ignoring changed section attributes for .progmem.data

Sketch uses 10962 bytes (33%) of program storage space. Maximum is 32256 bytes.

Global variables use 559 bytes (27%) of dynamic memory, leaving 1489 bytes for local variables. Maximum is 2048 bytes.

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x67

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x67

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x67

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 4 of 10: not in sync: resp=0x67

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 5 of 10: not in sync: resp=0x67

avrdude: stk500_recv(): programmer is not responding

Problem uploading to board. See http://www.arduino.cc/en/Guide/Troubleshooting#upload for suggestions.

avrdude: stk500_getsync() attempt 6 of 10: not in sync: resp=0x67

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 7 of 10: not in sync: resp=0x67

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 8 of 10: not in sync: resp=0x67

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 9 of 10: not in sync: resp=0x67

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x67

This report would have more information with
“Show verbose output during compilation”
option enabled in File -> Preferences.

Reply
Henry Kafton
November 11, 2021 at 8:50 pm
Ya, me too.
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 4 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 5 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 6 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 7 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 8 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 9 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x00
Problem uploading to board. See https://support.arduino.cc/hc/en-us/sections/360003198300 for suggestions.

Reply
Henry Kafton
November 11, 2021 at 8:51 pm
Ya, me too.
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 4 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 5 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 6 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 7 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 8 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 9 of 10: not in sync: resp=0x00
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x00
Problem uploading to board. See https://support.arduino.cc/hc/en-us/sections/360003198300 for suggestions.
(It thinks my comment is copped.)

Reply
Dale Fink
April 18, 2021 at 2:06 pm
There is a lot wrong with the drawing. The first 5V (far left on the Arduino board) is going to the 2nd column of the breadboard (+). This means that the breadboard is upside down. Going from here, the 2nd 5V from the Arduino board SHOULD be going to the last column of the breadboard (+). The left most GND of the Arduino board SHOULD be going to the next to last column on the breadboard (-). The negative of the LED SHOULD be going to the next to last column of the bread board (-).
The leads from the DIP switches SHOULD be wired to digital terminals 2,3, and 4 not 1,2, and 3.

Reply
Kadrian Gurchiek
October 16, 2021 at 2:57 pm
the board is upside down on every drawing

Reply
John Lofstedt
April 19, 2021 at 1:47 pm
I did the code and made my o
Arduino: 1.8.13 (Windows 10), Board: “Arduino Uno”

C:\Users\Kiddos\Desktop\Arduino\arduino-builder -dump-prefs -logger=machine -hardware C:\Users\Kiddos\Desktop\Arduino\hardware -tools C:\Users\Kiddos\Desktop\Arduino\tools-builder -tools C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -built-in-libraries C:\Users\Kiddos\Desktop\Arduino\libraries -libraries C:\Users\Kiddos\Documents\Arduino\libraries -fqbn=arduino:avr:uno -vid-pid=1A86_7523 -ide-version=10813 -build-path C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174 -warnings=none -build-cache C:\Users\Kiddos\AppData\Local\Temp\arduino_cache_220506 -prefs=build.warn_data_percentage=75 -prefs=runtime.tools.arduinoOTA.path=C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -prefs=runtime.tools.arduinoOTA-1.3.0.path=C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -prefs=runtime.tools.avrdude.path=C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -prefs=runtime.tools.avrdude-6.3.0-arduino17.path=C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -prefs=runtime.tools.avr-gcc.path=C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -prefs=runtime.tools.avr-gcc-7.3.0-atmel3.6.1-arduino7.path=C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -verbose C:\Users\Kiddos\Desktop\Arduino\Bitmat\Bitmat.ino

C:\Users\Kiddos\Desktop\Arduino\arduino-builder -compile -logger=machine -hardware C:\Users\Kiddos\Desktop\Arduino\hardware -tools C:\Users\Kiddos\Desktop\Arduino\tools-builder -tools C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -built-in-libraries C:\Users\Kiddos\Desktop\Arduino\libraries -libraries C:\Users\Kiddos\Documents\Arduino\libraries -fqbn=arduino:avr:uno -vid-pid=1A86_7523 -ide-version=10813 -build-path C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174 -warnings=none -build-cache C:\Users\Kiddos\AppData\Local\Temp\arduino_cache_220506 -prefs=build.warn_data_percentage=75 -prefs=runtime.tools.arduinoOTA.path=C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -prefs=runtime.tools.arduinoOTA-1.3.0.path=C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -prefs=runtime.tools.avrdude.path=C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -prefs=runtime.tools.avrdude-6.3.0-arduino17.path=C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -prefs=runtime.tools.avr-gcc.path=C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -prefs=runtime.tools.avr-gcc-7.3.0-atmel3.6.1-arduino7.path=C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr -verbose C:\Users\Kiddos\Desktop\Arduino\Bitmat\Bitmat.ino

Using board ‘uno’ from platform in folder: C:\Users\Kiddos\Desktop\Arduino\hardware\arduino\avr

Using core ‘arduino’ from platform in folder: C:\Users\Kiddos\Desktop\Arduino\hardware\arduino\avr

Detecting libraries used…

“C:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\tools\\avr/bin/avr-g++” -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -flto -w -x c++ -E -CC -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10813 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR “-IC:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\arduino\\avr\\cores\\arduino” “-IC:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\arduino\\avr\\variants\\standard” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\sketch\\Bitmat.ino.cpp” -o nul -DARDUINO_LIB_DISCOVERY_PHASE

Alternatives for U8glib.h: [U8glib@1.19.1]

ResolveLibrary(U8glib.h)

-> candidates: [U8glib@1.19.1]

“C:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\tools\\avr/bin/avr-g++” -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -flto -w -x c++ -E -CC -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10813 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR “-IC:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\arduino\\avr\\cores\\arduino” “-IC:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\arduino\\avr\\variants\\standard” “-IC:\\Users\\Kiddos\\Documents\\Arduino\\libraries\\U8glib\\src” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\sketch\\Bitmat.ino.cpp” -o nul -DARDUINO_LIB_DISCOVERY_PHASE

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\U8glib.cpp

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\chessengine.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_bitmap.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_circle.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_clip.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_api.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_api_16gr.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_attiny85_hw_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_common.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_fast_parallel.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_hw_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_hw_usart_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_no_en_parallel.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_parallel.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_port_d_wr.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_ssd_i2c.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_st7920_custom.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_st7920_hw_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_st7920_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_std_sw_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_sw_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_t6963.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_arduino_uc_i2c.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_atmega_hw_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_atmega_parallel.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_atmega_st7920_hw_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_atmega_st7920_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_atmega_sw_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_atxmega_hw_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_atxmega_st7920_hw_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_i2c.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_io.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_linux_ssd_i2c.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_msp430_hw_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_null.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_psoc5_ssd_hw_parallel.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_raspberrypi_hw_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_raspberrypi_ssd_i2c.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_com_std_sw_spi.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_cursor.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_delay.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_a2_micro_printer.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_flipdisc_2x7.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_gprof.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ht1632.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ili9325d_320x240.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ks0108_128x64.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_lc7981_160x80.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_lc7981_240x128.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_lc7981_240x64.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_lc7981_320x64.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ld7032_60x32.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_null.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_pcd8544_84x48.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_pcf8812_96x65.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_sbn1661_122x32.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ssd1306_128x32.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ssd1306_128x64.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ssd1306_64x48.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ssd1309_128x64.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ssd1322_nhd31oled_bw.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ssd1322_nhd31oled_gr.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ssd1325_nhd27oled_bw.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ssd1325_nhd27oled_bw_new.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ssd1325_nhd27oled_gr.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ssd1325_nhd27oled_gr_new.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ssd1327_96x96_gr.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ssd1351_128x128.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_ssd1353_160x128.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_st7565_64128n.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_st7565_dogm128.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_st7565_dogm132.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_st7565_lm6059.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_st7565_lm6063.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_st7565_nhd_c12832.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_st7565_nhd_c12864.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_st7687_c144mvgd.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_st7920_128x64.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_st7920_192x32.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_st7920_202x32.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_t6963_128x128.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_t6963_128x64.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_t6963_240x128.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_t6963_240x64.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_tls8204_84x48.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_uc1601_c128032.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_uc1608_240x128.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_uc1608_240x64.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_uc1610_dogxl160.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_uc1611_dogm240.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_uc1611_dogxl240.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_uc1701_dogs102.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_dev_uc1701_mini12864.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_ellipse.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_font.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_font_data.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_line.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_ll_api.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_page.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pb.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pb14v1.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pb16h1.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pb16h2.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pb16v1.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pb16v2.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pb32h1.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pb8h1.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pb8h1f.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pb8h2.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pb8h8.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pb8v1.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pb8v2.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pbxh16.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_pbxh24.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_polygon.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_rect.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_rot.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_scale.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_state.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_u16toa.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_u8toa.c

Using cached library dependencies for file: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib\src\clib\u8g_virtual_screen.c

Generating function prototypes…

“C:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\tools\\avr/bin/avr-g++” -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -flto -w -x c++ -E -CC -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10813 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR “-IC:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\arduino\\avr\\cores\\arduino” “-IC:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\arduino\\avr\\variants\\standard” “-IC:\\Users\\Kiddos\\Documents\\Arduino\\libraries\\U8glib\\src” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\sketch\\Bitmat.ino.cpp” -o “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\preproc\\ctags_target_for_gcc_minus_e.cpp” -DARDUINO_LIB_DISCOVERY_PHASE

“C:\\Users\\Kiddos\\Desktop\\Arduino\\tools-builder\\ctags\\5.8-arduino11/ctags” -u –language-force=c++ -f – –c++-kinds=svpf –fields=KSTtzns –line-directives “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\preproc\\ctags_target_for_gcc_minus_e.cpp”

Compiling sketch…

“C:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\tools\\avr/bin/avr-g++” -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10813 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR “-IC:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\arduino\\avr\\cores\\arduino” “-IC:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\arduino\\avr\\variants\\standard” “-IC:\\Users\\Kiddos\\Documents\\Arduino\\libraries\\U8glib\\src” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\sketch\\Bitmat.ino.cpp” -o “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\sketch\\Bitmat.ino.cpp.o”

Compiling libraries…

Compiling library “U8glib”

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\U8glib.cpp.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_clip.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_bitmap.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_circle.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_api.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_attiny85_hw_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_common.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_api_16gr.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_fast_parallel.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_hw_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_hw_usart_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\chessengine.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_parallel.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_port_d_wr.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_ssd_i2c.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_no_en_parallel.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_st7920_hw_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_st7920_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_st7920_custom.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_sw_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_t6963.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_uc_i2c.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_atmega_parallel.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_atmega_st7920_hw_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_atmega_hw_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_atmega_sw_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_arduino_std_sw_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_atmega_st7920_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_i2c.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_io.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_atxmega_st7920_hw_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_msp430_hw_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_atxmega_hw_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_null.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_raspberrypi_ssd_i2c.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_linux_ssd_i2c.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_raspberrypi_hw_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_psoc5_ssd_hw_parallel.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_a2_micro_printer.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_delay.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_com_std_sw_spi.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_flipdisc_2x7.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_gprof.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_cursor.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ks0108_128x64.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_lc7981_160x80.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ili9325d_320x240.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_lc7981_240x64.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_lc7981_320x64.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_lc7981_240x128.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_null.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_pcd8544_84x48.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ht1632.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_sbn1661_122x32.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ld7032_60x32.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_pcf8812_96x65.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ssd1309_128x64.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ssd1322_nhd31oled_bw.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ssd1322_nhd31oled_gr.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ssd1306_128x32.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ssd1325_nhd27oled_bw.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ssd1306_64x48.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ssd1325_nhd27oled_bw_new.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ssd1306_128x64.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ssd1327_96x96_gr.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ssd1351_128x128.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ssd1325_nhd27oled_gr_new.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_st7565_64128n.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ssd1325_nhd27oled_gr.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_st7565_dogm128.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_ssd1353_160x128.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_st7565_lm6063.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_st7565_dogm132.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_st7565_nhd_c12864.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_st7920_128x64.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_st7565_nhd_c12832.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_st7565_lm6059.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_st7920_192x32.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_st7687_c144mvgd.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_t6963_128x64.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_st7920_202x32.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_t6963_240x128.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_t6963_128x128.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_uc1601_c128032.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_uc1608_240x128.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_uc1608_240x64.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_tls8204_84x48.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_uc1610_dogxl160.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_uc1611_dogm240.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_uc1611_dogxl240.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_uc1701_mini12864.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_ellipse.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_uc1701_dogs102.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_font_data.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_line.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_dev_t6963_240x64.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_page.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_font.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_ll_api.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pb.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pb14v1.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pb16v1.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pb16h2.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pb16h1.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pb16v2.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pb32h1.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pb8h1.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pb8h1f.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pb8v1.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pb8h2.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pb8h8.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pb8v2.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pbxh24.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_polygon.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_pbxh16.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_rot.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_scale.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_rect.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_u16toa.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_state.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_virtual_screen.c.o

Using previously compiled file: C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174\libraries\U8glib\clib\u8g_u8toa.c.o

Compiling core…

Using precompiled core: C:\Users\Kiddos\AppData\Local\Temp\arduino_cache_220506\core\core_arduino_avr_uno_ea2b1c45e5fa244f967d03ec5c157c84.a

Linking everything together…

“C:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\tools\\avr/bin/avr-gcc” -w -Os -g -flto -fuse-linker-plugin -Wl,–gc-sections -mmcu=atmega328p -o “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174/Bitmat.ino.elf” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\sketch\\Bitmat.ino.cpp.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\U8glib.cpp.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\chessengine.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_bitmap.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_circle.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_clip.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_api.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_api_16gr.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_attiny85_hw_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_common.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_fast_parallel.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_hw_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_hw_usart_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_no_en_parallel.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_parallel.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_port_d_wr.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_ssd_i2c.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_st7920_custom.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_st7920_hw_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_st7920_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_std_sw_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_sw_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_t6963.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_arduino_uc_i2c.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_atmega_hw_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_atmega_parallel.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_atmega_st7920_hw_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_atmega_st7920_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_atmega_sw_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_atxmega_hw_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_atxmega_st7920_hw_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_i2c.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_io.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_linux_ssd_i2c.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_msp430_hw_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_null.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_psoc5_ssd_hw_parallel.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_raspberrypi_hw_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_raspberrypi_ssd_i2c.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_com_std_sw_spi.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_cursor.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_delay.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_a2_micro_printer.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_flipdisc_2x7.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_gprof.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ht1632.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ili9325d_320x240.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ks0108_128x64.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_lc7981_160x80.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_lc7981_240x128.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_lc7981_240x64.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_lc7981_320x64.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ld7032_60x32.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_null.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_pcd8544_84x48.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_pcf8812_96x65.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_sbn1661_122x32.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ssd1306_128x32.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ssd1306_128x64.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ssd1306_64x48.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ssd1309_128x64.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ssd1322_nhd31oled_bw.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ssd1322_nhd31oled_gr.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ssd1325_nhd27oled_bw.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ssd1325_nhd27oled_bw_new.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ssd1325_nhd27oled_gr.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ssd1325_nhd27oled_gr_new.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ssd1327_96x96_gr.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ssd1351_128x128.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_ssd1353_160x128.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_st7565_64128n.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_st7565_dogm128.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_st7565_dogm132.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_st7565_lm6059.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_st7565_lm6063.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_st7565_nhd_c12832.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_st7565_nhd_c12864.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_st7687_c144mvgd.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_st7920_128x64.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_st7920_192x32.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_st7920_202x32.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_t6963_128x128.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_t6963_128x64.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_t6963_240x128.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_t6963_240x64.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_tls8204_84x48.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_uc1601_c128032.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_uc1608_240x128.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_uc1608_240x64.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_uc1610_dogxl160.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_uc1611_dogm240.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_uc1611_dogxl240.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_uc1701_dogs102.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_dev_uc1701_mini12864.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_ellipse.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_font.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_font_data.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_line.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_ll_api.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_page.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pb.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pb14v1.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pb16h1.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pb16h2.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pb16v1.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pb16v2.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pb32h1.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pb8h1.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pb8h1f.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pb8h2.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pb8h8.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pb8v1.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pb8v2.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pbxh16.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_pbxh24.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_polygon.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_rect.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_rot.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_scale.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_state.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_u16toa.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_u8toa.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174\\libraries\\U8glib\\clib\\u8g_virtual_screen.c.o” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174/..\\arduino_cache_220506\\core\\core_arduino_avr_uno_ea2b1c45e5fa244f967d03ec5c157c84.a” “-LC:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174” -lm

C:\Users\Kiddos\AppData\Local\Temp\ccWWQd6e.s: Assembler messages:

C:\Users\Kiddos\AppData\Local\Temp\ccWWQd6e.s:5222: Warning: ignoring changed section attributes for .progmem.data

“C:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\tools\\avr/bin/avr-objcopy” -O ihex -j .eeprom –set-section-flags=.eeprom=alloc,load –no-change-warnings –change-section-lma .eeprom=0 “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174/Bitmat.ino.elf” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174/Bitmat.ino.eep”

“C:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\tools\\avr/bin/avr-objcopy” -O ihex -R .eeprom “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174/Bitmat.ino.elf” “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174/Bitmat.ino.hex”

Using library U8glib at version 1.19.1 in folder: C:\Users\Kiddos\Documents\Arduino\libraries\U8glib

“C:\\Users\\Kiddos\\Desktop\\Arduino\\hardware\\tools\\avr/bin/avr-size” -A “C:\\Users\\Kiddos\\AppData\\Local\\Temp\\arduino_build_45174/Bitmat.ino.elf”

Sketch uses 11602 bytes (35%) of program storage space. Maximum is 32256 bytes.

Global variables use 410 bytes (20%) of dynamic memory, leaving 1638 bytes for local variables. Maximum is 2048 bytes.

C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr/bin/avrdude -CC:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr/etc/avrdude.conf -v -patmega328p -carduino -PCOM4 -b115200 -D -Uflash:w:C:\Users\Kiddos\AppData\Local\Temp\arduino_build_45174/Bitmat.ino.hex:i

avrdude: Version 6.3-20190619

Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/

Copyright (c) 2007-2014 Joerg Wunsch

System wide configuration file is “C:\Users\Kiddos\Desktop\Arduino\hardware\tools\avr/etc/avrdude.conf”

Using Port : COM4

Using Programmer : arduino

Overriding Baud Rate : 115200

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x0f

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x0f

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x0f

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 4 of 10: not in sync: resp=0x0f

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 5 of 10: not in sync: resp=0x0f

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 6 of 10: not in sync: resp=0x0f

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 7 of 10: not in sync: resp=0x0f

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 8 of 10: not in sync: resp=0x0f

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 9 of 10: not in sync: resp=0x0f

avrdude: stk500_recv(): programmer is not responding

avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x0f

Problem uploading to board. See http://www.arduino.cc/en/Guide/Troubleshooting#upload for suggestions.

avrdude done. Thank you.

wn bitmap but I keep getting the same error message. HELP!!

Reply
Belrey Dahonog (Administrator)
April 20, 2021 at 12:22 am
Hi John, send me an email a belrey@inventr.io so I can assist you with this issue.

Reply
Henry Kafton
November 12, 2021 at 4:02 pm
You need to shorten your comments.

Reply
Matthew Pedone
May 10, 2021 at 2:09 pm
The website he uses, since he didn’t include a link: https://diyusthad.com/image2cpp

Also, if you don’t want to install GIMP, you can convert to XBM here: https://www.online-utility.org/image/convert/to/XBM

And, yes, if you’re on Windows, you can open XBM files in Notepad to see the code, so you don’t have to download anything

Reply
Capt Judan Vos
May 11, 2021 at 11:36 pm
I’ve been getting an error while attempting to upload the code. “Warning: ignoring changed section attributes for .progmem.data” I’d appreciate any hints you’d be willing to send my way, as to what I’m doing wrong.

Reply
Matthew Pedone
May 12, 2021 at 12:06 pm
That warning seems to be related to PROGMEM, which helps deal with the memory usage. I think in the simplest terms, it loads the bitmaps into program memory, rather than onto the Arduino’s RAM, as there wouldn’t be enough space there. As for why the assembler warns of changes to the PROGMEM attributes, I don’t know. Might be a result of using U8glib instead of U8g2, but that’s wild speculation on my part.

This is the official Arduino reference on progmem: https://www.arduino.cc/reference/en/language/variables/utilities/progmem/

And this is a website that explains it in more detail: https://www.e-tinkers.com/2020/05/do-you-know-arduino-progmem-demystified/

I don’t know that either answer this question, but they may help.

Reply
Capt Judan Vos
May 13, 2021 at 5:28 am
Thank you for the insight, I’ll check it out in depth.

Reply
John Lavrakas
May 17, 2021 at 5:53 pm
Thanks for the clarification. Much appreciated, Matthew.

Reply
Paul Jenkins
July 9, 2021 at 4:39 pm
Got this to work after swapping the SDA & SCL pins as described in the first comment above. Not done much else as I’m assuming this is just a setup for the next lesson.

Reply
Mitchell Baird
August 23, 2021 at 1:24 pm
There are 2 things we had to change to get this to work.
1. The SCL from the oled screen needs to go to A5 and SDA to A4
2. Make sure the voltage and ground are not mixed up in the last 2 columns of the breadboard.

Reply
Jim Sabo
August 25, 2021 at 6:40 pm
Once again, the diagram in the video is different than the one on the page.

Which is correct? I’m assuming the video, because the one on the page appears to have swapped VCC and GND for the video display, which seems like it would fry the display.

Reply
Jim Sabo
August 25, 2021 at 7:12 pm
If anyone is getting the error “avrdude: stk500_recv(): programmer is not responding,” unplug the wire from the TX port before hitting Upload on your computer.

Reply
Jim Sabo
August 25, 2021 at 7:36 pm
I’ll clarify that comment: If you use the wiring diagram on the page (as opposed to the one in the video), it will have you plug into port 1.

You can’t upload to the board with something plugged in there, and will get the above error. Unplugging will fix it.

HOWEVER, the diagram in the video, AND the code, have you leave ports 0 and 1 open, and start with port 2.

If you try to use port 1, you’ll also need to update the code to match what you did. But obviously then you have to keep unplugging and replugging that wire every time you upload.

So long story short, follow the diagram in the video, at least for these wires.

Reply
Jimmie Gunther
August 25, 2021 at 9:39 pm
My OLED is now fried, your drawing has a direct short from OLED GND to 5V .

Reply
Tina Hinojosa
August 27, 2021 at 2:36 pm
I just used plain old Microsoft Paint (Yes. On Windows 10.) to draw and converted with ImageMagick Display. The option isn’t there to -choose- a .xbm extension, but if you type the extension in the save dialog in Imagemagick, it will convert it.

Reply
Rufus Smith
September 4, 2021 at 3:07 pm
While I understand the other hardware will be used in future lessons, that’s a lot of schematic (and spurious code) for a simple bitmap graphic lesson.

Reply
Rufus Smith
September 4, 2021 at 3:13 pm
I don’t see the website links promised in the video. “Down Below.”

Reply
Joseph Lechner
October 29, 2021 at 10:10 am
The website with the image converter is https://diyusthad.com/. The Iimage2cpp tool is also available on Github

Reply
Henry Kafton
November 11, 2021 at 10:11 pm
Did anyone else’s resistors get super hot?

Reply
Leave a Comment
Logged in as ryan gott. Log out?


Privacy Overview
This website uses cookies to improve your experience while you navigate through the website. Out of these, the cookies that are categorized as necessary are stored on your browser as they are essential for the working of basic functionalities of the ...
Necessary
Always Enabled
Non-Necessary

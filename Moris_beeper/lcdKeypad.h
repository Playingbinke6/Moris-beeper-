#ifndef lcdKeypad_h
#define lcdKeypad_h

#include "contact.h"
#include "memory.h"
#include "message.h"

#include <iostream>
#include <LiquidCrystal.h>
#include <Arduino.h> 

using namespace std;

// Button types
typedef enum { LEFT, RIGHT, UP, DOWN, SELECT, NONE } Button;

class LcdKeypad : public LiquidCrystal {
public:
    // Constructor
    LcdKeypad(LiquidCrystal inScreen)
        : LiquidCrystal(inScreen), screen(inScreen), lastButton(NONE), lastDebounceTime(0) {}

    // Get pressed button (debounced)
    Button getButtonPress() {
        Button currentButton = detectButton();

        // If button state changes, reset debounce timer
        if (currentButton != lastButton) {
            lastDebounceTime = millis();
        }

        // Register button if stable for 50ms
        if ((millis() - lastDebounceTime) > 50) {
            if (currentButton != lastButton) {
                lastButton = currentButton;
                return currentButton;
            }
        }

        return NONE; // No button pressed
    }

private:
    LiquidCrystal screen;        // LCD object
    Button lastButton;           // Last pressed button
    unsigned long lastDebounceTime; // Time of last button change

    // Detect raw button state
    Button detectButton() {
        int buttonValue = analogRead(A0); // Read A0 for button value

        // Match ranges to buttons
        if (buttonValue < 50) return RIGHT;
        if (buttonValue > 130 && buttonValue < 150) return UP;
        if (buttonValue > 330 && buttonValue < 345) return DOWN;
        if (buttonValue > 490 && buttonValue < 520) return LEFT;
        if (buttonValue > 700 && buttonValue < 730) return SELECT;

        return NONE; // No button detected
    }
};

#endif

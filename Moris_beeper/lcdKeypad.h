#ifndef lcdKeypad_h
#define lcdKeypad_h

#include "contact.h"
#include "memory.h"
#include "message.h"

#include <iostream>
#include <LiquidCrystal.h>

using namespace std;

class LcdKeypad : public LiqudCrystal{

public:

    LcdKeypad(LiquidCrystal inScreen);

    Button getButtonPress();

private: 

    typedef enum {LEFT, RIGHT, UP, DOWN, SELECT, NONE} Button;

    LiquidCrystal screen;

};

LcdKeypad::LcdKeypad(LiquidCrystal inScreen): screen(inScreen){}

LcdKeypad::Button getButtonPress(){

    //code that finds which button is being registered at this time
    //check the voltage divider

}

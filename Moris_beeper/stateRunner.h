#ifndef stateRunner_h
#define stateRunner_h

#include "memory.h"
#include "contact.h"
#include "message.h"
#include "lcdKeypad.h"


using namespace std;

State nextState;//when running you will need to set nextState to currentState
                //before the main switch statement

                //anything that checks for timeOutWait / UP input
                //can be optimized (see MESSAGE_FAILED on both)

void run_SETUP(){

    //=================================

}

void run_MENU(){
    
    static int xPos = 0;

    //"doublePrintOnce"("Menu:", 0, 0, NOCLEAR);

    switch(result){

        case RIGHT:

            xPos = (xPos == 3) ? 0 : xPos+1;
            break;
            
        case LEFT:

            xPos = (xPos == 0) ? 3 : xPos-1;
            break;

        case SELECT{

            if(xPos == 0){nextState = CONTACTS;}
            if(xPos == 1){nextState = MESSAGES;}
            if(xPos == 2){nextState = NEW_CONTACT;}
            if(xPos == 3){nextState = ABOUT_ME;}

            lcd.clear();

        }break;
    }
}

void run_MESSAGE_RECEIVED(){

    //=========================

}

void run_CONTACTS(){

    //============================
        
}

void run_MESSAGES(){

    //==============================

}

void run_MESSAGE_NEW(){

    //================================

}

void MESSAGE_OPEN(){

    //=================================

}

void run_MESSAGE_FAILED(){

    if(previousState != MESSAGE_FAILED){

        timer = millis();

        result = lcd.getButtonPress();

        while(result != UP && millis() - timer < timeoutWait){
            
            result = lcd.getButtonPress();
            doublePrintOnce("MESSAGE FAILED", 0, 0, NOCLEAR);

        }

        lcd.clear();
        nextState = MENU;
    }
}

void run_NEW_CONTACT(){

    lcd.clear();

    if (/*memObj*/.getNumberContacts() >=10){

        static bool getOut = false; //On contacts, On default, might do something?
        nextState = LIST_FULL;

    }else{

        nextState = NEW_CONTACT_NAME;

    }
}

void run_NEW_CONTACT_NAME(){

    //===============================

}

void run_NEW_CONTACT_UUID(){

    //===============================

}

void run_CONTACT_ADDED(){

    //==============================

}

void run_LIST_FULL(){

    if(previousState != LIST_FULL){

        timer = millis();

        result = lcd.getButtonPress;
        while(result != UP && millis() - timer < timeoutWait){
        
            result = lcd.getButtonPress;
            doublePrintOnce("Contact List ", 0, 0, NOCLEAR);
            doublePrintOnce("is full!", 1, 0, NOCLEAR);

        }
        /*curNameSoFar = "a          ";
        curUUID = "a           ";*/
        lcd.clear();
        nextState = MENU;

    }

}

void run_ABOUT_ME(){

    if(preivousState != ABOUT_ME){

        //====================

    }

    switch(result){

        case UP:{

            lcd.clear;
            nextState = MENU;

        }break;

        case  SELECT:{

            lcd.clear();
            nextState = SETUP;

        }break;
    }
}

#endif

//at the end of running the state machine
//include updating previous to current
//and current to next

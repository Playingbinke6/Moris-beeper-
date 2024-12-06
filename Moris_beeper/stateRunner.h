#include "LcdKeypad.h"

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

        default:{

            if(xPos == 0){doublePrintOnce("<-  Contacts  ->", 1, 0, NOCLEAR)}
            if(xPos == 1){doublePrintOnce("<-  Messages  ->", 1, 0, NOCLEAR)}
            if(xPos == 2){doublePrintOnce("<-  N. Contact  ->", 1, 0, NOCLEAR)}
            if(xPos == 3){doublePrintOnce("<-  About Me  ->", 1, 0, NOCLEAR)}
        }
    }
}

void run_MESSAGE_RECEIVED(){

    //=========================

}

void run_CONTACTS(){

    static short xPos = 0;
    static unsigned short contactAddress = 21;

    switch(result){

        


        
        case UP:{

            nextState = MENU;
            lcd.clear;
        }break;   

        case RIGHT:{

            if (xPos >= memory.getNumberContacts() - 1){

                contactNumber = 0;//make sure this is added to global
                xPos = 0;

            }else{

                contactNumber++;
                xPos++;

            }
        }break;

        case LEFT:{

            if(xPos == 0){

                xPos = memory.getNumberContacts() -1;
                counter = xPos;

            }else{

                counter--;
                xPos--;

            }
        }break;

        case SELECT:{

            lcd.clear();
            nextState = MESSAGE_NEW;

        }break;

        default:{

            if(memory.getNumberContacts() == 0){

                if(previousState == MENU){

                    timer = millis();

                }

                lcd.clear();
                doublePrintOnce("No contacts!", 0, 0, NOCLEAR);

                result = lcd.getButtonPress();
                while(result != UP && millis() - timer < timeoutWait){
            
                    result = lcd.getButtonPress();
                    doublePrintOnce("MESSAGE FAILED", 0, 0, NOCLEAR);

                }

                lcd.clear();
                nextState = MENU;

            }else{

                //=====================================

            }
        }
    }
        
}

void run_MESSAGES(){

    static unsigned short xPos;
    doublePrintOnce("Messages:", 0, 0, NOCLEAR);

    switch(result){

        case UP:{

            lcd.clear();
            nextState = MENU;

        }break;

        case RIGHT:{

            if(xPos >= memory.getNumberMessages() -1){

                messageNumber = 0;//add this to global
                xPos = 0;

            }else{

                messageNumber++;
                xPos++;

            }

        }break;

        case LEFT{

            if(counter == 0){

                xPos = memory.getNumberMessages() -1;
                messageNumber = xPos;

            }else{

                xPos--;
                messageNumber--;

            }

        }break;

        case SELECT{

            lcd.clear();
            nextState = MESSAGE_OPEN;

        }

        default:{

            //==========================

        }

    }

}

void run_MESSAGE_NEW(){

    //================================

}

void run_MESSAGE_OPEN(){

    //=================================

}

void run_MESSAGE_SENT(){

    //================================

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

    if (memory.getNumberContacts() >=10){

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

//at the end of running the state machine
//include updating previous to current
//and current to next

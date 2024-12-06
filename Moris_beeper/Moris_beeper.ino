#include "memory.h"
#include "contact.h"
#include "Entropy.h"
#include "message.h"
#include "lcdKeypad.h"
#include <inttypes.h>

const unsigned short maxNumMessages = 20;
const unsigned short maxNumContacts = 10;
const unsigned short messageSize = 16;
const unsigned short buzzerPin;
const unsigned short nameLength = 10;
const unsigned short uuidLength = 5;


//   = = = = = START OF RADIO CODE = = = = =
RF24 radio(A1, A2);
char transmission[uuidLength*2  + 4];
char prevTransmission[uuidLength*2  + 4];

void startReciever(){
  radio.startListening();
  radio.openReadingPipe(1, UUID);
  radio.setPALevel(RF24_PA_MIN);
}

bool reciever(){
  startReciever();
  if(radio.available()){//look for transmission
    radio.read(&transmission, sizeof(transmission));
  }

  bool transmitionIsSame = true;
  for(int i=0; i<uuidLength*2 + 3; i++){//wait till new transmission has been recieved
    if(transmission[i] != prevTransmission[i]){
      transmitionIsSame = false;
      break;
    }
  }
      
  if((transmissionIsSame  == false)){//updates the prevTransmission var
    for(int i=0; i<uuidLength*2 + 3; i++){
      prevTransmission[i] = transmission[i];
    }

    return true;
  }
  else{
    return false;
  }
}

void startTransmit(){
  radio.stopListening();
  radio.openWritingPipe(address);
  radio.setPALevel(LOW);

}

bool transmissionRecieved(){//makes sure the transmition was recieved
  startTransmit();
  radio.stopListening();

  if(radio.write(&transmission, sizeof(transmission))){ // check if the message was recived
    radio.startListening();
    return true;
  }
  else{
    radio.startListening();
    return false;
  }
}
//   = = = = = END OF RADIO CODE = = = = =



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

//memory and eeprom class

//size of the pieces of data we need to store:
//UUID: 5 bytes
//Name: 10 bytes
//Message: 13 bytes
//

#ifndef memory_h
#define memory_h

#include "Contact.h"
#include "Message.h"
#include <inttypes.h>

class Memory {
public:
  Memory();
  Memory(Contact node);
  unsigned char* getMyUUID();
  char* getMyName();
  unsigned char* getNodeUUID(uint8_t index);
  char* getNodeName(uint8_t index);
  unsigned short getNumberContacts();
  unsigned short getNumberMessages();
  Contact getContact(unsigned short index);
  Message getMessage(unsigned short index);
  bool saveContact(Contact contact);
  void saveMessage(Message message);
  void saveNodeInformation(Contact contact);
    // Add as you see fit
  uint8_t readMemory(unsigned short address);
  void writeMemory(unsigned short address, uint8_t value);
    
protected:
  bool hasSchema();
  void setSchema();
  void clearMessages();
  void clearContacts();
  unsigned short getMessagePointerOffset();
    // Add as you see fit
private:
  const unsigned short MAX_CONTACTS = 10;
  const unsigned short MAX_MESSAGES = 20;
      // Add as you see fit
  const unsigned short messageSize = 16;
  const unsigned short buzzerPin = 3;
  const unsigned short nameSize = 10;
  const unsigned short uuidSize = 5;
  const unsigned short OFFSET = 500;// = = = = = = = = = = need to specify exact number
  
};


// Memory::Memory(){

// }
// Memory::Memory(Contact node){

// }

unsigned char* Memory::getMyUUID(){//return the UUID of myself
  unsigned char* UUID;
  for(int i=0; i<5; i++){//40 bit UUID => 5 bytes => 5 indexes in the memory
      UUID[i] = readMemory(3 + i);//UUID starts at the 3rd index in the memory
  }
  return UUID;
}

char* Memory::getMyName(){//return the name of myself
  char* name;
  for(int i=0; i<10; i++){//name is of length 10
      name[i] = readMemory(8 + i);//8+i to get the bytes behind the UUID(first 5)
  }
  return name;
}

unsigned char* Memory::getNodeUUID(uint8_t index){//return the UUID of a contact at index
  unsigned char* UUID;

  if(index<0 || index>9)
    return UUID;

  for(int i=0; i<5; i++){//adds the chars at the indexes to the char*
      UUID[i] = readMemory(index*15+ 21 + i);//21 offset to bring it to the list
  }
  return UUID;
}

char* Memory::getNodeName(uint8_t index){//return the name of contact at index
  char* name;

  if(index<0 || index>9)
    return name;

  for(int i=0; i<10; i++){//adds the chars at the indexes to the char*
      name[i] = readMemory(index*15+ 26 + i);//same index as the UUID read but with +5 bytes to skip the UUID of the contact
  }
  return name;
}

unsigned short Memory::getNumberContacts(){//return the number of contacts
  readMemory(20);//index for the number of contacts
}

unsigned short Memory::getNumberMessages(){//return the number of messages
  readMemory(173);//index for the number of messages
}

Contact Memory::getContact(unsigned short index){//return the contact at the corisponding index (0 - 9)
  //contacts are stored UUID(5 bytes) then Name(10 bytes) in their address
  unsigned char* UUID = getNodeUUID(index);
  const char* NAME = getNodeName(index);
  return Contact(UUID, NAME);
}

Message Memory::getMessage(unsigned short index){//return the message obj at the index

}

bool Memory::saveContact(Contact contact){// save a new contact if there is sapce avalable = = = = = = = =
  int index = readMemory(20);
  writeMemory(20, index+1);

  if(index >= 10)//if the list of contcacts is full return false
    return false;

  unsigned char* uuid = contact.retrieveUUID();
  const char* name = contact.retrieveName();

  for(int i=0; i<5; i++){//write the UUID
    writeMemory(index*15+ 21, uint8_t(uuid[i]));
  }

  for(int i=0; i<10; i++){//write the NAME
    writeMemory(index*15+ 26, uint8_t(name[i]));// each char in char array is one byte,
  }//so index through each char and cast to byte, then write that byte
}

void Memory::saveMessage(Message message){//save a message to the next avalable index, loop if more than 20 messages
  
  
  //save the from var
  unsigned char* from = message.getFrom();
  //save the to var
  unsigned char* to = message.getTo();
  //save payload
  uint16_t payload = message.getPayload();
  //save payload length
  uint8_t length = message.getLength();
}

void Memory::saveNodeInformation(Contact contact){
  //this might update the linked list of contacts for the new contact? = = = = = = = = = 
}

uint8_t readMemory(unsigned short address){//read from the memory byte you have to check and make sure that nothing is writing when you try to read
  // wait for any ongoing EEPROM write operation to complete:
  // if EEPE is 1 then writing is happning and cannot read
  while (EECR & (1 << EEPE));

  // set the EEPROM address register (EEAR) to the inputed address
  EEAR = address;

  // set the EERE (EEPROM Read Enable) bit in the EEPROM control register (EECR)
  // this alows reading to happen
  EECR |= (1 << EERE);

  // return the data from the EEPROM data register (EEDR)
  // the EEDR has the byte we wanted to read from the inputed address
  return EEDR;
}

void writeMemory(unsigned short address, uint8_t value){//write a value to the memory but you also have to make sure that nothing else is writing at that time
  // wait for any ongoing EEPROM write operation to complete when EEPE == 0
  while (EECR & (1 << EEPE));

  // set EEAR to the inputed address
  EEAR = address;

  // load the data to be written to EEPROM data register (EEDR)
  EEDR = data;

  // enable the Master Write Enable (EEMPE) bit in the EEPROM cont reg
  EECR |= (1 << EEMPE);

  // start the write operation by setting the EEPROM Programming Enable (EEPE) bit
  // *this bit must be set within 4 clock cycles after EEMPE is set*
  EECR |= (1 << EEPE);
}

// ---------- ---------- start of the protected functions: ---------- ---------- 

bool Memory::hasSchema(){// return true if schema is set up right
  unsigned short failed = 0;
  //check the first flag (000 - 002 => 0xC0FFEE)
  if(readMemory(0) != (0xC0) || readMemory(1) != (0xFF) || readMemory(2) != (0xEE)){// if first flag DNE
    failed++;
  }

  // check second flag (018 - 019 => 0xFACE)
  else if(readMemory(18) != (0xFA) || readMemory(19) != (0xCE)){// if second flag DNE
    failed++;
  }

  // check thrid flag (171 - 172 => 0xCA11)
  else if(readMemory(171) != (0xCa) || readMemory(172) != (0x11)){// if third flag DNE
    failed++;
  }
  

  //Serial.print(failed);
  //Serial.println(" FAILED CASES ")
  if(failed == 0)// all of the test cases passed for schema
    return true;
  return false;// else false

}

void Memory::setSchema(){//store the Schema in the memory
  //set 0xC0FFEE flag (000 - 002)
  writeMemory(0, 0xC0);
  writeMemory(1, 0xFF);
  writeMemory(2, 0xEE);

  //set 0xFACE flag (018 - 019)
  writeMemory(18, 0xFA);
  writeMemory(19, 0xCE);

  //set 0xCA11 flag (171 - 172)
  writeMemory(171, 0xCA);
  writeMemory(172, 0x11);

  //clear messages and contacts
  clearMessages();
  clearContacts();

  //set offset value
  writeMemory(434, OFFSET);
}

void Memory::clearMessages(){//clear all of the messages from memory (174 - 433)
  for(int i=174; i<=433; i++){
    writeMemory(i, 0);
  }
}

void Memory::clearContacts(){//clear all of the contacts from memory (021 - 170)
  for(int i=21; i<=170; i++){
    writeMemory(i, 0);
  }
}

unsigned short Memory::getMessagePointerOffset(){//get the offset for the pointers in messages?
  return readMemory(434);
}

#endif

//memory and eeprom class

#ifndef memory_h
#define memory_h

#include "Contact.h"
#include "Message.h"

class Memory {
public:
  Memory();
  Memory(Contact node);
  unsigned char* getNodeUUID();
  char* getNodeName();
  unsigned short getNumberContacts();
  unsigned short getNumberMessages();
  Contact getContact(unsigned short index);
  Message getMessage(unsigned short index);
  bool saveContact(Contact contact);
  void saveMessage(Message message);
  void saveNodeInformation(Contact contact);
    // Add as you see fit
  byte read(unsigned short address);
  void write(unsigned short address, byte value);
    
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
};


// Memory::Memory(){

// }
// Memory::Memory(Contact node){

// }

unsigned char* Memory::getNodeUUID(){
  //return my UUID as a char pointer
}

char* Memory::getNodeName(){
  //return the name of the node 
}

unsigned short Memory::getNumberContacts(){
  //return the number of contacts
}

unsigned short Memory::getNumberMessages(){
  //return the number of messages? = = = = = = = = = = = = = = = = =
}

Contact Memory::getContact(unsigned short index){
  //return the contact at the corisponding index
}

Message Memory::getMessage(unsigned short index){
  //return the message at the corisponding index
}

bool Memory::saveContact(Contact contact){
  //save the contact
  //if the list of contcacts is full return false
}

void Memory::saveMessage(Message message){
  //save the message 
  //might need to add another input for the place to save
  //will just overwrite prev message if there is one
}

void Memory::saveNodeInformation(Contact contact){
  //this might update the linked list of contacts for the new contact? = = = = = = = = = 
}

byte read(unsigned short address){
  //read from the memory byt you have to check and make sure that nothing is writing when you try to read
}

void write(unsigned short address, byte value){
  //write a value to the mem but you also have to make sure that nothing else is writing at that time
}

// ---------- ---------- start of the protected functions: ---------- ---------- 

bool Memory::hasSchema(){
  //return true if schema exists
  bool hasBeenSetUp = true;

  //check the first flag (000 - 002 => 0xC0FFEE)
  if(read(0) != (0xC0) || read(1) != (0xFF) || read(2) != (0xEE)){// if first flag DNE
    hasBeenSetUp = false;
  }

  // check second flag (018 - 019 => 0xFACE)
  else if(read(18) != (0xFA) || read(19) != (0xCE)){// if second flag DNE
    hasBeenSetUp = false;
  }

  // check thrid flag (171 - 172 => 0xCA11)
  else if(read(171) != (0xCa) || read(172) != (0x11)){// if third flag DNE
    hasBeenSetUp = false;
  }
  


}

void Memory::setSchema(){
  //store the Schema in the memory
}

void Memory::clearMessages(){
  //clear all of the messages from memory
}

void Memory::clearContacts(){
  //clear all of the contacts from memory
}

unsigned short Memory::getMessagePointerOffset(){
  //get the offset for the pointers in messages? = = == = = = = = =
}

#endif

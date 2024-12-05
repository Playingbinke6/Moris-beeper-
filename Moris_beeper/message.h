
#ifndef message_h
#define message_h

#include"memory.h"

class Message : public Memory {
public:

  Message();
  Message(unsigned char* inFrom, unsigned char* inTo, unsigned short inPayload, unsigned char inLength);
  Message(unsigned char* inFrom, unsigned char* inTo, char* inMessage);
  void setLength(unsigned char inLength);
  void setTo(unsigned char* inTo);
  void setFrom(unsigned char* inFrom);
  void setPayload(unsigned short inPayload);
  unsigned char getLength();
  unsigned char* getTo();
  unsigned char* getFrom();
  unsigned short getPayload();
  char* getPayloadString();

protected:

  unsigned short stringToPayload(char const* message);
  char* payloadToString(unsigned short payload, unsigned char length);

private:

  unsigned char* from;
  unsigned char* to;
  unsigned short payload;
  unsigned char length;
  char* message[];

  };
    


  Message::Message(){}
  
  Message::Message(unsigned char* inFrom, unsigned char* inTo, unsigned short inPayload, unsigned char inLength)
    :from(inFrom), to(inTo), payload(inPayload), length(inLength){

      for (unsigned short i, i < this->length, i++){
        
        this->*(message + i) = payloadToChar(this->payload, this->length);
        
      }
    }

  Message::Message(unsigned char* inFrom, unsigned char* inTo, char* inMessage)
    :from(inFrom), to(inTo), message(inMessage){

    this->length = static_cast<unsigned char>(sizeof(this->message));
    
    this->payload = stringToPayload(this->message);
    
  }

  void Message::setLength(unsigned char inLength){
    this->length = inLength;
  }

  void Message::setTo(unsigned char* inTo){
    this->to = inTo;
  }

  void Message::setFrom(unsigned char* inFrom){
    this->from = inFrom;
  }

  void Message::setPayload(unsigned short inPayload){
    this->payload = inPayload;
  }

  unsigned char Message::getLength(){
    return this->length;
  }

  unsigned char* Message::getTo(){
    return this->to;
  }

  unsigned char* Message::getFrom(){
    return this->from;
  }

  unsigned short Message::getPayload(){
    return this->payload;
  }

  char* Message::getPayloadString(){
    return payloadToString(this->payload, this->length);
  }

  unsigned short Message::stringToPayload(char const* message){

    for(unsigned short i, i < this->length, i++){
      
      
      
    }
    
  }

  char* Message::payloadToChar(bool payloadBit){

    return (payloadBit ? "-" : ".");
    
  }

#endif

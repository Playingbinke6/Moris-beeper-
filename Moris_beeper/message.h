#infdef message_h
#define message_h

#include"memory.h"

enum Mchar{a, b, c, d, e, f, g, h, i, j, k, l, m,
           n, o, p, q, r, s, t, u, v, w, x, y, z};

class Message : public Memory {
public:

  Messages();
  Message(unsigned char* inFrom, unsigned char* inTo, unsigned short inPayload, unsigned char inLength);
  Message(unsigned char* inFrom, unsigned inChar* to, char const* inMessage);
  void setLength(unsigned char inLength);
  void setTo(unsigned char* inTo);
  void setFrom(unsigned char* inFrom);
  void setPayload(unsigned short inPayload);
  unsigned char getLength();
  unsigned char* getTo();
  unsigned char* getFrom();
  unsigned short getPayload();
  char* getPayloadString();
  char* payloadToString(unsigned short payload, unsigned char length);

protected:

  unsigned short charToCode (Mchar let);
  char codeToChar(uin8_t code);  
  unsigned short stringToPayload(char const* message);

private:

  unsigned char* from;
  unsigned char* to;
  unsigned short payload;
  unsigned char length;

  const uin8_t codes[26] = 
  {
    B 00 00 10 11, //A
    B 11 10 10 10, //B
    B 11 10 11 10, //C
    B 00 11 10 10, //D
    B 00 00 00 10, //E
    B 10 10 11 10, //F
    B 00 11 11 10, //G
    B 10 10 10 10, //H
    B 00 00 10 10, //I
    B 10 11 11 11, //J
    B 00 11 10 11, //K
    B 10 11 10 10, //L
    B 00 00 11 11, //M
    B 00 00 11 10, //N
    B 00 11 11 11, //O
    B 10 11 11 10, //P
    B 11 11 10 11, //Q
    B 00 10 11 10, //R
    B 00 10 10 10, //S
    B 00 00 00 11, //T
    B 00 10 10 11, //U
    B 10 10 10 11, //V
    B 00 10 11 11, //W
    B 11 10 10 11, //X
    B 11 10 11 11, //Y
    B 11 11 10 10, //Z
  };
    


  Message(){}
  Message(unsigned char* inFrom, unsigned char* inTo, unsigned short inPayload, unsigned char inLength)
    :from(inFrom), to(inTo), payload(inPayload), length(inLength){

      message = payloadToString(payload, length);
      writeMemory((174 + 13n), message);
      n++;
      
    }

  Message(unsigned char* inFrom, unsigned inChar* to, char const* inMessage)
    :from(inFrom), to(inTo), message(inMessage){

    length = strlen(message);
    payload = stringToPayload(message, length);
    writeMemory((174 + 13n), message);
    n++;    
    
  }

  void setLength(unsigned char inLength){
    length = inLength;
  }

  void setTo(unsigned char* inTo){
    to = inTo;
  }

  void setFrom(unsigned char* inFrom){
    from = inFrom;
  }

  void setPayload(unsigned short inPayload){
    payload = inPayload;
  }

  unsigned char getLength(){
    return length;
  }

  unsigned char* getTo(){
    return to;
  }

  unsigned char* getFrom(){
    return from;
  }

  unsigned short getPayload(){
    return payload;
  }

  char* getPayloadString(){
    return payloadToString(payload, length);
  }

protected:

  unsigned short charToCode (Mchar let){
    return codes[let];
  }

  char codeToChar(uin8_t code){

    for(int i=0; i < 26; i++){

      if(code == codes[i]){

        return static_cast<Mchar>(i);
        
      } 
    }  
  }

  unsigned short stringToPayload(char const* message){

    
    
  }

  char* payloadToString(unsigned short payload, unsigned char length){


    
  }

#endif

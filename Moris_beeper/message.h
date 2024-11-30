#infdef message_h
#define message_h

class Message {
public:
  Message(){}
  Message(unsigned char* inFrom, unsigned char* inTo, unsigned short inPayload, unsigned char inLength)
    :from(inFrom), to(inTo), payload(inPayload), length(inLength){

    
      
    }

  Message(unsigned char* inFrom, unsigned inChar* to, char const* inMessage)
    :from(inFrom), to(inTo), message(inMessage){

    length = strlen(message);
    
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
    //------------------------------------------------------------------------------
  }

protected:
  unsigned short stringToPayload(char const* message){}
  char* payloadToString(unsigned short payload, unsigned char length){}
private:
  unsigned char* from;
  unsigned char* to;
  unsigned short payload;
  unsigned char length;
  
  
};

#endif

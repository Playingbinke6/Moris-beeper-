#infdef message_h
#define message_h

class Message {
public:
  Message(){}
  Message(unsigned char* inFrom, unsigned char* inTo, unsigned short inPayload, unsigned char inLength)
    :*from(*inFrom), *to(*inTo), payload(inPayload), length(inLength){

    
      
    }

  Message(unsigned char* inFrom, unsigned inChar* to, char const* inMessage)
    :*from(*inFrom), *to(*inTo), *message(*inMessage){

    length = sizeOf(message);
    
  }

  void setLength(unsigned char length){}

  void setTo(unsigned char* to){}

  void setFrom(unsigned char* from){}

  void setPayload(unsigned short payload){}

  unsigned char getLength(){}

  unsigned char* getTo(){}

  unsigned char* getFrom(){}

  unsigned short getPayload(){}

  char* getPayloadString(){}

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

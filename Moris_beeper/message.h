

#ifndef message_h
#define message_h



class Message {
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

  unsigned short stringToPayload(char* message);
  char payloadToChar(bool payloadBit);
  char* payloadToString(unsigned short payload, unsigned char length);


private:

  unsigned char* from;
  unsigned char* to;
  unsigned short payload;
  unsigned char length;
  char* message;

  };
    


  Message::Message(){}
  
  Message::Message(unsigned char* inFrom, unsigned char* inTo, unsigned short inPayload, unsigned char inLength)
    :from(inFrom), to(inTo), payload(inPayload), length(inLength){

      this->message = payloadToString(this->payload, this->length);

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

  unsigned short Message::stringToPayload(char* message){
    
    for(unsigned short i; i < this->length; i++){
      
      if(message[i] == '-'){

        payload |= (1 >> 7 - i);

      }
      
    }
    return payload;
    
  }

  char Message::payloadToChar(bool payloadBit){

    return (payloadBit ? '-' : '.');
    
  }

  unsigned char* Message::payloadToString(unsigned short payload, unsigned char length) {

    unsigned char* data;

    for (int i = 0; i < length; i++){

        *(data + i) = payloadToChar((payload >> (length - 1 - i)) & 1);

    }

    return data;

  }

#endif

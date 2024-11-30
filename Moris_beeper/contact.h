#infdef contact_h
#define contact_h

class Contact {
public:
  Contact();
  Contact(unsigned char* givenUUID, char const* givenName);
  Contact(unsigned char* givenUUID, char givenName);
  void setUUID(unsigned char* givenUUID);
  void setName(char const* givenName);
  void setName(char givenName);
  unsigned char* getUUID();
  char* getName();
    // Add as you see fit

private:
  // ...
  // ...
  // ...
};

#endif

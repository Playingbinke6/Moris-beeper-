#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstring> // For basic string operations

class Contact {
  public:
    // Constructors
    Contact();
    Contact(unsigned char* givenUUID, const char* givenName);
    Contact(unsigned char* givenUUID, char givenName);

    // Setters
    void updateUUID(unsigned char* givenUUID);
    void updateName(const char* givenName);
    void updateName(char givenName);

    // Getters
    unsigned char* retrieveUUID();
    const char* retrieveName() const;

  private:
    // Helpers
    void resetUUID();
    void resetName();

    // Constants
    static const int UUID_SIZE = 5;
    static const int MAX_NAME_LENGTH = 10;

    // Member variables
    unsigned char uuid[UUID_SIZE];
    char name[MAX_NAME_LENGTH + 1];
};

#endif // CONTACT_HPP

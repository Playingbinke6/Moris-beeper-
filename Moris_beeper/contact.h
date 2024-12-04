#ifndef contact_h
#define contact_h

#include "memory.h"

class Contact : public Memory {
  public:
    // Default constructor
    Contact() {
        resetUUID();
        resetName();
    }

    // Constructor with UUID and const char* name
    Contact(unsigned char* givenUUID, const char* givenName) {
        updateUUID(givenUUID);
        updateName(givenName);
    }

    // Constructor with UUID and single char name
    Contact(unsigned char* givenUUID, char givenName) {
        updateUUID(givenUUID);
        char tempName[2] = {givenName, '\0'};
        updateName(tempName);
    }

    // Update UUID
    void updateUUID(unsigned char* givenUUID) {
        if (givenUUID) {
            for (int i = 0; i < UUID_SIZE; ++i) {
                uuid[i] = givenUUID[i];
            }
        } else {
            resetUUID();
        }
    }

    // Update name with const char*
    void updateName(const char* givenName) {
        if (givenName) {
            int i = 0;
            while (i < MAX_NAME_LENGTH && givenName[i] != '\0') {
                name[i] = givenName[i];
                ++i;
            }
            name[i] = '\0';
        } else {
            resetName();
        }
    }

    // Update name with a single char
    void updateName(char givenName) {
        name[0] = givenName;
        name[1] = '\0';
    }

    // Retrieve UUID
    unsigned char* retrieveUUID() {
        return uuid;
    }

    // Retrieve name
    const char* retrieveName() const {
        return name;
    }

  private:
    // Reset UUID to default (all zeros)
    void resetUUID() {
        for (int i = 0; i < UUID_SIZE; ++i) {
            uuid[i] = 0;
        }
    }

    // Reset name to default (empty string)
    void resetName() {
        for (int i = 0; i <= MAX_NAME_LENGTH; ++i) {
            name[i] = '\0';
        }
    }

    static const int UUID_SIZE = 5;          // UUID is 40 bits (5 bytes)
    static const int MAX_NAME_LENGTH = 10;  // Maximum name length (10 characters)
    unsigned char uuid[UUID_SIZE];          // Array to store UUID
    char name[MAX_NAME_LENGTH + 1];         // Array to store name (plus null terminator)
};

#endif
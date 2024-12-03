#include "Contact.hpp"

// Default constructor
Contact::Contact() {
    resetUUID();
    resetName();
}

// Constructor with UUID and const char* name
Contact::Contact(unsigned char* givenUUID, const char* givenName) {
    updateUUID(givenUUID);
    updateName(givenName);
}

// Constructor with UUID and single char name
Contact::Contact(unsigned char* givenUUID, char givenName) {
    updateUUID(givenUUID);
    char tempName[2] = {givenName, '\0'};
    updateName(tempName);
}

// Update UUID
void Contact::updateUUID(unsigned char* givenUUID) {
    if (givenUUID) {
        for (int i = 0; i < UUID_SIZE; ++i) {
            uuid[i] = givenUUID[i];
        }
    } else {
        resetUUID();
    }
}

// Update name with const char*
void Contact::updateName(const char* givenName) {
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
void Contact::updateName(char givenName) {
    name[0] = givenName;
    name[1] = '\0';
}

// Retrieve UUID
unsigned char* Contact::retrieveUUID() {
    return uuid;
}

// Retrieve name
const char* Contact::retrieveName() const {
    return name;
}

// Reset UUID
void Contact::resetUUID() {
    for (int i = 0; i < UUID_SIZE; ++i) {
        uuid[i] = 0;
    }
}

// Reset name
void Contact::resetName() {
    for (int i = 0; i <= MAX_NAME_LENGTH; ++i) {
        name[i] = '\0';
    }
}

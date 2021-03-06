#ifndef Propel_h
#define Propel_h

#include <Arduino.h>

enum {BOOL, INT, CHAR, FLOAT, DOUBLE, STRING};

class PropelBase { //all nested, because let's not interfere with devs' Arduino code more than we have to
  private:
    class PropelNode {
      public:
        PropelNode(const char*, void*, int);
        const char* name;
        void* address;
        int type;
        PropelNode* next;
    };

    class PropelDict {
      public:
        void* getNode(char*, int);
        void setNode(char*, void*, int);
        void setNode(const char*, void*, int);
        void deleteNode(char*);
        void deleteNode(const char*);
        PropelNode* head;
    };

    PropelDict varDict;
    void writeMessage(PropelNode*, char*);
    String readMessage();
  public:
    PropelBase();
    void function (const char*, void*);
    void variable(const char*, void*, int);
} extern Propel;


#endif

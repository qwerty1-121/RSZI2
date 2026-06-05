#ifndef ALLOCATOR_TEST_OBJECT_H
#define ALLOCATOR_TEST_OBJECT_H

#include "Allocator.h"

class AllocatorTestObject
{
    DECLARE_ALLOCATOR

public:
    AllocatorTestObject();
    AllocatorTestObject(int id, int priority, int payload);

    int getId() const;
    int getPriority() const;
    int getPayload() const;

    void setPayload(int payload);

private:
    int id_;
    int priority_;
    int payload_;

    int data_[16];
};

#endif 
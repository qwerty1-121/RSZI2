#include "AllocatorTestObject.h"

IMPLEMENT_ALLOCATOR(AllocatorTestObject, 0, 0)

AllocatorTestObject::AllocatorTestObject()
    : id_(0),
      priority_(0),
      payload_(0),
      data_{}
{
}

AllocatorTestObject::AllocatorTestObject(int id, int priority, int payload)
    : id_(id),
      priority_(priority),
      payload_(payload),
      data_{}
{
}

int AllocatorTestObject::getId() const
{
    return id_;
}

int AllocatorTestObject::getPriority() const
{
    return priority_;
}

int AllocatorTestObject::getPayload() const
{
    return payload_;
}

void AllocatorTestObject::setPayload(int payload)
{
    payload_ = payload;
}
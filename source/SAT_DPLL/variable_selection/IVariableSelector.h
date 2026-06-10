#ifndef IVARIABLE_SELECTOR_H
#define IVARIABLE_SELECTOR_H

class BoolEquation;

class IVariableSelector
{
public:
    virtual ~IVariableSelector() {}

    virtual int selectVariable(BoolEquation& equation) const = 0;
};

#endif // IVARIABLE_SELECTOR_H
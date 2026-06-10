#ifndef FIRST_VARIABLE_SELECTOR_H
#define FIRST_VARIABLE_SELECTOR_H

#include "IVariableSelector.h"

class FirstVariableSelector : public IVariableSelector
{
public:
    int selectVariable(BoolEquation& equation) const override;
};

#endif // FIRST_VARIABLE_SELECTOR_H
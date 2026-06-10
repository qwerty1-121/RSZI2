#ifndef MIN_UNDEFINED_SELECTOR_H
#define MIN_UNDEFINED_SELECTOR_H

#include "IVariableSelector.h"

class MinUndefinedSelector : public IVariableSelector
{
public:
    int selectVariable(BoolEquation& equation) const override;
};

#endif // MIN_UNDEFINED_SELECTOR_H
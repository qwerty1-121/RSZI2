#include "FirstVariableSelector.h"

#include "boolequation.h"

int FirstVariableSelector::selectVariable(BoolEquation& equation) const
{
    for (int i = 0; i < equation.mask.getSize(); ++i) {
        if (equation.mask[i] == 0) {
            return i;
        }
    }

    return 0;
}
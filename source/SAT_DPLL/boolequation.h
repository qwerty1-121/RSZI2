#ifndef BOOLEQUATION_H
#define BOOLEQUATION_H

#include "boolinterval.h"
#include "IVariableSelector.h"

class BoolEquation
{
public:
    BoolInterval **cnf;
    BoolInterval *root;
    int cnfSize;
    int count;
    BBV mask;

    BoolEquation(
        BoolInterval **cnf,
        BoolInterval *root,
        int cnfSize,
        int count,
        BBV mask,
        IVariableSelector *variableSelector = nullptr
    );

    BoolEquation(BoolEquation &equation);

    int CheckRules();
    bool Rule1Row1(BoolInterval *interval);
    bool Rule2RowNull(BoolInterval *interval);
    void Rule3ColNull(BBV vector);
    bool Rule4Col0(BBV vector);
    bool Rule5Col1(BBV vector);
    void Simplify(int ixCol, char value);

    void setVariableSelector(IVariableSelector *variableSelector);
    int ChooseColForBranching();

private:
    IVariableSelector *variableSelector_;
};

#endif // BOOLEQUATION_H
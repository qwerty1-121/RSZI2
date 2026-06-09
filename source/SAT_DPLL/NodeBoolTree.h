#ifndef NODEBOOLTREE_H
#define NODEBOOLTREE_H

#include "Allocator.h"
#include "BBV.h"
#include "boolinterval.h"
#include "boolequation.h"

class NodeBoolTree
{
    DECLARE_ALLOCATOR

public:
    explicit NodeBoolTree(BoolEquation *equation);
    NodeBoolTree(const NodeBoolTree &node);

    NodeBoolTree *lt = nullptr;
    NodeBoolTree *rt = nullptr;

    BoolEquation *eq = nullptr;
};

#endif // NODEBOOLTREE_H
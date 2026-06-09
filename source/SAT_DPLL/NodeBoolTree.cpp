#include "NodeBoolTree.h"

IMPLEMENT_ALLOCATOR(NodeBoolTree, 0, 0)

NodeBoolTree::NodeBoolTree(BoolEquation *equation)
    : eq(equation)
{
}

NodeBoolTree::NodeBoolTree(const NodeBoolTree &node)
    : lt(node.lt),
      rt(node.rt),
      eq(node.eq)
{
}
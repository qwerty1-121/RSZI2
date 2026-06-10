#include "MinUndefinedSelector.h"

#include "boolequation.h"

#include <algorithm>
#include <vector>

int MinUndefinedSelector::selectVariable(BoolEquation& equation) const
{
    std::vector<int> indexes;
    std::vector<int> values;
    bool isInitialized = false;

    for (int i = 0; i < equation.mask.getSize(); ++i) {
        if (equation.mask[i] == 0) {
            indexes.push_back(i);
        }
    }

    if (indexes.empty()) {
        return 0;
    }

    for (int i = 0; i < equation.cnfSize; ++i) {
        BoolInterval* interval = equation.cnf[i];

        if (interval != nullptr) {
            if (!isInitialized) {
                for (int k = 0; k < static_cast<int>(indexes.size()); ++k) {
                    if (interval->getValue(indexes.at(k)) == '-') {
                        values.push_back(1);
                    } else {
                        values.push_back(0);
                    }
                }

                isInitialized = true;
            } else {
                for (int k = 0; k < static_cast<int>(indexes.size()); ++k) {
                    if (interval->getValue(indexes.at(k)) == '-') {
                        values.at(k)++;
                    }
                }
            }
        }
    }

    if (values.empty()) {
        return indexes.at(0);
    }

    const int minElementIndex =
        std::min_element(values.begin(), values.end()) - values.begin();

    return indexes.at(minElementIndex);
}
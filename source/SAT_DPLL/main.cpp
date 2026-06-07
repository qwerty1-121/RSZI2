#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QStack>
#include <string>
#include <cstring>
#include <stack>
#include <ostream>
#include "NodeBoolTree.h"
#include "boolinterval.h"
#include "boolequation.h"
#include "BBV.h"
#include "AllocatorExperiment.h"


int main(int argc, char *argv[])
{
    if (argc > 1 && std::strcmp(argv[1], "--allocator-experiment") == 0) {
        AllocatorExperiment::run();
        return 0;
    }

    QStringList full_file_list;
    QList<QStringList> Elements;
    std::string filepath;
    QStringList inputs;

    //std::cout << "Input file path...\n";
    //std::cin >> filepath;

    // Hardcode input
    // filepath = "sat_ex_2.pla";
    // filepath = "Sat_ex11_3.pla";
    filepath = "Sat_ex30_3.pla";

    QFile file(QString::fromUtf8(filepath.c_str()));

    //считываем весь файл
    if ((file.exists()) && (file.open(QIODevice::ReadOnly))) {
        while (!file.atEnd()) {
            full_file_list << file.readLine().replace("\r\n", "");
        }

        int cnfSize = full_file_list.length();
        BoolInterval **CNF = new BoolInterval*[cnfSize];
        int rangInterval = -1; // error

        if (cnfSize) {
            rangInterval = full_file_list[0].toUtf8().trimmed().length();
        }

        for (int i = 0; i < cnfSize; i++) { // Заполняем массив
            QString strv = full_file_list[i];
            CNF[i] = new BoolInterval(strv.toUtf8().trimmed().data());
        }

        QString rootvec = "";
        QString rootdnc = "";

        for (int i = 0; i < rangInterval; i++) {
            rootvec += "0";
            rootdnc += "1";
        }

        QByteArray v = rootvec.toUtf8();

        BBV vec(v.data());
        QByteArray d = rootdnc.toUtf8();
        BBV dnc(d.data());

        BoolInterval *root = new BoolInterval(vec, dnc);

        BoolEquation *boolequation = new BoolEquation(CNF, root, cnfSize, cnfSize, vec);

        bool rootIsFinded = false;
        stack<NodeBoolTree *> BoolTree;
        NodeBoolTree *startNode = new NodeBoolTree(boolequation);
        BoolTree.push(startNode);

        do {
            NodeBoolTree *currentNode(BoolTree.top());

            if (currentNode->lt == nullptr &&
                    currentNode->rt == nullptr) {
                BoolEquation *currentEquation = currentNode->eq;
                bool flag = true;

                while (flag) {
                    int a = currentEquation->CheckRules();

                    switch (a) {
                        case 0: {
                            BoolTree.pop();
                            flag = false;
                            break;
                        }

                        case 1: {
                            if (currentEquation->count == 0 ||
                                    currentEquation->mask.getWeight() ==
                                    currentEquation->mask.getSize()) {
                                flag = false;
                                rootIsFinded = true;

                                for (int i = 0; i < cnfSize; i++) {
                                    if (!CNF[i]->isEqualComponent(*currentEquation->root)) {
                                        rootIsFinded = false;
                                        BoolTree.pop();
                                        break;
                                    }
                                }
                            }

                            break;
                        }

                        case 2: {
                            int indexBranching = currentEquation->ChooseColForBranching();

                            BoolEquation *Equation0 = new BoolEquation(*currentEquation);
                            BoolEquation *Equation1 = new BoolEquation(*currentEquation);

                            Equation0->Simplify(indexBranching, '0');
                            Equation1->Simplify(indexBranching, '1');

                            NodeBoolTree *Node0 = new NodeBoolTree(Equation0);
                            NodeBoolTree *Node1 = new NodeBoolTree(Equation1);

                            currentNode->lt = Node0;
                            currentNode->rt = Node1;

                            BoolTree.push(Node1);
                            BoolTree.push(Node0);

                            flag = false;
                            break;
                        }
                    }
                }
            } else {
                BoolTree.pop();
            }

        } while (BoolTree.size() > 1 && !rootIsFinded);

        if (rootIsFinded) {
            cout << "Root is:\n ";
            BoolInterval *finded_root = BoolTree.top()->eq->root;
            cout << string(*finded_root);
        } else {
            cout << "Root is not exists!";
        }

    } else {
        std::cout << "File does not exists.\n";
    }

    return 0;
}
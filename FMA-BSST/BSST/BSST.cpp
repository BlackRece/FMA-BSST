// BSST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "BinSST.h"

int main() {
    std::cout << "\t\t_.-BSST Example-._\n";

    std::cout << "\n1) Create a tree:\n" << std::endl;
    
    BinSST tree = BinSST();
    tree.Print();

    std::cout << "\n\n2) Add '5' to tree:\n" << std::endl;
    tree.Insert(5);
    tree.Print();

    std::cout << "\n\n2) Delete '5' from tree:\n" << std::endl;
    tree.Delete(5);
    tree.Print();

    std::cout << "\n\n2) Insert '01683678' to tree:\n" << std::endl;
    tree.Insert(0);
    tree.Insert(1);
    tree.Insert(6);
    tree.Insert(8);
    tree.Insert(3);
    tree.Insert(6);
    tree.Insert(7);
    tree.Insert(8);
    tree.Print();

    std::cout << "\n\nEnd of example" << std::endl;
    std::cin;
}

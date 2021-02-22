/*	BSST.cpp - by Rece Thompson-Hamilton */

#include "BinSST.h"

int main() {
    cout << "\t\t_.-BSST Example-._\n";

    cout << "\n1) Create a tree:\n" << endl;
    
    BinSST tree = BinSST();
    cout << tree.Print(tree._root) << endl;

    cout << "\n\n3) Add '5' to tree:\n" << endl;
    tree._root = tree.Insert(tree._root, 5);
    cout << tree.Print(tree._root) << endl;

    cout << "\n\n4) Delete '5' from tree:\n" << endl;
    tree._root = tree.Delete(tree._root, 5);
    cout << tree.Print(tree._root) << endl;

    cout << "\n\n5) Insert '01683678' to tree:\n" << endl;
    int data[] = { 0,1,6,8,3,6,7,8 };
    
    for (int i = 0; i < 8; ++i) {
        cout << "\nInserting " << to_string(data[i]) << endl;
        tree._root = tree.Insert(tree._root, data[i]);
        cout << tree.Print(tree._root) << endl;
    }

    cout << "\nNotice that duplicates are discarded!" << endl;
    cout << "\n\n6) Delete '7' from tree:\n" << 
        "LEAF NODE" << endl;
    tree.Delete(tree._root, 7);
    cout << tree.Print(tree._root) <<endl;

    cout << "\n\n6) Delete '1' from tree:\n" <<
        "SINGLE CHILD NODE" << endl;
    tree.Delete(tree._root, 1);
    cout << tree.Print(tree._root) << endl;

    cout << "\n\n6) Delete '6' from tree:\n" <<
        "TWO CHILD NODES" << endl;
    tree.Delete(tree._root, 6);
    cout << tree.Print(tree._root) << endl;

    cout << "\n\n7) Insert '01683678' \n" << endl;
    for (int i = 0; i < 8; ++i) 
        tree._root = tree.Insert(tree._root, data[i]);
    cout << tree.Print(tree._root) << endl;

    cout << "\n\nFind node with key = '6' from tree:\n" << endl;
    cout << tree.Print(
        tree.Find(tree._root, 6)
    ) << endl;

    cout << "\n\nEnd of example" << endl;
    cin;
}

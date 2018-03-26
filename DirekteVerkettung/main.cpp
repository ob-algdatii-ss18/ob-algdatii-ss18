#include <iostream>
#include "Hashing.h"

using namespace std;

int main() {
    Hashing *hashing = new Hashing();
    cout << "15? " << (hashing->search(15) ? "ja" : "nein") << endl;
    hashing->insert(15);
    cout << "15? " << (hashing->search(15) ? "ja" : "nein") << endl;
    cout << "43? " << (hashing->search(43) ? "ja" : "nein") << endl;
    hashing->insert(43);
    cout << "43? " << (hashing->search(43) ? "ja" : "nein") << endl;
    cout << "15? " << (hashing->search(15) ? "ja" : "nein") << endl;
    hashing->remove(15);
    cout << "15? " << (hashing->search(15) ? "ja" : "nein") << endl;
    hashing->insert(1);
    hashing->insert(22);
    hashing->insert(22);
    hashing->insert(14);
    hashing->insert(46);
    hashing->insert(53);
    hashing->insert(6);
    hashing->insert(172);
    hashing->insert(172);
    hashing->insert(92);
    hashing->insert(44);
    hashing->insert(44);
    hashing->remove(53);
    cout << "Hashtable" << endl << "=========" << endl << *hashing;
    return 0;
}
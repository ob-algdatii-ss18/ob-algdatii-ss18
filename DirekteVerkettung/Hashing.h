#ifndef DIREKTEVERKETTUNG_HASHING_H
#define DIREKTEVERKETTUNG_HASHING_H

#include <iostream>

namespace details {
    static const unsigned short m = 7;

    inline const unsigned short h(const unsigned int key) {
        return static_cast<const unsigned short>(key % m);
    }
}

class Hashing {
private:

    struct HashTableEntry {
        const unsigned int key;
        HashTableEntry *nextSynonym = nullptr;

        // inline
        HashTableEntry(const unsigned int k) : key(k) {}
    };

    // Separate Verkettung
    // HashTableEntry hashtable[details::m];
    HashTableEntry *hashtable[details::m];

public:

    bool search(const unsigned int) const;

    void insert(const unsigned int);

    void remove(const unsigned int);

    friend std::ostream &operator<<(std::ostream &, const Hashing &);

};

#endif //DIREKTEVERKETTUNG_HASHING_H

#include "Hashing.h"

bool Hashing::search(const unsigned int key) const {
    HashTableEntry *current = hashtable[details::h(key)];
    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }
        current = current->nextSynonym;
    }
    return false;
}

void Hashing::insert(const unsigned int key) {
    auto hashAddress = details::h(key);
    if (hashtable[hashAddress] == nullptr) {
        hashtable[hashAddress] = new HashTableEntry(key);
    } else {
        auto current = hashtable[hashAddress];
        while (current->key != key) {
            if (current->nextSynonym == nullptr) {
                current->nextSynonym = new HashTableEntry(key);
                return;
            } else
                current = current->nextSynonym;
        }
    }
}

void Hashing::remove(const unsigned int key) {
    auto hashAddress = details::h(key);
    if (hashtable[hashAddress] != nullptr) {
        if (hashtable[hashAddress]->key == key) {
            auto tmp = hashtable[hashAddress];
            hashtable[hashAddress] = hashtable[hashAddress]->nextSynonym;
            tmp->nextSynonym = nullptr;
            delete tmp;
        } else {
            auto prev = hashtable[hashAddress];
            auto current = prev->nextSynonym;
            while (current != nullptr) {
                if (current->key == key) {
                    auto tmp = current;
                    prev->nextSynonym = current->nextSynonym;
                    tmp->nextSynonym = nullptr;
                    delete tmp;
                    return;
                }
                prev = current;
                current = current->nextSynonym;
            }
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Hashing &hashing) {
    for (unsigned short i = 0; i < details::m; i++) {
        os << "[" << i << "]";
        auto current = hashing.hashtable[i];
        while (current != nullptr) {
            os << " -> " << current->key;
            current = current->nextSynonym;
        }
        os << std::endl;
    }
    return os;
}

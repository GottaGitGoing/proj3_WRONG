// HashMap.cpp
#include <string>
#include <iostream>
#include "HashMap.hpp"



namespace 
{
    unsigned int ascii_hash(const std::string& s)
    {
        int hash_value = 0;
        // Credit to Professor Pattis. I had the idea of changing letter to ascii and add
        // the hash value. and I saw that professor pattis had done something similiar.
        for (int i=0; i<s.size(); ++i)
        {
            hash_value = 31*hash_value + s[i]; 
        }
        return hash_value;
    }
}

HashMap::HashFunction hash_it = ascii_hash;

unsigned int GetHash(std::string& s, HashMap::HashFunction)
{
    int hash = ascii_hash(s);
    return hash;
}


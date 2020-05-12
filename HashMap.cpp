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

HashMap::HashFunction def_hash = ascii_hash;


HashMap::HashMap()
    : hashFunction{def_hash}, Buckets{new Node*[HashMap::INITIAL_BUCKET_COUNT]}
    , sz{0}, cap{INITIAL_BUCKET_COUNT}
{
    for (unsigned int i=0; i< HashMap::bucketCount(); ++i)
    {
        Buckets[i] = nullptr;
    }
}

HashMap::HashMap(HashMap::HashFunction hashFunction)
    :Buckets{new Node*[HashMap::INITIAL_BUCKET_COUNT]}
    , sz{0}, cap{INITIAL_BUCKET_COUNT}
{
    def_hash = hashFunction;
}


HashMap::HashMap(const HashMap& hm)
   : Buckets{new Node*[hm.cap]}, sz{hm.sz}, cap{hm.cap}
{

}


HashMap::~HashMap()
{
    for (unsigned int i=0;i < HashMap::bucketCount();++i)
    {
        delete Buckets[i];
    }
    delete[] Buckets;
}


unsigned int HashMap::bucketCount() const
{
    return cap;
}


unsigned int GetHash(std::string& s, HashMap::HashFunction hasher )
{
    int hash = def_hash(s);
    return hash;
}


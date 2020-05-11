#include "HashMap.hpp"
#include <string>
#include <iostream>
int main()
{

    const std::string g = "arna";
    std::cout << GetHash(g) % 10 << std::endl;
    return 0;
}


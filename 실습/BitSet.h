#include <iostream>
#include <exception>
#include "Bvector.h"

class IncompatibleException : public std::exception{
public:
    int first,second;
    IncompatibleException(int f, int s) : first(f), second(s){
        std::cout << "In + operation, the operands are not compatible." << std::endl;
        std::cout << "The size of the first BitSet is" << first << std::endl;
        std::cout << "The size of the first BitSet is" << second << std::endl;
    }
};

class BitSet : public Bvector{
    public:
        BitSet(int sz=32);
void insert(int v);
friend BitSet operator+(const BitSet& v1, const BitSet& v2);
friend std::ostream& operator<<(std::ostream& os, const BitSet& s);
};
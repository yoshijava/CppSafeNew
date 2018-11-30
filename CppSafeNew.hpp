#ifndef GLOBAL_NEW_DELETE_OVERLOAD_H
#define GLOBAL_NEW_DELETE_OVERLOAD_H
#include <cstdio>
#include <iostream>
#include <map>

std::map<void *, unsigned int> lengthMap;
// Global new/delete overloading
void * operator new(size_t size) 
{ 
    std::cout << "New operator overloading " << std::endl; 
    void * p = malloc(size); 
    lengthMap[p] = size;
    return p; 
} 
  
void operator delete(void * p) 
{ 
    std::cout << "Delete operator overloading " << std::endl; 
    lengthMap.erase(p);
    free(p); 
} 

#endif

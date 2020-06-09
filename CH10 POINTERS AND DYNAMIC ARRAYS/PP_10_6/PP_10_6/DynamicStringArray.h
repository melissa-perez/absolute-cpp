#pragma once

#include <iostream>
#include <string>
using namespace std;

class DynamicStringArray
{
public:
   DynamicStringArray() : dynamicArray(nullptr), size(0) {};
   ~DynamicStringArray();
   DynamicStringArray(const DynamicStringArray &dynStrArr);
   const DynamicStringArray& operator=(const DynamicStringArray &rhs);
   int getSize() const { return size; }
   void addEntry(string stringToAdd);
   bool deleteEntry(string stringToDelete);
   string* getEntry(int index) const;

private:
   string *dynamicArray;
   int size;
   void allocateCleanArray();
   void deallocateArray();
};




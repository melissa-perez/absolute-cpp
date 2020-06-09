#include "DynamicStringArray.h"

using namespace std;
DynamicStringArray::~DynamicStringArray()
{
   deallocateArray();
}

DynamicStringArray::DynamicStringArray(const DynamicStringArray &dynStrArr)
{
   *this = dynStrArr;
}

const DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray &rhs)
{
   if (this != &rhs)
   {
      this->deallocateArray();
      this->size = rhs.size;
      this->allocateCleanArray();
 
      for (int i = 0; i < size; i++)
        this->dynamicArray[i] = rhs.dynamicArray[i];
   }
   return *this;
}

void DynamicStringArray::addEntry(string stringToAdd)
{
   int newSize = this->size + 1;
   string *newArray = new string[newSize];

   for (int i = 0; i < this->size; i++) 
      newArray[i] = this->dynamicArray[i];
 
   newArray[newSize - 1] = stringToAdd;
   deallocateArray();
   allocateCleanArray();
   this->size = newSize;
   this->dynamicArray = newArray;
}

bool DynamicStringArray::deleteEntry(string stringToDelete)
{
   bool stringFound = false;
   int indexStringLocated = 0;
   int newSize = this->size - 1;

   for (int i = 0; i < this->size; i++)
   {
      if (this->dynamicArray[i] == stringToDelete)
      {
         stringFound = true;
         indexStringLocated = i;
         int j = 0, k = 0;
         string *newArray = new string[newSize];
         while (j < newSize)
         {
            if (k != indexStringLocated)
               newArray[j] = this->dynamicArray[k];
            
            else 
               j--;
            j++;
            k++;
         }
         deallocateArray();
         allocateCleanArray();
         this->size = newSize;
         this->dynamicArray = newArray;
         break;
      }
  }
   return stringFound;
}

string* DynamicStringArray::getEntry(int index) const
{
   string *stringToReturn = nullptr;

   for (int i = 0; i < this->size; i++)
   {
      if (i == index)
      {
         stringToReturn = &dynamicArray[i];
         break;
      }       
   }
   return stringToReturn;
}

void DynamicStringArray::allocateCleanArray()
{
   if (dynamicArray != nullptr)
      deallocateArray();

   dynamicArray = new string[size];
}

void DynamicStringArray::deallocateArray()
{
   delete[] dynamicArray;
   dynamicArray = nullptr;
   size = 0;
}
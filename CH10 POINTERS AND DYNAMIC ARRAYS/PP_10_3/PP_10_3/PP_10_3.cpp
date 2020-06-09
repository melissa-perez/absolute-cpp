#include <iostream>
#include <string>
using namespace std;

void reverse(char *stringToReverse)
{
   char *head = nullptr, *tail = nullptr;
   char tmp;

   if (stringToReverse) {
      head = stringToReverse, tail = head;
      while (*tail)
         tail++;

      tail--;

      while (head < tail)
      {
         tmp = *head;
         *head++ = *tail;
         *tail-- = tmp;
      }
   }
}

int main()
{
   string input;
   cout << "Enter a word: ";
   getline(cin, input);

   char *strArr = &(input[0]);

   cout << "The input: " << input << endl;
   reverse(strArr);
   cout << "The input reversed: " << strArr << endl;
   return 0;
}

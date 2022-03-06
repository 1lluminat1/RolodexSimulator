//
//  input_helper.h
//  Rolodex
//
//  Created by Christopher Garland on 3/1/22.
//

#ifndef input_helper_h
#define input_helper_h

#include <iostream>
#include <cctype>

// after prompting with given string,
// reads a character and returns its
// capital version (if any).
//
// prints string.  reads character.
// calls toupper in return statement.
//
inline char get_upchar(const char prompt[] = "")   // in
{
   char ch;
   std::cout << prompt << std::endl;
   std::cin >> ch;
   std::cin.clear();
   std::cin.ignore(10000,'\n');
   return std::toupper(ch);
}
#endif /* input_helper_h */

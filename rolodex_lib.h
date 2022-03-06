//
//  rolodex_lib.h
//  Rolodex
//
//  Created by Christopher Garland on 3/2/22.
//

#ifndef rolodex_lib_h
#define rolodex_lib_h

#include "rolodex_entry.h"
#include <string>

CompTo int_to_compto (const int & num)
{
   CompTo result;
   if (num == 0)
   {
      result = Fname;
   }
   else if (num == 1)
   {
      result = Lname;
   }
   else if (num == 2)
   {
      result = Street;
   }
   else if (num == 3)
   {
      result = Town;
   }
   else if (num == 4)
   {
      result = State;
   }
   else if (num == 5)
   {
      result = Phone;
   }
   else if (num == 6)
   {
      result = Email;
   }
   else if (num == 7)
   {
      result = Zip5;
   }
   else if (num == 8)
   {
      result = Zip4;
   }
   else
   {
      result = ERROR;
   }
   return result;
}

CompTo str_to_compto(const char ch[])
{
   CompTo result;
   if (strcmp(ch, "FIRST") == 0 || strcmp(ch, "F") == 0)
   {
      result = Fname;
   }
   else if (strcmp(ch, "LAST") == 0 || strcmp(ch, "L") == 0)
   {
      result = Lname;
   }
   else if (strcmp(ch, "STREET") == 0 || strcmp(ch, "S") == 0)
   {
      result = Street;
   }
   else if (strcmp(ch, "TOWN") == 0 || strcmp(ch, "L") == 0)
   {
      result = Town;
   }
   else if (strcmp(ch, "STATE") == 0 || strcmp(ch, "ST") == 0)
   {
      result = State;
   }
   else if (strcmp(ch, "PHONE") == 0 || strcmp(ch, "P") == 0)
   {
      result = Phone;
   }
   else if (strcmp(ch, "Email") == 0 || strcmp(ch, "E") == 0)
   {
      result = Email;
   }
   else if (strcmp(ch, "ZIP5") == 0)
   {
      result = Zip5;
   }
   else if (strcmp(ch, "ZIP4") == 0)
   {
      result = Zip4;
   }
   else
   {
      result = ERROR;
   }
   return result;
}

void press_enter_to_continue()
{
   std::cout << "Press ENTER to continue...\n";
   std::cin.clear();
   std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n' );
}

void compare_to(char dest[], RolodexEntry entry, CompTo sort_by)
{
   entry.enum_to_ch(dest, sort_by);
}

CompTo get_byvar(void)
{
   CompTo by_what;
   size_t MAX_FIELD = 7;
   char field[MAX_FIELD];
   std::cin >> field;
   if (std::isdigit(field[0]))
   {
      int i = field[0] - '0';
      int j = field[1] - '0';
      if (i == 0)
      {
         by_what = ERROR;
      }
      else if (i == 1 && j == 0)
      {
         by_what = ERROR;
      }
      else
      {
         by_what = int_to_compto(i - 1);
      }
   }
   else
   {
      size_t i = 0;
      while(field[i] != '\0')
      {
         field[i] = toupper(field[i]);
         ++i;
      }
      by_what = str_to_compto(field);
   }
   return by_what;
}

void char_up(char target[])
{
   size_t i = 0;
   while (target[i] != '\0')
   {
      target[i] = std::toupper(target[i]);
      i++;
   }
}

std::string enum_to_string(CompTo which)
{
   const std::string COMPTO_NAMES[9] =
   {"Fname", "Lname", "Street", "Town", "State", "Phone",
      "Email", "Zip-5", "Zip-4"};
   return COMPTO_NAMES[which];
}

#endif /* rolodex_lib_h */

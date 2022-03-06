//
//  rolodex_entry.cpp
//  Rolodex
//
//  Created by Christopher Garland on 2/28/22.
//

#include "rolodex_entry.h"

void RolodexEntry::input(void)
{
   size_t MAX_TEMP = 61;// set equal to largest possible (email)
   char temp[MAX_TEMP];
   int temp_zip = 0;
   size_t i = 0, cur = 0;
   while (cur < 9)
   {
      if (cur == 0)
      {
         std::cout << "First Name: ";
         get_line(temp, MAX_TEMP);
         std::cout << std::endl;
         set_fname(temp);
      }
      else if (cur == 1)
      {
         std::cout << "Last Name: ";
         get_line(temp, MAX_TEMP);
         set_lname(temp);
         std::cout << std::endl;
      }
      else if (cur == 2)
      {
         std::cout << "Street: ";
         get_line(temp, MAX_TEMP);
         set_street(temp);
         std::cout << std::endl;
      }
      else if (cur == 3)
      {
         std::cout << "Town: ";
         get_line(temp, MAX_TEMP);
         set_town(temp);
         std::cout << std::endl;
      }
      else if (cur == 4)
      {
         std::cout << "State: ";
         get_line(temp, MAX_TEMP);
         set_state(temp);
         std::cout << std::endl;
      }
      else if (cur == 5)
      {
         std::cout << "Phone: ";
         get_line(temp, MAX_TEMP);
         set_phone(temp);
         std::cout << std::endl;
      }
      else if (cur == 6)
      {
         std::cout << "Email: ";
         get_line(temp, MAX_TEMP);
         set_email(temp);
         std::cout << std::endl;
      }
      else if (cur == 7)
      {
         std::cout << "Zip-5: ";
         std::cin >> temp_zip;
         set_zip(temp_zip);
         std::cout << std::endl;
      }
      else if (cur == 8)
      {
         std::cout << "Zip-4: ";
         std::cin >> temp_zip;
         set_zip_4(temp_zip);
         std::cout << std::endl;
      }
      cur++;
      i = 0;
      temp_zip = 0;
      strcpy(temp, "");
   }
   std::cin.clear();
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
   return;
}

//
//  rolodex_menu.h
//  Rolodex
//
//  Created by Christopher Garland on 2/28/22.
//

#ifndef rolodex_menu_h
#define rolodex_menu_h

#include <iostream>
#include <iomanip>
#include <string>
#include "rolodex_mngr.h"

std::string enum_to_str(const int & choice)
{
   std::string temp = "";
   switch(choice)
   {
      case 0:
      {
         temp = "Quit";
         break;
      }
      case 1:
      {
         temp = "Add entry";
         break;
      }
      case 2:
      {
         temp = "Edit entry";
         break;
      }
      case 3:
      {
         temp = "Delete entry";
         break;
      }
      case 4:
      {
         temp = "Find entry";
         break;
      }
      case 5:
      {
         temp = "Print all entries";
         break;
      }
      case 6:
      {
         temp = "Sort entries";
         break;
      }
      case 7:
      {
         temp = "First Name";
         break;
      }
      case 8:
      {
         temp = "Last Name";
         break;
      }
      case 9:
      {
         temp = "Street";
         break;
      }
      case 10:
      {
         temp = "Town";
         break;
      }
      case 11:
      {
         temp = "State";
         break;
      }
      case 12:
      {
         temp = "Phone Number";
         break;
      }
      case 13:
      {
         temp = "Email Address";
         break;
      }
      case 14:
      {
         temp = "Zip-5";
         break;
      }
      case 15:
      {
         temp = "Zip-4";
         break;
      }
      case 16:
      {
         temp = "Return to Main Menu";
         break;
      }
   }
   return temp;
}

// Displays the values of the array converted to phrases, in order
void menu_from_nums(const int arr[], size_t size, std::string prefix = "")
{
   std::cout << std::endl;
   for (size_t i = 0; i < size; i++)
   {
      std::cout << i + 1 << ") ";
      if ( (i != size - 1) && (i != 9))
      {
         std::cout << prefix;
      }
      std::cout << enum_to_str(arr[i]) << std::endl;
   }
   std::cout << std::endl;
}

void gen_main_men(void)
{
   const size_t MAX_MAIN = 7;
   const int main[MAX_MAIN] = {1, 2, 3, 4, 5, 6, 0};
   const std::string prefix = "";
   menu_from_nums(main, MAX_MAIN, prefix);
}

void gen_byvar_men(const char prefix[])
{
   const size_t MAX_MENU = 10;
   const int s_menu[MAX_MENU] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
   menu_from_nums(s_menu, MAX_MENU, prefix);
}

short get_mchoice(int & curMen)
{                  // curMen == 0 --> MAIN MENU
                   // curMen == 2 --> EDIT MENU
                   //        == 3 --> DELETE MENU
                   //        == 4 --> FIND MENU
                   //        == 6 --> SORT MENU
   short choice = 0;
   std::cin >> choice;
   std::cin.clear();
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
   
   return choice;
}

void display_table_head_border(void)
{
   std::cout << std::setfill('~');
   std::cout << std::setw(9) << std::left << "+"
   << std::setw(8) << "+" << std::setw(11) << "+" << std::right << "+"
   << std::setw(11) << "+" << std::setw(3) << "+"  << std::setw(11) << "+"
   << std::setw(12) << "+" << std::setw(11) << "+" << std::endl;
   std::cout << std::setfill(' ');
}

void display_table_header(void)
{
   std::cout << std::endl;
   display_table_head_border();
   std::cout << std::left << std::setw(1) << "|"
             << std::left << std::setw(9) << "[FNAME] |"
             << std::setw(8) << "[LNAME]|"
             << std::setw(11) << "[STREET]  |"
             << std::setw(6)  << "[TOWN]"
             << std::setw(3)  << "[STATE]|"
             << std::setw(10) << "[PHONE]   |"
             << std::setw(10) << "[EMAIL]    |"
             << std::setw(8) << "[ZIP]"
             << std::right << std::setw(3) << "|" << std::endl;
   display_table_head_border();
}

void display_row(const RolodexEntry & entry)
{
   size_t MAX_COPY = 15;
   char orig[MAX_EMAIL];
   char copy[MAX_COPY];
   std::cout << std::setfill(' ');
   std::cout << std::left << std::setw(1) << "|";
   
   // FNAME
   entry.get_fname(orig);
   strncpy(copy, orig, 7);
   strcpy(orig, "");
   std::cout << std::setw(8) << copy;
   strcpy(copy, "");
   std::cout << std::setw(1) << "|";
   
   // LNAME
   entry.get_lname(orig);
   strncpy(copy, orig, 7);
   strcpy(orig, "");
   std::cout << std::setw(7) << copy;
   strcpy(copy, "");
   std::cout << std::setw(1) << "|";
   
   // STREET
   entry.get_street(orig);
   strncpy(copy, orig, 10);
   strcpy(orig, "");
   std::cout << std::setw(10) << copy;
   strcpy(copy, "");
   std::cout << std::setw(1) << "|";
   
   // TOWN
   entry.get_town(orig);
   strncpy(copy, orig, 10);
   strcpy(orig, "");
   std::cout << std::setw(10) << copy;
   strcpy(copy, "");
   std::cout << std::setw(1) << "|";
   
   //STATE
   entry.get_state(orig);
   strncpy(copy, orig, 3);
   strcpy(orig, "");
   std::cout << std::setw(2) << copy;
   strcpy(copy, "");
   std::cout << std::setw(1) << "|";
   
   // PHONE NUMBER
   entry.get_phone(orig);
   strncpy(copy, orig, 10);
   strcpy(orig, "");
   std::cout << std::setw(10) << copy;
   strcpy(copy, "");
   std::cout << std::setw(1) << "|";
   
   // EMAIL ADDRESS
   entry.get_email(orig);
   strncpy(copy, orig, 11);
   strcpy(orig, "");
   std::cout << std::setw(11) << copy;
   strcpy(copy, "");
   std::cout << std::setw(1) << "|";
   
                                // ZIP-5                  // ZIP-4
   std::cout << std::setw(5) << entry.get_zip() << "-" << entry.get_zip_4();
   std::cout << std::setw(1) << "|" << std::endl;
}

void gen_men_from_choice(const int & men_choice)
{
   size_t MAX_PREFIX = 20;
   char prefix[MAX_PREFIX];
   if ( men_choice == 2)// a choice of 2 means edit
   {
      strcpy(prefix, "Edit ");
      gen_byvar_men(prefix);
   }
   else if (men_choice == 4)// a choice of 4 means find
   {
      strcpy(prefix, "Find ");
      gen_byvar_men(prefix);
   }
   else if (men_choice == 6)// a choice of 6 means sort
   {
      strcpy(prefix, "Sort ");
      gen_byvar_men(prefix);
   }
   return;
}


#endif /* rolodex_menu_h */

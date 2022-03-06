//
//  rolodex.h
//  Rolodex
//
//  Created by Christopher Garland on 2/26/22.
//

#ifndef rolodex_entry_h
#define rolodex_entry_h

#include <iostream>
#include <cstring>
#include <limits>
#include <cmath>

const bool CLEAR_BUFFER_AFTER_FAIL = true,
                LEAVE_BUFFER_ALONE = false;

const size_t MAX_NAME = 21,
             MAX_STREET = 41,
             MAX_TOWN = 31,
             MAX_STATE = 3,
             MAX_PHONE = 14,
             MAX_EMAIL = 61;
enum CompTo { Fname = 0, Lname, Street, Town, State, Phone, Email, Zip5, Zip4,
   ERROR};


class RolodexEntry
{
   char fname[MAX_NAME], lname[MAX_NAME];
   char street[MAX_STREET], town[MAX_TOWN], state[MAX_STATE];
   char phone[MAX_PHONE];
   char email[MAX_EMAIL];
   long zip;
   short zip_4;
   
public:
  
   // CONSTRUCTORS
   RolodexEntry(void) : zip{}, zip_4{}
   {// default ctor
      fname[0] = '\0'; lname[0] = '\0';
      street[0] = '\0'; town[0] = '\0'; state[0] = '\0';
      phone[0] = '\0'; email[0] = '\0';
   }
   RolodexEntry(const RolodexEntry & r) : zip{r.zip}, zip_4{r.zip_4}
   {// copy ctor
      strcpy(fname, r.fname);
      strcpy(lname, r.lname);
      strcpy(street, r.street);
      strcpy(town, r.town);
      strcpy(state, r.state);
      strcpy(phone, r.phone);
      strcpy(email, r.email);
   }
   
   // ACCESSORS
   void get_fname(char copy[], size_t len = 0) const
   {
      if (len <= 1)
      {
         strcpy(copy, fname);
      }
      else // len > 1
      {
         strncpy(copy, fname, len - 1);
         copy[len - 1] = '\0';
      }
      return;
   }
   void get_lname(char copy[], size_t len = 0) const
   {
      if (len <= 1)
      {
         strcpy(copy, lname);
      }
      else // len > 1
      {
         strncpy(copy, lname, len - 1);
         copy[len - 1] = '\0';
      }
      return;
   }
   void get_street(char copy[], size_t len = 0) const
   {
      if (len <= 1)
      {
         strcpy(copy, street);
      }
      else // len > 1
      {
         strncpy(copy, street, len - 1);
         copy[len - 1] = '\0';
      }
      return;
   }
   void get_town(char copy[], size_t len = 0) const
   {
      if (len <= 1)
      {
         strcpy(copy, town);
      }
      else // len > 1
      {
         strncpy(copy, town, len - 1);
         copy[len - 1] = '\0';
      }
      return;
   }
   void get_state(char copy[], size_t len = 0) const
   {
      if (len <= 1)
      {
         strcpy(copy, state);
      }
      else // len > 1
      {
         strncpy(copy, state, len - 1);
         copy[len - 1] = '\0';
      }
      return;
   }
   void get_phone(char copy[], size_t len = 0) const
   {
      if (len <= 1)
      {
         strcpy(copy, phone);
      }
      else // len > 1
      {
         strncpy(copy, phone, len - 1);
         copy[len - 1] = '\0';
      }
      return;
   }
   void get_email(char copy[], size_t len = 0) const
   {
      if (len <= 1)
      {
         strcpy(copy, email);
      }
      else // len > 1
      {
         strncpy(copy, email, len - 1);
         copy[len - 1] = '\0';
      }
      return;
   }
   long get_zip(void) const {return zip;}
   short get_zip_4(void) const {return zip_4;}
   
   // MUTATORS
   bool set_fname(const char orig[])
   {
      strncpy(fname, orig, MAX_NAME-1);
      fname[MAX_NAME-1] = '\0';
      return true;
   }
   bool set_lname(const char orig[])
   {
      strncpy(lname, orig, MAX_NAME-1);
      lname[MAX_NAME-1] = '\0';
      return true;
   }
   bool set_street(const char orig[])
   {
      strncpy(street, orig, MAX_STREET-1);
      street[MAX_STREET-1] = '\0';
      return true;
   }
   bool set_town(const char orig[])
   {
      strncpy(town, orig, MAX_TOWN-1);
      town[MAX_TOWN-1] = '\0';
      return true;
   }
   bool set_state(const char orig[])
   {
      strncpy(state, orig, MAX_STATE-1);
      state[MAX_STATE-1] = '\0';
      return true;
   }
   bool set_phone(const char orig[])
   {
      strncpy(phone, orig, MAX_PHONE-1);
      phone[MAX_PHONE-1] = '\0';
      return true;
   }
   bool set_email(const char orig[])
   {
      strncpy(email, orig, MAX_EMAIL-1);
      email[MAX_EMAIL-1] = '\0';
      return true;
   }
   bool set_zip(long new_zip)
   {
      bool okay = false;
      if (cnt_dig(int(new_zip)) == 5)
      {
         zip = new_zip;
         okay = true;
      }
      return okay;
   }
   bool set_zip_4(short new_zip_4)
   {
      bool okay = false;
      if (cnt_dig(new_zip_4) == 4)
      {
         zip_4 = new_zip_4;
         okay = true;
      }
      return okay;
   }
   
   // EXTRA FUNCTIONS
   //
   void enum_to_ch(char dest[], CompTo sort_type, size_t len = 0) const
   {
      if (sort_type == Fname)
      {
         get_fname(dest, len);
      }
      else if (sort_type == Lname)
      {
         get_lname(dest);
      }
      else if (sort_type == Street)
      {
         get_street(dest);
      }
      else if (sort_type == Town)
      {
         get_town(dest);
      }
      else if (sort_type == State)
      {
         get_state(dest);
      }
      else if (sort_type == Phone)
      {
         get_phone(dest);
      }
      else if (sort_type == Email)
      {
         get_email(dest);
      }
   }
   
   // compares a string against requested data type
   short compare(const char comp_this[], CompTo to_this, size_t len = 0) const
   {
      char temp[MAX_EMAIL];
      enum_to_ch(temp, to_this);
      return strncmp(comp_this, temp, len);
   }
   
   void input(void);
  
   
   bool get_line(char s[], size_t MAX_S,
                        char stop = '\n',
                        bool clear = CLEAR_BUFFER_AFTER_FAIL) const
   {
      bool failed;
      std::cout.flush();             // or cout << flush;
      if (std::cin.peek() == stop)
      {
          std::cin.ignore();
      }
      std::cin.getline(s, MAX_S, stop);
      failed = std::cin.fail();
      if (failed && clear)
      {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), stop);
      }
     return failed;
   }
   
   // counst the number of digits in a number
   int cnt_dig(int num) const {return int(log10(num) + 1);}
   
};

#endif /* rolodex_entry_h */

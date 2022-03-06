//
//  linear_search.h
//  Rolodex
//
//  Created by Christopher Garland on 3/4/22.
//

#ifndef linear_search_h
#define linear_search_h
#include <vector>
#include "rolodex_mngr.h"
#include "rolodex_lib.h"

// linear search algortihm modified to work with a vector
// of RolodexEntry base type
size_t linear_search(const std::vector<RolodexEntry> & list,
                       char find[], CompTo search_type,
                       std::vector<RolodexEntry>::size_type start)
{
   std::vector<RolodexEntry>::size_type v_pos = start;
   size_t begin = 0;
   char orig[MAX_EMAIL];
   char target[strlen(find)];// var for truncated target
   bool found = false;
   while(v_pos < list.size() && !found)
   {
      compare_to(orig, list[v_pos], search_type);// obtain char[] representation
      strncpy(target, orig, strlen(find));// initial truncated search target
      char_up(target);// convert to uppercase
      while ((begin + strlen(find)) <= strlen(orig) &&// while we havent met end
            !found)// and havent found search term
      {
         if (strcmp(find, target) == 0)
         {
            found = true;
         }
         else
         {
            begin++;// increment begin index
            strncpy(target, orig+begin, strlen(find));// truncate to target length
            char_up(target);// convert to uppercase
         }
      }
      if (!found)
      {
         v_pos++;
      }
      begin = 0;
   }
   return v_pos;
}

#endif /* linear_search_h */

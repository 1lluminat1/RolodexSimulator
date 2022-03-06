//
//  rolodex_mngr.h
//  Rolodex
//
//  Created by Christopher Garland on 2/26/22.
//

#ifndef rolodex_mngr_h
#define rolodex_mngr_h

#include "rolodex_entry.h"
#include "insertion_sort.h"
#include "rolodex_menu.h"
#include "binary_search.h"
#include "linear_search.h"

const size_t MAX_ENTRIES = 101;

class Rolodex
{
   RolodexEntry list[MAX_ENTRIES];
   size_t current;
   int sorted_on;
public:
// Constructors
   // default ctor                   //default to 9 to avoid enum issues
   Rolodex(void):list{}, current{0}, sorted_on{9} {}
   // copy ctor
   Rolodex(const Rolodex & r):current{r.current}, sorted_on{r.sorted_on}{}
   
// Accessors
   RolodexEntry get (size_t index) const { return list[index];}
   size_t get_current(void) const {return current;}
   int get_sorted_on(void) const {return sorted_on;}
   
// Mutators
   bool set(size_t index, const RolodexEntry & new_entry)
   {
      bool okay = false;
      if ( (index <= current) && !full() )
      {
         list[index] = RolodexEntry(new_entry);
         okay = true;
      }
      else
      {
         okay = add(new_entry);
      }
      return okay;
   }
   bool add(const RolodexEntry & new_entry)
   {
      bool okay = false;
      if (!full())
      {
         list[current] = RolodexEntry(new_entry);
         okay = true;
         current++;
      }
      else
      {
         std::cout << std::endl << "\nError: Max Entries Reached.\n"
         << std::endl;
      }
      return okay;
   }
   void set_current(const size_t & num) {current = num; return;}
   void set_sorted_on(const int & num) {sorted_on = num; return;}
   
// Extra Functions
   
   // sets entries in the rolodex from vec of RolodexEntryies
   void insert_srtd_vec(std::vector<RolodexEntry> & vec)
   {
      for (size_t i = 0; i < current; ++i)
      {
         set(i, vec[i]);
      }
   }
   // returns if the rolodex is full of entries
   bool full(void) const { return current == MAX_ENTRIES; } const
   // sorts the entries according to chosen column
   void sort(CompTo sort_by, const size_t MAX_ENTRY)
   {
      std::vector<RolodexEntry> sorted_vec;
      for (size_t i = 0; i < get_current(); ++i)
      {
         sorted_vec.push_back(get(i));
      }
      good_insertion(sorted_vec, sort_by, MAX_ENTRY);
      insert_srtd_vec(sorted_vec);
      set_sorted_on(sort_by);
   }
   // prints all entries currently in the rolodex
   void print_all(void) const
   {
      size_t max;
      display_table_header();
      max = get_current();
      for (size_t i = 0; i < max; i++)
      {
         display_row(get(i));
      }
      display_table_head_border();
   }
   // takes in a start index, and shifts all entries above down one
   void shift_entries(const size_t & to)
   {
      RolodexEntry temp;
      size_t cur_before = get_current();
      for (size_t i = to - 1; i < (cur_before - 1); i++)
      {
         set(i, get(i+1));
      }
   }
   // controls the binary search routine
   size_t bin_search(char find[], CompTo search_type) const
   {
      std::vector<RolodexEntry> searched_vec;
      for (size_t i = 0; i < get_current(); i++)
      {
         searched_vec.push_back(get(i));
      }
      size_t found_index = binary_search(searched_vec, find, search_type);
      return found_index;
   }
   // controls the linear search routine
   size_t lin_search(char find[], CompTo search_type, size_t start) const
   {
      std::vector<RolodexEntry> searched_vec;
      for (size_t i = 0; i < get_current(); i++)
      {
         searched_vec.push_back(get(i));
      }
      size_t found_index = linear_search(searched_vec, find,
                                         search_type, start);
      return found_index;
   }
    
   
   
};

#endif /* rolodex_mngr_h */

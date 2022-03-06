//
//  insertion_sort.h
//  Rolodex
//
//  Created by Christopher Garland on 3/2/22.
//

#ifndef insertion_sort_h
#define insertion_sort_h

#include <vector>
#include "rolodex_mngr.h"
#include "rolodex_lib.h"


/*
 * Place the new element into the head of the sub-vector
 * specified of the given vector.  The current element at
 * that position (as well as any which follow it) are
 * shifted toward the end of the sub-vector.  A value of
 * true will be returned if the sub-vector was non-empty;
 * false will be returned otherwise.
 */
template <typename Base_Type>
   inline
bool insert(std::vector<Base_Type> & vec,
            typename std::vector<Base_Type>::size_type before_me,
            const Base_Type & new_item,
            typename std::vector<Base_Type>::size_type end)
{
    bool okay = before_me < end;
    if (okay)
    {
        for (typename std::vector<Base_Type>::size_type pos = end;
             pos > before_me; pos--)
        {
            vec[pos] = vec[pos-1];
        }
        vec[before_me] = new_item;
    }
    return okay;
}

// vector is placed into in sorted order -- non-ascending
// (decreasing)

void good_insertion(std::vector<RolodexEntry> & list,
                    CompTo sort_by, size_t MAX_ENTRY)
{
   char comp[MAX_ENTRY];
   std::vector<RolodexEntry>::size_type dest;
   RolodexEntry holder;
   for (std::vector<RolodexEntry>::size_type next = 1;
        next < list.size(); ++next)
   {
      holder = list[next];
      dest = next;
      compare_to(comp, list[dest-1], sort_by);
      while (dest > 0 &&
             (holder.compare(comp, sort_by) > 0))
      {
         --dest;
      }
      if (dest != next)
      {
         insert(list, dest, holder, next);
      }
      compare_to(comp, list[dest-1], sort_by);
   }
   return;
}
#endif /* insertion_sort_h */

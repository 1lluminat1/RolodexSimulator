//
//  binary_search.h
//  Rolodex
//
//  Created by Christopher Garland on 3/2/22.
//

#ifndef binary_search_h
#define binary_search_h

#include "rolodex_mngr.h"
#include "rolodex_lib.h"

/*
 * Searches through vector v for element f.
 *
 * NOTE:  The elements of v **MUST** be in order for this
 *        search to work!!!  (We assume non-decreasing --
 *        ascending-like -- order here.)
 *
 * Returns position of f if found or a position not
 * containing f (if f is not present).
 */
// remember that v must be in order (I'm assuming ascending-like order here)
size_t binary_search(const std::vector<RolodexEntry> & v, char f[],
                     CompTo search_type)
{
    std::vector<RolodexEntry>::size_type bot = 0,
              top = v.size() - 1,
              mid = (bot + top) / 2;
    while (bot < top &&  // more elements to search thru
           v[mid].compare(f, search_type) != 0)  // not what we want
    {
        if (v[mid].compare(f, search_type) < 0)  // f falls above middle
        {
            bot = mid + 1;    // move bottom up just past middle
        }
        else  // v[mid] > f  -- f falls below middle
        {
            top = mid;        // move top down to middle (balances mid's integer division)
        }
        mid = (bot + top) / 2;
    }
    return mid;   // item is either at mid or not there
}

#endif /* binary_search_h */

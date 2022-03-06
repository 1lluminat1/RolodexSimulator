//
//  RolodexSimulator.cpp
//  Rolodex
//
//  Created by Christopher Garland on 2/26/22.
//

#include <iostream>
#include "rolodex_entry.h"
#include "rolodex_mngr.h"
#include "rolodex_menu.h"
#include "input_helper.h"
#include "rolodex_lib.h"
using namespace std;

int main()
{
   Rolodex rolodex;
   RolodexEntry temp_entry, test_e1, test_e2, test_e3, test_e4, test_e5,
   test_e6, test_e7, test_e8, test_e9, test_e10;
   
   test_e1.set_fname("Christopher"); test_e1.set_lname("Garland");
   test_e1.set_street("701 Sunfish point"); test_e1.set_town("Schaumburg");
   test_e1.set_state("IL"); test_e1.set_phone("8473383386");
   test_e1.set_email("cgarland101@hotmail.com"); test_e1.set_zip(60194);
   test_e1.set_zip_4(6792); rolodex.add(test_e1);
   
   test_e2.set_fname("Jessie"); test_e2.set_lname("Donohue");
   test_e2.set_street("4757 S Harlem Ave"); test_e2.set_town("Worth");
   test_e2.set_state("IL"); test_e2.set_phone("8159054354");
   test_e2.set_email("jdonohue@gmail.com"); test_e2.set_zip(60194);
   test_e2.set_zip_4(6792); rolodex.add(test_e2);
   
   test_e3.set_fname("Dustin"); test_e3.set_lname("Garland");
   test_e3.set_street("506 charlela ln"); test_e3.set_town("Elk Grove");
   test_e3.set_state("IL"); test_e3.set_phone("7298376472");
   test_e3.set_email("dgarl89@woway.com"); test_e3.set_zip(49876);
   test_e3.set_zip_4(2928); rolodex.add(test_e3);
   
   test_e4.set_fname("Candace"); test_e4.set_lname("Ehardt");
   test_e4.set_street("147 N Higgans Rd"); test_e4.set_town("Hoffman Estates");
   test_e4.set_state("IL"); test_e4.set_phone("8476548761");
   test_e4.set_email("cgarland@gmail.com"); test_e4.set_zip(60785);
   test_e4.set_zip_4(2347); rolodex.add(test_e4);
   
   test_e5.set_fname("Jason"); test_e5.set_lname("Ehardt");
   test_e5.set_street("145 Fox Lake Rd"); test_e5.set_town("Fox Lake");
   test_e5.set_state("IL"); test_e5.set_phone("6309754673");
   test_e5.set_email("jehardt145@gmail.com"); test_e5.set_zip(67165);
   test_e5.set_zip_4(7350); rolodex.add(test_e5);
   
   test_e6.set_fname("Gus"); test_e6.set_lname("Gains");
   test_e6.set_street("345 Gantry Rd"); test_e6.set_town("Elgin");
   test_e6.set_state("IL"); test_e6.set_phone("6746518985");
   test_e6.set_email("gusgains@hotmail.com"); test_e6.set_zip(45623);
   test_e6.set_zip_4(1674); rolodex.add(test_e6);
   
   test_e7.set_fname("Jade"); test_e7.set_lname("Femur");
   test_e7.set_street("477 Lake Ln"); test_e7.set_town("Aurora");
   test_e7.set_state("IL"); test_e7.set_phone("7918747364");
   test_e7.set_email("jfem@gmail.com"); test_e7.set_zip(94357);
   test_e7.set_zip_4(3895); rolodex.add(test_e7);
   
   test_e8.set_fname("John"); test_e8.set_lname("Doe");
   test_e8.set_street("123 Pond Ave"); test_e8.set_town("Downers Grove");
   test_e8.set_state("IL"); test_e8.set_phone("1823759871");
   test_e8.set_email("jdoe4444444444444444435@gmail.com"); test_e8.set_zip(99976);
   test_e8.set_zip_4(7936); rolodex.add(test_e8);
   
   test_e9.set_fname("Jeff"); test_e9.set_lname("Cross");
   test_e9.set_street("56 first stttttttttttttttt"); test_e9.set_town("Wellington");
   test_e9.set_state("IL"); test_e9.set_phone("1894873764");
   test_e9.set_email("jeffcross56@gmail.com"); test_e9.set_zip(54366);
   test_e9.set_zip_4(6178); rolodex.add(test_e9);
   
   test_e10.set_fname("Alex"); test_e10.set_lname("Burrrrrrrrrrrrrrrrrrr");
   test_e10.set_street("967 eleventh st"); test_e10.set_town("Oak Lawn");
   test_e10.set_state("IL"); test_e10.set_phone("1893763892");
   test_e10.set_email("aburr666@gmail.com"); test_e10.set_zip(56377);
   test_e10.set_zip_4(4592); rolodex.add(test_e10);
   
   bool running = true;// controls the entire menu, false means end the program
   int cur_men = 0;
   while (running)
   {
      switch (cur_men)
      {
         case 0:// main
         {
            gen_main_men();
            cout << "Enter menu choice: ";
            cur_men = get_mchoice(cur_men);
            break;
         }
         case 1:// add
         {
            cout << "\n\t\t~~~~~ ENTRY MODE ~~~~~\n";
            bool okay = true;
            while (okay)
            {
               temp_entry.input();
               rolodex.set(rolodex.get_current(), temp_entry);
               const char prompt[] =
               {"Would you like to add another entry? (Y/N)"};
               char ans = get_upchar(prompt);
               cin.clear();
               if (ans == 'N')
               {
                  okay = false;
               }
            }
            cout << "\t\t~~~~~ END ENTRY MODE ~~~~~\n";
            break;
         }
         case 2:// edit
         {  // first we check to see if there any entries available to edit
            if (rolodex.get_current() == 0)
            {// if not, return them to the main menu
               cout << "ERROR: You have no entries to edit!\n";
               cur_men = 0;
               break;
            }// if yes, start edit mode
            cout << "\n\t\t~~~~~ EDIT MODE ~~~~~\n";
            bool okay = true;
            while (okay)
            {
               rolodex.print_all();// print all current entries (up to 10)
               cout << "Enter row number you wish to edit,"
                    << " or 0 to return to main menu. \n";
               int choice;
               cin >> choice;// obtain menu choice
               cin.clear();
               if (choice == 0)// if choice is 0, return to main menu
               {
                  cur_men = 0;
                  okay = false;
               }
               else
               {// first we display the entry that was chosen
                  display_table_header();
                  display_row(rolodex.get(choice-1));
                  display_table_head_border();
                  cout << "\nWhich field do you wish to modify?" << endl;
                  cout << "You can enter column num, name or first"
                       << " letter of the column name(S for STREET, st for "
                  << "state. " << endl;
                  cout << "For ZIP, please enter ZIP5 or ZIP4\n";
                  gen_byvar_men("Edit ");
                  CompTo by_what = get_byvar();// find out which field they
                  bool contin = false;         // want to edit
                  char n_value[MAX_EMAIL];
                  do
                  {
                     cin.clear();
                     cout << "\nPlease enter the new value forb"
                     << enum_to_string(by_what);
                     cin >> n_value;// obtain the new value
                     size_t i = strlen(n_value);// find out how long this new
                     while (cin.peek() != '\n') // value is, and contiue input
                     {                          // until newline char is met
                        cin.get(n_value[i]);
                        i++;
                     }
                     cin.clear();
                     cout << "\nYou entered: " << n_value
                          << ", is this correct? (Y/N)";
                     cout << "\nWARNING: new value will DELETE the existing"
                          << " value for this field.\n";
                     char ans = get_upchar();// get confirmation answer
                     cin.clear();
                     if (ans == 'Y')
                     {
                        contin = true;// end loop if confirmed
                     }
                  } while (!contin);// continue loop if not confirmed
                  RolodexEntry temp = rolodex.get(choice - 1);// temp holder
                  if (by_what == 0)// fname
                  {
                     temp.set_fname(n_value);
                  }
                  else if (by_what == 1)// lname
                  {
                     temp.set_lname(n_value);
                  }
                  else if (by_what == 2)// street
                  {
                     temp.set_street(n_value);
                  }
                  else if (by_what == 3)// town
                  {
                     temp.set_town(n_value);
                  }
                  else if (by_what == 4)// state
                  {
                     temp.set_state(n_value);
                  }
                  else if (by_what == 5)// phone
                  {
                     temp.set_phone(n_value);
                  }
                  else if (by_what == 6)// email
                  {
                     temp.set_email(n_value);
                  }
                  else if (by_what == 7)// zip5
                  {
                     temp.set_zip(strtol(n_value, nullptr, 10));
                  }
                  else// zip4
                  {
                     temp.set_zip_4(strtol(n_value, nullptr, 10));
                  }
                  rolodex.set(choice - 1, temp);// finalize the edit
                  char prompt[] = "Success! edit another? (Y/N)\n";
                  char ans = get_upchar(prompt);// ask if they want to
                  cin.clear();
                  if (ans == 'N')               // edit again
                  {
                     okay = false;// end loop and
                     cur_men = 0; // return them to main menu
                  }               // if they are done
               }
            }
            cout << "\n\t\t~~~~~ END EDIT MODE ~~~~~\n";
            break;// end edit mode, return to main menu
         }
         case 3:// delete
         {// first we check if there are any entries to delete
            if (rolodex.get_current() == 0)
            {
               cout << "ERROR: You have no entries to delete!" << endl;
               cur_men = 0;// return to main menu if not
               break;
            }
            cout << "\t\t~~~~~ DELETE MODE ~~~~~\n";
            bool contin = false;
            do// begin delete mode if yes
            {
               rolodex.print_all();
               cout << "Enter row number you wish to delete, or you"
                << " can also press 0 or 10 to return to main menu." << endl;
               int choice;
               cin >> choice;
               cin.clear();
               if (choice == 0 || choice == 10)// if 0 or 10 is chosen
               {
                  cur_men = 0;// return to main menu
               }
               else
               {// if not, confirm index selection
                  cout << "\nYou selected number " << choice
                       << ", is this correct?";
                  cout << "\nWARNING! This will delete"
                  << " the entire entry PERMANENTLY! (Y/N)" << endl;
                  display_table_header();
                  display_row(rolodex.get(choice - 1));
                  display_table_head_border();
                  char ans = get_upchar();
                  cin.clear();
                  if (ans == 'N')
                  {
                     contin = false;// back to main menu if unconfirmed
                  }
                  else// else, begin the deletion
                  {
                     RolodexEntry temp;
                     if (choice == rolodex.get_current())// if choice =
                     {// current entries, than no adjustments will need to be
                        rolodex.set(0, temp);// made, no matter how many
                        rolodex.set_current(0);// entries there currently are.
                     }// 2 entries has 2 situations:
                     else if (rolodex.get_current() == 2)
                     {// either the choice is index 1, meaning no adjustment
                        if ((choice - 1) == 1)
                        {
                           rolodex.set(1, temp);
                           rolodex.set_current(1);
                        }// or the choice is index 0,
                        else
                        {// meaning index 1 must be moved down to index 0
                           rolodex.set(0, rolodex.get(1));
                           rolodex.set(1, temp);
                           rolodex.set_current(1);
                        }
                     }
                     else// anything else is done with a loop
                     {
                        size_t cur_before = rolodex.get_current();
                        rolodex.shift_entries(choice);
                        rolodex.set_current(cur_before-1);
                     }
                     cout <<
                     "Success! Would you like to delete another entry?";
                     char ans = get_upchar();
                     cin.clear();
                     if (ans == 'N')
                     {
                        contin = false;
                        cur_men = 0;
                     }
                  }
               }
            } while (contin);
            cout << "\t\t~~~~~ END DELETE MODE ~~~~~\n";
            break;
         }
         case 4:// find
         {
            if (rolodex.get_current() == 0 || rolodex.get_current() == 1)
            {
               cout << "\nERROR: You must have more than one entry"
                    << " in order to search!" << endl;
               cur_men = 0;
               break;
            }
            else
            {
               cout << "\n\t\t ~~~~~ FIND MODE ~~~~~" << endl;
               bool contin = false;
               do
               {
                  CompTo search_by = ERROR;// var for target search column
                  char term[MAX_EMAIL];// var for search target
                  gen_byvar_men("Find by ");
                  cout
                  << "Please enter the first letter of the column you wish"
                  << " to search with, or a number that corresponds to it.\n"
                  << "You can also press 0 to return to main menu." << endl;
                  search_by = get_byvar();// obtain search by
                  cin.clear();
                  if (search_by == ERROR)// if 0 or 10 is entered
                  {
                     cur_men = 0;//return to main menu
                     break;
                  }
                  bool found = false;// controls linear search
                  bool okay = true;
                  vector<RolodexEntry> matches;// to hold search matches
                  while (okay)
                  {
                     cout << "\nSearching " << enum_to_string(search_by);
                     cout << "...\nWhat term would you like to search with?"
                     << endl;// prompting for search target
                     cin >> term;
                     size_t i = strlen(term);
                     while (cin.peek() != '\n')
                     {
                        cin.get(term[i]);
                        i++;
                     }
                     cin.clear();
                     cout << "\nYou entered " << term <<
                     ", is that correct? (Y/N)" << endl;// confirming input
                     char ans = get_upchar();
                     cin.clear();
                     if (ans == 'Y')
                     {
                        okay = false;
                     }
                  }
                  char_up(term);// convert to up char for searching
                  size_t found_index = 0;
                  cout << "\nOkay, searching " << enum_to_string(search_by)
                  << " for " << term << "..." << endl;
                  if (int_to_compto(rolodex.get_sorted_on()) == search_by)
                  {// if chosen sorted type equals the current rolodex sort...
                     found_index = rolodex.bin_search(term, search_by);
                  }// then we can search using binary search
                  else
                  {// else we use linear search
                     size_t begin = 0;
                     do
                     {
                        found_index = rolodex.lin_search
                        (term, search_by, begin);
                        if (found_index < rolodex.get_current())
                        {
                           found = true;
                           // next search starts at found + 1
                           begin = found_index + 1;
                           // add success to search matches
                           matches.push_back(rolodex.get(found_index));
                        }// if found_index is greater than cur, end loop
                     } while (found_index < rolodex.get_current() - 1);
                  }
                  if (found)
                  {
                     cout << "\nSuccess! " << matches.size() << " match";
                     if (matches.size() > 1)
                     {
                        cout << "es";
                     }
                     cout << " found!" << endl;
                     display_table_header();
                     for (vector<RolodexEntry>::size_type i = 0;
                          i < matches.size(); i++)
                     {
                        display_row(matches[i]);
                     }
                     display_table_head_border();
                     press_enter_to_continue();
                  }
                  else
                  {
                     cout << "\nSorry, no matches found for " << term <<
                     " in " << enum_to_string(search_by) << "." << endl;
                  }
                  char prompt[] = "\nWould you like to search again? (Y/N)";
                  char ans = get_upchar(prompt);
                  cin.clear();
                  if (ans == 'N')
                  {
                     cur_men = 0;
                     contin = true;
                  }
               } while (!contin);
            }
            cout << "\n\t\t ~~~~~ END FIND MODE ~~~~~\n";
            cur_men = 0;
            break;
         }
         case 5:// print
         {
            rolodex.print_all();
            press_enter_to_continue();
            cur_men = 0;
            break;
         }
         case 6:// sort
         {
            if (rolodex.get_current() <= 1)
            {
               cout << "ERROR: You need more than one entry"
                    << " in order to sort!\n";
               cur_men = 0;
               break;
            }
            cout << "\n\t~~~~~ SORT MODE ~~~~~\n";
            gen_byvar_men("Sort by ");
            cout << "Enter menu choice: ";
            int choice = 0;
            cin >> choice;
            cin.clear();
            if (choice == 10)
            {
               cur_men = 0;
            }
            else
            {
               CompTo sort_type = int_to_compto(choice-1);
               rolodex.sort(sort_type, MAX_EMAIL);
               const char prompt[] =
               {"Would you like to view sorted data now? (Y/N) "};
               char ans = get_upchar(prompt);
               if (ans == 'Y')
               {
                  rolodex.print_all();
                  //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  press_enter_to_continue();
               }
               cur_men = 0;
            }
            break;
         }
         case 7:// quit
         {
            cout << setfill('~');
            cout << setw(28) << left << "x";
            cout << setw(28) << right << "x" << endl;
            cout << setfill(' ');
            cout << setw(1) << "|";
            cout << "\t\tThank you for using the Rolodex Simulator!";
            cout << setw(8) << right << "|" << endl;
            cout << setw(1) << "|" << setw(55) << "|";
            cout << endl << setw(1) << "|" << setw(35) << right <<
            "\t\tPlease come back again!" << setw(18) << right << "|" << endl;
            cout << setfill('~');
            cout << setw(28) << left << "x";
            cout << setw(28) << right << "x" << endl;
            running = false;
            break;
         }
      }
   }
   return 0;
}

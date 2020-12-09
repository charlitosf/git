
#include <iostream>
#include "Planet.h"

// ------------------------------------------------------
void menu()
{
  cout << "-----========== Evacuation ==========-----" << endl
       << "1- List info" << endl
       << "2- Add/modify base" << endl
       << "3- Add ship" << endl
       << "4- Delete base" << endl
       << "5- Delete ship" << endl
       << "6- Evacuation plan" << endl
       << "q- Quit" << endl
       << "Option: " ;
}


int main()
{
   Planet planet("Hoth");
   char option;

   do {
        menu();
        cin >> option; cin.get();

        switch (option) {
          case '1': {
            cout << planet;
            break;
          }
          case '2': {
            planet.createBase();
            break;
          }
          case '3': {
            planet.createShip();
            break;
          }
          case '4': {
            planet.deleteBase();
            break;
          }
          case '5': {
            planet.deleteShip();
            break;
          }
          case '6': {
            planet.evacuationPlan();
            break;
          }
          case 'q': {
            break;
          }
          default:  {
            Util::error(ERR_UNKNOWN_OPTION);
            break;
          }
        }
   } while (option != 'q');

   return 0;
}

#include <iostream>
#include "database.hpp"
#include "databaseConsole.hpp"
#include <wx/wx.h>
#include "databaseGUI.hpp"
#include "schoolClass.hpp"

extern int mygetch();
schoolClass klasa1A;

int main(int argc,char **argv)
{

  database *bazaDanych;
  int wybor = 0;

  while(wybor!='3')
  {
    system("clear");
    std::cout << "Wybierz wersje bazy:" << std::endl;
    std::cout << "1.Tekstowa." << std::endl;
    std::cout << "2.Graficzna." << std::endl;
    std::cout << "3.Wyjscie." << std::endl;

    wybor = mygetch();
    switch(wybor)
    {
      case '1':
        bazaDanych = new databaseConsole(klasa1A);
        while(bazaDanych->menu() == false) {}
        delete bazaDanych;
        break;
      case '2':
        wxEntry(argc,argv);
        break;
      case '3':
        std::cout << "ŻEGNAJ.";
        mygetch();
        break;
      default:
        std::cout << "Błędny wybór.";
        mygetch();
        break;
    }
  }
  return 0;
}

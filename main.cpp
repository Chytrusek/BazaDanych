#include <iostream>
#include "database.hpp"
#include "databaseConsole.hpp"
#include <wx/wx.h>
#include "databaseGUI.hpp"

extern int mygetch();

int main(int argc,char **argv)
{
  system("clear");
  std::cout << "Wybierz wersje bazy:" << std::endl;
  std::cout << "1.Tekstowa." << std::endl;
  std::cout << "2.Graficzna." << std::endl;
  std::cout << "3.Wyjscie." << std::endl;

  database *bazaDanych;
  int wybor = 0;

  while(wybor!='3')
  {
    wybor = mygetch();
    system("clear");
    switch(wybor)
    {
      case '1':
        bazaDanych = new databaseConsole;
        while(bazaDanych->menu() == false) {}
        break;
      case '2':
        wxEntry(argc,argv);
        break;
      default:
        std::cout << "ŻEGNAJ.";
        mygetch();
        break;
    }
  }
}

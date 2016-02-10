#include <iostream>
#include "database.hpp"
#include "databaseConsole.hpp"

int main()
{
  database *bazaDanych;
  bazaDanych = new databaseConsole;

  while(true)
  {
    if (bazaDanych->menu())           //wybrano wyjscie z programu
      break;
  }

}

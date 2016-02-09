#include <iostream>
#include "database.hpp"
#include "databaseConsole.hpp"

int main()
{
  database *bazaDanych;
  bazaDanych = new databaseConsole;

  bazaDanych->menu();
  std::getchar();
}

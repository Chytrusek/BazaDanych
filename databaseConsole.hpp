#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "database.hpp"
#include "schoolClass.hpp"

class databaseConsole : public database
{
  private:
    schoolClass *pointerKlasa1A;
public:
  void wyswietl();
  bool menu();
  void dodajRekord();
  void usunRekord();

  databaseConsole(schoolClass &globalKlasa1A);
  ~databaseConsole();

};


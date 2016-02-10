#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "database.hpp"
#include "schoolClass.hpp"

class databaseConsole : public database
{
public:
  void wyswietl();
  bool menu();
  void dodajRekord();
  void usunRekord();

};


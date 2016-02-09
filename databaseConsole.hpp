#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "database.hpp"
#include "schoolClass.hpp"

class databaseConsole : public database
{
  schoolClass klasa1A;

public:
  void wyswietl();
  bool menu();
  void dodajRekord();

};


#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "schoolClass.hpp"

class database
{
protected:
  schoolClass klasa1A;
public:
  void zapisz();
  void wczytaj();
  virtual void wyswietl() = 0;
  virtual bool menu() = 0;

};


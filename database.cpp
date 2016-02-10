#include <iostream>
#include <string>
#include <vector>
#include "database.hpp"
#include "schoolClass.hpp"
#include <fstream>

void database::zapisz()
{
  std::fstream save;
  save.open("save.txt", std::ios::out);
  if(save.good() == true)
  {
    for(auto uczen : klasa1A.wyswietl())
    {
      save << uczen.nrDziennika << " ";
      save << uczen.imie << " ";
      save << uczen.nazwisko << " ";
      save << uczen.pesel << std::endl;
    }
    save.close();
  }
}

void database::wczytaj()
{
  std::ifstream save;
  save.open("save.txt", std::ios::in);
  if(save.good() == true)
  {
    while(!save.eof())
    {
      int nrDziennika = 0;
      std::string imie,nazwisko,pesel;

      save >> nrDziennika;
      save >> imie;
      save >> nazwisko;
      save >> pesel;

      if(nrDziennika!=0)
        klasa1A.dodajUcznia(imie, nazwisko, pesel);
    }
  }
}


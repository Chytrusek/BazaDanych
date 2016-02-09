#pragma once
#include <string>
#include <algorithm>
#include <vector>

struct student
{
  int nrDziennika;
  std::string imie,nazwisko,pesel;
};


class schoolClass
{
private:
  std::vector<student> uczniowie;

  void sortujUczniow();
public:
  void dodajUcznia( std::string imie,
                    std::string nazwisko,
                    std::string pesel );

  void usunUcznia( std::string nazwisko );
  std::vector<student> wyswietl();
};



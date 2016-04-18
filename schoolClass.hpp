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

public:
  void sortujUczniow();
  void dodajUcznia( std::string imie,
                    std::string nazwisko,
                    std::string pesel );
  void dodajBlanka();

  void edytujImieUcznia( int id, std::string wartosc );
  void edytujNazwiskoUcznia( int id, std::string wartosc );
  void edytujPeselUcznia( int id, std::string wartosc );

  void usunUcznia( std::string nazwisko );
  void usunWszystkichUczniow();
  std::vector<student> wyswietl();
};



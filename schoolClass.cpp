#include "schoolClass.hpp"
#include <string>
#include <algorithm>
#include <vector>

void schoolClass::dodajUcznia(std::string imie,
                              std::string nazwisko,
                              std::string pesel)
{
  student uczen;
  uczen.imie = imie;
  uczen.nazwisko = nazwisko;
  uczen.pesel = pesel;
  uczniowie.push_back(uczen);

  sortujUczniow();

}

void schoolClass::sortujUczniow()
{
  std::sort(uczniowie.begin(),uczniowie.end(),
            [](const student  &a, const student &b)
             { return a.nazwisko < b.nazwisko; });

  for(unsigned int i=0;i<uczniowie.size();i++)
    uczniowie.at(i).nrDziennika = i+1;
}

void schoolClass::usunUcznia(std::string nazwisko)
{
  for(unsigned int i=0;i<uczniowie.size();i++)
    if(uczniowie.at(i).nazwisko == nazwisko)
      uczniowie.erase(uczniowie.begin() + i);
}

void schoolClass::usunWszystkichUczniow()
{
  for(unsigned int i=0;i<uczniowie.size();i++)
    uczniowie.erase(uczniowie.begin() + i);
}

std::vector<student> schoolClass::wyswietl()
{
  return uczniowie;
}

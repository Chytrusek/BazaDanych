#include "studentClass.h"
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
            [](const data &a, const data &b)
              { return a.nazwisko < b.nazwisko() }
}



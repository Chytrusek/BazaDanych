#include <iostream>
#include <string>
#include <vector>
#include "database.hpp"
#include "schoolClass.hpp"
#include "databaseConsole.hpp"

using std::cout;
using std::cin;
using std::endl;
int mygetch();


void databaseConsole::wyswietl()
{
  system("clear");

  cout << "|Nr|Imie      |Nazwisko       |PESEL      |" << endl;
  cout << "|--|----------|---------------|-----------|" << endl;
  for(auto uczen :  klasa1A.wyswietl())
  {
    cout << "|";
    cout.width(2);
    cout << std::left << uczen.nrDziennika << "|";
    cout.width(10);
    cout << uczen.imie << "|";
    cout.width(15);
    cout << uczen.nazwisko << "|";
    cout.width(11);
    cout << uczen.pesel << "|";
    cout << endl << std::right;
  }
  mygetch();
}

void databaseConsole::dodajRekord()
{
  std::string imie,nazwisko,PESEL;

  system("clear");
  cout << "Podaj imie: ";
  cin >> imie;
  cout << "Podaj nazwisko: ";
  cin >> nazwisko;
  cout << "Podaj PESEL: ";
  cin >> PESEL;

  klasa1A.dodajUcznia(imie, nazwisko, PESEL);
}

void databaseConsole::usunRekord()
{
  system("clear");

  std::string nazwisko;
  cout << "Podaj nazwisko osoby do usuniecia: ";
  cin >> nazwisko;
  klasa1A.usunUcznia(nazwisko);
}

bool databaseConsole::menu()
{
  int wybor = 0;
  system("clear");
  cout << "Wybierz opcje." << endl;
  cout << "1.Wyswietl baze." << endl;
  cout << "2.Dodaj rekord." << endl;
  cout << "3.Usun rekord." << endl;
  cout << "4.Zapisz stan." << endl;
  cout << "5.Wczytaj stan." << endl;
  cout << "6.Wyjscie." << endl;

  wybor = mygetch() - '0';
  switch(wybor)
  {
    case 1:
      wyswietl();
      break;
    case 2:
      dodajRekord();
      break;
    case 3:
      usunRekord();
      break;
    case 4:
      zapisz();
      break;
    case 5:
      wczytaj();
      break;
    case 6:
      return true;
      break;
  }

  return false;
}


//___________________________________________________________________________//

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int mygetch( ) {
  struct termios oldt,newt;
  int ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}

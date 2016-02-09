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
  for(auto uczen :  klasa1A.wyswietl())
  {
     cout << uczen.nazwisko;              //uzupelnic petle o wszystko
  }
}

void databaseConsole::dodajRekord()
{
  std::string imie,nazwisko,PESEL;

  system("clear");
  cout << "Podaj imie";
  cin >> imie;
  cout << "Podaj nazwisko";
  cin >> nazwisko;
  cout << "Podaj PESEL";
  cin >> PESEL;

  klasa1A.dodajUcznia(imie, nazwisko, PESEL);
}

bool databaseConsole::menu()
{
  int wybor = 0;
  system("clear");
  cout << "Wybierz opcje:" << endl;
  cout << "1.Wyswietl baze:" << endl;
  cout << "2.Dodaj rekord:" << endl;

  wybor = mygetch() - 48;
  switch(wybor)
  {
    case 1:
      wyswietl();
      break;
    case 2:
      dodajRekord();
      break;

  }
}




#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int mygetch( ) {
  struct termios oldt,
                 newt;
  int            ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}

#include "database.hpp"
#include "schoolClass.hpp"
#include <wx/wx.h>
#include "databaseGUI.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

schoolClass klasa1A;


bool Aplikacja::OnInit()
{
	Ramka *glownaRamka = new Ramka("Baza Danych", wxPoint(50, 50), wxSize(600,600));
	glownaRamka->Show(true);
  return true;
}

enum
{
  ID_Save = 1,
  ID_Load = 2,
  ID_Imie = 3,
  ID_Nazwisko = 4,
  ID_Pesel = 5,
  ID_NrDziennika = 6,
  ID_NastepnyRekord = 7,
  ID_PoprzedniRekord = 8
};
Ramka::Ramka(const wxString& tytul, const wxPoint& pozycja,
              const wxSize& rozmiar) : wxFrame(NULL, wxID_ANY, tytul, pozycja, rozmiar)
{
  wxMenu *Plik = new wxMenu;
  Plik->Append(ID_Save,"Zapisz", "Zapisze baze danych do pliku.");
  Plik->Append(ID_Load,"Wczytaj", "Wczytam baze danych z pliku.");

  wxMenuBar *menu = new wxMenuBar;
  menu->Append(Plik, "Plik" );
  SetMenuBar(menu);
  CreateStatusBar();
  SetStatusText("Baza Danych - Kamil Mielnik" );

  klasa1A.dodajUcznia("","","");

  std::ostringstream strumien;
  strumien << klasa1A.wyswietl().at(ktoryNumer).nrDziennika;

  wxString nrDziennika = strumien.str();
  wxString imie = klasa1A.wyswietl().at(ktoryNumer).imie;
  wxString nazwisko = klasa1A.wyswietl().at(ktoryNumer).nazwisko;
  wxString pesel = klasa1A.wyswietl().at(ktoryNumer).pesel;

  etykietaNrDziennika = new wxStaticText(this,wxID_ANY,"Nr Dziennika:",wxPoint(20,15),wxSize(100,-1));
  etykietaImie = new wxStaticText(this,wxID_ANY,"Imie:",wxPoint(20,65),wxSize(100,-1));
  etykietaNazwisko = new wxStaticText(this,wxID_ANY,"Nazwisko:",wxPoint(20,115),wxSize(100,-1));
  etykietaPesel = new wxStaticText(this,wxID_ANY,"PESEL:",wxPoint(20,165),wxSize(100,-1));
  poleNrDziennika = new wxTextCtrl(this,ID_NrDziennika,nrDziennika,wxPoint(120,10),wxSize(50,-1));
  poleImie = new wxTextCtrl(this,ID_Imie,imie,wxPoint(120,60),wxSize(200,-1));
  poleNazwisko = new wxTextCtrl(this,ID_Nazwisko,nazwisko,wxPoint(120,110),wxSize(200,-1));
  polePesel = new wxTextCtrl(this,ID_Pesel,pesel,wxPoint(120,160),wxSize(200,-1));

  poprzedniRekord = new wxButton(this,ID_PoprzedniRekord,wxT("Poprzedni Rekord"),wxPoint(10,230));
  nastepnyRekord = new wxButton(this,ID_NastepnyRekord,wxT("Nastepny Rekord"),wxPoint(180,230));
}

void Ramka::OnExit(wxCommandEvent& event)
{
  Close(true);
}

void Ramka::Save(wxCommandEvent& event)
{
  wxMessageBox( wxT("Zapisano") );
}

void Ramka::Load(wxCommandEvent& event)
{
  wxMessageBox( wxT("Wczytano") );
}

void Ramka::ZmienionoImie(wxCommandEvent& event)
{
  klasa1A.edytujImieUcznia(ktoryNumer,std::string(poleImie->GetValue().mb_str()));
}

void Ramka::ZmienionoNazwisko(wxCommandEvent& event)
{
  klasa1A.edytujNazwiskoUcznia(ktoryNumer,std::string(poleNazwisko->GetValue().mb_str()));

}
void Ramka::ZmienionoPesel(wxCommandEvent& event)
{
  klasa1A.edytujPeselUcznia(ktoryNumer,std::string(polePesel->GetValue().mb_str()));
}

void Ramka::Wyswietl()
{
  std::ostringstream strumien;
  strumien << klasa1A.wyswietl().at(ktoryNumer).nrDziennika;

  wxString nrDziennika = strumien.str();
  wxString imie = klasa1A.wyswietl().at(ktoryNumer).imie;
  wxString nazwisko = klasa1A.wyswietl().at(ktoryNumer).nazwisko;
  wxString pesel = klasa1A.wyswietl().at(ktoryNumer).pesel;

  poleImie->ChangeValue(imie);
  polePesel->ChangeValue(pesel);
  poleNazwisko->ChangeValue(nazwisko);
  poleNrDziennika->ChangeValue(nrDziennika);
}

wxBEGIN_EVENT_TABLE(Ramka,wxFrame)
  EVT_MENU(ID_Save, Ramka::Save)
  EVT_MENU(ID_Load, Ramka::Load)
  EVT_TEXT(ID_Imie, Ramka::ZmienionoImie)
	wxEND_EVENT_TABLE()

IMPLEMENT_APP_NO_MAIN(Aplikacja);

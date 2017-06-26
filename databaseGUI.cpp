#include "database.hpp"
#include "schoolClass.hpp"
#include <wx/wx.h>
#include "databaseGUI.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

extern schoolClass klasa1A;

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
  ID_PoprzedniRekord = 8,
  ID_SzukajID = 9,
  ID_SzukajNazwisko = 10
};

Ramka::Ramka(const wxString& tytul, const wxPoint& pozycja,
    const wxSize& rozmiar) : wxFrame(NULL, wxID_ANY, tytul, pozycja, rozmiar)
{
  wxMenu *Plik = new wxMenu;
  Plik->Append(ID_Save,"Zapisz", "Zapisze baze danych do pliku.");
  Plik->Append(ID_Load,"Wczytaj", "Wczytam baze danych z pliku.");
  wxMenu *Szukaj = new wxMenu;
  Szukaj->Append(ID_SzukajID,"Poprzez nr.","Wyszukiwanie rekordu po numerze ucznia w dzienniku");
  Szukaj->Append(ID_SzukajNazwisko,"Poprzez nazwisko.","Wyszukiwanie rekordu po nazwisku ucznia");

  wxMenuBar *menu = new wxMenuBar;
  menu->Append(Plik, "Plik" );
  menu->Append(Szukaj, "Szukaj" );
  SetMenuBar(menu);
  CreateStatusBar();
  SetStatusText("Baza Danych - Kamil Mielnik" );

  std::cout << klasa1A.wyswietl().size();
  if(klasa1A.wyswietl().size()==0)
    klasa1A.dodajBlanka();

  std::ostringstream strumien;
  strumien << klasa1A.wyswietl().at(ktoryNumer).nrDziennika;

  wxString nrDziennika = strumien.str();
  wxString imie = klasa1A.wyswietl().at(ktoryNumer).imie;
  wxString nazwisko = klasa1A.wyswietl().at(ktoryNumer).nazwisko;
  wxString pesel = klasa1A.wyswietl().at(ktoryNumer).pesel;

  etykietaNrDziennika = new wxStaticText(this,wxID_ANY,"Nr Dziennika:",wxPoint(20,15),wxSize(100,-1));
  licznikRekordow = new wxStaticText(this,wxID_ANY,"Liczba rekordow w bazie: 0",wxPoint(200,15));
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
  wxMessageBox( wxT("Zapisano") );
}

void Ramka::Load(wxCommandEvent& event)
{
  std::ifstream save;
  save.open("save.txt", std::ios::in);
  if(save.good() == true)
  {
    klasa1A.usunWszystkichUczniow();
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
  ktoryNumer = 0;
  Wyswietl();
  wxMessageBox( wxT("Wczytano") );
}

void Ramka::SzukajID(wxCommandEvent& event)
{
  std::stringstream pytanie;
  pytanie << "Podaj ktory ID chesz wyswietlic (zakres 1 do "<<klasa1A.wyswietl().size()<<").";
  wxString pytanieString = pytanie.str();

  wxTextEntryDialog *dialog = new wxTextEntryDialog(this,pytanieString);
  dialog->ShowModal();
  std::string odpowiedz = std::string(dialog->GetValue().mb_str());
  pytanie.str("");
  pytanie << odpowiedz;
  int id;
  pytanie >> id;
  id--;
  if(id>=0 && id<=klasa1A.wyswietl().size()-1)
    ktoryNumer = id;
  else
    wxMessageBox( wxT("Niewlasciwy ID"));
  //ktoryNumer = klasa1A.znajdzUcznia(odpowiedz);
  Wyswietl();

}

void Ramka::SzukajNazwisko(wxCommandEvent& event)
{
  std::stringstream pytanie;
  pytanie << "Podaj nazwisko szukanej osoby.";
  wxString pytanieString = pytanie.str();

  wxTextEntryDialog *dialog = new wxTextEntryDialog(this,pytanieString);
  dialog->ShowModal();
  std::string odpowiedz = std::string(dialog->GetValue().mb_str());
  int id;
  id = klasa1A.znajdzUcznia(odpowiedz);
  if(id>=0 && id<=klasa1A.wyswietl().size()-1)
    ktoryNumer = id;
  else
    wxMessageBox( wxT("Brak takiej osoby w bazie"));
  Wyswietl();
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

void Ramka::UstawieniePoprzedniegoRekordu(wxCommandEvent& event)
{
  if(ktoryNumer>0)
  {
    if(ktoryNumer+1 == klasa1A.wyswietl().size())
    {
      if(poleNazwisko->GetValue().empty() &&
          poleImie->GetValue().empty() &&
          polePesel->GetValue().empty())
        klasa1A.usunUcznia(ktoryNumer);

      klasa1A.sortujUczniow();
    }
    ktoryNumer--;
    Wyswietl();
  }
  else
    wxMessageBox( wxT("Jesteś już na pierwszym rekordzie") );


}

void Ramka::UstawienieNastepnegoRekordu(wxCommandEvent& event)
{
  if(ktoryNumer+1 < klasa1A.wyswietl().size())
  {
    ktoryNumer++;
    Wyswietl();
  }
  else
    if(!poleNazwisko->GetValue().empty() ||
        !poleImie->GetValue().empty() ||
        !polePesel->GetValue().empty())
    {
      klasa1A.dodajBlanka();
      ktoryNumer++;
      Wyswietl();
    }
}

void Ramka::Wyswietl()
{
  std::ostringstream ileRekordowStrumien;
  ileRekordowStrumien << "Liczba rekordow w bazie: " << klasa1A.wyswietl().size();
  wxString ileRekordow = wxString(ileRekordowStrumien.str());
  licznikRekordow->SetLabel(ileRekordow);
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
  EVT_MENU(ID_SzukajID, Ramka::SzukajID)
  EVT_MENU(ID_SzukajNazwisko, Ramka::SzukajNazwisko)
  EVT_TEXT(ID_Imie, Ramka::ZmienionoImie)
  EVT_TEXT(ID_Nazwisko, Ramka::ZmienionoNazwisko)
  EVT_TEXT(ID_Pesel, Ramka::ZmienionoPesel)
  EVT_BUTTON(ID_PoprzedniRekord, Ramka::UstawieniePoprzedniegoRekordu)
  EVT_BUTTON(ID_NastepnyRekord, Ramka::UstawienieNastepnegoRekordu)
wxEND_EVENT_TABLE()

  IMPLEMENT_APP_NO_MAIN(Aplikacja);

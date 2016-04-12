#include "database.hpp"
#include "schoolClass.hpp"
#include <wx/wx.h>
#include "databaseGUI.hpp"
#include <vector>

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
  ID_Load = 2
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

  text = new wxTextCtrl(this,wxID_ANY,wxT("Imie"),wxDefaultPosition,wxSize(100,50));
  text2 = new wxTextCtrl(this,wxID_ANY,wxT("Imie"),wxPoint(200,200),wxSize(100,20));
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

wxBEGIN_EVENT_TABLE(Ramka,wxFrame)
  EVT_MENU(ID_Save, Ramka::Save)
  EVT_MENU(ID_Load, Ramka::Load)
	wxEND_EVENT_TABLE()

IMPLEMENT_APP_NO_MAIN(Aplikacja);

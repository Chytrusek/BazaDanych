#pragma once
#include "database.hpp"
#include "schoolClass.hpp"
#include <wx/wx.h>


class Aplikacja: public wxApp
{
  public:
    virtual bool OnInit();
};

  class Ramka: public wxFrame
  {
    public:
      int ktoryNumer = 0;
      Ramka(const wxString& tytul, const wxPoint& pozycja,
            const wxSize& rozmiar);
      wxStaticText *etykietaNrDziennika;
      wxStaticText *etykietaImie;
      wxStaticText *etykietaNazwisko;
      wxStaticText *etykietaPesel;
      wxStaticText *licznikRekordow;

      wxTextCtrl *poleNrDziennika;
      wxTextCtrl *poleImie;
      wxTextCtrl *poleNazwisko;
      wxTextCtrl *polePesel;
      wxButton *nastepnyRekord;
      wxButton *poprzedniRekord;

      void OnExit(wxCommandEvent& event);
      void Save(wxCommandEvent& event);
      void Load(wxCommandEvent& event);
      void SzukajNazwisko(wxCommandEvent& event);
      void SzukajID(wxCommandEvent& event);

      void ZmienionoImie(wxCommandEvent& event);
      void ZmienionoNazwisko(wxCommandEvent& event);
      void ZmienionoPesel(wxCommandEvent& event);
      void ZmienionoNrDziennika(wxCommandEvent& event);

      void UstawieniePoprzedniegoRekordu(wxCommandEvent& event);
      void UstawienieNastepnegoRekordu(wxCommandEvent& event);

      void Wyswietl();
      wxDECLARE_EVENT_TABLE();
  };

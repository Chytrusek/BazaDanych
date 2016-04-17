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
      wxTextCtrl *poleNrDziennika;
      wxTextCtrl *poleImie;
      wxTextCtrl *poleNazwisko;
      wxTextCtrl *polePesel;
      void OnExit(wxCommandEvent& event);
      void Save(wxCommandEvent& event);
      void Load(wxCommandEvent& event);

      void ZmienionoImie(wxCommandEvent& event);
      void ZmienionoNazwisko(wxCommandEvent& event);
      void ZmienionoPesel(wxCommandEvent& event);
      void ZmienionoNrDziennika(wxCommandEvent& event);

      wxDECLARE_EVENT_TABLE();
  };

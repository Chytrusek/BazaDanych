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
      Ramka(const wxString& tytul, const wxPoint& pozycja,
            const wxSize& rozmiar);
      wxTextCtrl *text;
      wxTextCtrl *text2;
      void OnExit(wxCommandEvent& event);
      void Save(wxCommandEvent& event);
      void Load(wxCommandEvent& event);
      wxDECLARE_EVENT_TABLE();
  };

#pragma once
#include "wx/wx.h"



class MainFrameFour : public wxFrame
{
public:
	MainFrameFour(const wxString& title);


private:

	// An event handler is simply a method that implements when we click on something.
	// You can name it whatever you'd like, but it is required to take an argument of a wxCommandEvent reference.
	void OnAnyButtonClicked(wxCommandEvent& evt);
	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);

	// Closing events need the "wxCloseEvent&"
	void OnClose(wxCloseEvent& evt);

};
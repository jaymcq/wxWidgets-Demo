#pragma once
#include "wx/wx.h"


// wxWidgets calls a window a Frame. Our frame inherits from wxFrame
class MainFrameTwo : public wxFrame
{
public:
	// Default constructor for MainFrame and here we can add the title of our window
	// wxString is the string implementation for wxWidgets, passing a const reference
	MainFrameTwo(const wxString& title);


private:

	// An event handler is simply a method that implements when we click on something.
	// You can name it whatever you'd like, but it is required to take an argument of a wxCommandEvent reference.
	void OnButtonClicked(wxCommandEvent& evt);

	// Our two new event handlers:
	void OnSliderChanged(wxCommandEvent& evt);
	void OnTextChanged(wxCommandEvent& evt);

	// Event Table:
	wxDECLARE_EVENT_TABLE();

};

#pragma once
#include "wx/wx.h"


// wxWidgets calls a window a Frame. Our frame inherits from wxFrame
class MainFrame : public wxFrame
{
public:
	// Default constructor for MainFrame and here we can add the title of our window
	// wxString is the string implementation for wxWidgets, passing a const reference
	MainFrame(const wxString& title);


};


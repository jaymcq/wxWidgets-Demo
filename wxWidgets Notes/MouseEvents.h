#pragma once
#include "wx/wx.h"



class MouseEvents : public wxFrame
{
public:
	MouseEvents(const wxString& title);


private:
	// Mouse Events require wxMouseEvent&
	void OnMouseEvent(wxMouseEvent& evt);
	
};
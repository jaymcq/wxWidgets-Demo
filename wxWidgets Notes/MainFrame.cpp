#include "MainFrame.h"
#include "wx/wx.h"

// Required arguments for wxFrame (parents of the frame (if none use 'this' or 'nullptr'), a window ID ( if we don't care use wxID_ANY), the window title (You can call it whatever you want here but since we are using a parameter we will use 'title'), 
// a window size ( can use whatever you'd like but here we will use wxDefaultPosition), a window size ( can be whatever, we will use wxDefaultSize). Position and size are optional all together.

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize) {

	// In order to start the application we need an entry point, just like main() in console applications. We need a class that represents the app itself. It will be called 'App'.

}

// Make sure all includes are made here:
#include "App.h"
#include "MainFrame.h"
#include "wx/wx.h"

// We need to let wxWidgets know which class represents our application
// We do this with the macro IMPLEMENT_APP with our App as the parameter:
wxIMPLEMENT_APP(App);

// Define our entry point:
bool App::OnInit() {
	// Create an instance of MainFrame:
	MainFrame* mainFrame = new MainFrame("First Window");

	// We can use some extra functions to define how big our window is and where it appears on the screen here too. 
	// The reason to do this is that if we define it in our wxFrame arguments, that is the soze for the whole window.
	// Doing it this way is giving the exact space you want the client part of the window to be, it will add the title and borders to that.
	mainFrame->SetClientSize(1000, 800);
	mainFrame->Center();

	// The frame will be hidden, we need to call the Show() method:
	mainFrame->Show();

	// Return true to keep the program going, returning false will have the window close immediately:
	return true;
}


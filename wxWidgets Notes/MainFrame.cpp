#include "MainFrame.h"
#include "wx/wx.h"
#include "wx/spinctrl.h" // For the spin control


// If you want all your buttons to have an ID you set up you can use an enum

// Always dynamically allocate any thing you do. Can cause major problems if you don't.

// We do NOT need to manually delete anything off the heap. wxWidgets will do that automatically when the program is closed.

// Required arguments for wxFrame (parents of the frame (if none use 'this' or 'nullptr'), a window ID ( if we don't care use wxID_ANY), the window title (You can call it whatever you want here but since we are using a parameter we will use 'title'), 
// a window size ( can use whatever you'd like but here we will use wxDefaultPosition), a window size ( can be whatever, we will use wxDefaultSize). Position and size are optional all together.

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize) {

	// In order to start the application we need an entry point, just like main() in console applications. We need a class that represents the app itself. It will be called 'App'.
	// Size and screen location are added in the App.cpp file

	// Adding controls:
	// If we were to add a button right now, with the parent being MainFrame, the button will scale to the whole size. To fix this we need a wxPanel and make that the parent.
	wxPanel* panel = new wxPanel(this);

	// Note that the starting position for anything is the top left pixel of whatever you're adding
	
	// Button:
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35));
	 
	// Check Box - This has a default size so xe can leave it blank to load the default
	wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "Check Box", wxPoint(550, 55));

	// Static Text - Renders text that is not editable
	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "Static Text - NOT Editable", wxPoint(120, 150));

	// Text Box - Called a text controller in wxWidgets, using -1 means use the default
	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "This is a text box!", wxPoint(500, 145), wxSize(200, -1));

	// Slider - we have to add an initial value, a minimum value, and a maximum value
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1));

	// Gauge - usually used for loading bars and such, needs a maximum value
	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
	// To set the gauges value, use SetValue()
	gauge->SetValue(50);

	// Multiple choice - you can use wxArrayString class built in or use your own array
	wxArrayString choices;
	choices.Add("A");
	choices.Add("B");
	choices.Add("C");

	// Now we add wxChoice with all the usual parameters passing in our array at the end. If using your own array there is a constructor for that passing in the number of choices and the array itself.
	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);

	// If you want your choice box to have a default response, use Select() and the index you want
	choice->Select(0);

	// Spin control - you need the 'wx/spinctrl.h' included, you can add a string for the name and initial, minimum and maximum values
	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "Spin Controller", wxPoint(550, 375), wxSize(100, 1));

	// List Box - will need an array added to the end
	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices);

	// Radio Box - will need an array added to the end
	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "Radio Box", wxPoint(485, 475), wxDefaultSize, choices);

}

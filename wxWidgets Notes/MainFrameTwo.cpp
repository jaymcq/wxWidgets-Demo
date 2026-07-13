#include "MainFrameTwo.h"
#include "wx/wx.h"

// Like before we will use an enum to store IDs, there are three rules to using an enum:
//		Must be a positive value
//		Cannot be 0 or 1
//		Can not be from wxID_LOWEST (4999) to wxID_HIGHEST (5999)

enum IDs {
	BUTTON_ID = 2,
	SLIDER_ID = 3,
	TEXT_ID = 4
};

// Now we define the event table:
// Takes two parameters, the class we are defining the event able for and it's base class
wxBEGIN_EVENT_TABLE(MainFrameTwo, wxFrame)
EVT_BUTTON(BUTTON_ID, MainFrameTwo::OnButtonClicked) // Need the button ID and the event handler
EVT_SLIDER(SLIDER_ID, MainFrameTwo::OnSliderChanged) // Notice the different event macro
EVT_TEXT(TEXT_ID, MainFrameTwo::OnTextChanged)
wxEND_EVENT_TABLE()


MainFrameTwo::MainFrameTwo(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	// Create a button
	wxButton* button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));

	// When we click the button, if we want something to happen, we need an event handler. These will be in the 'MainFrameTwo.h'.
	// We also need an event table, which will also be declared in the 'MainFrameTwo'h'.

	// Let's add two more events, a slider and a text control
	wxSlider* slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
	wxTextCtrl* text = new wxTextCtrl(panel, TEXT_ID, "", wxPoint(300, 375), wxSize(200, -1));

	// Create a status bar at the bottom:
	CreateStatusBar();

}

void MainFrameTwo::OnButtonClicked(wxCommandEvent& evt) {
	// Now we can output the button click to status bar using:
	wxLogStatus("Button Clicked!");
}

// Define both new event handlers:

void MainFrameTwo::OnSliderChanged(wxCommandEvent& evt) {
	// Here we want to output text when the slider is changed:
	wxString str = wxString::Format("Slider Value: %d", evt.GetInt());
	wxLogStatus(str);
}

void MainFrameTwo::OnTextChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("Text: %s", evt.GetString());
	wxLogStatus(str);
}
#include "MainFrameThree.h"
#include "wx/wx.h"

// For MainFrameThree we will dynamically implement event handlers. This is done with the bind method.

MainFrameThree::MainFrameThree(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	// Create a button
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));

	// When we click the button, if we want something to happen, we need an event handler. These will be in the 'MainFrameTwo.h'.
	// We also need an event table, which will also be declared in the 'MainFrameTwo'h'.

	// Let's add two more events, a slider and a text control
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
	wxTextCtrl* text = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1));

	// Bind - There are three overloads possible, Class, Functor, or method. Our event handlers are Class methods so use the first overload.
	// The first argument we need is an event tag, this is a button so wxEVT_BUTTON is used, then the class method that should be called, OnButtonClicked which we need a pointer to.
	// Lastly, a pointer to the object that will handle the event, in this case 'this'.
	button->Bind(wxEVT_BUTTON, &MainFrameThree::OnButtonClicked, this);
	slider->Bind(wxEVT_SLIDER, &MainFrameThree::OnSliderChanged, this);
	text->Bind(wxEVT_TEXT, &MainFrameThree::OnTextChanged, this);

	// To unbind is simple, requiring the same arguments but in Unbind"
	// button->Unbind(wxEVT_BUTTON, &MainFrameThree::OnButtonClicked, this);


	// Create a status bar at the bottom:
	CreateStatusBar();

}

void MainFrameThree::OnButtonClicked(wxCommandEvent& evt) {
	// Now we can output the button click to status bar using:
	wxLogStatus("Button Clicked!");
}

// Define both new event handlers:

void MainFrameThree::OnSliderChanged(wxCommandEvent& evt) {
	// Here we want to output text when the slider is changed:
	wxString str = wxString::Format("Slider Value: %d", evt.GetInt());
	wxLogStatus(str);
}

void MainFrameThree::OnTextChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("Text: %s", evt.GetString());
	wxLogStatus(str);
}
#include "MainFrameFour.h"
#include "wx/wx.h"

// For MainFrameThree we will dynamically implement event handlers. This is done with the bind method.

MainFrameFour::MainFrameFour(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	// Create a button
	wxButton* button1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

	// You can Bind to not only the object such as a button, but to the panel itself:
	//panel->Bind(wxEVT_BUTTON, &MainFrameFour::OnButtonClicked, this);

	// Binding the OnClose event:
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrameFour::OnClose, this);

	// Or even on MainFrameFour itself:
	this->Bind(wxEVT_BUTTON, &MainFrameFour::OnAnyButtonClicked, this);
	button1->Bind(wxEVT_BUTTON, &MainFrameFour::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &MainFrameFour::OnButton2Clicked, this);

	/*
		When we do things this way it is called Event Propagation.
		Our 'Button' is a child of 'Panel' which is a child of 'Frame'. All wxCommandEvents and only wxCommandEvents
		propagate up the chain until they are handled. If nothing handles the event, the App class gets the chance.
		wxWidgets will check for an event handler on the Button, then will check the Panel, and then the Frame until it is found.
		The magic in this is when we have more than one button. If we add a new button and have the Frame handle the event handler,
		both buttons will do the same thing without needing to add more code. Useful if you want feedback if any button is clicked.

		Now, if we add event handlers for each of the buttons and bind them to the buttons what will happen if we click on button 1?
		No window will appear and "Button 1 Clicked!" will appear in the status bar. This is due to the order event handlers are looked for.
		Since we have a handler for button 1 here, "OnAnyButtonClicked" will never be called.

		If we want that to happen, we use the Skip() function. If we do that, than both the individual button click handler and the
		any button handler are used simultaneously.
	*/



	// Create a status bar at the bottom:
	CreateStatusBar();

}

// Making a close window event:
void MainFrameFour::OnClose(wxCloseEvent& evt) {
	wxLogMessage("Frame Closed!");
	// If we don't add the skip here, the window won't close like it should.
	evt.Skip();
}

void MainFrameFour::OnAnyButtonClicked(wxCommandEvent& evt) {
	// Using wxLogMessage, when button is clicked a new window pops up telling you it was clicked.
	wxLogMessage("Button Clicked!");
}

void MainFrameFour::OnButton1Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button 1 Clicked!");
	evt.Skip();
}

void MainFrameFour::OnButton2Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button 2 Clicked!");
	evt.Skip();
}

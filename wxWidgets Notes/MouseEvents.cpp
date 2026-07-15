#include "MouseEvents.h"
#include "wx/wx.h"

MouseEvents::MouseEvents(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	wxButton* button = new wxButton(panel, wxID_ANY, "Buttopn", wxPoint(300, 250), wxSize(200, 100));

	// Sometimes with data being streamed constantly, your updating values will flicker as the update.
	// You can fix this with Double Frame Buffering like this:
	wxStatusBar* stats = CreateStatusBar();
	stats->SetDoubleBuffered(true);

	// We will use left click here, but you can get right click (wxEVT_RIGHT_DOWN) and center wheel clicks (wxEVT_MIDDLE_DOWN)
	// We can even get double clicks with wxEVT_LEFT_DCLICK or wxEVT_RIGHT_DCLICK
	panel->Bind(wxEVT_LEFT_DOWN, &MouseEvents::OnMouseEvent, this);

	// To detect motion:
	panel->Bind(wxEVT_MOTION, &MouseEvents::OnMouseEvent, this);

	// Currently, the mouse tracker will not work while over a button or other event because a mouse event is not the same as a command event.
	// You can fix this by binding:
	button->Bind(wxEVT_MOTION, &MouseEvents::OnMouseEvent, this);

	// Remember that the reported mouse location is in relation to the event it's on.
	// IE. When hovering over the button, the reported location will be in reference to the top left corner of the button, not the panel.
	// If we want this to not be the case, we should use the wxGetMousePosition in our event handler.

	// Right now we get coordinates based on the client (the open window), but what if we want the coordinates in reference to the screen itself?
	// You can swap between the two options freely using: ScreenToClient(position) or ClientToScreen(position)

}

// wxMouseEvent captures data about the clicks and cursor location
void MouseEvents::OnMouseEvent(wxMouseEvent& evt) {
	// wxPoint mousePos = evt.GetPosition();
	wxPoint mousePos = wxGetMousePosition();
	mousePos = this->ScreenToClient(mousePos);
	wxString message = wxString::Format("Mouse Event Detected at: (x=%d y=%d", mousePos.x, mousePos.y);
	wxLogStatus(message);
}
#pragma once
#include "wx/wx.h"

// App must inherit from wxApp
class App : public wxApp
{
public:
	// We need a boolean method called 'OnInit'
	bool OnInit();
};


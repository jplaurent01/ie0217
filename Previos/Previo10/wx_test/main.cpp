#include <wx/wx.h>

class App : public wxApp {
	bool OnInit() {
		wxFrame* window = new wxFrame(NULL, wxID_ANY, "GUI TEST", wxDefaultPosition, wxSize(600, 400));
		wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
		wxStaticText* text = new wxStaticText(window, wxID_ANY, "BIEN HECHO", wxDefaultPosition, wxDefaultSize,
			wxALIGN_CENTER_HORIZONTAL);
		//text->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
		text->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
		sizer->Add(text, 1, wxALIGN_CENTER);
		window->SetSizer(sizer);
		window->Show();
		return true;
	}

};

wxIMPLEMENT_APP(App);

#include "MainFrame.hpp" // Incluye la declaraci�n de la clase MainFrame
#include <wx/wx.h> // Incluye la biblioteca principal de wxWidgets
#include <wx/spinctrl.h> // Incluye la biblioteca para controles de tipo SpinCtrl



/*******************************MANEJO ESTATICO******************************/
//enum IDs {
  //  BUTTON_ID = 2,
  //  SLIDER_ID = 3,
  //  TEXT_ID = 4
//};
//wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
  //  EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
    //EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)
    //EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
//wxEND_EVENT_TABLE()
/***************************************************************************/

// Constructor de la clase MainFrame
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

    // Crea un panel que contendr� todos los controles
    wxPanel* panel = new wxPanel(this);

    // Crea un bot�n con el texto "Boton" en la posici�n (150, 50) y tama�o (100, 35) dentro del panel
    wxButton* button = new wxButton(panel, wxID_ANY, "Boton", wxPoint(150, 50), wxSize(100, 35), wxBU_LEFT);

    // Crea un checkbox con el texto "Checkbox" en la posici�n (550, 50) dentro del panel
    wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "Checkbox", wxPoint(550, 50), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);

    // Crea un texto est�tico con el texto "StaticTaext" en la posici�n (120, 50) dentro del panel
    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticTaext", wxPoint(120, 150));
    staticText->SetBackgroundColour(*wxLIGHT_GREY);
    // Crea un control de texto con el texto "textCtrl" en la posici�n (500, 145) y ancho de 200 dentro del panel
    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "textCtrl", wxPoint(500, 145), wxSize(200, -1), wxTE_PASSWORD);

    // Crea un slider con rango de 0 a 100, valor inicial de 25, en la posici�n (100, 250) y ancho de 200 dentro del panel
    wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL);

    // Crea una barra de progreso con valor m�ximo de 100 en la posici�n (500, 255) y ancho de 200 dentro del panel
    wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1), wxGA_VERTICAL);

    // Crea una lista de opciones
    wxArrayString choices;
    choices.Add("Item A");
    choices.Add("Item B");
    choices.Add("Item C");

    // Crea un control de selecci�n con las opciones de la lista en la posici�n (150, 375) y ancho de 100 dentro del panel
    wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices, wxCB_SORT);
    choice->Select(0); // Selecciona el primer �tem de la lista

    // Crea un control SpinCtrl (contador) en la posici�n (550, 375) y ancho de 100 dentro del panel
    wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1), wxSP_WRAP);

    // Crea una lista de selecci�n en la posici�n (150, 475) y ancho de 100 dentro del panel
    wxListBox* listbox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices, wxLB_MULTIPLE);

    // Crea un grupo de botones de radio con las opciones de la lista en la posici�n (485, 475) dentro del panel
    wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices, 3, wxRA_SPECIFY_ROWS);
}

    /*******************************MANEJO DINAMICO******************************/
    // Crea un panel que contendr� todos los controles
    //wxPanel* panel = new wxPanel(this);

    // Crea un bot�n con el texto "Boton" en la posici�n (150, 50) y tama�o (100, 35) dentro del panel
    //wxButton* button = new wxButton(panel, wxID_ANY, "Boton", wxPoint(300, 275), wxSize(200, 50));

    // Crea un slider con rango de 0 a 100, valor inicial de 25, en la posici�n (100, 250) y ancho de 200 dentro del panel
    //wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));

    // Crea un control de texto con el texto "textCtrl" en la posici�n (500, 145) y ancho de 200 dentro del panel
    //wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1));

    // Vincula el evento de clic del bot�n al m�todo OnButtonClicked de MainFrame
    // Esto significa que cuando se haga clic en el bot�n, se llamar� al m�todo OnButtonClicked
    // El tercer argumento 'this' se refiere a la instancia de MainFrame
    //button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    // Vincula el evento de cambio del control deslizante al m�todo OnSliderChanged de MainFrame
    // Esto significa que cuando se cambie el control deslizante, se llamar� al m�todo OnSliderChanged
    // El tercer argumento 'this' se refiere a la instancia de MainFrame
    //slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
    // Vincula el evento de cambio de texto al m�todo OnTextChanged de MainFrame
    // Esto significa que cuando se cambie el texto en el control de texto, se llamar� al m�todo OnTextChanged
    // El tercer argumento 'this' se refiere a la instancia de MainFrame
    //textCtrl->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);
    // Desvincula el evento de clic del bot�n del m�todo OnButtonClicked de MainFrame
    // Esto significa que el m�todo OnButtonClicked ya no se llamar� cuando se haga clic en el bot�n
    //button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    //CreateStatusBar();
//}
    /*******************************MANEJO ESTATICO******************************/
    // Crea un panel que contendr� todos los controles
    //wxPanel* panel = new wxPanel(this);

    // Crea un bot�n con el texto "Boton" en la posici�n (150, 50) y tama�o (100, 35) dentro del panel
    //wxButton* button = new wxButton(panel, BUTTON_ID, "Boton", wxPoint(300, 275), wxSize(200, 50));
    
    // Crea un slider con rango de 0 a 100, valor inicial de 25, en la posici�n (100, 250) y ancho de 200 dentro del panel
    //wxSlider* slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));

    // Crea un control de texto con el texto "textCtrl" en la posici�n (500, 145) y ancho de 200 dentro del panel
    //wxTextCtrl* textCtrl = new wxTextCtrl(panel, TEXT_ID, "", wxPoint(300, 375), wxSize(200, -1));

    // Crea un checkbox con el texto "Checkbox" en la posici�n (550, 50) dentro del panel
    //wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "Checkbox", wxPoint(550, 50));

    // Crea un texto est�tico con el texto "StaticTaext" en la posici�n (120, 50) dentro del panel
    //wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticTaext", wxPoint(120, 150));

    
    // Crea una barra de progreso con valor m�ximo de 100 en la posici�n (500, 255) y ancho de 200 dentro del panel
    //wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));

    // Crea una lista de opciones
    //wxArrayString choices;
    //choices.Add("Item A");
    //choices.Add("Item B");
    //choices.Add("Item C");

    // Crea un control de selecci�n con las opciones de la lista en la posici�n (150, 375) y ancho de 100 dentro del panel
    //wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);
    //choice->Select(0); // Selecciona el primer �tem de la lista

    // Crea un control SpinCtrl (contador) en la posici�n (550, 375) y ancho de 100 dentro del panel
    //wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1));

    // Crea una lista de selecci�n en la posici�n (150, 475) y ancho de 100 dentro del panel
    //wxListBox* listbox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices);

    // Crea un grupo de botones de radio con las opciones de la lista en la posici�n (485, 475) dentro del panel
    //wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices);
    
    //CreateStatusBar();
//}

/***************************METDOS PRIVADOS PARA EL MANEJO DE EVENTOS************************/
// Evento cuando se presiona el boton
//void MainFrame::OnButtonClicked(wxCommandEvent& evt){
  //  wxLogStatus("Boton presionado");
//}

// Evento cuando se cambia el valor del slider
//void MainFrame::OnSliderChanged(wxCommandEvent& evt) {
  //  wxString str = wxString::Format("Valor Slider: %d", evt.GetInt());
  //  wxLogStatus(str);
//}

// Evento cuando se cambia el texto en el control de texto
//void MainFrame::OnTextChanged(wxCommandEvent& evt) {
  //  wxString str = wxString::Format("Texto: %s", evt.GetString());
  //  wxLogStatus(str);
//}

//Estilos
/*
#include "MainFrame.hpp" // Incluye la declaraci�n de la clase MainFrame

#include <wx/wx.h> // Incluye la biblioteca principal de wxWidgets
#include <wx/spinctrl.h> // Incluye la biblioteca para controles de tipo SpinCtrl

// Constructor de la clase MainFrame
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    // Crea un panel que contendr� todos los controles
    wxPanel* panel = new wxPanel(this);

    // Crea un bot�n con el texto "Boton" en la posici�n (150, 50) y tama�o (100, 35) dentro del panel
    wxButton* button = new wxButton(panel, wxID_ANY, "Boton", wxPoint(150, 50), wxSize(100, 35), wxBU_LEFT);

    // Crea un checkbox con el texto "Checkbox" en la posici�n (550, 50) dentro del panel
    wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "Checkbox", wxPoint(550, 50), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);

    // Crea un texto est�tico con el texto "StaticTaext" en la posici�n (120, 50) dentro del panel
    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticTaext", wxPoint(120, 150));
    staticText->SetBackgroundColour(*wxLIGHT_GREY);
    // Crea un control de texto con el texto "textCtrl" en la posici�n (500, 145) y ancho de 200 dentro del panel
    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "textCtrl", wxPoint(500, 145), wxSize(200, -1), wxTE_PASSWORD);

    // Crea un slider con rango de 0 a 100, valor inicial de 25, en la posici�n (100, 250) y ancho de 200 dentro del panel
    wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL);

    // Crea una barra de progreso con valor m�ximo de 100 en la posici�n (500, 255) y ancho de 200 dentro del panel
    wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1), wxGA_VERTICAL);

    // Crea una lista de opciones
    wxArrayString choices;
    choices.Add("Item A");
    choices.Add("Item B");
    choices.Add("Item C");

    // Crea un control de selecci�n con las opciones de la lista en la posici�n (150, 375) y ancho de 100 dentro del panel
    wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices, wxCB_SORT);
    choice->Select(0); // Selecciona el primer �tem de la lista

    // Crea un control SpinCtrl (contador) en la posici�n (550, 375) y ancho de 100 dentro del panel
    wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1), wxSP_WRAP);

    // Crea una lista de selecci�n en la posici�n (150, 475) y ancho de 100 dentro del panel
    wxListBox* listbox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices, wxLB_MULTIPLE);

    // Crea un grupo de botones de radio con las opciones de la lista en la posici�n (485, 475) dentro del panel
    wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices, 3, wxRA_SPECIFY_ROWS);
}
*/

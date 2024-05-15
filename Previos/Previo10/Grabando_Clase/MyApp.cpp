#include "MyApp.hpp" // Incluye la declaraci�n de la clase de la aplicaci�n
#include "MainFrame.hpp" // Incluye la declaraci�n de la clase de la ventana principal

// Macro para implementar la funci�n principal de la aplicaci�n
wxIMPLEMENT_APP(App);

// M�todo de inicializaci�n de la aplicaci�n
bool App::OnInit() {
    // Crea una instancia de la ventana principal con el t�tulo "C++ GUI"
    MainFrame* mainFrame = new MainFrame("C++ GUI");

    // Muestra la ventana principal en pantalla
    mainFrame->Show();

    // Devuelve true para indicar que la inicializaci�n fue exitosa
    return true;
}

/***************************************************************
consola o terminal

trabaja con acentos y caracteres especiales
***************************************************************/

#include <wx/wx.h>

// clase app
class ConsoleApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP_CONSOLE(ConsoleApp);

// clase frame
class ConsoleFrame : public wxFrame {
public:
    ConsoleFrame(const wxString& title);

private:
    wxTextCtrl *textCtrl;
    wxTextCtrl *inputCtrl;

    void OnInputEnter(wxCommandEvent& event);
    //void OnClose(wxCloseEvent& event);
};

// similar a main en wxwidgets
bool ConsoleApp::OnInit() {
    // crear frame
    ConsoleFrame *frame = new ConsoleFrame("Terminal");
    frame->Show(true);
    return true;
}

ConsoleFrame::ConsoleFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400)) {
    // método contructor del frame,
    // toma un parámetro const wxString& title que representa el titulo de la ventana
    // NULL parent del frame
    // wxID_ANY identificador unico del frame
    // wxSize tamaño predeterminado

    // area de texto para output
    textCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
                               wxDefaultPosition, wxDefaultSize,
                               wxTE_MULTILINE | wxTE_READONLY | wxHSCROLL);

    // area de texto para input
    inputCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
                                wxDefaultPosition, wxDefaultSize,
                                wxTE_PROCESS_ENTER);

    // cambiar color, se pueden establecer en rgb: wxColour(0, 0, 20)
    textCtrl->SetBackgroundColour(wxColour("#282C34"));
    textCtrl->SetForegroundColour(wxColour("#ABB2BF"));
    inputCtrl->SetBackgroundColour(wxColour("#282C34"));
    inputCtrl->SetForegroundColour(wxColour("#ABB2BF"));

    // cambiar el tipo de letra
    wxFont font(10, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas"));
    textCtrl->SetFont(font);
    inputCtrl->SetFont(font);

    // conectar evento de entrada de texto
    inputCtrl->Bind(wxEVT_TEXT_ENTER, &ConsoleFrame::OnInputEnter, this);

    // organizar controles en un sizer
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(textCtrl, 1, wxEXPAND | wxALL, 5);
    sizer->Add(inputCtrl, 0, wxEXPAND | wxALL, 5);

    // linea inicial
    textCtrl->AppendText("Terminal iniciada\n");

    SetSizer(sizer);
    Layout();
}

// evento intro
void ConsoleFrame::OnInputEnter(wxCommandEvent& event) {
    // obtener el texto ingresado
    wxString inputText = inputCtrl->GetValue();

    // mostrar el texto ingresado en el area de texto
    textCtrl->AppendText("Comando: " + inputText + "\n");

    // limpia el area de entrada
    inputCtrl->Clear();
}



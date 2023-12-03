
/*
maneja acentos y caracteres como ñ en c++ con interfaz gráfica
recogidos en varaible wxString desde entrada texto

tener codeblock bien configurado
archivo cbp archivo de proyecto en codeblock
desde inicio sin importar proyecto
    file, new, project, wx, borrar todos los archivos salvo main.cpp (y resources)
    tener referenciado el archivo libwxmsw32u.a en el linker
*/

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    void OnButtonClicked(wxCommandEvent& event);
private:
    wxTextCtrl* textCtrl;
    wxButton* printButton;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame("Acentos y ñ", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
    textCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
    printButton = new wxButton(this, wxID_ANY, "Imprimir acentos y ñ", wxDefaultPosition, wxDefaultSize);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(textCtrl, 1, wxEXPAND | wxALL, 10);
    sizer->Add(printButton, 0, wxALIGN_CENTER | wxALL, 10);

    SetSizerAndFit(sizer);

    Connect(printButton->GetId(), wxEVT_BUTTON, wxCommandEventHandler(MyFrame::OnButtonClicked));
}

void MyFrame::OnButtonClicked(wxCommandEvent& event) {
    // Imprimir acentos y ñ en el control de texto
    textCtrl->AppendText("¡Hola con acentos y ñ!\n");

    // Leer desde la entrada estándar (stdin)
    wxString input;
    wxTextEntryDialog dialog(this, "Introduce una línea de texto:", "Entrada de texto");
    if (dialog.ShowModal() == wxID_OK) {
        input = dialog.GetValue();
        textCtrl->AppendText("Has introducido: " + input + "\n");
    }
}


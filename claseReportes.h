#pragma once
public ref class claseReportes
{
    public:
        System::Windows::Forms::Label^ ci;
        System::Windows::Forms::Label^ nombre;
        System::Windows::Forms::Label^ tlfReportes;
        System::Windows::Forms::Label^ fechaReportes;
        System::Windows::Forms::Label^ horaReportes;
        System::Windows::Forms::Label^ refReportes;

        claseReportes(System::String^ ciTexto, System::String^ nombreTexto, System::String^ tlfTexto, System::String^ fechaTexto, System::String^ horaTexto, System::String^ refTexto) {
            ci = gcnew System::Windows::Forms::Label();
            nombre = gcnew System::Windows::Forms::Label();
            tlfReportes = gcnew System::Windows::Forms::Label();
            fechaReportes = gcnew System::Windows::Forms::Label();
            horaReportes = gcnew System::Windows::Forms::Label();
            refReportes = gcnew System::Windows::Forms::Label();

            ci->Text = ciTexto;
            nombre->Text = nombreTexto;
            tlfReportes->Text = tlfTexto;
            fechaReportes->Text = fechaTexto;
            horaReportes->Text = horaTexto;
            refReportes->Text = refTexto;

            // Configurar las anclas
            ci->Anchor = System::Windows::Forms::AnchorStyles::Top;
            nombre->Anchor = System::Windows::Forms::AnchorStyles::Top;
            tlfReportes->Anchor = System::Windows::Forms::AnchorStyles::Top;
            fechaReportes->Anchor = System::Windows::Forms::AnchorStyles::Top;
            horaReportes->Anchor = System::Windows::Forms::AnchorStyles::Top;
            refReportes->Anchor = System::Windows::Forms::AnchorStyles::Top;
        }

};


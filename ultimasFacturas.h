#pragma once
ref class ultimasFacturas
{
public:
    ultimasFacturas(System::String^ nombre, System::String^ ci, System::String^ tlf, System::Windows::Forms::TableLayoutPanel^ tproductos, System::String^ fecha, System::String^ hora, System::String^ ref) {
        this->Nombre = nombre;
        this->CI = ci;
        this->Tlf = tlf;
        this->tablaProductos = tproductos;
        this->Fecha = fecha;
        this->Hora = hora;
        this->Ref = ref;
    }

    property System::String^ Nombre;
    property System::String^ CI;
    property System::String^ Tlf;
    property System::Windows::Forms::TableLayoutPanel^ tablaProductos;
    property System::String^ Fecha;
    property System::String^ Hora;
    property System::String^ Ref;
};



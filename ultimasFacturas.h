#pragma once

using namespace System;
using namespace System::Collections::Generic;
ref class ultimasFacturas
{
public:
    ultimasFacturas(String^ nombre, String^ ci, String^ tlf, List<int>^ productos, List<int>^ cantidad, String^ fecha, String^ hora) {
        this->Nombre = nombre;
        this->CI = ci;
        this->Tlf = tlf;
        this->Productos = productos;
        this->Cantidad = cantidad;
        this->Fecha = fecha;
        this->Hora = hora;
    }

    property String^ Nombre;
    property String^ CI;
    property String^ Tlf;
    property List<int>^ Productos;
    property List<int>^ Cantidad;
    property String^ Fecha;
    property String^ Hora;

};


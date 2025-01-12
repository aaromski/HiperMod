// Cliente.h
#include "conexion.h"
#pragma once



using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

public ref class Cliente {
public:
    Cliente(int id) : id_(id) {
        conexion = gcnew Conexion();
        IniciarTimer();
        maxCantidad = 0;
        seguir = true;
        productoCount = 1;
    }

    int GetId() { 
        return id_; 
    }

    bool GetSeguir() {
        return seguir;
    }

    void IniciarTimer() {
        productoTimer = gcnew Timer();
        productoTimer->Interval = 5000; // Cada 10 segundos
        productoTimer->Tick += gcnew EventHandler(this, &Cliente::OnProductoTimerTick);
        productoTimer->Start();
    }

    void PausarTimer() { 
        if (productoTimer != nullptr) { 
            productoTimer->Stop(); 
        } 
    }

    void ContinuarTimer() { 
        if (productoTimer != nullptr) { 
            productoTimer->Start(); 
        } 
    }

    property List<int>^ Cantidad {
        List<int>^ get() {
            return cantidad;
        }
    }

    property List<int>^ Productos { 
        List<int>^ get() { 
            return productos; 
        } 
    }

private:
    Conexion^ conexion;
    int id_;
    List<int>^ cantidad = gcnew List<int>();
    List<int>^ productos = gcnew List<int>();
    
    Timer^ productoTimer;
    int productoCount = 1; // Contador de productos
    int maxCantidad;
    bool seguir;

    void AgregarProducto() {
        
        // Generar una cantidad aleatoria
        int cant = conexion->randomNumero();

        // Verificar que sumar `cant` no exceda `30`
        if ((productoCount <= 10 && maxCantidad + cant <= 30) && seguir) {
            maxCantidad += cant;

            int producto = productoCount++;
            productos->Add(producto);
            cantidad->Add(cant);
            
        }
        else  {
            seguir = false;
        }
    }



    void OnProductoTimerTick(Object^ sender, EventArgs^ e) {
        AgregarProducto();
    }
};

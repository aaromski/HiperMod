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

        tCompras = gcnew Timer(); tCompras->Interval = 1000; 
        // Cada segundo 
        tCompras->Tick += gcnew EventHandler(this, &Cliente::OnCreacionTimerTick); 
        tCompras->Start(); 
        tiempoComprando = 0;
    }

    int GetId() { 
        return id_; 
    }

    bool GetSeguir() {
        return seguir;
    }

    int GetCountP() {
        return productoCount;
    }

    int GetTiempo() {
        return tiempoComprando;
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
    Timer^ tCompras;
    Timer^ productoTimer;
    int productoCount = 0; // Contador de productos
    int maxCantidad;
    int tiempoComprando;
    bool seguir;

    void AgregarProducto() {
            int producto = randomProducto(); 
            while (productos->Contains(producto)) { 
                producto = randomProducto(); 
            }
        // Generar una cantidad aleatoria
        int cant = randomCantidad();

        // Verificar que sumar `cant` no exceda `30`
        if ((productoCount < 10 && maxCantidad + cant <= 30) && seguir) {
            maxCantidad += cant;
            productos->Add(producto);
            cantidad->Add(cant);
            productoCount++;
        }
        else  {
            seguir = false;
            productoTimer->Stop();
        }
    }

    int randomCantidad() {
        std::srand(static_cast<unsigned>(std::time(nullptr))); // Generar un número aleatorio entre 1 y 5 
        int cantidad = (std::rand() % 5) + 1;
        return cantidad;
    }

    int randomProducto() {
        std::srand(static_cast<unsigned>(std::time(nullptr))); 
        return (std::rand() % 16) + 1; // Números del 1 al 10 
    }

    void OnProductoTimerTick(Object^ sender, EventArgs^ e) {
        AgregarProducto();
    }

    void OnCreacionTimerTick(Object^ sender, EventArgs^ e) {
        tiempoComprando++; 
    }
};

#pragma once
#include <ctime>
#include <random>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
ref class claseCliente
{
    public:
        claseCliente(int id) : id_(id) {
            IniciarTimer();
            maxCantidad = 0;
            seguir = true;
            productoCount = 1;
            maxProdu = randomCantidad(0);
            tCompras = gcnew Timer(); tCompras->Interval = 1000;
            // Cada segundo 
            tCompras->Tick += gcnew EventHandler(this, &claseCliente::OnCreacionTimerTick);
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

        void reiniciar() {
            tiempoComprando = 0;
        }

        void IniciarTimer() {
            productoTimer = gcnew Timer();
            productoTimer->Interval = 60000; // Cada 60 segundos
            productoTimer->Tick += gcnew EventHandler(this, &claseCliente::OnProductoTimerTick);
            productoTimer->Start();
        }

        void PausarTimer() {
            if (productoTimer != nullptr) {
                productoTimer->Stop();
                tCompras->Stop();
            }
        }

        void ContinuarTimer() {
            if (productoTimer != nullptr) {
                productoTimer->Start();
                tCompras->Start();
            }
        }
        void dobleV() {
            productoTimer->Interval = 30000; // Cada 30 segundos
            tCompras->Interval = 500;        // Cada 0.5 segundos
        }

        void velocidadInicial() {
            productoTimer->Interval = 60000;
            tCompras->Interval = 1000;
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
        int id_;
        List<int>^ cantidad = gcnew List<int>();
        List<int>^ productos = gcnew List<int>();
        Timer^ tCompras;
        Timer^ productoTimer;
        int productoCount = 0; // Contador de productos
        int maxCantidad;
        int tiempoComprando;
        bool seguir;
        static int maxProdu;

        void AgregarProducto() {
            int producto = randomProducto();
            while (productos->Contains(producto)) {
                producto = randomProducto();
            }
            // Generar una cantidad aleatoria
            int cant = randomCantidad(1);
            int maxProducto = randomCantidad(0);
            // Verificar que sumar `cant` no exceda `30`
            if ((productoCount <= maxProducto && maxCantidad + cant <= 30) && seguir) {
                maxCantidad += cant;
                productos->Add(producto);
                cantidad->Add(cant);
                productoCount++;
            }
            else {
                seguir = false;
                productoTimer->Stop();
            }
        }

        int randomCantidad(int opcion) {
            std::srand(static_cast<unsigned>(std::time(nullptr))); // Generar un n�mero aleatorio entre 1 y 5 
            if (opcion == 1) {
                int cantidad = (std::rand() % 5) + 1;
                return cantidad;
            }
            else {
                maxProdu = (std::rand() % 10) + 5;
                return maxProdu; // Asegura que el n�mero sea al menos 1 
            }
        }

        int randomProducto() {
            std::srand(static_cast<unsigned>(std::time(nullptr)));
            return (std::rand() % 16) + 1; // N�meros del 1 al 10 
        }

        void OnProductoTimerTick(Object^ sender, EventArgs^ e) {
            AgregarProducto();
        }

        void OnCreacionTimerTick(Object^ sender, EventArgs^ e) {
            tiempoComprando++;
        }

};


#pragma once
#include "Cliente.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Diagnostics;

ref class gestorTempo
{
    public:
        static int generarClientes;
        bool estaPausado;
        int tiempo;

        gestorTempo() {
            // Constructor inicializa las variables de instancia
            generarClientes = 1;
            estaPausado = false;
            tiempo = 0;
        }
        void PausarTemporizador(System::Windows::Forms::Timer^ timer1, List<Cliente^>^ listClient) {
            if (timer1->Enabled) {
                timer1->Stop();
                // Iterar a través de cada cliente en `listClient` y pausar sus timers
                for each (Cliente ^ cliente in listClient) {
                    cliente->PausarTimer(); // Asegúrate de tener este método en la clase `Cliente`
                }
                // Guardar el tiempo transcurrido
                estaPausado = true;
            }
        }

        void reanudarTemporizador(System::Windows::Forms::Timer^ timer1, List<Cliente^>^ listClient) {
            if (!timer1->Enabled) {
                // Si el temporizador está deshabilitado, no continuar
                return;
            }

            if (estaPausado) { // Ajustar el startTime para compensar el tiempo pausado 
                timer1->Start();
                estaPausado = false;
                // Iterar a través de cada cliente en `listClient` y pausar sus timers
                for each (Cliente ^ cliente in listClient) {
                    cliente->ContinuarTimer(); // Asegúrate de tener este método en la clase `Cliente`
                }
            }
        }

        void tiempoTranscurrido(ToolStripTextBox^ text) {
            tiempo++; // Incrementa tiempo en cada Tick
            // Convierte el tiempo en horas, minutos y segundos
            int hours = tiempo / 3600;
            int minutes = (tiempo % 3600) / 60;
            int seconds = tiempo % 60;
            // Muestra el tiempo en formato de horas, minutos y segundos
            text->Text = String::Format("{0:D2}:{1:D2}:{2:D2}", hours, minutes, seconds);
        }

        void tiemposClientes(List<Cliente^>^ listClient, Label^ tCaja, Label^ tCola, int id) {
            tCaja->Text = ConvertirTiempo(listClient[0]->GetTiempo());
            if (listClient->Count > 1) {
                tCola->Text = ConvertirTiempo(listClient[id + 1]->GetTiempo());
            }
        }

        String^ ConvertirTiempo(int segundosTotales) { 
            int minutos = (segundosTotales % 3600) / 60; 
            int segundos = segundosTotales % 60; 
            return String::Format("{0:D2}:{1:D2}", minutos, segundos); 
        }

        void dobleVelocidad(System::Windows::Forms::Timer^ crearCliente, System::Windows::Forms::Timer^ mostrarCliente, List<Cliente^>^ listClient) {
            crearCliente->Interval = 90000;
            mostrarCliente->Interval = 35000;
            for each(Cliente ^ cliente in listClient) {
                cliente->dobleV(); // Asegúrate de tener este método en la clase `Cliente`
            }
        }

        void veloInicial(System::Windows::Forms::Timer^ crearCliente, System::Windows::Forms::Timer^ mostrarCliente, List<Cliente^>^ listClient) {
            crearCliente->Interval = 180000;
            mostrarCliente->Interval = 65000;
            for each(Cliente ^ cliente in listClient) {
                cliente->velocidadInicial(); // Asegúrate de tener este método en la clase `Cliente`
            }
        }
};



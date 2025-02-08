#pragma once
#include "Cliente.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Diagnostics;

ref class gestorTempo
{
    public:
        static int generarClientes;
        Stopwatch^ startTime;
        TimeSpan tiempoPausado;
        bool estaPausado;
        int T1;
        int T2;

        gestorTempo() {
            // Constructor inicializa las variables de instancia
            generarClientes = 1;
            startTime = Stopwatch::StartNew();
            tiempoPausado = TimeSpan::Zero;
            estaPausado = false;
            T1 = 1;  // 1 minuto en segundos
            T2 = 0; // 3 minutos en segundos
        }
        void PausarTemporizador(Timer^ timer1, List<Cliente^>^ listClient) {
            startTime->Stop();
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

        void reanudarTemporizador(Timer^ timer1, List<Cliente^>^ listClient) {
            if (estaPausado) { // Ajustar el startTime para compensar el tiempo pausado 

                startTime->Start(); 
                timer1->Start(); 
                estaPausado = false; 
                // Iterar a través de cada cliente en `listClient` y pausar sus timers
                for each (Cliente ^ cliente in listClient) {
                    cliente->ContinuarTimer(); // Asegúrate de tener este método en la clase `Cliente`
                }
                tiempoPausado = TimeSpan::Zero;
            }
        }

        void tiempoTranscurrido(ToolStripTextBox^ text) {
            TimeSpan tiempoTranscurrido = startTime->Elapsed;
            text->Text = String::Format("{0:D2}:{1:D2}:{2:D2}", tiempoTranscurrido.Hours, tiempoTranscurrido.Minutes, tiempoTranscurrido.Seconds);
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
};



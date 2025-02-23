#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include "conexion.h"
#include "Reportes.h"
#include "formClientes.h"
#include "Inventario.h"
#include "gestorTempo.h"
#include "ultimasFacturas.h"
#include "claseReportes.h"
#include "Cliente.h"
#include <thread>
namespace HiperMod {
	using namespace System::Threading;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;
	using namespace System::Media;
	/// <summary>
	/// Resumen de MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			
			InitializeComponent();
			//TODO: agregar código de constructor aquí
			//
			inventario = gcnew Inventario();
			formCliente = gcnew formClientes();
			reportes = gcnew Reportes();
			this->startTime = DateTime::Now;
			this->data = gcnew Conexion();
			this->tempo = gcnew gestorTempo();
			this->sonidobeeb = gcnew SoundPlayer("preview.wav");

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Reportes^ reportes;
	private: formClientes^ formCliente;
	private: Inventario^ inventario;
	private: System::Windows::Forms::Button^ button_Fac;
	private: System::Windows::Forms::Button^ button_Cli;
	private: System::Windows::Forms::Button^ button_Rep;
	private: System::Windows::Forms::Button^ button_Inv;
	internal: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ B_cerrar;
	private: System::Windows::Forms::ToolStripButton^ pausar;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
	private: System::Windows::Forms::ToolStripTextBox^ toolStripTextBox1;
	private: System::DateTime startTime;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::ToolStripButton^ reanudar;
	private: System::Windows::Forms::ToolStripLabel^ toolStripButton4;
	private: Conexion^ data;
	private: System::Drawing::Color botonClickeado = System::Drawing::Color::FromArgb(
		static_cast<System::Int32>(static_cast<System::Byte>(246)),
		static_cast<System::Int32>(static_cast<System::Byte>(120)),
		static_cast<System::Int32>(static_cast<System::Byte>(0))
	);
	private: System::Drawing::Color Normal = System::Drawing::Color::FromArgb(
			   static_cast<System::Int32>(static_cast<System::Byte>(0)),
			   static_cast<System::Int32>(static_cast<System::Byte>(195)),
			   static_cast<System::Int32>(static_cast<System::Byte>(240))
	);
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panelFacturaD;
	private: System::Windows::Forms::Label^ hora;
	private: System::Windows::Forms::Label^ fecha;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label42;
	private: System::Windows::Forms::ComboBox^ clientesEnCola;
	private: System::Windows::Forms::SplitContainer^ splitCaja;
	private: System::Windows::Forms::Label^ label38;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ tlf;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ cedula;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ nombreA;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ tiempoCaja;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ Fecha_Caja;
	private: System::Windows::Forms::Label^ TIEMPOCAU;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::SplitContainer^ splitCola;
	private: System::Windows::Forms::Label^ label43;
	private: System::Windows::Forms::Label^ label44;
	private: System::Windows::Forms::Label^ tlf_Cola;
	private: System::Windows::Forms::Label^ label46;
	private: System::Windows::Forms::Label^ cedula_Cola;
	private: System::Windows::Forms::Label^ label48;
	private: System::Windows::Forms::Label^ nombre_Cola;
	private: System::Windows::Forms::Label^ label50;
	private: System::Windows::Forms::Label^ tiempoCola;
	private: System::Windows::Forms::Label^ label52;
	private: System::Windows::Forms::Label^ Fecha_Cola;
	private: System::Windows::Forms::Label^ label54;
	private: System::Windows::Forms::Label^ label55;
	private: System::Windows::Forms::Label^ cantidad;
	private: System::Windows::Forms::Panel^ panel2FacturaD;
	private: System::Windows::Forms::Timer^ Mover; static bool finalizo = false;
	private: System::Windows::Forms::Label^ LabelMontoTotal;
	private: System::Windows::Forms::Label^ montoTotal;
	private: System::Windows::Forms::Label^ nombrefac;
	private: System::Windows::Forms::Label^ tlfac;
	private: System::Windows::Forms::Label^ cedulafac;
	private: Cliente^ clientes;
	private: gestorTempo^ tempo;
	private: claseReportes^ nuevoReporte;
	private: DataTable^ BaseDatosReportes;
	private: DataTable^ BaseDatosInventario;
	private: DataTable^ BaseDatosCliente;
	private: System::Windows::Forms::Timer^ tiempoCC;
	private: System::Windows::Forms::Timer^ tiempo;
	private: List<Cliente^>^ listClient = gcnew List<Cliente^>();
	private: SoundPlayer^ sonidobeeb;
	private: ultimasFacturas^ Factura;
	private: List<ultimasFacturas^>^ listFacturas = gcnew List<ultimasFacturas^>();
	private: System::Windows::Forms::Timer^ crearClientes;
	private: System::Windows::Forms::Timer^ mostrarCliente;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::Label^ Ref;
	private: System::Windows::Forms::Label^ refFactura;
private: System::Windows::Forms::ToolStripButton^ bt_Finalizar;

	private:
	bool UseImage = true;
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->button_Fac = (gcnew System::Windows::Forms::Button());
			this->button_Cli = (gcnew System::Windows::Forms::Button());
			this->button_Rep = (gcnew System::Windows::Forms::Button());
			this->button_Inv = (gcnew System::Windows::Forms::Button());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->B_cerrar = (gcnew System::Windows::Forms::ToolStripButton());
			this->reanudar = (gcnew System::Windows::Forms::ToolStripButton());
			this->pausar = (gcnew System::Windows::Forms::ToolStripButton());
			this->bt_Finalizar = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripTextBox1 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelFacturaD = (gcnew System::Windows::Forms::Panel());
			this->Ref = (gcnew System::Windows::Forms::Label());
			this->refFactura = (gcnew System::Windows::Forms::Label());
			this->tlfac = (gcnew System::Windows::Forms::Label());
			this->cedulafac = (gcnew System::Windows::Forms::Label());
			this->nombrefac = (gcnew System::Windows::Forms::Label());
			this->montoTotal = (gcnew System::Windows::Forms::Label());
			this->cantidad = (gcnew System::Windows::Forms::Label());
			this->LabelMontoTotal = (gcnew System::Windows::Forms::Label());
			this->hora = (gcnew System::Windows::Forms::Label());
			this->fecha = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->clientesEnCola = (gcnew System::Windows::Forms::ComboBox());
			this->splitCaja = (gcnew System::Windows::Forms::SplitContainer());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->tlf = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->cedula = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->nombreA = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->tiempoCaja = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->Fecha_Caja = (gcnew System::Windows::Forms::Label());
			this->TIEMPOCAU = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2FacturaD = (gcnew System::Windows::Forms::Panel());
			this->splitCola = (gcnew System::Windows::Forms::SplitContainer());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->tlf_Cola = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->cedula_Cola = (gcnew System::Windows::Forms::Label());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->nombre_Cola = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->tiempoCola = (gcnew System::Windows::Forms::Label());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->Fecha_Cola = (gcnew System::Windows::Forms::Label());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->Mover = (gcnew System::Windows::Forms::Timer(this->components));
			this->tiempoCC = (gcnew System::Windows::Forms::Timer(this->components));
			this->tiempo = (gcnew System::Windows::Forms::Timer(this->components));
			this->crearClientes = (gcnew System::Windows::Forms::Timer(this->components));
			this->mostrarCliente = (gcnew System::Windows::Forms::Timer(this->components));
			this->toolStrip1->SuspendLayout();
			this->panelFacturaD->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitCaja))->BeginInit();
			this->splitCaja->Panel1->SuspendLayout();
			this->splitCaja->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitCola))->BeginInit();
			this->splitCola->Panel1->SuspendLayout();
			this->splitCola->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_Fac
			// 
			this->button_Fac->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_Fac->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Fac->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Fac->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button_Fac->Location = System::Drawing::Point(0, 27);
			this->button_Fac->Name = L"button_Fac";
			this->button_Fac->Size = System::Drawing::Size(136, 25);
			this->button_Fac->TabIndex = 6;
			this->button_Fac->Text = L"Facturacion";
			this->button_Fac->UseVisualStyleBackColor = false;
			// 
			// button_Cli
			// 
			this->button_Cli->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->button_Cli->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Cli->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Cli->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_Cli->Location = System::Drawing::Point(426, 27);
			this->button_Cli->Name = L"button_Cli";
			this->button_Cli->Size = System::Drawing::Size(136, 25);
			this->button_Cli->TabIndex = 1;
			this->button_Cli->Text = L"Clientes";
			this->button_Cli->UseVisualStyleBackColor = false;
			// 
			// button_Rep
			// 
			this->button_Rep->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->button_Rep->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Rep->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Rep->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button_Rep->Location = System::Drawing::Point(284, 27);
			this->button_Rep->Name = L"button_Rep";
			this->button_Rep->Size = System::Drawing::Size(136, 25);
			this->button_Rep->TabIndex = 2;
			this->button_Rep->Text = L"Reportes";
			this->button_Rep->UseVisualStyleBackColor = false;
			// 
			// button_Inv
			// 
			this->button_Inv->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->button_Inv->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Inv->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Inv->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button_Inv->Location = System::Drawing::Point(142, 27);
			this->button_Inv->Name = L"button_Inv";
			this->button_Inv->Size = System::Drawing::Size(136, 25);
			this->button_Inv->TabIndex = 3;
			this->button_Inv->Text = L"Inventario";
			this->button_Inv->UseVisualStyleBackColor = false;
			// 
			// toolStrip1
			// 
			this->toolStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->toolStrip1->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->B_cerrar, this->reanudar,
					this->pausar, this->bt_Finalizar, this->toolStripTextBox1, this->toolStripButton4, this->toolStripButton2, this->toolStripButton1
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Padding = System::Windows::Forms::Padding(0);
			this->toolStrip1->Size = System::Drawing::Size(800, 25);
			this->toolStrip1->Stretch = true;
			this->toolStrip1->TabIndex = 4;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// B_cerrar
			// 
			this->B_cerrar->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->B_cerrar->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->B_cerrar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B_cerrar.Image")));
			this->B_cerrar->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->B_cerrar->Name = L"B_cerrar";
			this->B_cerrar->Size = System::Drawing::Size(23, 22);
			this->B_cerrar->Text = L"toolStripButton1";
			this->B_cerrar->ToolTipText = L"Cerrar";
			this->B_cerrar->Click += gcnew System::EventHandler(this, &MenuPrincipal::B_cerrar_Click);
			// 
			// reanudar
			// 
			this->reanudar->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->reanudar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"reanudar.Image")));
			this->reanudar->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->reanudar->Name = L"reanudar";
			this->reanudar->Size = System::Drawing::Size(23, 22);
			this->reanudar->Text = L"toolStripButton3";
			this->reanudar->ToolTipText = L"Continuar";
			this->reanudar->Click += gcnew System::EventHandler(this, &MenuPrincipal::reanudar_Click);
			// 
			// pausar
			// 
			this->pausar->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->pausar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pausar.Image")));
			this->pausar->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->pausar->Name = L"pausar";
			this->pausar->Size = System::Drawing::Size(23, 22);
			this->pausar->Text = L"toolStripButton1";
			this->pausar->ToolTipText = L"Pausar";
			this->pausar->Click += gcnew System::EventHandler(this, &MenuPrincipal::pausar_Click);
			// 
			// bt_Finalizar
			// 
			this->bt_Finalizar->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->bt_Finalizar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bt_Finalizar.Image")));
			this->bt_Finalizar->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->bt_Finalizar->Name = L"bt_Finalizar";
			this->bt_Finalizar->Size = System::Drawing::Size(23, 22);
			this->bt_Finalizar->Text = L"Finalizar";
			this->bt_Finalizar->Click += gcnew System::EventHandler(this, &MenuPrincipal::bt_Finalizar_Click);
			// 
			// toolStripTextBox1
			// 
			this->toolStripTextBox1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->toolStripTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->toolStripTextBox1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toolStripTextBox1->ForeColor = System::Drawing::SystemColors::Menu;
			this->toolStripTextBox1->Name = L"toolStripTextBox1";
			this->toolStripTextBox1->Size = System::Drawing::Size(80, 25);
			this->toolStripTextBox1->TextBoxTextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Overflow = System::Windows::Forms::ToolStripItemOverflow::Never;
			this->toolStripButton4->Size = System::Drawing::Size(16, 22);
			this->toolStripButton4->Text = L"toolStripButton4";
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(23, 22);
			this->toolStripButton2->Text = L"toolStripButton2";
			this->toolStripButton2->ToolTipText = L"X2";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &MenuPrincipal::toolStripButton2_Click);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"Minimizar";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &MenuPrincipal::toolStripButton1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Black", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(37, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(165, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"FACTURA DIGITAL";
			// 
			// panelFacturaD
			// 
			this->panelFacturaD->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelFacturaD->Controls->Add(this->Ref);
			this->panelFacturaD->Controls->Add(this->refFactura);
			this->panelFacturaD->Controls->Add(this->tlfac);
			this->panelFacturaD->Controls->Add(this->cedulafac);
			this->panelFacturaD->Controls->Add(this->nombrefac);
			this->panelFacturaD->Controls->Add(this->montoTotal);
			this->panelFacturaD->Controls->Add(this->cantidad);
			this->panelFacturaD->Controls->Add(this->LabelMontoTotal);
			this->panelFacturaD->Controls->Add(this->hora);
			this->panelFacturaD->Controls->Add(this->fecha);
			this->panelFacturaD->Controls->Add(this->label18);
			this->panelFacturaD->Controls->Add(this->label17);
			this->panelFacturaD->Controls->Add(this->label16);
			this->panelFacturaD->Controls->Add(this->label15);
			this->panelFacturaD->Controls->Add(this->label13);
			this->panelFacturaD->Controls->Add(this->label12);
			this->panelFacturaD->Controls->Add(this->label11);
			this->panelFacturaD->Controls->Add(this->label10);
			this->panelFacturaD->Controls->Add(this->label9);
			this->panelFacturaD->Controls->Add(this->label7);
			this->panelFacturaD->Controls->Add(this->label6);
			this->panelFacturaD->Controls->Add(this->label5);
			this->panelFacturaD->Controls->Add(this->label4);
			this->panelFacturaD->Controls->Add(this->label3);
			this->panelFacturaD->Controls->Add(this->label2);
			this->panelFacturaD->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panelFacturaD->Location = System::Drawing::Point(12, 57);
			this->panelFacturaD->Name = L"panelFacturaD";
			this->panelFacturaD->Size = System::Drawing::Size(245, 514);
			this->panelFacturaD->TabIndex = 1;
			// 
			// Ref
			// 
			this->Ref->AutoSize = true;
			this->Ref->Location = System::Drawing::Point(43, 105);
			this->Ref->Name = L"Ref";
			this->Ref->Size = System::Drawing::Size(41, 15);
			this->Ref->TabIndex = 25;
			this->Ref->Text = L"label8";
			this->Ref->Visible = false;
			// 
			// refFactura
			// 
			this->refFactura->AutoSize = true;
			this->refFactura->Location = System::Drawing::Point(185, 168);
			this->refFactura->Name = L"refFactura";
			this->refFactura->Size = System::Drawing::Size(41, 15);
			this->refFactura->TabIndex = 24;
			this->refFactura->Text = L"label8";
			this->refFactura->Visible = false;
			// 
			// tlfac
			// 
			this->tlfac->AutoSize = true;
			this->tlfac->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tlfac->Location = System::Drawing::Point(30, 144);
			this->tlfac->Name = L"tlfac";
			this->tlfac->Size = System::Drawing::Size(41, 15);
			this->tlfac->TabIndex = 23;
			this->tlfac->Text = L"label8";
			this->tlfac->Visible = false;
			// 
			// cedulafac
			// 
			this->cedulafac->AutoSize = true;
			this->cedulafac->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cedulafac->Location = System::Drawing::Point(62, 131);
			this->cedulafac->Name = L"cedulafac";
			this->cedulafac->Size = System::Drawing::Size(41, 15);
			this->cedulafac->TabIndex = 22;
			this->cedulafac->Text = L"label8";
			this->cedulafac->Visible = false;
			// 
			// nombrefac
			// 
			this->nombrefac->AutoSize = true;
			this->nombrefac->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nombrefac->Location = System::Drawing::Point(64, 118);
			this->nombrefac->Name = L"nombrefac";
			this->nombrefac->Size = System::Drawing::Size(41, 15);
			this->nombrefac->TabIndex = 21;
			this->nombrefac->Text = L"label8";
			this->nombrefac->Visible = false;
			// 
			// montoTotal
			// 
			this->montoTotal->AutoSize = true;
			this->montoTotal->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->montoTotal->Location = System::Drawing::Point(179, 491);
			this->montoTotal->Name = L"montoTotal";
			this->montoTotal->Size = System::Drawing::Size(14, 15);
			this->montoTotal->TabIndex = 20;
			this->montoTotal->Text = L"0";
			this->montoTotal->Visible = false;
			// 
			// cantidad
			// 
			this->cantidad->AutoSize = true;
			this->cantidad->Location = System::Drawing::Point(212, 92);
			this->cantidad->Name = L"cantidad";
			this->cantidad->Size = System::Drawing::Size(14, 15);
			this->cantidad->TabIndex = 13;
			this->cantidad->Text = L"0";
			// 
			// LabelMontoTotal
			// 
			this->LabelMontoTotal->AutoSize = true;
			this->LabelMontoTotal->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LabelMontoTotal->Location = System::Drawing::Point(3, 491);
			this->LabelMontoTotal->Name = L"LabelMontoTotal";
			this->LabelMontoTotal->Size = System::Drawing::Size(92, 15);
			this->LabelMontoTotal->TabIndex = 19;
			this->LabelMontoTotal->Text = L"MONTO TOTAL:";
			this->LabelMontoTotal->Visible = false;
			// 
			// hora
			// 
			this->hora->AutoSize = true;
			this->hora->Location = System::Drawing::Point(179, 183);
			this->hora->Name = L"hora";
			this->hora->Size = System::Drawing::Size(59, 15);
			this->hora->TabIndex = 18;
			this->hora->Text = L"aqui hora";
			this->hora->Visible = false;
			// 
			// fecha
			// 
			this->fecha->AutoSize = true;
			this->fecha->Location = System::Drawing::Point(54, 183);
			this->fecha->Name = L"fecha";
			this->fecha->Size = System::Drawing::Size(72, 15);
			this->fecha->TabIndex = 17;
			this->fecha->Text = L"aqui va la fe";
			this->fecha->Visible = false;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(3, 196);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(223, 16);
			this->label18->TabIndex = 16;
			this->label18->Text = L"------------------------------------------------------";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(135, 183);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(44, 15);
			this->label17->TabIndex = 15;
			this->label17->Text = L"HORA:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(4, 183);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(50, 15);
			this->label16->TabIndex = 14;
			this->label16->Text = L"FECHA:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(4, 170);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(64, 15);
			this->label15->TabIndex = 13;
			this->label15->Text = L"FACTURA:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 144);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(31, 15);
			this->label13->TabIndex = 11;
			this->label13->Text = L"TLF:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(3, 131);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(59, 15);
			this->label12->TabIndex = 10;
			this->label12->Text = L"CEDULA:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(3, 118);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(61, 15);
			this->label11->TabIndex = 9;
			this->label11->Text = L"CLIENTE:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(3, 105);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(34, 15);
			this->label10->TabIndex = 8;
			this->label10->Text = L"REF:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(3, 92);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(204, 15);
			this->label9->TabIndex = 7;
			this->label9->Text = L"TOTAL UNITARIO DE PRODUCTOS:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(27, 65);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(179, 15);
			this->label7->TabIndex = 5;
			this->label7->Text = L"CONTRIBUYENTE ORDINARIO";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 52);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(224, 15);
			this->label6->TabIndex = 4;
			this->label6->Text = L"C. GURI, PUERTO ORDAZ ED BOLIVAR";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(62, 39);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 15);
			this->label5->TabIndex = 3;
			this->label5->Text = L"C.C ALTAVISTA I";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(62, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 15);
			this->label4->TabIndex = 2;
			this->label4->Text = L"HIPERMOD C.A.";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(55, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 15);
			this->label3->TabIndex = 1;
			this->label3->Text = L"RIF J-5552225555";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(78, 1);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 15);
			this->label2->TabIndex = 0;
			this->label2->Text = L"SENIAT";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Arial Black", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label19->Location = System::Drawing::Point(318, 97);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(190, 22);
			this->label19->TabIndex = 2;
			this->label19->Text = L"CAJA AUTIMATIZADA";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Font = (gcnew System::Drawing::Font(L"Arial Black", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label42->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label42->Location = System::Drawing::Point(572, 97);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(165, 22);
			this->label42->TabIndex = 5;
			this->label42->Text = L"CLIENTE EN COLA";
			// 
			// clientesEnCola
			// 
			this->clientesEnCola->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->clientesEnCola->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->clientesEnCola->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clientesEnCola->ForeColor = System::Drawing::SystemColors::Window;
			this->clientesEnCola->FormattingEnabled = true;
			this->clientesEnCola->Location = System::Drawing::Point(576, 545);
			this->clientesEnCola->Name = L"clientesEnCola";
			this->clientesEnCola->Size = System::Drawing::Size(201, 26);
			this->clientesEnCola->TabIndex = 8;
			this->clientesEnCola->Text = L"SELECCIONAR CLIENTE";
			this->clientesEnCola->SelectedIndexChanged += gcnew System::EventHandler(this, &MenuPrincipal::clientesEnCola_SelectedIndexChanged);
			// 
			// splitCaja
			// 
			this->splitCaja->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(212)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->splitCaja->IsSplitterFixed = true;
			this->splitCaja->Location = System::Drawing::Point(269, 134);
			this->splitCaja->Name = L"splitCaja";
			this->splitCaja->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitCaja.Panel1
			// 
			this->splitCaja->Panel1->Controls->Add(this->label38);
			this->splitCaja->Panel1->Controls->Add(this->label22);
			this->splitCaja->Panel1->Controls->Add(this->tlf);
			this->splitCaja->Panel1->Controls->Add(this->label21);
			this->splitCaja->Panel1->Controls->Add(this->cedula);
			this->splitCaja->Panel1->Controls->Add(this->label20);
			this->splitCaja->Panel1->Controls->Add(this->nombreA);
			this->splitCaja->Panel1->Controls->Add(this->label28);
			this->splitCaja->Panel1->Controls->Add(this->tiempoCaja);
			this->splitCaja->Panel1->Controls->Add(this->label27);
			this->splitCaja->Panel1->Controls->Add(this->Fecha_Caja);
			this->splitCaja->Panel1->Controls->Add(this->TIEMPOCAU);
			this->splitCaja->Panel1->Controls->Add(this->label25);
			// 
			// splitCaja.Panel2
			// 
			this->splitCaja->Panel2->AutoScroll = true;
			this->splitCaja->Size = System::Drawing::Size(253, 360);
			this->splitCaja->SplitterDistance = 101;
			this->splitCaja->SplitterWidth = 1;
			this->splitCaja->TabIndex = 10;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(164, 55);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(81, 13);
			this->label38->TabIndex = 28;
			this->label38->Text = L"POR ASIGNAR";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(9, 3);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(55, 13);
			this->label22->TabIndex = 12;
			this->label22->Text = L"CLIENTE:";
			// 
			// tlf
			// 
			this->tlf->AutoSize = true;
			this->tlf->Location = System::Drawing::Point(34, 29);
			this->tlf->Name = L"tlf";
			this->tlf->Size = System::Drawing::Size(53, 13);
			this->tlf->TabIndex = 27;
			this->tlf->Text = L"aqui va tlf";
			this->tlf->Visible = false;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(9, 16);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(53, 13);
			this->label21->TabIndex = 13;
			this->label21->Text = L"CEDULA:";
			// 
			// cedula
			// 
			this->cedula->AutoSize = true;
			this->cedula->Location = System::Drawing::Point(59, 16);
			this->cedula->Name = L"cedula";
			this->cedula->Size = System::Drawing::Size(53, 13);
			this->cedula->TabIndex = 26;
			this->cedula->Text = L"aqui va ci";
			this->cedula->Visible = false;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(9, 29);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(29, 13);
			this->label20->TabIndex = 14;
			this->label20->Text = L"TLF:";
			// 
			// nombreA
			// 
			this->nombreA->AutoSize = true;
			this->nombreA->Location = System::Drawing::Point(60, 3);
			this->nombreA->Name = L"nombreA";
			this->nombreA->Size = System::Drawing::Size(119, 13);
			this->nombreA->TabIndex = 25;
			this->nombreA->Text = L"NOMBRE Y APELLIDO";
			this->nombreA->Visible = false;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(9, 55);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(60, 13);
			this->label28->TabIndex = 19;
			this->label28->Text = L"FACTURA:";
			// 
			// tiempoCaja
			// 
			this->tiempoCaja->AutoSize = true;
			this->tiempoCaja->Location = System::Drawing::Point(194, 68);
			this->tiempoCaja->Name = L"tiempoCaja";
			this->tiempoCaja->Size = System::Drawing::Size(51, 13);
			this->tiempoCaja->TabIndex = 24;
			this->tiempoCaja->Text = L"aqui hora";
			this->tiempoCaja->Visible = false;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(9, 68);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(45, 13);
			this->label27->TabIndex = 20;
			this->label27->Text = L"FECHA:";
			// 
			// Fecha_Caja
			// 
			this->Fecha_Caja->AutoSize = true;
			this->Fecha_Caja->Location = System::Drawing::Point(54, 68);
			this->Fecha_Caja->Name = L"Fecha_Caja";
			this->Fecha_Caja->Size = System::Drawing::Size(83, 13);
			this->Fecha_Caja->TabIndex = 23;
			this->Fecha_Caja->Text = L"aqui va la fecha";
			this->Fecha_Caja->Visible = false;
			// 
			// TIEMPOCAU
			// 
			this->TIEMPOCAU->AutoSize = true;
			this->TIEMPOCAU->Location = System::Drawing::Point(152, 68);
			this->TIEMPOCAU->Name = L"TIEMPOCAU";
			this->TIEMPOCAU->Size = System::Drawing::Size(45, 13);
			this->TIEMPOCAU->TabIndex = 21;
			this->TIEMPOCAU->Text = L"Tiempo:";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(10, 81);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(235, 16);
			this->label25->TabIndex = 22;
			this->label25->Text = L"---------------------------------------------------------";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel2FacturaD);
			this->panel1->Controls->Add(this->splitCola);
			this->panel1->Controls->Add(this->splitCaja);
			this->panel1->Controls->Add(this->clientesEnCola);
			this->panel1->Controls->Add(this->label42);
			this->panel1->Controls->Add(this->label19);
			this->panel1->Controls->Add(this->panelFacturaD);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, 58);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(799, 593);
			this->panel1->TabIndex = 7;
			// 
			// panel2FacturaD
			// 
			this->panel2FacturaD->Location = System::Drawing::Point(20, 273);
			this->panel2FacturaD->Name = L"panel2FacturaD";
			this->panel2FacturaD->Size = System::Drawing::Size(233, 272);
			this->panel2FacturaD->TabIndex = 19;
			// 
			// splitCola
			// 
			this->splitCola->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
				static_cast<System::Int32>(static_cast<System::Byte>(201)));
			this->splitCola->IsSplitterFixed = true;
			this->splitCola->Location = System::Drawing::Point(533, 134);
			this->splitCola->Name = L"splitCola";
			this->splitCola->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitCola.Panel1
			// 
			this->splitCola->Panel1->Controls->Add(this->label43);
			this->splitCola->Panel1->Controls->Add(this->label44);
			this->splitCola->Panel1->Controls->Add(this->tlf_Cola);
			this->splitCola->Panel1->Controls->Add(this->label46);
			this->splitCola->Panel1->Controls->Add(this->cedula_Cola);
			this->splitCola->Panel1->Controls->Add(this->label48);
			this->splitCola->Panel1->Controls->Add(this->nombre_Cola);
			this->splitCola->Panel1->Controls->Add(this->label50);
			this->splitCola->Panel1->Controls->Add(this->tiempoCola);
			this->splitCola->Panel1->Controls->Add(this->label52);
			this->splitCola->Panel1->Controls->Add(this->Fecha_Cola);
			this->splitCola->Panel1->Controls->Add(this->label54);
			this->splitCola->Panel1->Controls->Add(this->label55);
			this->splitCola->Size = System::Drawing::Size(255, 360);
			this->splitCola->SplitterDistance = 101;
			this->splitCola->SplitterWidth = 1;
			this->splitCola->TabIndex = 10;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(163, 55);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(81, 13);
			this->label43->TabIndex = 28;
			this->label43->Text = L"POR ASIGNAR";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(8, 3);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(55, 13);
			this->label44->TabIndex = 12;
			this->label44->Text = L"CLIENTE:";
			// 
			// tlf_Cola
			// 
			this->tlf_Cola->AutoSize = true;
			this->tlf_Cola->Location = System::Drawing::Point(33, 29);
			this->tlf_Cola->Name = L"tlf_Cola";
			this->tlf_Cola->Size = System::Drawing::Size(53, 13);
			this->tlf_Cola->TabIndex = 27;
			this->tlf_Cola->Text = L"aqui va tlf";
			this->tlf_Cola->Visible = false;
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(8, 16);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(53, 13);
			this->label46->TabIndex = 13;
			this->label46->Text = L"CEDULA:";
			// 
			// cedula_Cola
			// 
			this->cedula_Cola->AutoSize = true;
			this->cedula_Cola->Location = System::Drawing::Point(58, 16);
			this->cedula_Cola->Name = L"cedula_Cola";
			this->cedula_Cola->Size = System::Drawing::Size(53, 13);
			this->cedula_Cola->TabIndex = 26;
			this->cedula_Cola->Text = L"aqui va ci";
			this->cedula_Cola->Visible = false;
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(8, 29);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(29, 13);
			this->label48->TabIndex = 14;
			this->label48->Text = L"TLF:";
			// 
			// nombre_Cola
			// 
			this->nombre_Cola->AutoSize = true;
			this->nombre_Cola->Location = System::Drawing::Point(59, 3);
			this->nombre_Cola->Name = L"nombre_Cola";
			this->nombre_Cola->Size = System::Drawing::Size(119, 13);
			this->nombre_Cola->TabIndex = 25;
			this->nombre_Cola->Text = L"NOMBRE Y APELLIDO";
			this->nombre_Cola->Visible = false;
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(8, 55);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(60, 13);
			this->label50->TabIndex = 19;
			this->label50->Text = L"FACTURA:";
			// 
			// tiempoCola
			// 
			this->tiempoCola->AutoSize = true;
			this->tiempoCola->Location = System::Drawing::Point(193, 68);
			this->tiempoCola->Name = L"tiempoCola";
			this->tiempoCola->Size = System::Drawing::Size(51, 13);
			this->tiempoCola->TabIndex = 24;
			this->tiempoCola->Text = L"aqui hora";
			this->tiempoCola->Visible = false;
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(8, 68);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(45, 13);
			this->label52->TabIndex = 20;
			this->label52->Text = L"FECHA:";
			// 
			// Fecha_Cola
			// 
			this->Fecha_Cola->AutoSize = true;
			this->Fecha_Cola->Location = System::Drawing::Point(53, 68);
			this->Fecha_Cola->Name = L"Fecha_Cola";
			this->Fecha_Cola->Size = System::Drawing::Size(83, 13);
			this->Fecha_Cola->TabIndex = 23;
			this->Fecha_Cola->Text = L"aqui va la fecha";
			this->Fecha_Cola->Visible = false;
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(151, 68);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(45, 13);
			this->label54->TabIndex = 21;
			this->label54->Text = L"Tiempo:";
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label55->Location = System::Drawing::Point(9, 81);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(235, 16);
			this->label55->TabIndex = 22;
			this->label55->Text = L"---------------------------------------------------------";
			// 
			// Mover
			// 
			this->Mover->Interval = 200;
			this->Mover->Tick += gcnew System::EventHandler(this, &MenuPrincipal::Mover_Tick);
			// 
			// tiempoCC
			// 
			this->tiempoCC->Interval = 1000;
			this->tiempoCC->Tick += gcnew System::EventHandler(this, &MenuPrincipal::tiempoCC_Tick);
			// 
			// tiempo
			// 
			this->tiempo->Enabled = true;
			this->tiempo->Interval = 1000;
			this->tiempo->Tick += gcnew System::EventHandler(this, &MenuPrincipal::tiempo_Tick);
			// 
			// crearClientes
			// 
			this->crearClientes->Enabled = true;
			this->crearClientes->Interval = 180000;
			this->crearClientes->Tick += gcnew System::EventHandler(this, &MenuPrincipal::crearClientes_Tick);
			// 
			// mostrarCliente
			// 
			this->mostrarCliente->Interval = 60000;
			this->mostrarCliente->Tick += gcnew System::EventHandler(this, &MenuPrincipal::mostrarCliente_Tick_1);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(800, 650);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->button_Inv);
			this->Controls->Add(this->button_Rep);
			this->Controls->Add(this->button_Cli);
			this->Controls->Add(this->button_Fac);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MenuPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MenuPrincipal";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->panelFacturaD->ResumeLayout(false);
			this->panelFacturaD->PerformLayout();
			this->splitCaja->Panel1->ResumeLayout(false);
			this->splitCaja->Panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitCaja))->EndInit();
			this->splitCaja->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->splitCola->Panel1->ResumeLayout(false);
			this->splitCola->Panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitCola))->EndInit();
			this->splitCola->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: 
			TableLayoutPanel^ tableCola;           // Los tablelayoutpanel son las tablas que contienen toda la informacion de los productosreportes
			TableLayoutPanel^ tablaCaja;
			TableLayoutPanel^ tablaFactura;
		
	// Agrega una nueva factura a la lista de últimas facturas
	void agregarAUltimaFactura() {
		static int Max_10 = 1;  // Contador para limitar a 10 facturas
			// Crear una nueva instancia de ultimasFacturas
			ultimasFacturas^ nuevaFactura = gcnew ultimasFacturas(
				nombrefac->Text,
				cedulafac->Text,
				tlf->Text,
				tablaFactura,
				fecha->Text,
				hora->Text,
				Ref->Text
			);
			if (Max_10 <= 11) {
				listFacturas->Add(nuevaFactura);
				reportes->comboUltimasF->Items->Add("Factura N " + (Max_10++));
			}
			else {
				listFacturas->RemoveAt(0);
				listFacturas->Add(nuevaFactura);
			}
	}
	// Cargar la tabla de la última factura en el panel
	void cargarTablaUltimaFactura(int index) {
		// Limpia el panel antes de agregar el nuevo TableLayoutPanel
		reportes->panelTabla->Controls->Clear();
		if (listFacturas[index] != nullptr) {
			// Agrega el TableLayoutPanel al panel
			reportes->panelTabla->Controls->Add(listFacturas[index]->tablaProductos);
		}
	}

	// Mostrar la factura en el reporte
	void mostrarFactura(int index) {
		reportes->panelUltimasf->Visible = true;
		reportes->ultima_Nombre->Text = listFacturas[index ]->Nombre;
		reportes->ultima_Ci->Text = listFacturas[index ]->CI;
		reportes->ultima_Tlf->Text = listFacturas[index ]->Tlf;
		reportes->ultima_Fecha->Text = listFacturas[index ]->Fecha;
		reportes->ultima_Hora->Text = listFacturas[index ]->Hora;
		reportes->Ref1->Text = listFacturas[index]->Ref;
		reportes->Ref2->Text = listFacturas[index]->Ref;
		reportes->ultima_MontoTotal->Text = montoTotal->Text;
		cargarTablaUltimaFactura(index);
		reportes->panelUltimasf->Refresh();
}

	// Agregar un reporte de compra a la tabla de reportes
	void agregarReporteACompra(int fila, claseReportes^ reporte, TableLayoutPanel^ tablaCOT) {  // COT = Tabla Compra o Tabla Tiempo superado
		tablaCOT->RowStyles->Insert(1, gcnew RowStyle(SizeType::Absolute, 15));
		tablaCOT->Controls->Add(reporte->ci, 0, fila);
		tablaCOT->Controls->Add(reporte->nombre, 1, fila);
		tablaCOT->Controls->Add(reporte->tlfReportes, 2, fila);
		tablaCOT->Controls->Add(reporte->fechaReportes, 3, fila);
		tablaCOT->Controls->Add(reporte->horaReportes, 4, fila);
		tablaCOT->Controls->Add(reporte->refReportes, 5, fila);
		tablaCOT->PerformLayout();
	}

	// Generar reportes de compras y agregar la factura a la lista
	void reportesCompras() {
		

		claseReportes^ nuevoReporte = gcnew claseReportes(
			cedulafac->Text, nombrefac->Text, tlf->Text, fecha->Text, hora->Text, Ref->Text);
		if (listClient[0]->GetTardo()) {                // Si el cliente tardo mas de 10 min lo agrega en la tabla de tiempo superado
			int fila = reportes->tablaTsuperado->RowCount;
			reportes->tablaTsuperado->RowCount++;
			agregarReporteACompra(fila - 1, nuevoReporte, reportes->tablaTsuperado);
		}
		else {
			int fila = reportes->tablaCompraC->RowCount;
			reportes->tablaCompraC->RowCount++;
			agregarReporteACompra(fila - 1, nuevoReporte, reportes->tablaCompraC);
			
		}
		
		agregarAUltimaFactura();
	}

	// Generar una referencia única para la factura y actualiza datos de la factura
	void generarRef(double totalMonto) {
		static int ref = 74853;
		Ref->Text = "*" + Convert::ToString(ref);
		refFactura->Text = Ref->Text;
		ref++;
		this->montoTotal->Text = totalMonto.ToString("F2");
		this->nombrefac->Text = nombreA->Text;
		this->cedulafac->Text = cedula->Text;
		this->tlfac->Text = tlf->Text;
		this->hora->Text = DateTime::Now.ToString("HH:mm:ss");
	}

	// Hacer visible la información de la factura
	void visibilidadInformacionFactura(){ 
		this->hora->Visible = true;
		this->Ref->Visible = true;
		this->refFactura->Visible = true;
		this->fecha->Visible = true;
		this->nombrefac->Visible = true;
		this->cedulafac->Visible = true;
		this->tlfac->Visible = true;
		this->LabelMontoTotal->Visible = true;
		this->montoTotal->Visible = true;
		this->cantidad->Visible = true;
	}
	// Finalizar la transferencia y actualizar la cola de clientes
	void finalizarTransferencia() {
		int index = clientesEnCola->SelectedIndex;
		// Remover el primer cliente de `listClient` y la primera persona en la cola
		if (listClient->Count > 0) {
			reportesCompras();
			Thread^ hiloVentas = gcnew Thread(gcnew ParameterizedThreadStart(this, &MenuPrincipal::tablaVentasProductosThread));
			hiloVentas->Start(listClient[0]);
			listClient->RemoveAt(0);
			if (clientesEnCola->Items->Count > 0) {
				clientesEnCola->Items->RemoveAt(0);
			}
		}
		// Manejar eliminación del primer item
		if (index == 0 && clientesEnCola->Items->Count > 0) {
			// Seleccionar el nuevo primer item si hay más elementos
			clientesEnCola->SelectedIndex = 0;
			mostrarEnCola(listClient, 1); // Mostrar el nuevo primer cliente

		}
		else if (index > 0) {
				index = clientesEnCola->SelectedIndex;
				mostrarEnCola(listClient, index+1); // Mostrar el cliente en la nueva posición
			
		}
		if (clientesEnCola->Items->Count == 0) {
			if (tableCola != nullptr) {
				LimpiarYPreparaTabla(tableCola);
			}
			sinClientes();
		}
		if (listClient->Count > 0) {            // Mostrar en caja solo si la cola no esta vacia
			mostrarEnCaja(listClient);
		}
	
	}

	void tablaVentasProductosThread(Object^ comprasClienteObj) {
		Cliente^ comprasCliente = dynamic_cast<Cliente^>(comprasClienteObj);
		if (comprasCliente != nullptr) {
			tablaVentasProductos(comprasCliente);
		}
	}

	void tablaVentasProductos(Cliente^ comprasCliente) {
		int count = comprasCliente->Productos->Count;
		data->abrirConexion();
		for (int i = 0; i < count; i++) {
			int cod = comprasCliente->Productos[i];
			int cant = comprasCliente->Cantidad[i];
			data->guardarCompras(BaseDatosInventario, cod, cant, reportes->ventasTotales);
		}
		data->cerrarConexion();
	}


	// Pasar los productos a la factura y generar la referencia
	void pasarAFactura(double totalMonto) {
		if (panel2FacturaD->Controls->Count == 0) {
			tablaFactura = AgregarTabla(panel2FacturaD);
		}
		else {
			this->panel2FacturaD->Controls->Clear();
			tablaFactura = AgregarTabla(panel2FacturaD);
		}


		cantidad->Text = "0";
		InicializarMoverTimer();
		generarRef(totalMonto);
		if (!this->hora->Visible) {
			visibilidadInformacionFactura();
		}
		
	}

	


	void ProcesarTabla(List<Cliente^>^ listClient, TableLayoutPanel^ tabla, int id, double& total, DataTable^ inventario) {
    if (listClient->Count > 0 && id >= 0) {
        int cant = 0;
        if (listClient[id]->Productos->Count > 0) {
            for (int i = 0; i < listClient[id]->Productos->Count; i++) {
                Label^ nombre = gcnew Label();
                Label^ precioIz = gcnew Label();
                Label^ precioDe = gcnew Label();
                bool productoEncontrado = data->mostrarProductos(inventario, listClient[id]->Productos[i], nombre, precioIz, precioDe, listClient[id]->Cantidad[i], total);

                if (productoEncontrado) {
                    cant += listClient[id]->Cantidad[i];

                    nombre->AutoSize = true;
                    precioIz->AutoSize = true;
                    precioDe->AutoSize = true;
                    precioDe->Anchor = System::Windows::Forms::AnchorStyles::Top;
                    precioIz->Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left;

                    int row = tabla->RowCount++;
                    tabla->RowStyles->Add(gcnew RowStyle(SizeType::AutoSize));
                    tabla->Controls->Add(nombre, 0, row);

                    row = tabla->RowCount++;
                    tabla->RowStyles->Add(gcnew RowStyle(SizeType::AutoSize));
                    tabla->Controls->Add(precioIz, 0, row);
                    tabla->Controls->Add(precioDe, 1, row);
                }
            }
        }
    }
}



	// Crear un nuevo cliente
	void CrearCliente(DataTable^ clientes) {
		static int rowIndex = 0;
		static bool siHayClientes = true;

		if (!siHayClientes) {
			// Si ya no hay clientes disponibles, no ejecutar la función
			return;
		}

		try {
			int clienteID = data->obtenerIDCliente(clientes, rowIndex);
			Cliente^ nuevoCliente = gcnew Cliente(clienteID);
			listClient->Add(nuevoCliente);
			rowIndex++; // Incrementar la fila para el próximo cliente
		}
		catch (Exception^) {
			MessageBox::Show("No hay más clientes");
			siHayClientes = false;
		}
	}



	// Mostrar la información del cliente en caja
	void mostrarEnCaja(List<Cliente^>^ listClient) {
		double totalMonto = 0.0;
		int id = listClient[0]->GetId();
		data->datos(BaseDatosCliente, id, nombreA, cedula, tlf);
		MostrarInformacionCliente(nombreA, cedula, tlf);
		if (EsNuevaTabla(splitCaja->Panel2)) {
			tablaCaja = AgregarTabla(splitCaja->Panel2);
		}
		else {
			LimpiarYPreparaTabla(tablaCaja);
		}

		ProcesarTabla(listClient, tablaCaja, 0, totalMonto, BaseDatosInventario);
		if (!listClient[0]->GetSeguir()) {
			pasarAFactura(totalMonto);
		}
	}

	// Mostrar la información del cliente en la cola
	void mostrarEnCola(List<Cliente^>^ listClient, int posCola) {
		
		if (EsNuevaTabla(splitCola->Panel2)) {
			tableCola = AgregarTabla(splitCola->Panel2);
		}
		else {
			LimpiarYPreparaTabla(tableCola);
		}
		double totalCola = 0;
		ProcesarTabla(listClient, tableCola, posCola, totalCola, BaseDatosInventario);
		PrepararInformacionCola(posCola);

		if (!Fecha_Cola->Visible) {
			Fecha_Cola->Text = DateTime::Now.ToString("dd/MM/yyyy");
			Fecha_Cola->Visible = true;
		}
	}

	bool EsNuevaTabla(Panel^ panel) {
		return panel->Controls->Count == 0;
	}

	void LimpiarYPreparaTabla(TableLayoutPanel^ table) {
		table->Controls->Clear();
		table->RowCount = 0;
		table->RowStyles->Clear();
	}

	void MostrarInformacionCliente(Label^ nombre, Label^ cedula, Label^ tlf) {            // Primero en cola
		nombre->Visible = true;
		cedula->Visible = true;
		tlf->Visible = true;
		Fecha_Caja->Text = DateTime::Now.ToString("dd/MM/yyyy");
		Fecha_Caja->Visible = true;
		tiempoCaja->Visible = true;
	}

	void PrepararInformacionCola(int posCola) {
		if (posCola > 0) {
			int number = listClient[posCola]->GetId();
			data->datos(BaseDatosCliente, number, nombre_Cola, cedula_Cola, tlf_Cola);
			MostrarInformacionCliente(nombre_Cola, cedula_Cola, tlf_Cola);
		}
	}

	void sinClientes() {
		nombre_Cola->Visible = false;
		cedula_Cola->Visible = false;
		tlf->Visible = false;
	}
	

	void AsignarColoresABotones()
	{
		// Array con los botones
		array<Button^>^ botones = {
			this->button_Fac,
			this->button_Inv,
			this->button_Rep,
			this->button_Cli,
			
		};

		// Asignar el color a cada botón en el array
			for each(Button ^ boton in botones)
			{
				boton->BackColor = Normal;
			}
		
		
	}
	
void OcultarPaneles()
{
	this->panel1->Visible = false;
	reportes->panel1->Visible = false;
	inventario->panel1->Visible = false;
	formCliente->panel1->Visible = false;
}

void ObtenerBaseDatosEnHilo(Object^ state) {
	DataTable^ datosTemp = data->getData("ventasproductos");

	// Volver al hilo de la UI para actualizar los controles
	this->Invoke(gcnew Action<DataTable^>(this, &MenuPrincipal::ActualizarDataGridView), datosTemp);
}

private: void ActualizarDataGridView(DataTable^ BaseDatosReportesTemp) {
	BaseDatosReportes = BaseDatosReportesTemp;
	reportes->dataGridView1->DataSource = BaseDatosReportes;
}

private: System::Void Boton_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Obtener el botón que fue clickeado
	Button^ botonClick = dynamic_cast<Button^>(sender);

	// Si el botón clickeado está en el formulario principal
	if (botonClick == button_Fac || botonClick == button_Inv || botonClick == button_Rep || botonClick == button_Cli)
	{
		
		
		// Restablecer los colores de todos los botones principales
		AsignarColoresABotones();
		botonClick->BackColor = botonClickeado; // Cambiar el color del botón clickeado

		OcultarPaneles(); 

		// Cambiar el panel según el botón clickeado
		if (botonClick == button_Rep)
		{
			reportes->panel1->Visible = true;
			Thread^ hiloDatos = gcnew Thread(gcnew ParameterizedThreadStart(this, &MenuPrincipal::ObtenerBaseDatosEnHilo));
			hiloDatos->Start();
		}
		else if (botonClick == button_Fac)
		{
			
			this->panel1->Visible = true;
		}
		else if (botonClick == button_Inv) {
			inventario->panel1->Visible = true;
		}
		else {
			formCliente->panel1->Visible = true;
		}
	}
	// Si el botón clickeado está en el formulario de reportes
	else if (botonClick == reportes->button_Compras || botonClick == reportes->button_TSuperado)
	{
		// Restablecer solo los colores de los botones dentro del panel de reportes
		array<Button^>^ botonesReportes = { reportes->button_Compras, reportes->button_TSuperado };
		for each (Button ^ boton in botonesReportes)
		{
			boton->BackColor = Normal;
		}

		botonClick->BackColor = botonClickeado; // Cambiar el color del botón clickeado
	}

	
}

TableLayoutPanel^ AgregarTabla(Panel^ panel) {
		// Crear una instancia de TableLayoutPanel
		TableLayoutPanel^ tableLayoutPanel = gcnew TableLayoutPanel();
		tableLayoutPanel->RowCount = 1; // Número de filas
		tableLayoutPanel->ColumnCount = 2; // Número de columnas
		// Configurar estilo de columna 
		tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 60.0F)); // 60% para la primera columna 
		tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 40.0F)); // 40% para la segunda columna
		tableLayoutPanel->Dock = DockStyle::Fill; // Ajustar al tamaño del contenedor
		tableLayoutPanel->HorizontalScroll->Enabled = false; // Deja activo solo el scroll vertical 
		tableLayoutPanel->HorizontalScroll->Visible = false;
		// Añadir el TableLayoutPanel al Panel específico
		panel->Controls->Add(tableLayoutPanel);
		return tableLayoutPanel;
		
}

private: System::Void B_cerrar_Click(System::Object^ sender, System::EventArgs^ e) { //metodo para cerrar el programa
	data->TruncateTable();
	this->Close();
}

	   // Método para inicializar componentes
void InicializarComponentes()
{
	this->panel2FacturaD->Controls->Add(tablaFactura);
	this->fecha->Text = DateTime::Now.ToString("dd/MM/yyyy");

	InicializarPaneles();
	AsignarEventos();
}

	   // Método para inicializar paneles
void InicializarPaneles()
{
	// Agregar todos los paneles al formulario y establecer su visibilidad inicial
	this->Controls->Add(reportes->panel1);
	reportes->panel1->Location = System::Drawing::Point(0, 58);
	reportes->panel1->Visible = false;

	this->Controls->Add(inventario->panel1);
	inventario->panel1->Location = System::Drawing::Point(0, 58);
	inventario->panel1->Visible = false;
	BaseDatosInventario = data->baseDatos("productos");
	inventario->dataGridView1->DataSource = BaseDatosInventario;

	this->Controls->Add(formCliente->panel1);
	formCliente->panel1->Location = System::Drawing::Point(0, 58);
	formCliente->panel1->Visible = false;
	BaseDatosCliente = data->baseDatos("cliente");
	formCliente->dataGridView1->DataSource = BaseDatosCliente;
	// Ocultar la quinta columna
	formCliente->dataGridView1->Columns[4]->Visible = false;
}

	   // Método para asignar eventos a los botones
void AsignarEventos()
{
	this->button_Fac->Click += gcnew System::EventHandler(this, &MenuPrincipal::Boton_Click);
	this->button_Inv->Click += gcnew System::EventHandler(this, &MenuPrincipal::Boton_Click);
	this->button_Rep->Click += gcnew System::EventHandler(this, &MenuPrincipal::Boton_Click);
	this->button_Cli->Click += gcnew System::EventHandler(this, &MenuPrincipal::Boton_Click);
	reportes->button_Compras->Click += gcnew System::EventHandler(this, &MenuPrincipal::Boton_Click);
	reportes->button_TSuperado->Click += gcnew System::EventHandler(this, &MenuPrincipal::Boton_Click);
	reportes->comboUltimasF->SelectedIndexChanged += gcnew System::EventHandler(this, &MenuPrincipal::comboBox_SelectedIndexChanged);
}

	   // Evento de carga del formulario
private: System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e) { // Lo que este dentro de este metodo se inicia automaticamente apenas abrir el programa
		InicializarComponentes();
}
private: System::Void toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e) {  // Cambiar la velocidad del programa 
	if (UseImage == true) {
		this->toolStripButton4->Image = System::Drawing::Image::FromFile("final.png");
		tiempoCC->Interval = 500;
		tempo->dobleVelocidad(crearClientes, mostrarCliente, listClient);
		UseImage = false;
	}
	else {
		this->toolStripButton4->Image = System::Drawing::Image::FromFile("inicial.png");
		tiempoCC->Interval = 1000;
		tempo->veloInicial(crearClientes, mostrarCliente, listClient);
		UseImage = true;
	}
}

void InicializarMoverTimer() { 
	Mover = gcnew System::Windows::Forms::Timer();
	Mover->Interval = 500; // Intervalo de 0.5 segundo 
	Mover->Tick += gcnew EventHandler(this, &MenuPrincipal::Mover_Tick);
	Mover->Start(); // Iniciar el Timer 
}

private: System::Void Mover_Tick(System::Object^ sender, System::EventArgs^ e) {
	int movedCount = 0; // Contador de controles movidos
	for (int i = 0; i < 3 && tablaCaja->Controls->Count > 0; ++i) {
		// Mover el control
		Control^ control = tablaCaja->Controls[0];
		tablaCaja->Controls->Remove(control);
		tablaFactura->Controls->Add(control);
		movedCount++; // Incrementar el contador de controles movidos
	}

	// Solo actualizar cantidad si se ha movido al menos un control
	if (movedCount > 0) {
		cantidad->Text = (Convert::ToInt32(cantidad->Text) + 1).ToString();
		sonidobeeb->Play();
	}
	else {
		// Si no se movieron controles, detener el timer
		finalizo = true;
		Mover->Stop();
		finalizarTransferencia();
	} 
}
	 


private: System::Void pausar_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarCliente->Stop();
	crearClientes->Stop();
	tempo->PausarTemporizador(tiempo, listClient);
}

private: System::Void reanudar_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarCliente->Start();
	crearClientes->Start();
	tempo->reanudarTemporizador(tiempo, listClient);
}

private: System::Void clientesEnCola_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = clientesEnCola->SelectedIndex;
	if (splitCola->Panel2->Controls->Contains(tableCola)) { 
		splitCola->Panel2->Controls->Remove(tableCola); 
	}
	mostrarEnCola(listClient, selectedIndex+1);
}


private: System::Void tiempoCC_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (listClient->Count > 0) {
		int id = 0;
		if (clientesEnCola->SelectedIndex >= 0) {
			id = clientesEnCola->SelectedIndex;
			tiempoCola->Visible = true;
		}
		tempo->tiemposClientes(listClient, tiempoCaja, tiempoCola,id);
	}
}
private: System::Void tiempo_Tick(System::Object^ sender, System::EventArgs^ e) {
	tempo->tiempoTranscurrido(toolStripTextBox1);
}

private: System::Void comboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	// Obtener el ComboBox que fue seleccionado
	ComboBox^ comboBox = dynamic_cast<ComboBox^>(sender);
	// Obtener el índice seleccionado
	int index = comboBox->SelectedIndex;
	if (index >= 0) {
		mostrarFactura(index);
		reportes->comboUltimasF->Refresh(); // Forzar refresco del ComboBox
	}
}
private: System::Void crearClientes_Tick(System::Object^ sender, System::EventArgs^ e) {
	int generarClientes = tempo->generarClientes;
		CrearCliente(BaseDatosCliente);
		if (generarClientes > 1) {
			clientesEnCola->Items->Add("Cliente " + generarClientes);
		}
		tempo->generarClientes++;
		if (generarClientes == 1) {
			mostrarEnCaja(listClient);
			if (tiempoCC->Enabled == false) {
				tiempoCC->Enabled = true;
				mostrarCliente->Enabled = true;
			}
		}
		if (!UseImage) {
			tempo->dobleVelocidad(crearClientes, mostrarCliente, listClient);
		}
	}
private: System::Void mostrarCliente_Tick_1(System::Object^ sender, System::EventArgs^ e) {
	if (listClient[0]->GetTiempo() > 600) {
		enviarUltimo(listClient[0]);
		mostrarEnCaja(listClient);
	}
	else {
		mostrarEnCaja(listClient);
	}
	if (splitCola->Panel2->Controls->Count > 0) {
		if (clientesEnCola->SelectedIndex != -1) {
			mostrarEnCola(listClient, clientesEnCola->SelectedIndex + 1);
		}
	}
	
}

	   void enviarUltimo(Cliente^ cliente) {
		   Cliente^ ultimo = cliente;
		   listClient->RemoveAt(0);
		   listClient->Add(ultimo);
		   ultimo->reiniciar();
		   ultimo->siTardo();
		   // Obtener el nombre del primer elemento
		   String^ firstItemName = clientesEnCola->Items[0]->ToString();
		   // Encontrar el índice del primer dígito en el nombre del cliente
		   int digitIndex = firstItemName->IndexOf(" ") + 1;
		   // Extraer el número del nombre del primer cliente
		   int number = Convert::ToInt32(firstItemName->Substring(digitIndex));
		   // Crear el nuevo nombre con el número reducido en 1
		   String^ newItemName = "Cliente " + (number - 1).ToString();
		   // Agregar el nuevo elemento al ComboBox
		   clientesEnCola->Items->Add(newItemName);
		   clientesEnCola->Items->RemoveAt(0);
} 

private: System::Void toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->WindowState = FormWindowState::Minimized;

}

void finalizarSimulacion() {
	tempo->PausarTemporizador(tiempo, listClient);
	crearClientes->Enabled = false;
	mostrarCliente->Enabled = false;
	tiempo->Enabled = false;
	tiempoCC->Enabled = false;
	splitCaja->Panel1->Controls->Clear();
	splitCaja->Panel2->Controls->Clear();
	splitCola->Panel1->Controls->Clear();
	splitCola->Panel2->Controls->Clear();
	clientesEnCola->Controls->Clear();
}

private: System::Void bt_Finalizar_Click(System::Object^ sender, System::EventArgs^ e) {
	finalizarSimulacion();
}
};

}





 

#pragma once
#include "ultimasFacturas.h"
namespace HiperMod {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Reportes
	/// </summary>
	public ref class Reportes : public System::Windows::Forms::Form
	{
	public:
		Reportes(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Reportes()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	public: System::Windows::Forms::Button^ button_Compras;
	public: System::Windows::Forms::Button^ button_TSuperado;
	public: System::Windows::Forms::TableLayoutPanel^ tablaVentasProductos;
	private: System::Windows::Forms::Label^ label8;
	public: System::Windows::Forms::TableLayoutPanel^ tablaCompraC;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label12;
	public: System::Windows::Forms::ComboBox^ comboUltimasF;
	private: System::Windows::Forms::Label^ label11;
	public: System::Windows::Forms::Panel^ panelUltimasf;
	 System::Windows::Forms::Label^ ultima_Tlf;
	 System::Windows::Forms::Label^ ultima_Ci;
	 System::Windows::Forms::Label^ ultima_Nombre;
	 System::Windows::Forms::Label^ ultima_Hora;
	 System::Windows::Forms::Label^ ultima_Fecha;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label31;
	public: System::Windows::Forms::Label^ ultima_MontoTotal;
	private: System::Windows::Forms::Label^ label25;
	public: String^ itemUltimo;
	public: System::Windows::Forms::Label^ Ref1;
	public: System::Windows::Forms::Label^ Ref2;
	public: System::Windows::Forms::Panel^ panelTabla;
	private: System::Windows::Forms::Label^ label38;
	public:
	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::Label^ label35;

	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ label20;
	private:
		   // Evento personalizado

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panelUltimasf = (gcnew System::Windows::Forms::Panel());
			this->panelTabla = (gcnew System::Windows::Forms::Panel());
			this->Ref1 = (gcnew System::Windows::Forms::Label());
			this->Ref2 = (gcnew System::Windows::Forms::Label());
			this->ultima_MontoTotal = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->ultima_Tlf = (gcnew System::Windows::Forms::Label());
			this->ultima_Ci = (gcnew System::Windows::Forms::Label());
			this->ultima_Nombre = (gcnew System::Windows::Forms::Label());
			this->ultima_Hora = (gcnew System::Windows::Forms::Label());
			this->ultima_Fecha = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->comboUltimasF = (gcnew System::Windows::Forms::ComboBox());
			this->tablaVentasProductos = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tablaCompraC = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button_Compras = (gcnew System::Windows::Forms::Button());
			this->button_TSuperado = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panelUltimasf->SuspendLayout();
			this->tablaVentasProductos->SuspendLayout();
			this->tablaCompraC->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panelUltimasf);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->comboUltimasF);
			this->panel1->Controls->Add(this->tablaVentasProductos);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->tablaCompraC);
			this->panel1->Controls->Add(this->button_Compras);
			this->panel1->Controls->Add(this->button_TSuperado);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(0, 58);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(799, 592);
			this->panel1->TabIndex = 8;
			// 
			// panelUltimasf
			// 
			this->panelUltimasf->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelUltimasf->Controls->Add(this->panelTabla);
			this->panelUltimasf->Controls->Add(this->Ref1);
			this->panelUltimasf->Controls->Add(this->Ref2);
			this->panelUltimasf->Controls->Add(this->ultima_MontoTotal);
			this->panelUltimasf->Controls->Add(this->label25);
			this->panelUltimasf->Controls->Add(this->ultima_Tlf);
			this->panelUltimasf->Controls->Add(this->ultima_Ci);
			this->panelUltimasf->Controls->Add(this->ultima_Nombre);
			this->panelUltimasf->Controls->Add(this->ultima_Hora);
			this->panelUltimasf->Controls->Add(this->ultima_Fecha);
			this->panelUltimasf->Controls->Add(this->label18);
			this->panelUltimasf->Controls->Add(this->label17);
			this->panelUltimasf->Controls->Add(this->label16);
			this->panelUltimasf->Controls->Add(this->label19);
			this->panelUltimasf->Controls->Add(this->label21);
			this->panelUltimasf->Controls->Add(this->label22);
			this->panelUltimasf->Controls->Add(this->label23);
			this->panelUltimasf->Controls->Add(this->label24);
			this->panelUltimasf->Controls->Add(this->label26);
			this->panelUltimasf->Controls->Add(this->label27);
			this->panelUltimasf->Controls->Add(this->label28);
			this->panelUltimasf->Controls->Add(this->label29);
			this->panelUltimasf->Controls->Add(this->label30);
			this->panelUltimasf->Controls->Add(this->label31);
			this->panelUltimasf->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panelUltimasf->Location = System::Drawing::Point(549, 65);
			this->panelUltimasf->Name = L"panelUltimasf";
			this->panelUltimasf->Size = System::Drawing::Size(237, 483);
			this->panelUltimasf->TabIndex = 16;
			this->panelUltimasf->Visible = false;
			// 
			// panelTabla
			// 
			this->panelTabla->Location = System::Drawing::Point(-1, 185);
			this->panelTabla->Name = L"panelTabla";
			this->panelTabla->Size = System::Drawing::Size(236, 280);
			this->panelTabla->TabIndex = 29;
			// 
			// Ref1
			// 
			this->Ref1->AutoSize = true;
			this->Ref1->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Ref1->Location = System::Drawing::Point(36, 80);
			this->Ref1->Name = L"Ref1";
			this->Ref1->Size = System::Drawing::Size(29, 14);
			this->Ref1->TabIndex = 28;
			this->Ref1->Text = L"hora";
			// 
			// Ref2
			// 
			this->Ref2->AutoSize = true;
			this->Ref2->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Ref2->Location = System::Drawing::Point(167, 145);
			this->Ref2->Name = L"Ref2";
			this->Ref2->Size = System::Drawing::Size(29, 14);
			this->Ref2->TabIndex = 27;
			this->Ref2->Text = L"hora";
			// 
			// ultima_MontoTotal
			// 
			this->ultima_MontoTotal->AutoSize = true;
			this->ultima_MontoTotal->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ultima_MontoTotal->Location = System::Drawing::Point(183, 465);
			this->ultima_MontoTotal->Name = L"ultima_MontoTotal";
			this->ultima_MontoTotal->Size = System::Drawing::Size(13, 14);
			this->ultima_MontoTotal->TabIndex = 26;
			this->ultima_MontoTotal->Text = L"0";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(7, 465);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(83, 14);
			this->label25->TabIndex = 25;
			this->label25->Text = L"MONTO TOTAL:";
			// 
			// ultima_Tlf
			// 
			this->ultima_Tlf->AutoSize = true;
			this->ultima_Tlf->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ultima_Tlf->Location = System::Drawing::Point(30, 121);
			this->ultima_Tlf->Name = L"ultima_Tlf";
			this->ultima_Tlf->Size = System::Drawing::Size(35, 14);
			this->ultima_Tlf->TabIndex = 23;
			this->ultima_Tlf->Text = L"label8";
			// 
			// ultima_Ci
			// 
			this->ultima_Ci->AutoSize = true;
			this->ultima_Ci->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ultima_Ci->Location = System::Drawing::Point(57, 108);
			this->ultima_Ci->Name = L"ultima_Ci";
			this->ultima_Ci->Size = System::Drawing::Size(35, 14);
			this->ultima_Ci->TabIndex = 22;
			this->ultima_Ci->Text = L"label8";
			// 
			// ultima_Nombre
			// 
			this->ultima_Nombre->AutoSize = true;
			this->ultima_Nombre->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ultima_Nombre->Location = System::Drawing::Point(57, 94);
			this->ultima_Nombre->Name = L"ultima_Nombre";
			this->ultima_Nombre->Size = System::Drawing::Size(35, 14);
			this->ultima_Nombre->TabIndex = 21;
			this->ultima_Nombre->Text = L"label8";
			// 
			// ultima_Hora
			// 
			this->ultima_Hora->AutoSize = true;
			this->ultima_Hora->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ultima_Hora->Location = System::Drawing::Point(182, 159);
			this->ultima_Hora->Name = L"ultima_Hora";
			this->ultima_Hora->Size = System::Drawing::Size(29, 14);
			this->ultima_Hora->TabIndex = 18;
			this->ultima_Hora->Text = L"hora";
			// 
			// ultima_Fecha
			// 
			this->ultima_Fecha->AutoSize = true;
			this->ultima_Fecha->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ultima_Fecha->Location = System::Drawing::Point(57, 159);
			this->ultima_Fecha->Name = L"ultima_Fecha";
			this->ultima_Fecha->Size = System::Drawing::Size(66, 14);
			this->ultima_Fecha->TabIndex = 17;
			this->ultima_Fecha->Text = L"aqui va la fe";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(6, 172);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(223, 16);
			this->label18->TabIndex = 16;
			this->label18->Text = L"------------------------------------------------------";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(138, 159);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(40, 14);
			this->label17->TabIndex = 15;
			this->label17->Text = L"HORA:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(7, 159);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(44, 14);
			this->label16->TabIndex = 14;
			this->label16->Text = L"FECHA:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(7, 146);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(58, 14);
			this->label19->TabIndex = 13;
			this->label19->Text = L"FACTURA:";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(3, 121);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(28, 14);
			this->label21->TabIndex = 11;
			this->label21->Text = L"TLF:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(3, 108);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(51, 14);
			this->label22->TabIndex = 10;
			this->label22->Text = L"CEDULA:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(3, 95);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(50, 14);
			this->label23->TabIndex = 9;
			this->label23->Text = L"CLIENTE:";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(3, 82);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(29, 14);
			this->label24->TabIndex = 8;
			this->label24->Text = L"REF:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(41, 65);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(150, 14);
			this->label26->TabIndex = 5;
			this->label26->Text = L"CONTRIBUYENTE ORDINARIO";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->Location = System::Drawing::Point(26, 52);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(194, 14);
			this->label27->TabIndex = 4;
			this->label27->Text = L"C. GURI, PUERTO ORDAZ ED BOLIVAR";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->Location = System::Drawing::Point(76, 39);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(85, 14);
			this->label28->TabIndex = 3;
			this->label28->Text = L"C.C ALTAVISTA I";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->Location = System::Drawing::Point(76, 27);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(82, 14);
			this->label29->TabIndex = 2;
			this->label29->Text = L"HIPERMOD C.A.";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(69, 14);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(94, 14);
			this->label30->TabIndex = 1;
			this->label30->Text = L"RIF J-5552225555";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->Location = System::Drawing::Point(92, 1);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(42, 14);
			this->label31->TabIndex = 0;
			this->label31->Text = L"SENIAT";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(608, 12);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(132, 18);
			this->label11->TabIndex = 15;
			this->label11->Text = L"Ultimas Facturas";
			// 
			// comboUltimasF
			// 
			this->comboUltimasF->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->comboUltimasF->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboUltimasF->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboUltimasF->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboUltimasF->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->comboUltimasF->FormattingEnabled = true;
			this->comboUltimasF->Location = System::Drawing::Point(599, 33);
			this->comboUltimasF->Name = L"comboUltimasF";
			this->comboUltimasF->Size = System::Drawing::Size(168, 26);
			this->comboUltimasF->TabIndex = 14;
			this->comboUltimasF->DropDown += gcnew System::EventHandler(this, &Reportes::comboUltimasF_DropDown);
			this->comboUltimasF->DropDownClosed += gcnew System::EventHandler(this, &Reportes::comboUltimasF_DropDownClosed);
			// 
			// tablaVentasProductos
			// 
			this->tablaVentasProductos->BackColor = System::Drawing::SystemColors::Info;
			this->tablaVentasProductos->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tablaVentasProductos->ColumnCount = 7;
			this->tablaVentasProductos->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				40)));
			this->tablaVentasProductos->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				140)));
			this->tablaVentasProductos->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				60)));
			this->tablaVentasProductos->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				70)));
			this->tablaVentasProductos->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				70)));
			this->tablaVentasProductos->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				70)));
			this->tablaVentasProductos->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tablaVentasProductos->Controls->Add(this->label38, 6, 0);
			this->tablaVentasProductos->Controls->Add(this->label37, 5, 0);
			this->tablaVentasProductos->Controls->Add(this->label36, 4, 0);
			this->tablaVentasProductos->Controls->Add(this->label35, 3, 0);
			this->tablaVentasProductos->Controls->Add(this->label33, 2, 0);
			this->tablaVentasProductos->Controls->Add(this->label32, 1, 0);
			this->tablaVentasProductos->Controls->Add(this->label20, 0, 0);
			this->tablaVentasProductos->Location = System::Drawing::Point(1, 390);
			this->tablaVentasProductos->Name = L"tablaVentasProductos";
			this->tablaVentasProductos->RowCount = 2;
			this->tablaVentasProductos->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tablaVentasProductos->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tablaVentasProductos->Size = System::Drawing::Size(538, 202);
			this->tablaVentasProductos->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(0, 369);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(164, 18);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Ventas por productos";
			// 
			// tablaCompraC
			// 
			this->tablaCompraC->AutoScroll = true;
			this->tablaCompraC->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(212)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->tablaCompraC->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tablaCompraC->ColumnCount = 6;
			this->tablaCompraC->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				80)));
			this->tablaCompraC->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				120)));
			this->tablaCompraC->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				100)));
			this->tablaCompraC->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				80)));
			this->tablaCompraC->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				80)));
			this->tablaCompraC->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tablaCompraC->Controls->Add(this->label15, 5, 0);
			this->tablaCompraC->Controls->Add(this->label13, 3, 0);
			this->tablaCompraC->Controls->Add(this->label9, 0, 0);
			this->tablaCompraC->Controls->Add(this->label14, 4, 0);
			this->tablaCompraC->Controls->Add(this->label10, 1, 0);
			this->tablaCompraC->Controls->Add(this->label12, 2, 0);
			this->tablaCompraC->Location = System::Drawing::Point(0, 158);
			this->tablaCompraC->Name = L"tablaCompraC";
			this->tablaCompraC->RowCount = 2;
			this->tablaCompraC->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tablaCompraC->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tablaCompraC->Size = System::Drawing::Size(539, 208);
			this->tablaCompraC->TabIndex = 10;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(469, 1);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(27, 13);
			this->label15->TabIndex = 6;
			this->label15->Text = L"Ref:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(307, 1);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(37, 13);
			this->label13->TabIndex = 4;
			this->label13->Text = L"Fecha";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(4, 1);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(20, 13);
			this->label9->TabIndex = 0;
			this->label9->Text = L"C.I";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(388, 1);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(30, 13);
			this->label14->TabIndex = 5;
			this->label14->Text = L"Hora";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(85, 1);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(92, 13);
			this->label10->TabIndex = 1;
			this->label10->Text = L"Nombre y Apellido";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(206, 1);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(49, 13);
			this->label12->TabIndex = 3;
			this->label12->Text = L"Telefono";
			// 
			// button_Compras
			// 
			this->button_Compras->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->button_Compras->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Compras->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Compras->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button_Compras->Location = System::Drawing::Point(3, 120);
			this->button_Compras->Name = L"button_Compras";
			this->button_Compras->Size = System::Drawing::Size(136, 25);
			this->button_Compras->TabIndex = 9;
			this->button_Compras->Text = L"Compras";
			this->button_Compras->UseVisualStyleBackColor = false;
			// 
			// button_TSuperado
			// 
			this->button_TSuperado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->button_TSuperado->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_TSuperado->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_TSuperado->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button_TSuperado->Location = System::Drawing::Point(145, 120);
			this->button_TSuperado->Name = L"button_TSuperado";
			this->button_TSuperado->Size = System::Drawing::Size(136, 25);
			this->button_TSuperado->TabIndex = 8;
			this->button_TSuperado->Text = L"T.  Superado";
			this->button_TSuperado->UseVisualStyleBackColor = false;
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Location = System::Drawing::Point(3, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(536, 111);
			this->panel2->TabIndex = 0;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 91);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(58, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"REF: 5555";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 78);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(128, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"OPE: JOSE CARABALLO";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(156, 55);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(214, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"C. GURI, PUERTO ORDAZ EDO BOLIVAR";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(211, 42);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"C.C ALTAVISTA I";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(217, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"HIPERMOD C.A";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(213, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"RIF J-555222555";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(238, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"SENIAT";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(4, 1);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(30, 13);
			this->label20->TabIndex = 0;
			this->label20->Text = L"COD";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(45, 1);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(80, 13);
			this->label32->TabIndex = 1;
			this->label32->Text = L"DESCRIPCIÓN";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(186, 1);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(39, 13);
			this->label33->TabIndex = 2;
			this->label33->Text = L"CANT:";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(247, 1);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(56, 13);
			this->label35->TabIndex = 4;
			this->label35->Text = L"PRECIO $";
			this->label35->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(318, 1);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(64, 13);
			this->label36->TabIndex = 5;
			this->label36->Text = L"PRECIO BS";
			this->label36->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(389, 1);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(59, 13);
			this->label37->TabIndex = 6;
			this->label37->Text = L"VENTAS $";
			this->label37->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(460, 1);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(67, 13);
			this->label38->TabIndex = 7;
			this->label38->Text = L"VENTAS BS";
			this->label38->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Reportes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 650);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Reportes";
			this->Text = L"Reportes";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panelUltimasf->ResumeLayout(false);
			this->panelUltimasf->PerformLayout();
			this->tablaVentasProductos->ResumeLayout(false);
			this->tablaVentasProductos->PerformLayout();
			this->tablaCompraC->ResumeLayout(false);
			this->tablaCompraC->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		void comboUltimasF_DropDown(System::Object^ sender, System::EventArgs^ e) {
			ComboBox^ comboUltimasF = safe_cast<ComboBox^>(sender);
			int totalItems = comboUltimasF->Items->Count;

			if (totalItems > 0) {
				// Almacenar temporalmente el último ítem y eliminarlo del ComboBox
				itemUltimo = comboUltimasF->Items[totalItems - 1]->ToString();
				comboUltimasF->Items->RemoveAt(totalItems - 1);

				// Ajustar el número de ítems visibles si hay más de un ítem
				if (totalItems > 1) {
					comboUltimasF->MaxDropDownItems = totalItems - 1;
				}
				
			}
		}

		void comboUltimasF_DropDownClosed(System::Object^ sender, System::EventArgs^ e) {
			ComboBox^ comboUltimasF = safe_cast<ComboBox^>(sender);
			if (itemUltimo != nullptr) {
				comboUltimasF->Items->Add(itemUltimo);
				itemUltimo = nullptr;
			}
		}


};
}

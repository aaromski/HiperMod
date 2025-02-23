#pragma once
#include "conexion.h"
namespace HiperMod {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Inventario
	/// </summary>
	public ref class Inventario : public System::Windows::Forms::Form
	{
	private:
		static Inventario^ instance = nullptr;
		Inventario(void)
		{
			InitializeComponent();
			conexion = gcnew Conexion();
			//
			//TODO: agregar código de constructor aquí
			//
		}
	public:
		static property Inventario^ Instance{
			Inventario ^ get() {
				if (instance == nullptr || instance->IsDisposed) {
					instance = gcnew Inventario();
				}
				return instance;
			}
		}

			static void ShowForm() {
			if (instance == nullptr || instance->IsDisposed) {
				instance = gcnew Inventario();
			}
			instance->Show();
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Inventario()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Panel^ panel1;
	public: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: Conexion^ conexion;
	private: int idRow;
	private: int columnIndex;
	private: DataTable^ baseProducto;
	private: System::Windows::Forms::Button^ modificar;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->modificar = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->modificar);
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(0, 58);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(799, 543);
			this->panel1->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(599, 232);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(153, 20);
			this->textBox2->TabIndex = 5;
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(599, 146);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(153, 20);
			this->textBox1->TabIndex = 4;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(596, 204);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(104, 18);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Stock Nuevo:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(596, 120);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(105, 18);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Stock Actual:";
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
			this->panel2->TabIndex = 1;
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
			// modificar
			// 
			this->modificar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->modificar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->modificar->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->modificar->ForeColor = System::Drawing::SystemColors::Control;
			this->modificar->Location = System::Drawing::Point(599, 459);
			this->modificar->Name = L"modificar";
			this->modificar->Size = System::Drawing::Size(153, 35);
			this->modificar->TabIndex = 1;
			this->modificar->Text = L"Modificar";
			this->modificar->UseVisualStyleBackColor = false;
			this->modificar->Click += gcnew System::EventHandler(this, &Inventario::modificar_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::MenuBar;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(6, 120);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(533, 395);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Inventario::dataGridView1_CellContentClick);
			// 
			// Inventario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 600);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Inventario";
			this->Text = L"Inventario";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	void actualizarBaseDatos() {
			//Modificar Stock disponible
			conexion->modificarCelda(idRow, textBox2->Text, dataGridView1->Columns[columnIndex]->HeaderText, "productos");

			// Actualizar el DataGridView
			baseProducto = conexion->baseDatos("productos");
			dataGridView1->DataSource = baseProducto;
			dataGridView1->Refresh();
			textBox1->Clear();
	}

	private: System::Void modificar_Click(System::Object^ sender, System::EventArgs^ e) {
		actualizarBaseDatos();
	}

private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->ColumnIndex == 2 && e->RowIndex >= 0) {  //Seleccionar solo si es de la columna Stock
		// Obtener el valor de la celda seleccionada
		columnIndex = e->ColumnIndex;
		idRow = Convert::ToInt32(dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString());
		String^ cellValue = dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString();
		textBox1->Text = cellValue;
	}
}
};
}

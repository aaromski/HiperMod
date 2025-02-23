#pragma once
#include "conexion.h"
namespace HiperMod {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;


	/// <summary>
	/// Resumen de Clientes
	/// </summary>
	public ref class formClientes : public System::Windows::Forms::Form
	{
	private:
		static formClientes^ instance = nullptr;
		formClientes(void)
		{
			InitializeComponent();
			conexion = gcnew Conexion();
			//
			//TODO: agregar código de constructor aquí
			//
		}
	public:
		static property formClientes^ Instance{
			formClientes ^ get() {
				if (instance == nullptr || instance->IsDisposed) {
					instance = gcnew formClientes();
				}
				return instance;
			}
		}

			static void ShowForm() {
			if (instance == nullptr || instance->IsDisposed) {
				instance = gcnew formClientes();
			}
			instance->Show();
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~formClientes()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Panel^ panel1;
	protected:
	private: int idRow;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Button^ btUniversal;
	private: int row;
	private: int column;
	public: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::DirectoryServices::DirectorySearcher^ directorySearcher1;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripSplitButton^ toolStripSplitButton1;
	private: System::Windows::Forms::ToolStripMenuItem^ agregarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ eliminarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ modificarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripLabel^ toolStripLabel1;
	private: Conexion^ conexion;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	public:
	private: DataTable^ baseDatosClientes;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(formClientes::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripSplitButton1 = (gcnew System::Windows::Forms::ToolStripSplitButton());
			this->agregarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eliminarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->modificarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btUniversal = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->directorySearcher1 = (gcnew System::DirectoryServices::DirectorySearcher());
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->btUniversal);
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(0, 58);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(799, 543);
			this->panel1->TabIndex = 8;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(577, 206);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(33, 15);
			this->label12->TabIndex = 17;
			this->label12->Text = L"TLF:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(577, 159);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(60, 15);
			this->label11->TabIndex = 16;
			this->label11->Text = L"Apellido:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(577, 110);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(57, 15);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Nombre:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(577, 63);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(24, 15);
			this->label9->TabIndex = 14;
			this->label9->Text = L"CI:";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->toolStrip1);
			this->panel3->Location = System::Drawing::Point(545, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(254, 30);
			this->panel3->TabIndex = 12;
			// 
			// toolStrip1
			// 
			this->toolStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(154)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->toolStrip1->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripSplitButton1,
					this->toolStripLabel1
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(254, 25);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripSplitButton1
			// 
			this->toolStripSplitButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripSplitButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->agregarToolStripMenuItem,
					this->eliminarToolStripMenuItem, this->modificarToolStripMenuItem
			});
			this->toolStripSplitButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripSplitButton1.Image")));
			this->toolStripSplitButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripSplitButton1->Name = L"toolStripSplitButton1";
			this->toolStripSplitButton1->Size = System::Drawing::Size(32, 22);
			this->toolStripSplitButton1->Text = L"toolStripSplitButton1";
			// 
			// agregarToolStripMenuItem
			// 
			this->agregarToolStripMenuItem->Name = L"agregarToolStripMenuItem";
			this->agregarToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->agregarToolStripMenuItem->Text = L"Agregar";
			this->agregarToolStripMenuItem->Click += gcnew System::EventHandler(this, &formClientes::agregarToolStripMenuItem_Click);
			// 
			// eliminarToolStripMenuItem
			// 
			this->eliminarToolStripMenuItem->Name = L"eliminarToolStripMenuItem";
			this->eliminarToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->eliminarToolStripMenuItem->Text = L"Eliminar";
			this->eliminarToolStripMenuItem->Click += gcnew System::EventHandler(this, &formClientes::eliminarToolStripMenuItem_Click);
			// 
			// modificarToolStripMenuItem
			// 
			this->modificarToolStripMenuItem->Name = L"modificarToolStripMenuItem";
			this->modificarToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->modificarToolStripMenuItem->Text = L"Modificar";
			this->modificarToolStripMenuItem->Click += gcnew System::EventHandler(this, &formClientes::modificarToolStripMenuItem_Click);
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(57, 22);
			this->toolStripLabel1->Text = L"Opciones";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(580, 222);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(166, 20);
			this->textBox4->TabIndex = 9;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(580, 175);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(166, 20);
			this->textBox3->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(580, 126);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(166, 20);
			this->textBox2->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(580, 79);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(166, 20);
			this->textBox1->TabIndex = 6;
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
			this->panel2->Location = System::Drawing::Point(3, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(536, 111);
			this->panel2->TabIndex = 4;
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
			// btUniversal
			// 
			this->btUniversal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btUniversal->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btUniversal->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btUniversal->ForeColor = System::Drawing::SystemColors::Control;
			this->btUniversal->Location = System::Drawing::Point(580, 274);
			this->btUniversal->Name = L"btUniversal";
			this->btUniversal->Size = System::Drawing::Size(166, 35);
			this->btUniversal->TabIndex = 3;
			this->btUniversal->Text = L"Agregar";
			this->btUniversal->UseVisualStyleBackColor = false;
			this->btUniversal->Click += gcnew System::EventHandler(this, &formClientes::btUniversal_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::MenuBar;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(6, 117);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(533, 395);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &formClientes::dataGridView1_CellContentClick);
			// 
			// directorySearcher1
			// 
			this->directorySearcher1->ClientTimeout = System::TimeSpan::Parse(L"-00:00:01");
			this->directorySearcher1->ServerPageTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			this->directorySearcher1->ServerTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			// 
			// formClientes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 600);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"formClientes";
			this->Text = L"Clientes";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	

	private: System::Void btUniversal_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ textBoton = btUniversal->Text;
		String^ tex_ci = textBox1->Text;
		String^ tex_nombre = textBox2->Text;
		String^ tex_apellido = textBox3->Text;
		String^ tex_tlf = textBox4->Text;

		if (textBoton == "Agregar") {
			// Validar los datos
			if (!Regex::IsMatch(tex_ci, "^[0-9]+$")) {
				MessageBox::Show("El campo CI debe contener solo números.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (noVacioNiDigitos(tex_nombre)) {
				MessageBox::Show("El campo no puede estar vacío ni contener digitos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (noVacioNiDigitos(tex_apellido)) {
				MessageBox::Show("El campo no puede estar vacío ni contener digitos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (!Regex::IsMatch(tex_tlf, "^[0-9]+$")) {
				MessageBox::Show("El campo Teléfono debe contener solo números.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			// Llamar a la función Insertar
			conexion->Insertar(tex_ci, tex_nombre , tex_apellido, tex_tlf);
			actualizarBaseDatos();
		}

		if (textBoton == "Modificar") {
			switch (column)
			{
				case 0: if (soloNumeros(tex_nombre)) {
					MessageBox::Show("El campo debe contener solo números.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return; 
				} break;

				case 1: if (noVacioNiDigitos(tex_nombre)) {
					MessageBox::Show("El campo no puede estar vacío ni contener digitos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				} break;

				case 2: if (noVacioNiDigitos(tex_nombre)) {
					MessageBox::Show("El campo no puede estar vacío ni contener digitos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				} break;

				case 3: if (soloNumeros(tex_nombre)) {
					MessageBox::Show("El campo solo debe contener números.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				} break;

			default:
				return; break;
			}
			conexion->modificarCelda(idRow, textBox2->Text, dataGridView1->Columns[column]->HeaderText, "cliente");
			actualizarBaseDatos();
		}

		if (textBoton == "Eliminar") {

			if (soloNumeros(tex_ci) || column != 0) {
				MessageBox::Show("Seleccione Solamente Cedulas", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else {
				System::Windows::Forms::DialogResult resultado = MessageBox::Show("¿Estás seguro de eliminarlo?", "Confirmación",MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				if (resultado == System::Windows::Forms::DialogResult::Yes) {
					// Aquí puedes llamar a la función que elimina el registro de la base de datos
					conexion->Eliminar(tex_ci);
					actualizarBaseDatos();
				}
			}
			}
			
	}

bool noVacioNiDigitos(String^ texbox) {
	if (String::IsNullOrWhiteSpace(texbox) || Regex::IsMatch(texbox, "^[0-9]+$")) {
		return true;
	}
	else {
		return false;
	}
}

bool soloNumeros(String^ texbox) {
	if (!Regex::IsMatch(texbox, "^[0-9]+$")) {
		return true;
	}
	else {
		return false;
	}
}

void actualizarBaseDatos() {
	// Actualizar el DataGridView
	baseDatosClientes = conexion->baseDatos("cliente");
	dataGridView1->DataSource = baseDatosClientes;
	dataGridView1->Refresh();
}

private: System::Void eliminarToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	ocultarTextBox();
	limpiarTextBox();
	textBox2->Visible = false;
	label9->Text = "CI:";
	btUniversal->Text = "Eliminar";
	btUniversal->Location = Point(580, 117);
}
private: System::Void modificarToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	ocultarTextBox();
	limpiarTextBox();
	textBox2->Visible = true;
	label9->Text = "Modificar Celda:";                    
	btUniversal->Text = "Modificar";
}

void ocultarTextBox() {
	textBox1->Enabled = false;           //Desactivar para evitar modificacion
	textBox3->Visible = false;
	textBox4->Visible = false;
	label10->Visible = false;
	label11->Visible = false;
	label12->Visible = false;
	btUniversal->Location = Point(580, 168);
}

void limpiarTextBox() {
	textBox1->Clear();
	textBox2->Clear();
	textBox3->Clear();
	textBox4->Clear();
}

void verTextBox() {
	textBox1->Enabled = true;
	textBox2->Visible = true;
	textBox3->Visible = true;
	textBox4->Visible = true;
	label10->Visible = true;
	label11->Visible = true;
	label12->Visible = true;
	btUniversal->Location = Point(580, 274);
}
private: System::Void agregarToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	verTextBox();
	limpiarTextBox();
	label9->Text = "CI:";
	btUniversal->Text = "Agregar";
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	// Obtener el índice de la fila y columna seleccionada
	 row = e->RowIndex;
	 column = e->ColumnIndex;

	// Validar que los índices de la fila y columna sean válidos
	if (row < 0 || column < 0)
		return;

	// Obtener el valor de la celda seleccionada
	String^ cellValue = dataGridView1->Rows[row]->Cells[column]->Value->ToString();

	if (btUniversal->Text == "Modificar" || btUniversal->Text == "Eliminar") {
		// Asignar el valor de la celda seleccionada al textBox1
		textBox1->Text = cellValue;
		idRow = Convert::ToInt32(dataGridView1->Rows[row]->Cells[4]->Value->ToString());
	}
}
};
}

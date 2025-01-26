#pragma once
#include <iostream>
#include <stdlib.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;
using namespace System::Data::Common;
ref class Conexion
{
	String^ cn;
	MySqlConnection^ st;
public:
	Conexion() {
		this->cn = "datasource=localhost; username=root; password=123456; database=hipermod;";
		this->st = gcnew MySqlConnection(this->cn);
	}

public:
	void  abrirConexion() {
		this->st->Open();
	}
	void  cerrarConexion() {
		this->st->Close();
	}

	void Insertar(String^ CI, String^ nombre, String^ apellido, int tlf) {
		String^ sentencia = "INSERT INTO Clientes (CI, Nombre, Apellido, Telefono) VALUES (@CI, @Nombre, @Apellido, @Telefono)";
		MySqlCommand^ ejecutar = gcnew MySqlCommand(sentencia, this->st);
		ejecutar->Parameters->AddWithValue("@CI", CI);
		ejecutar->Parameters->AddWithValue("@Nombre", nombre);
		ejecutar->Parameters->AddWithValue("@Apellido", apellido);
		ejecutar->Parameters->AddWithValue("@Telefono", tlf);
		this->st->Open();
		ejecutar->ExecuteNonQuery();
		this->st->Close();
	}

	void Eliminar(String^ CI) {
		String^ sentencia = "DELETE FROM Clientes WHERE CI = @CI"; 
		MySqlCommand^ ejecutar = gcnew MySqlCommand(sentencia, this->st);
		ejecutar->Parameters->AddWithValue("@CI", CI);
		this->st->Open();
		ejecutar->ExecuteNonQuery();
		this->st->Close();
	}

	DataTable^ getData(String^ tableName)
	{
		// Construir la consulta SQL utilizando el parámetro tableName
		String^ sql = "SELECT * FROM " + tableName;
		MySqlCommand^ cursor = gcnew MySqlCommand(sql, this->st);
		MySqlDataAdapter^ data = gcnew MySqlDataAdapter(cursor);
		DataTable^ tabla = gcnew DataTable();
		data->Fill(tabla);
		return tabla;
	}

	array<int>^ alazar() { 
		array<int>^ numeros = gcnew array<int> { 1, 2, 3 }; 
		Random^ rnd = gcnew Random(); 
		for (int i = 0; i < numeros->Length; ++i) { 
			int j = rnd->Next(i, numeros->Length); 
			int temp = numeros[i]; numeros[i] = numeros[j]; numeros[j] = temp; 
		} 
		return numeros; 
	}
	void datos(int id, Label^ nombreA, Label^ ci, Label^ tlf) { // Metodo para buscar la informacion del cliente y guardala en label
		String^ sentencia = "SELECT nombre, apellido, CI, Tlf FROM cliente WHERE ID = @ID";
		MySqlCommand^ ejecutar = gcnew MySqlCommand(sentencia, this->st);
		ejecutar->Parameters->AddWithValue("@ID", id);
		this->st->Open();
		MySqlDataReader^ lector = ejecutar->ExecuteReader();
		if (lector->Read()) {
			String^ nombre = lector["nombre"]->ToString();
			String^ apellido = lector["apellido"]->ToString();
			nombreA->Text = nombre + " " + apellido;
			String^ cedula = lector["CI"]->ToString();
			ci->Text = cedula;
			String^ telefono = lector["tlf"]->ToString();
			tlf->Text = telefono;
			
		}
		else { 
			nombreA->Text = "Cliente no encontrado"; 
		}
		lector->Close();
		this->st->Close();
	}

	void mostrarProductos(int id, Label^ nombreP, Label^ izqui, Label^ dere, int cantidad,  double& montoTotal ) {
		String^ sentencia = "SELECT descripcion, Precio_BS FROM productos WHERE ID = @ID";
		MySqlCommand^ ejecutar = gcnew MySqlCommand(sentencia, this->st);
		ejecutar->Parameters->AddWithValue("@ID", id);
		MySqlDataReader^ lector = ejecutar->ExecuteReader();

		if (lector->Read()) {

			String^ producto = lector["descripcion"]->ToString();
			nombreP->Text = producto;

			String^ precioP = lector["Precio_BS"]->ToString();
			izqui->Text = cantidad + "x" + precioP;

			double precioNumerico = Double::Parse(precioP);
			double resultado = cantidad * precioNumerico;
			dere->Text = "Bs " + resultado.ToString("F2");

			montoTotal += resultado;
		}
		else {
			nombreP->Text = "Producto no encontrado";
		}

		lector->Close();
	}

};




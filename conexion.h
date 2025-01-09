#pragma once
#include <iostream>
#include <ctime>
#include <random>
#include <stdlib.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;
using namespace MySql::Data::MySqlClient;
ref class Conexion
{
	String^ cn;
	MySqlConnection^ st;
public:
	Conexion() {
		this->cn = "datasource=localhost; username=root; password=123456; database=producto;";
		this->st = gcnew MySqlConnection(this->cn);
	}

public:
	void  abrirConexion() {
		this->st->Open();
	}
	void  cerrarConexion() {
		this->st->Close();
	}
	void Insertar(int id, String^ descripcion, int stock, int precio) { // El metodo insertar y eliminar no los uso en el programa
		String^ sentencia = "Insert into datos values(@ID,@descripcion,@stock,@precio)";
		MySqlCommand^ ejecutar = gcnew MySqlCommand(sentencia, this->st);
		ejecutar->Parameters->AddWithValue("@ID", id);
		ejecutar->Parameters->AddWithValue("@descripcion", descripcion);
		ejecutar->Parameters->AddWithValue("@stock", stock);
		ejecutar->Parameters->AddWithValue("@precio", precio);
		this->st->Open();
		ejecutar->ExecuteNonQuery();
		this->st->Close();
	}
	void Eliminar(int id) { //Los dejo aqui por si necisitan despues, sirven para ingresar un producto a la base de datos o eliminar un producto de la base de datos.
		String^ sentencia = "Delete from datos where ID = @ID";
		MySqlCommand^ ejecutar = gcnew MySqlCommand(sentencia, this->st);
		ejecutar->Parameters->AddWithValue("@ID", id);
		this->st->Open();
		ejecutar->ExecuteNonQuery();
		this->st->Close();
	}
	DataTable^ Conexion::getData() //Tampoco utilizo esto, sirve para mostrar toda la base de datos en una tabla.
	{
		String^ sql = "select *from datos";
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
	// Este metodo es para buscar la informacion del producto y agregarla a la tabla de la forma como se aprecia en la simulacion
	// cantidad y cantidadcola es la cantidad del productas que lleva el cliente en caja y cola en ese momento
	//seguir es para saber si el cliente se va a pasar de los 30 productos y ref es para saber si es el cliente en caja o en cola.
	void productosF(int id, Label^ nombreP, Label^ izqui, Label^ dere, Label^ cantidad, Label^ cantCola, Label^ monto, bool% seguir, int ref) {
		int cant = randomNumero();
		Label^ labelActual = (ref == 1) ? cantidad : cantCola;
		int aux = Convert::ToInt32(labelActual->Text) + cant;

		if (aux > 30) {
			seguir = false;
			return;
		}
		
		String^ sentencia = "SELECT descripcion, precio FROM datos WHERE ID = @ID";
		MySqlCommand^ ejecutar = gcnew MySqlCommand(sentencia, this->st);
		ejecutar->Parameters->AddWithValue("@ID", id);
		this->st->Open();
		MySqlDataReader^ lector = ejecutar->ExecuteReader();

		if (lector->Read()) {
			labelActual->Text = aux.ToString();

			String^ producto = lector["descripcion"]->ToString();
			nombreP->Text = producto;

			String^ precioP = lector["precio"]->ToString();
			izqui->Text = cant + "x" + precioP;

			double precioNumerico = Convert::ToDouble(precioP);
			double resultado = cant * precioNumerico;
			dere->Text = "Bs " + resultado.ToString("F2");

			double montoActual = Convert::ToDouble(monto->Text);
			monto->Text = (ref == 1 ) ? (resultado + montoActual).ToString("F2") : (montoActual).ToString("F2");
		}
		else {
			nombreP->Text = "Producto no encontrado";
		}

		lector->Close();
		this->st->Close();
	}


	int randomNumero() {
		std::srand(static_cast<unsigned>(std::time(nullptr))); // Generar un número aleatorio entre 1 y 5 
		int cantidad = (std::rand() % 5) + 3;
		return cantidad;
	}
	int randomNumeroid() {
		std::srand(static_cast<unsigned>(std::time(nullptr))); // Generar un número aleatorio entre 1 y 5 
		int cantidad = (std::rand() % 3) + 1;
		return cantidad;
	}
};

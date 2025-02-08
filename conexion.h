#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
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
		String^ sql = "SELECT * FROM " + tableName + " ORDER BY `Ventas Bs` DESC";
		MySqlCommand^ cursor = gcnew MySqlCommand(sql, this->st);
		MySqlDataAdapter^ data = gcnew MySqlDataAdapter(cursor);
		DataTable^ tabla = gcnew DataTable();
		data->Fill(tabla);
		return tabla;
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

	void guardarCompras(int cod, int cantidad) {
		String^ consulta = "SELECT * FROM ventasproductos WHERE COD = @COD";
		MySqlCommand^ ejecutar = gcnew MySqlCommand(consulta, this->st);
		ejecutar->Parameters->AddWithValue("@COD", cod);

		MySqlDataReader^ lector = ejecutar->ExecuteReader();
		if (lector->Read()) {
			// El producto existe, actualizar la cantidad
			int cantidadActual = Convert::ToInt32(lector["Cantidad"]);
			int nuevaCantidad = cantidadActual + cantidad;
			double precioBs = Convert::ToDouble(lector["Precio Bs"]);
			double ventasBs = precioBs * nuevaCantidad;
			double precioDolares = Convert::ToDouble(lector["Precio $"]);
			double ventasDolares = precioDolares * nuevaCantidad;

			lector->Close(); // Cerrar el lector antes de ejecutar otra consulta

			// Actualizar la cantidad y ventas
			consulta = "UPDATE ventasproductos SET Cantidad = @nuevaCantidad, `Ventas $` = @ventasDolares, `Ventas Bs` = @ventasBs WHERE Cod = @COD";
			ejecutar = gcnew MySqlCommand(consulta, this->st);
			ejecutar->Parameters->AddWithValue("@nuevaCantidad", nuevaCantidad);
			ejecutar->Parameters->AddWithValue("@ventasDolares", ventasDolares);
			ejecutar->Parameters->AddWithValue("@ventasBs", ventasBs);
			ejecutar->Parameters->AddWithValue("@COD", cod);
			ejecutar->ExecuteNonQuery(); // Ejecutar la consulta de actualización
		}
		else {
			lector->Close(); // Cerrar el lector antes de ejecutar otra consulta

			// Variables para almacenar los datos obtenidos de la base de datos
			String^ descripcion = nullptr;
			double precioDolar = 0;
			double precioBs = 0;

			// Obtener descripción y precios desde la tabla productos
			obtenerDescripcionPrecios(cod, descripcion, precioDolar, precioBs);

			// Calcular las ventas
			double ventasBs = precioBs * cantidad;
			double ventasDolares = precioDolar * cantidad;

			consulta = "INSERT INTO ventasproductos (COD, Descripcion, Cantidad, `Precio $`, `Precio Bs`, `Ventas $`, `Ventas Bs`) VALUES (@COD, @Descripcion, @Cantidad, @PrecioDolares, @PrecioBs, @VentasDolares, @VentasBs)";
			ejecutar = gcnew MySqlCommand(consulta, this->st);
			ejecutar->Parameters->AddWithValue("@COD", cod);
			ejecutar->Parameters->AddWithValue("@Descripcion", descripcion);
			ejecutar->Parameters->AddWithValue("@Cantidad", cantidad);
			ejecutar->Parameters->AddWithValue("@PrecioDolares", precioDolar);
			ejecutar->Parameters->AddWithValue("@PrecioBs", precioBs);
			ejecutar->Parameters->AddWithValue("@VentasDolares", ventasDolares);
			ejecutar->Parameters->AddWithValue("@VentasBs", ventasBs);
			ejecutar->ExecuteNonQuery(); // Ejecutar la consulta de inserción
		}
	}


	void obtenerDescripcionPrecios(int id, String^& descripcion, double& dolar, double& bs) {
		String^ consulta = "SELECT descripcion, Precio_$, Precio_BS FROM productos WHERE ID = @ID";
		MySqlCommand^ ejecutar = gcnew MySqlCommand(consulta, this->st);
		ejecutar->Parameters->AddWithValue("@ID", id);
		MySqlDataReader^ lector = ejecutar->ExecuteReader();

		if (lector->Read()) {
			descripcion = lector["descripcion"]->ToString();

			dolar = Convert::ToDouble(lector["Precio_$"]);

			bs = Convert::ToDouble(lector["Precio_BS"]);
		}
		lector->Close();

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




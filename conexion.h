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
	MySqlConnection^ lectura;
public:
	Conexion() {
		this->cn = "datasource=bukg4jrlxiqgc8y4hk8m-mysql.services.clever-cloud.com; username=ucxdkhcpecvfvvi7; password=SeOGUfOv8pDvCM5ROZC2; database=bukg4jrlxiqgc8y4hk8m;";
		this->st = gcnew MySqlConnection(this->cn);
		this->lectura = gcnew MySqlConnection(this->cn);
	}

public:
	void  abrirConexion() {
		this->st->Open();
	}
	void  cerrarConexion() {
		this->st->Close();
	}

	void TruncateTable() {  // ELminar los datos de las ventas totales por producto en la base de datos
			String^ query = "TRUNCATE ventasproductos";
			MySqlCommand^ command = gcnew MySqlCommand(query, st);
			st->Open();
			command->ExecuteNonQuery();
			st->Close();
	}

	void modificarCelda(int id, String^ modificacion, String^ nombreDeColumna, String^ nombreTabla) {
		// Construir la consulta SQL utilizando el nombre de la tabla, la columna y el valor
		String^ sentencia = "UPDATE " + nombreTabla + " SET " + nombreDeColumna + " = @modificacion WHERE ID = @id" ;
		MySqlCommand^ ejecutar = gcnew MySqlCommand(sentencia, this->st);
		ejecutar->Parameters->AddWithValue("@modificacion", modificacion);
		ejecutar->Parameters->AddWithValue("@id", id);
		this->st->Open();
		ejecutar->ExecuteNonQuery();
		this->st->Close();
	}



	void Insertar(String^ CI, String^ nombre, String^ apellido, String^ tlf) {
		String^ sentencia = "INSERT INTO cliente (CI, Nombre, Apellido, Tlf) VALUES (@CI, @Nombre, @Apellido, @Telefono)";
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
		String^ sentencia = "DELETE FROM cliente WHERE CI = @CI"; 
		MySqlCommand^ ejecutar = gcnew MySqlCommand(sentencia, this->st);
		ejecutar->Parameters->AddWithValue("@CI", CI);
		this->st->Open();
		ejecutar->ExecuteNonQuery();
		this->st->Close();
	}

	DataTable^ getData(String^ tableName)
	{
		// Construir la consulta SQL utilizando el parámetro tableName
		String^ sql = "SELECT * FROM " + tableName + " ORDER BY `Ventas Bs` DESC"; //ORDENAR DE MAYOR A MENOR LAS VENTAS BS
		MySqlCommand^ cursor = gcnew MySqlCommand(sql, this->lectura);
		MySqlDataAdapter^ data = gcnew MySqlDataAdapter(cursor);
		DataTable^ tabla = gcnew DataTable();
		data->Fill(tabla);
		return tabla;
	}

	DataTable^ baseDatos(String^ tableName) 
	{
		String^ sql = "select *from " + tableName;
		MySqlCommand^ cursor = gcnew MySqlCommand(sql, this->lectura);
		MySqlDataAdapter^ data = gcnew MySqlDataAdapter(cursor);
		DataTable^ tabla = gcnew DataTable();
		data->Fill(tabla);
		return tabla;
	}

	int obtenerIDCliente(DataTable^ clientes, int row) {
		if (row < clientes->Rows->Count) {
			DataRow^ fila = clientes->Rows[row];
			return Convert::ToInt32(fila["ID"]);
		}
		else {
			throw gcnew Exception("No hay más clientes");
		}
	}



	void datos(DataTable^ clientes, int id, Label^ nombreA, Label^ ci, Label^ tlf) {
		String^ filtro = "ID = " + id.ToString();
		array<DataRow^>^ filasFiltradas = clientes->Select(filtro);

		if (filasFiltradas->Length > 0) {
			DataRow^ fila = filasFiltradas[0];
			String^ nombre = fila["nombre"]->ToString();
			String^ apellido = fila["apellido"]->ToString();
			nombreA->Text = nombre + " " + apellido;
			String^ cedula = fila["CI"]->ToString();
			ci->Text = cedula;
			String^ telefono = fila["Tlf"]->ToString();
			tlf->Text = telefono;
		}
	}

	bool mostrarProductos(DataTable^ inventario, int id, Label^ nombreP, Label^ izqui, Label^ dere, int cantidad, double& montoTotal) {
		String^ filtro = "ID = " + id.ToString();
		array<DataRow^>^ filasFiltradas = inventario->Select(filtro);

		bool productoEncontrado = false; // Variable para indicar si el producto fue encontrado

		if (filasFiltradas->Length > 0) {
			DataRow^ fila = filasFiltradas[0];
			String^ producto = fila["descripcion"]->ToString();
			nombreP->Text = producto;

			String^ precioP = fila["Precio_BS"]->ToString();
			izqui->Text = cantidad + "x" + precioP;

			double precioNumerico = Double::Parse(precioP);
			double resultado = cantidad * precioNumerico;
			dere->Text = "Bs " + resultado.ToString("F2");

			montoTotal += resultado;
			productoEncontrado = true; // Producto encontrado
		}

		return productoEncontrado;
	}


	void reducirStock(int cod, int cantidadVendida) {     //REDUCE EL STOCK CUANDO EL CLIENTE COMPRA ALGUN PRODUCTO
		String^ consulta = "SELECT Stock FROM productos WHERE ID = @ID";
		MySqlCommand^ ejecutar = gcnew MySqlCommand(consulta, this->st);
		ejecutar->Parameters->AddWithValue("@ID", cod);

		MySqlDataReader^ lector = ejecutar->ExecuteReader();
		if (lector->Read()) {
			// Obtener el stock actual
			int stockActual = Convert::ToInt32(lector["Stock"]);
			int nuevoStock = stockActual - cantidadVendida;

			lector->Close(); // Cerrar el lector antes de ejecutar otra consulta

			// Actualizar el stock en la tabla productos
			consulta = "UPDATE productos SET Stock = @nuevoStock WHERE ID = @ID";
			ejecutar = gcnew MySqlCommand(consulta, this->st);
			ejecutar->Parameters->AddWithValue("@nuevoStock", nuevoStock);
			ejecutar->Parameters->AddWithValue("@ID", cod);
			ejecutar->ExecuteNonQuery(); // Ejecutar la consulta de actualización
		}
		else {
			lector->Close();
		}
	}


	void guardarCompras(DataTable^ baseDatosInventario, int cod, int cantidad, Label^ ventasT) {
		double ventasTotales = Convert::ToDouble(ventasT->Text);
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
			ventasTotales += ventasBs;
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

			// Reducir el stock del producto
			reducirStock(cod, cantidad);
		}
		else {
			lector->Close(); // Cerrar el lector antes de ejecutar otra consulta

			// Variables para almacenar los datos obtenidos de la base de datos
			String^ descripcion = nullptr;
			double precioDolar = 0;
			double precioBs = 0;

			// Obtener descripción y precios desde la tabla productos
			obtenerDescripcionPrecios(baseDatosInventario, cod, descripcion, precioDolar, precioBs);

			// Calcular las ventas
			double ventasBs = precioBs * cantidad;
			ventasTotales += ventasBs;
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

			// Reducir el stock del producto
			reducirStock(cod, cantidad);
		}
		ventasT->Invoke(gcnew Action<Label^, double>(this, &Conexion::ActualizarVentasTotales), ventasT, ventasTotales);
	}

	void ActualizarVentasTotales(Label^ ventasT, double ventasTotales) {
		if (ventasT->InvokeRequired) {
			ventasT->Invoke(gcnew Action<Label^, double>(this, &Conexion::ActualizarVentasTotales), ventasT, ventasTotales);
		}
		else {
			ventasT->Text = ventasTotales.ToString("F2");
		}
	}

	void obtenerDescripcionPrecios(DataTable^ inventario, int id, String^% descripcion, double% dolar, double% bs) {
		String^ filtro = "ID = " + id.ToString();
		array<DataRow^>^ filasFiltradas = inventario->Select(filtro);

		if (filasFiltradas->Length > 0) {
			DataRow^ fila = filasFiltradas[0];
			descripcion = fila["descripcion"]->ToString();
			dolar = Convert::ToDouble(fila["Precio_$"]);
			bs = Convert::ToDouble(fila["Precio_BS"]);
		}
		else {
			throw gcnew Exception("Producto no encontrado en el inventario.");
		}
	}




};




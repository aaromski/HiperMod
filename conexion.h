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
	MySqlConnection^ escritura;
	MySqlConnection^ escritura2;
	MySqlConnection^ baseinventario;
	MySqlConnection^ ventasProductos;
public:
	Conexion() {
		this->cn = "datasource=bukg4jrlxiqgc8y4hk8m-mysql.services.clever-cloud.com; username=ucxdkhcpecvfvvi7; password=SeOGUfOv8pDvCM5ROZC2; database=bukg4jrlxiqgc8y4hk8m;";
		this->st = gcnew MySqlConnection(this->cn);
		this->escritura = gcnew MySqlConnection(this->cn);
		this->escritura2 = gcnew MySqlConnection(this->cn);
		this->baseinventario = gcnew MySqlConnection(this->cn);
		this->ventasProductos = gcnew MySqlConnection(this->cn);
	}

public:

	void abrirConexion(MySqlConnection^ conexion) {
		if (conexion->State != System::Data::ConnectionState::Open) {
			conexion->Open();
		}
	}

	void cerrarConexion(MySqlConnection^ conexion) {
		if (conexion->State == System::Data::ConnectionState::Open) {
			conexion->Close();
		}
	}

	bool HayDataReaderAbierto(MySqlConnection^ conexion) {
		if (conexion->State == System::Data::ConnectionState::Open) {
			try {
				MySqlCommand^ verificarCommand = gcnew MySqlCommand("SELECT 1", conexion);
				MySqlDataReader^ lector = verificarCommand->ExecuteReader();
				lector->Close();
				return false;
			}
			catch (MySqlException^) {
				return true;
			}
		}
		return false;
	}


	MySqlConnection^ ObtenerConexionDisponible() {
		if (HayDataReaderAbierto(escritura)) {
			return escritura2;
		}
		else if (HayDataReaderAbierto(escritura2)) {
			return st;
		}
		return escritura;
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

		try {
			this->st->Open();
			ejecutar->ExecuteNonQuery();
		}
		catch (MySqlException^) {
				MessageBox::Show("La entrada ya existe en la base de datos. No se pueden ingresar claves duplicadas.", "Error de Duplicación", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			if (this->st->State == ConnectionState::Open) {
				this->st->Close();
			}
		}
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
		int intentos = 3;
		while (intentos > 0) {
			try {
				// Construir la consulta SQL utilizando el parámetro tableName
				abrirConexion(ventasProductos);
				String^ sql = "SELECT * FROM " + tableName + " ORDER BY `Ventas Bs` DESC"; //ORDENAR DE MAYOR A MENOR LAS VENTAS BS
				MySqlCommand^ cursor = gcnew MySqlCommand(sql, ventasProductos);
				MySqlDataAdapter^ data = gcnew MySqlDataAdapter(cursor);
				DataTable^ tabla = gcnew DataTable();
				data->Fill(tabla);
				cerrarConexion(ventasProductos);
				return tabla;
			}
			catch (MySqlException^) {
				intentos--;
			}
			finally {
				// Asegurar que la conexión se cierre
				if (ventasProductos->State == System::Data::ConnectionState::Open) {
					cerrarConexion(ventasProductos);
				}
			}
		}
		// Si llegamos aquí, todos los intentos fallaron
		throw gcnew InvalidOperationException("No se pudo obtener la tabla después de múltiples intentos.");
	}

	DataTable^ baseDatos(String^ tableName) {
		int retryCount = 3; // Número de reintentos
		while (retryCount > 0) {
			try {
				// Construir la consulta SQL utilizando el parámetro tableName
				abrirConexion(baseinventario);
				String^ sql = "SELECT * FROM " + tableName;
				MySqlCommand^ cursor = gcnew MySqlCommand(sql, baseinventario);
				MySqlDataAdapter^ data = gcnew MySqlDataAdapter(cursor);
				DataTable^ tabla = gcnew DataTable();
				data->Fill(tabla);
				cerrarConexion(baseinventario);
				return tabla;
			}
			catch (MySqlException^) {
				// Registrar el error y decrementar el contador de reintentos
				retryCount--;
			}
			finally {
				// Asegurar que la conexión se cierre
				if (baseinventario->State == System::Data::ConnectionState::Open) {
					cerrarConexion(baseinventario);
				}
			}
		}
		// Si llegamos aquí, todos los intentos fallaron
		throw gcnew InvalidOperationException("No se pudo obtener la tabla después de múltiples intentos.");
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


	void reducirStock(int cod, int cantidadVendida, MySqlConnection^ Conexion) {
		String^ consulta = "SELECT Stock FROM productos WHERE ID = @ID";
		MySqlCommand^ ejecutar = gcnew MySqlCommand(consulta, Conexion);
		ejecutar->Parameters->AddWithValue("@ID", cod);

		MySqlDataReader^ lector = nullptr;
		try {
			lector = ejecutar->ExecuteReader();
			if (lector->Read()) {
				int stockActual = Convert::ToInt32(lector["Stock"]);
				int nuevoStock = stockActual - cantidadVendida;

				lector->Close(); // Cerrar el lector antes de ejecutar otra consulta
				lector = nullptr; // Evitar cerrar dos veces

				consulta = "UPDATE productos SET Stock = @nuevoStock WHERE ID = @ID";
				ejecutar = gcnew MySqlCommand(consulta, Conexion);
				ejecutar->Parameters->AddWithValue("@nuevoStock", nuevoStock);
				ejecutar->Parameters->AddWithValue("@ID", cod);
				ejecutar->ExecuteNonQuery();
			}
		}
		finally {
			if (lector != nullptr) {
				lector->Close();
			}
		}
	}

	void guardarCompras(DataTable^ baseDatosInventario, int cod, int cantidad, Label^ ventasT, MySqlConnection^ Conexion) {
		double ventasTotales = 0;
		ventasTotales = Convert::ToDouble(ventasT->Text);
		String^ consulta = "SELECT * FROM ventasproductos WHERE COD = @COD";
		MySqlCommand^ ejecutar = gcnew MySqlCommand(consulta, Conexion);
		ejecutar->Parameters->AddWithValue("@COD", cod);

		int intentos = 3; // Número de reintentos
		bool exito = false;
		while (intentos > 0 && !exito) {
			MySqlDataReader^ lector = nullptr;
			try {
				if (Conexion->State != ConnectionState::Open) {
					Conexion->Open();
				}

				lector = ejecutar->ExecuteReader();
				if (lector->Read()) {
					// El producto existe, actualizar la cantidad
					int cantidadActual = Convert::ToInt32(lector["Cantidad"]);
					int nuevaCantidad = cantidadActual + cantidad;
					double precioBs = Convert::ToDouble(lector["Precio Bs"]);
					double ventasBs = precioBs * cantidad;
					ventasTotales += ventasBs;
					ventasBs = precioBs * nuevaCantidad;
					double precioDolares = Convert::ToDouble(lector["Precio $"]);
					double ventasDolares = precioDolares * nuevaCantidad;

					lector->Close();
					lector = nullptr;
					// Actualizar la cantidad y ventas
					consulta = "UPDATE ventasproductos SET Cantidad = @nuevaCantidad, `Ventas $` = @ventasDolares, `Ventas Bs` = @ventasBs WHERE Cod = @COD";
					ejecutar = gcnew MySqlCommand(consulta, Conexion);
					ejecutar->Parameters->AddWithValue("@nuevaCantidad", nuevaCantidad);
					ejecutar->Parameters->AddWithValue("@ventasDolares", ventasDolares);
					ejecutar->Parameters->AddWithValue("@ventasBs", ventasBs);
					ejecutar->Parameters->AddWithValue("@COD", cod);
					ejecutar->ExecuteNonQuery();

					// Reducir el stock del producto
					reducirStock(cod, cantidad, Conexion);
				}
				else {
					lector->Close();
					lector = nullptr;
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
					ejecutar = gcnew MySqlCommand(consulta, Conexion);
					ejecutar->Parameters->AddWithValue("@COD", cod);
					ejecutar->Parameters->AddWithValue("@Descripcion", descripcion);
					ejecutar->Parameters->AddWithValue("@Cantidad", cantidad);
					ejecutar->Parameters->AddWithValue("@PrecioDolares", precioDolar);
					ejecutar->Parameters->AddWithValue("@PrecioBs", precioBs);
					ejecutar->Parameters->AddWithValue("@VentasDolares", ventasDolares);
					ejecutar->Parameters->AddWithValue("@VentasBs", ventasBs);
					ejecutar->ExecuteNonQuery();

					// Reducir el stock del producto
					reducirStock(cod, cantidad, Conexion);
				}
				exito = true; // Marcar éxito si no hay excepciones
			}
			catch (MySqlException^) {
				intentos--;
			}
			finally {
				if (lector != nullptr) {
					lector->Close();
				}
				if (Conexion->State == ConnectionState::Open) {
					Conexion->Close();
				}
			}
		}

		if (!exito) {
			MessageBox::Show("No se pudo completar la operación después de múltiples intentos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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




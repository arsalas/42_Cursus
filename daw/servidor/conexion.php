<?php

function crearConexion()
{
	// Cambiar en el caso en que se monte la base de datos en otro lugar
	$driver = "mysql";
	$host = "localhost";
	$user = "root";
	$pass = "";
	$baseDatos = "pac3_daw";
	$charset = "utf8";
	$options = [
		PDO::ATTR_EMULATE_PREPARES   => false, // turn off emulation mode for "real" prepared statements
		PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION, //turn on errors in the form of exceptions
		PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_OBJ, //make the default fetch be an associative array
	];

	try {
		$pdo = new PDO("{$driver}:host={$host};dbname={$baseDatos};charset={$charset}", $user, $pass, $options);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		return $pdo;
	} catch (PDOException $e) {
		die($e->getMessage());
	}
}


function cerrarConexion($conexion)
{
	$conexion = null;
}

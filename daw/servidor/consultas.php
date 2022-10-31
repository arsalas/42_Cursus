<?php

include "conexion.php";

function tipoUsuario($nombre, $correo)
{
	try {
		$pdo = crearConexion();
		$query = "SELECT * FROM user WHERE FullName = :name AND Email = :email";
		$stmt = $pdo->prepare($query);
		$stmt->bindParam(':name', $nombre);
		$stmt->bindParam(':email', $correo);
		$stmt->execute();
		$result = $stmt->fetchAll();
		if (count($result) > 0) return $result[0];
		else return false;
	} catch (PDOException $e) {
		return false;
	} finally {
		cerrarConexion($pdo);
	}
}


function esSuperadmin($nombre, $correo)
{
	$pdo = crearConexion();
	$query = "SELECT t1.*, t2.SuperAdmin
		FROM pac3_daw.user t1
		LEFT JOIN pac3_daw.setup t2 ON t1.UserID = t2.SuperAdmin
		WHERE FullName = :name AND Email = :email;";
	$stmt = $pdo->prepare($query);
	$stmt->bindParam(':name', $nombre);
	$stmt->bindParam(':email', $correo);
	$stmt->execute();
	$result = $stmt->fetchAll();
	if (isset($result[0]->SuperAdmin)) return true;
	else return false;
}


function getPermisos()
{
	try {
		$pdo = crearConexion();
		$query = "SELECT Autenticación AS auth FROM setup";
		$stmt = $pdo->prepare($query);
		$stmt->execute();
		$result = $stmt->fetchAll();
		if ($result && count($result) === 1) return $result[0]->auth;
		else return false;
	} catch (PDOException $e) {
		return false;
	} finally {
		cerrarConexion($pdo);
	}
}


function cambiarPermisos()
{
	try {
		$pdo = crearConexion();
		$query = "UPDATE setup SET Autenticación = IF(Autenticación = 1, 0, 1)";
		$stmt = $pdo->prepare($query);
		$result = $stmt->execute();
		return $result;
	} catch (PDOException $e) {
		return false;
	} finally {
		cerrarConexion($pdo);
	}
}


function getCategorias()
{
	try {
		$pdo = crearConexion();
		$query = "SELECT * FROM category";
		$stmt = $pdo->prepare($query);
		$stmt->execute();
		$result = $stmt->fetchAll();
		return $result;
	} catch (PDOException $e) {
		return false;
	} finally {
		cerrarConexion($pdo);
	}
}


function getListaUsuarios()
{
	try {
		$pdo = crearConexion();
		$query = "SELECT * FROM user";
		$stmt = $pdo->prepare($query);
		$stmt->execute();
		$result = $stmt->fetchAll();
		return $result;
	} catch (PDOException $e) {
		return false;
	} finally {
		cerrarConexion($pdo);
	}
}


function getProducto($ID)
{
	try {
		$pdo = crearConexion();
		$query = "SELECT * FROM product WHERE ProductID = :id";
		$stmt = $pdo->prepare($query);
		$stmt->bindParam(':id', $ID);
		$stmt->execute();
		$result = $stmt->fetchAll();
		if (count($result) === 1) return $result[0];
		else return [];
	} catch (PDOException $e) {
		return false;
	} finally {
		cerrarConexion($pdo);
	}
}


function getProductos($orden)
{
	try {
		$pdo = crearConexion();
		$query = "SELECT t1.*, t2.Name AS category 
		FROM product t1 
		INNER JOIN category t2 ON t1.CategoryID = t2.CategoryID 
		ORDER BY $orden ASC";
		$stmt = $pdo->prepare($query);
		$stmt->execute();
		$result = $stmt->fetchAll();
		return $result;
	} catch (PDOException $e) {
		return false;
	} finally {
		cerrarConexion($pdo);
	}
}


function anadirProducto($nombre, $coste, $precio, $categoria)
{
	try {
		$pdo = crearConexion();
		$query = "INSERT INTO product (Name, Cost, Price, CategoryID) VALUES (:name, :cost, :price, :category)";
		$stmt = $pdo->prepare($query);
		$stmt->bindParam(':name', $nombre);
		$stmt->bindParam(':cost', $coste);
		$stmt->bindParam(':price', $precio);
		$stmt->bindParam(':category', $categoria);
		$result = $stmt->execute();
		return $result;
	} catch (PDOException $e) {
		return false;
	} finally {
		cerrarConexion($pdo);
	}
}


function borrarProducto($id)
{
	try {
		$pdo = crearConexion();
		$query = "DELETE FROM product WHERE ProductID = :id";
		$stmt = $pdo->prepare($query);
		$stmt->bindParam(':id', $id);
		$result = $stmt->execute();
		return $result;
	} catch (PDOException $e) {
		return false;
	} finally {
		cerrarConexion($pdo);
	}
}


function editarProducto($id, $nombre, $coste, $precio, $categoria)
{
	try {
		$pdo = crearConexion();
		$query = "UPDATE product SET Name = :name, Cost = :cost, Price = :price, CategoryID = :idcategory WHERE ProductID = :id";
		$stmt = $pdo->prepare($query);
		$stmt->bindParam(':name', $nombre);
		$stmt->bindParam(':cost', $coste);
		$stmt->bindParam(':price', $precio);
		$stmt->bindParam(':idcategory', $categoria);
		$stmt->bindParam(':id', $id);
		$result = $stmt->execute();
		return $result;
	} catch (PDOException $e) {
		return false;
	} finally {
		cerrarConexion($pdo);
	}
}

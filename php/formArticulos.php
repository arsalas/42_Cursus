<?php
// formArticulo.php: contiene el formulario que permitirá realizar gestiones sobre los 
// productos. 
// => Comprobará si el acceso a esta página se ha hecho por un usuario que tiene 
// los permisos suficientes, comprobando la cookie creada en index.php. 
// => En el caso de venir al formulario para Añadir, mostrará un formulario vacío y 
// el botón de Añadir. Al completar todos los datos y pulsar sobre el botón, se 
// añadirá  el  producto  a  la  base  de  datos  y  mostrará  un  mensaje  de  que  el 
// producto se ha añadido. 
// => En el caso de venir al formulario para Editar, mostrará el formulario completo 
// con los datos del producto que se va a editar y el botón de Editar. Al realizar 
// las modificaciones y pulsar sobre el botón, se modificará el producto en la 
// base de datos y mostrará un mensaje de que el producto se ha modificado. 
// => En caso de venir al formulario para Borrar, mostrará el formulario completo 
// con los datos del producto que se va a borrar y el botón de Borrar. Al pulsar 
// sobre el botón, se eliminará el producto de la base de datos y mostrará un 
// mensaje de que le producto se ha borrado. 
// => Tendrá un enlace que permitirá volver a articulos.php. 
?>
<!DOCTYPE html>
<html>

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.3/css/bulma.min.css">
	<link rel="stylesheet" type="text/css" href="estilo.css">

	<title>Formulario de artículos</title>
</head>

<body>
	<!-- TODO: Comprobar la cookie de permisos -->
	<?php include "funciones.php";

	switch ($_GET['action']) {
		case 'new':
			$title = "Nuevo articulo";
			break;
		case 'edit':
			$title = "Editar articulo";
			break;
		case 'delete':
			$title = "Borrar articulo";
			break;
		default:
			$title = "";
			break;
	}

	// Comprobar si se han enviado datos por POST al completar el formulario
	if (isset($_POST['name']) && isset($_POST['cost']) && isset($_POST['price']) && isset($_POST['category'])) {

		// Editar
		if ($_GET['action'] === "edit") {
			$result = editarProducto($_GET['id'], $_POST['name'], $_POST['cost'], $_POST['price'], $_POST['category']);
			if ($result) $message = "Producto modificado";
			else $message = "El producto no se ha podido modificar";
		} else if ($_GET['action'] === "new") {
			$result = anadirProducto($_POST['name'], $_POST['cost'], $_POST['price'], $_POST['category']);
			if ($result) $message = "Producto añadido";
			else $message = "El producto no se ha podido añadir";
		} else if ($_GET['action'] === "delete") {
			$result = borrarProducto($_GET['id']);
			if ($result) $message = "Producto eliminado";
			else $message = "El producto no se ha podido eliminar";
		}
	?>
		<div><?= $message ?></div>
	<?php
	} else {
		if ($_GET['action'] === "edit" || $_GET['action'] === "delete") $product = getProducto($_GET['id']);
		else {
			$product = new stdClass();
			$product->Name = "";
			$product->Cost = 0;
			$product->Price = 0;
			$product->CategoryID = 1;
		}
	?>

		<div class="container-app">
			<div class="container">

				<nav class="breadcrumb" aria-label="breadcrumbs">
					<ul>
						<li><a href="articulos.php">Lista de artículos</a></li>
						<li class="is-active"><a href="#" aria-current="page"><?= $title ?></a></li>
					</ul>
				</nav>

				<form action="formArticulos.php?action=<?= $_GET['action'] ?><?= isset($_GET['id']) ? "&id={$_GET['id']}" : ""  ?>" method="POST">
					<div class="field">
						<label class="label">Nombre</label>
						<div class="control">
							<input name="name" class="input" value="<?= $product->Name ?>" type="text" placeholder="Nombre">
						</div>
					</div>
					<div class="field">
						<label class="label">Coste</label>
						<div class="control">
							<input name="cost" class="input" value="<?= $product->Cost ?>" type="number" step='0.01'>
						</div>
					</div>
					<div class="field">
						<label class="label">Precio</label>
						<div class="control">
							<input name="price" class="input" value="<?= $product->Price ?>" type="number" step='0.01'>
						</div>
					</div>
					<div class="field">
						<label class="label">Categoria</label>
						<div class="select">
							<?php pintaCategorias($product->CategoryID) ?>
						</div>
					</div>
					<div class="field">
						<?php if ($_GET['action'] === "edit") : ?>
							<button type="submit" class="button is-success"> Guardar</button>
						<?php elseif ($_GET['action'] === "new") : ?>
							<button type="submit" class="button is-info"> Añadir</button>
						<?php elseif ($_GET['action'] === "delete") : ?>
							<button type="submit" class="button is-danger"> Borrar</button>
						<?php endif; ?>
					</div>
				</form>
			</div>
		</div>

	<?php }	?>

</body>

</html>
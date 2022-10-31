<?php
// articulos.php:  contiene  el  sistema  de  control  sobre  los  productos  del  stock  de  la 
// tienda. Tendrá las siguientes características: 
// => Comprobará si el acceso a esta página se ha hecho por un usuario que tiene 
// los permisos suficientes, comprobando la cookie creada en index.php. 
// => Mostrará una tabla con los datos de todos los productos almacenados con 
// las siguientes columnas: ID, Nombre, Coste, Precio, Categoría y Acciones. 
// => Al  pulsar  sobre  el  título  de  cada  columna  (excepto  Acciones),  permitirá 
// ordenar  de  menor  a  mayor  el  contenido  de  la  tabla  basándose  en  el 
// parámetro que se ha pulsado. 
// => En el caso de que estén los permisos de la aplicación activados, aparecerán 
// también las siguientes opciones: 
// ▪ Un enlace para añadir un producto que lleva a formArticulo.php. 
// ▪ Un  enlace  junto  a  cada  producto  que  permite  editarlo  y  lleva  a 
// formArticulo.php 
// ▪ Un  enlace  junto  a  cada  producto  que  permite  borrarlo  y  lleva  a 
// formArticulo.php. 
// => Tendrá un enlace que permitirá volver a index.php. 
?>
<!DOCTYPE html>
<html>

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.3/css/bulma.min.css">
	<link rel="stylesheet" type="text/css" href="estilo.css">
	<title>Articulos</title>
</head>

<body>
	<?php include "funciones.php";
	if ($_COOKIE["user"] !== "authorized") header("Location: index.php");
	if (isset($_GET['order'])) $order = $_GET['order'];
	else $order = "ProductID";
	?>
	<div class="container-app">

		<div class="container">
			<nav class="breadcrumb" aria-label="breadcrumbs">
				<!-- <h1 class="is-size-3">Lista de artículos</h1> -->
				<ul>
					<li><a href="index.php">Indice</a></li>
					<li class="is-active"><a href="#" aria-current="page">Lista de artículos</a></li>
				</ul>
			</nav>
			<!-- <h1 class="is-size-3">Lista de artículos</h1>
			<a href="index.php">Volver a indice</a> -->
			<?php pintaProductos($order); ?>
		</div>
	</div>
</body>

</html>
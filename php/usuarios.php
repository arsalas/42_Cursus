<!DOCTYPE html>
<html>

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" href="estilo.css">
	<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.3/css/bulma.min.css">

	<title>Usuarios</title>
</head>

<body>

	<?php
	// 	usuarios.php:  contiene  el  sistema  de  control  sobre  los  permisos  de  los  usuarios 
	// 	autorizados  y  muestra  el  listado  de  todos  los  usuarios  registrados.  Tendrá  las 
	// 	siguientes características: 
	// 	Comprobará si el acceso a esta página se ha hecho por un usuario que tiene 
	// los permisos suficientes, comprobando la cookie creada en index.php. 
	// => Indicará el valor almacenado en la base de datos con los permisos actuales 
	// de la aplicación. 
	// => Tendrá un botón que, al pulsar sobre él, cambiará el valor de los permisos de 
	// la aplicación. 
	// => Mostrará  una  tabla  con  los  datos  de  todos  los  usuarios  registrados  en  la 
	// aplicación con las siguientes columnas: Nombre, Email y Autorizado. 
	// => En aquellos usuarios que estén autorizados, cambiará el color de fondo de la 
	// columna de Autorizado. 
	// => Tendrá un enlace que permitirá volver a index.php. 

	include "funciones.php";
	if (isset($_POST["action"]))  cambiarPermisos(); ?>
	<div class="container-app">
		<div class="container">
			<nav class="breadcrumb" aria-label="breadcrumbs">
				<ul>
					<li><a href="index.php">Indice</a></li>
					<li class="is-active"><a href="#" aria-current="page">Lista de usuarios</a></li>
				</ul>
			</nav>

			<?php if (getPermisos()) : ?>
				<div class="notification is-link is-success is-light">
					La aplicación tiene permisos
				</div>
			<?php else : ?>
				<div class="notification is-link is-danger is-light">
					La aplicación no tiene permisos
				</div>
			<?php endif ?>

			<div>
				<form action="usuarios.php" method="POST">
					<input name="action" value="auth" style="display:none">
					<div class="field">
						<?php if (getPermisos()) : ?>
							<button type="submit" class="button is-danger">Desactivar permisos</button>
						<?php else : ?>
							<button type="submit" class="button is-success">Activar permisos</button>
						<?php endif ?>

					</div>
				</form>
			</div>
			<br />
			<?php pintaTablaUsuarios(); ?>
		</div>
	</div>

</body>

</html>
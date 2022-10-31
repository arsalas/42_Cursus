<?php

include "consultas.php";


function pintaCategorias($defecto)
{
	$categories = getCategorias(); ?>
	<select name="category">
		<?php foreach ($categories as $category) : ?>
			<option value="<?= $category->CategoryID ?>" <?php if ($defecto === $category->CategoryID) echo " selected" ?> ><?= $category->Name ?></option>
		<?php endforeach; ?>
	</select>
<?php
}


function pintaTablaUsuarios()
{
	$users = getListaUsuarios(); ?>
	<table class="table is-bordered is-striped is-narrow is-fullwidth">
		<thead>
			<tr>
				<th>Nombre</th>
				<th>Email</th>
				<th>Autorizado</th>
			</tr>
		</thead>
		<tbody>
			<?php foreach ($users as $user) : ?>
				<tr <?php if ($user->Enabled) echo 'class="has-background-success"' ?>>
					<td><?= $user->FullName ?></td>
					<td><?= $user->Email ?></td>
					<td><?= $user->Enabled ?></td>
				</tr>
			<?php endforeach ?>
		</tbody>
	</table>
<?php }

function pintaProductos($orden)
{
	$products = getProductos($orden);
	$auth = getPermisos();
?>
	<table class="table is-bordered is-striped is-narrow is-fullwidth">
		<thead>
			<tr>
				<th><a href="articulos.php">ID</a></th>
				<th><a href="articulos.php?order=Name">Nombre</a></th>
				<th><a href="articulos.php?order=Cost">Coste</a></th>
				<th><a href="articulos.php?order=Price">Precio</a></th>
				<th><a href="articulos.php?order=CategoryID">Categoría</a></th>
				<th>Acciones</th>
			</tr>
		</thead>
		<tbody>
			<?php foreach ($products as $prod) : ?>
				<tr>
					<td><?= $prod->ProductID ?></td>
					<td><?= $prod->Name ?></td>
					<td><?= $prod->Cost ?></td>
					<td><?= $prod->Price ?></td>
					<td><?= $prod->category ?></td>
					<td>
						<?php if ($auth) : ?>
							<a href="formArticulos.php?action=edit&id=<?= $prod->ProductID ?>" class="button is-success is-small">Editar</a>
							<a href="formArticulos.php?action=delete&id=<?= $prod->ProductID ?>" class="button is-danger is-small">Borrar</a>
						<?php endif ?>
					</td>
				</tr>
			<?php endforeach ?>
		</tbody>
	</table>
<?php } ?>
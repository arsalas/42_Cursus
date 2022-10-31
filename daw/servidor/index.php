<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.3/css/bulma.min.css">
    <link rel="stylesheet" type="text/css" href="estilo.css">
    <title>Index.php</title>
</head>

<body>
    <div style="height:100vh; width:100vw; background-color:#eee; display:flex; justify-content:center; align-items:center">

        <?php
        // index.php:  contiene  el  sistema  de  acceso  a  la  aplicación  mediante  el  nombre  de 
        // usuario y su dirección de correo electrónico. En este fichero se deberá comprobar 
        // qué tipo de usuario es y permitir el acceso a la aplicación: 
        // => En caso de ser superadmin, mostrará su nombre y mostrará un enlace para 
        // acceder a usuarios.php 
        // => En  caso  de  ser  un  usuario  autorizado,  mostrará  su  nombre  y  mostrará  un 
        // enlace para acceder a articulos.php 
        // => En  caso  de  ser  un  usuario  registrado,  pero  no  autorizado,  mostrará  su 
        // nombre e indicará que no tiene permisos para acceder. 
        // => En  caso  de  que  sea  un  usuario  no  registrado  o  se  introduzcan  unos  datos 
        // incorrectos, indicará que el usuario no está registrado. 
        // => Almacenará en una cookie el tipo de usuario que ha intentado registrarse. 
        include "consultas.php";

        // Comprobar si tiene los valores del formulario
        if (isset($_POST["name"]) && $_POST["email"]) :
            $user = tipoUsuario($_POST["name"], $_POST["email"]);
            if (!$user) :
                // Si el usuario no existe
                unset($_COOKIE['user']); ?>
                <div class="notification is-danger is-light">
                    El usuario no esta registrado
                </div>
            <?php elseif (esSuperadmin($_POST["name"], $_POST["email"])) :
                // Si el usuario es superadmin
                setcookie("user", "superadmin");
            ?>
                <div class="notification is-warning is-light">
                    <?= $user->FullName ?>
                    <div><a href="usuarios.php">Usuarios</a></div>
                </div>
            <?php
            elseif ($user->Enabled === 0) :
                setcookie("user", "registered"); ?>
                <div class="notification is-warning is-light">
                    <?= $user->FullName ?> no tiene permisos para acceder
                </div> <?php
                    else :
                        setcookie("user", "authorized");
                        ?>
                <div class="notification is-warning is-light">
                    Autorizado
                    <div><a href="articulos.php">Articulos</a></div>

                </div>
            <?php endif;
                else : ?>
            <div class="box" style="min-width: 25%">
                <form method="post" action="">
                    <div class="field">
                        <label class="label">Nombre de usuario</label>
                        <div class="control">
                            <input name="name" class="input" type="text" placeholder="Nombre de usuario">
                        </div>
                    </div>
                    <div class="field">
                        <label class="label">Correo electrónico</label>
                        <div class="control">
                            <input name="email" class="input" type="email" placeholder="Correo electrónico">
                        </div>
                    </div>
                    <div class="field ">
                        <div class="control">
                            <button type="submit" class="button is-link is-fullwidth">Login</button>
                        </div>
                    </div>
                </form>
            </div>
        <?php endif ?>
    </div>
</body>

</html>
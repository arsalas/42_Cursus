#!/bin/sh
# Iniciamos mysql para poder ejecutar comandos (si no ponemos el ; no lee bien el comando)
service mysql start;
# Creamos la tabla a partir de las variables de entorno
mysql -e "CREATE DATABASE IF NOT EXISTS ${SQL_DATABASE};"
# Creamos un usuario
mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
# Damos derechos al usuario
mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
# Recargarmos la tabla de privilegios
mysql -e "FLUSH PRIVILEGES;"
# Cambiamos el usuario root
# mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
# Cerramos mysql
# mysqladmin -u root shutdown;
# service mysql restart;
# Comando para iniciar mysql y que no se cierre el programa
# exec mysqld_safe
# Paramos mysql
service mysql stop;
# Ejecutamos el mysqld --bind-address=0.0.0.0 que tenemos en el CMD del Dockerfile
exec "$@"
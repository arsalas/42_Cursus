#!/bin/sh

# Iniciamos mysql para poder ejecutar comandos
service mysql start;

# Creamos la tabla a partir de las variables de entorno
mysql -e "CREATE DATABASE IF NOT EXIST \`${SQL_DATABASE}\`;"

# Creamos un usuario
mysql -e "CREATE USER IF NOT EXIST \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"

# Damos derechos al usuario
mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"

# Cambiamos el usuario root
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"

# Recargarmos para que se apliquen los cambios
mysql -e "FLUSH PRIVILIEGES;"

# Cerramos mysql
mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown

# Comando recomendado para mysql
exec mysqld_safe


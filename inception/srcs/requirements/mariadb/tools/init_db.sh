#!/bin/sh
# Iniciamos mysql para poder ejecutar comandos (si no ponemos el ; no lee bien el comando)
service mysql start;
# Creamos la tabla a partir de las variables de entorno
mysql -e "CREATE DATABASE IF NOT EXISTS ${DB_DATABASE};"
# Creamos un usuario
mysql -e "CREATE USER IF NOT EXISTS \`${DB_USER}\`@'%' IDENTIFIED BY '${DB_PASSWORD}';"
# Damos derechos al usuario
mysql -e "GRANT ALL PRIVILEGES ON \`${DB_DATABASE}\`.* TO \`${DB_USER}\`@'%' IDENTIFIED BY '${DB_PASSWORD}';"
# Recargarmos la tabla de privilegios
mysql -e "FLUSH PRIVILEGES;"
# Paramos mysql
service mysql stop;
# Ejecutamos el mysqld --bind-address=0.0.0.0 que tenemos en el CMD del Dockerfile
exec "$@"
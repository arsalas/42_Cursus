#!/bin/sh
# Iniciamos mysql para poder ejecutar comandos (si no ponemos el ; no lee bien el comando)
service mysql start;
# Creamos la tabla a partir de las variables de entorno
mysql -e "CREATE DATABASE IF NOT EXISTS ${DB_DATABASE};"
# Creamos un usuario
mysql -e "CREATE USER IF NOT EXISTS \`${DB_USER}\`@'%' IDENTIFIED BY '${DB_PASSWORD}';"
# Damos derechos al usuario
mysql -e "GRANT ALL PRIVILEGES ON \`${DB_DATABASE}\`.* TO \`${DB_USER}\`@'%' IDENTIFIED BY '${DB_PASSWORD}';"
# Le damos un password al root
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';"
# Recargarmos la tabla de privilegios
mysql -e "FLUSH PRIVILEGES;"
# Cerramos el usuario root (con -p indicamos el password del usuario, tiene que ser -p seguido del pass sin espacios)
mysqladmin -u root -p$DB_ROOT_PASSWORD shutdown
# Paramos mysql
service mysql stop;
# Ejecutamos el mysqld --bind-address=0.0.0.0 que tenemos en el CMD del Dockerfile
exec "$@"
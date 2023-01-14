#!/bin/bash

# Indicamos que vamos a escuchar en el puerto 9000 para wordpress
sed -i "s/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/" "/etc/php/7.3/fpm/pool.d/www.conf"
chown -R www-data:www-data /var/www/*
chown -R 755 /var/www/*
mkdir -p /run/php/
touch /run/php/php7.3-fpm.pid

# Comprobamos si existe el archivo de configuracion, si no existe hemos de instalar y configurar wordpress
if [ ! -f /var/www/html/wp-config.php ]; then
	echo "Wordpress: setting up..."
	mkdir -p /var/www/html
	# Descargamos el cli de wordpress para la instalacion y configuracion por terminal
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp
	cd /var/www/html
	# Descargamos wordpress
	wp core download --allow-root
	# Creamos la configuracion de wordpress indicandole la base de datos
	echo "Wordpress: creating config..."
	wp config create --allow-root --dbname=${DB_DATABASE} --dbuser=${DB_USER} --dbpass=${DB_PASSWORD} --dbhost=mariadb:3306
	echo "Wordpress: creating users..."
	# Creamos al usuario root de wordpress
	wp core install --allow-root --url=${DOMAIN_NAME} --title=${WP_TITLE} --admin_user=${WP_ADMIN_USR} --admin_password=${WP_ADMIN_PWD} --admin_email=${WP_ADMIN_EMAIL}
	# Creamos otro usuario
	wp user create --allow-root ${WP_USR} ${WP_EMAIL} --user_pass=${WP_PWD}
	echo "Wordpress: is ready!"
fi

exec "$@"

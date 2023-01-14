FROM debian:buster

# Actualizamos el gestor de paquetes
RUN apt-get update

# Instalamos los pacquetes necesarios
RUN apt-get -y install php7.3 php-mysql php-fpm mariadb-server wget

# Exponemos el puerto 9000 que es donde estara wordpress
EXPOSE 9000

# Copiamos los archivos de configuracion
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d

# Copiamos el script para iniciar wordpress
COPY ./tools/wordpress_start.sh /var/www/

# Damos permisos de ejecucion al script
RUN chmod +x /var/www/wordpress_start.sh

# Indicamos que iniciaremos el contenedor ejecutando el script de instalacion
ENTRYPOINT [ "/var/www/wordpress_start.sh" ]

# El comado que usaremos para que no se cierre el contenedor
CMD ["/usr/sbin/php-fpm7.3", "--nodaemonize"]
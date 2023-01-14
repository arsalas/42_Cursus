FROM debian:buster

# Actualizamos el gestor de paquetes apt
RUN apt update -y && apt upgrade -y

# Instalamos mariadb
RUN apt-get install mariadb-server -y

# Copiamos el archivo de configuracion a la ruta donde corresponde 
COPY conf/50-server.cnf	/etc/mysql/conf.d/
COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/
# Copiamos el archivo de configuracion de la db
COPY tools/init_db.sh /init_db.sh

# Ejecutamos el script para configurar la db
ENTRYPOINT ["bash", "/init_db.sh"]
CMD ["mysqld", "--bind-address=0.0.0.0"]

# Exponemos el puerto de conexion a mariadb
EXPOSE 3306
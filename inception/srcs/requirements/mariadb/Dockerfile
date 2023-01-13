FROM debian:buster

# BORRAR
RUN export SQL_DATABASE=inception SQL_USER=aramirez SQL_PASSWORD=1234567

# Actualizamos el gestor de paquetes apt
RUN apt update -y && apt upgrade -y

# Instalamos mariadb
RUN apt-get install mariadb-server -y

# Copiamos el archivo de configuracion a la ruta donde corresponde 
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copiamos el archivo de configuracion de la db
COPY tools/init_db.sh /tmp/init_db.sh

# Ejecutamos el script para configurar la db
ENTRYPOINT ["bash", "/tmp/init_db.sh"]

# Exponemos el puerto de conexion a mariadb
EXPOSE 3306
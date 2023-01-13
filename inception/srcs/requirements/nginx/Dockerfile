FROM debian:buster

# Actualizamos la lista de paquetes apt-get
RUN apt-get update

# instalamos nginx y openssl, la flag -y es para que seleccione Y cuando pregunta en la instalacion
# openssl se encarga del certificado de seguridad
RUN apt-get install -y nginx openssl

# Crea el directorio donde se guardaran las claves ssl
RUN mkdir -p /etc/nginx/ssl

# Genera el certificado ssl y sus claves
RUN openssl req -newkey rsa:4096 -sha256 -days 365 -x509 -nodes \
-out /etc/nginx/ssl/aramirez.42.fr.crt \
-keyout /etc/nginx/ssl/aramirez.42.fr.key \
-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=aramirez.42.fr/UID=aramirez"

# Copiamos el archivo de configuracion en el contenedor
COPY conf/aramirez.42.fr /etc/nginx/sites-available

# Creamos un enlace simbolico de la configuracion
RUN ln -s /etc/nginx/sites-available/aramirez.42.fr /etc/nginx/sites-enabled

RUN mkdir -p /var/www/aramirez
COPY tools/index.html /var/www/aramirez

EXPOSE 443

# Ejecutamos nginx para levantar el servidor
CMD ["nginx", "-g", "daemon off;"]

# CONSTRUIMOS LA IMAGEN
# docker build -t nginx .
# LANZAMOS EN CONTENEDOR
# docker run -d -p 80:80 a86

# Crea un enlace simbolico
# ln -s /ruta/origen/archivo /ruta/destino/archivo
# Pone una configuracion de un sitio de sites available en sites-enabled
# ln -s ../sites-available/aaa .
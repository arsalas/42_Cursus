- isalpha
int isalpha(int c);
Comprueba si el caracter pasado es una letra (a-zA-Z)
Devuleve 0 si no se cumple y un numero si se cumple

- isdigit
int isdigit(int c);
Comprueba si el caracter pasado es una digito (1-9)
Devuleve 0 si no se cumple y un numero si se cumple

- isalnum
int isalnum(int c);
Comprueba si el caracter pasado es una digito (1-9) o una letra (a-zA-Z)
Devuleve 0 si no se cumple y un numero si se cumple

- isascii
int isascii(int c);
Comprueba si el caracter pasado es un caracter de ASCII (0000-0177)
Devuleve 0 si no se cumple y un numero si se cumple

- isprint
int isprint(int c);
Comprueba si el caracter pasado es un caracter imprimible (040-176)
Devuleve 0 si no se cumple y un numero si se cumple

- strlen
size_t strlen(const char *s);
Cuenta las letras que tiene el string pasdo
Devuleve las letras que tiene la string

- memset
void *memset(void *b, int c, size_t len);
Escribe en el puntero el caracter pasado en len bytes
Devuleve el puntero a la string

- bzero
void bzero(void *s, size_t n);
Escribe 0 en los primeros n bytes de la string, si n es 0 no hace nada
Devuleve el puntero a la string

- memcpy
void *memcpy(void *restrict dst, const void *restrict src, size_t n);
Copia n bytes de src en dst, si dst y src solapan es indefinido, se deberia usar memmove en estos casos
Devuleve el valor original de dst

- memmove
void *memmove(void *dst, const void *src, size_t len);
Copia n bytes de src en dst, si src y dst colisionan la copia de memoria no se puede destruir
Devuleve el valor original de dst

- strlcpy
size_t strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
Copia dstsize - 1 de caracteres de src a dst, se tiene que garantizar que termina en '\0'
Devuleve el total del tamaño de la string que se ha querido crear

- strcat
size_t strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
Contatena src al final de dst, esta string tendra al menos dstsize - strlen(dst) - 1, se garantiza la terminacion en '\0', si dstsize = 0
Devuleve el len de la string que ha intentado crear (dstsize + strlen(src))

- toupper
int toupper(int c);
Convierte una letra minuscula en mayuscula, se debe usar un unsigned char
Devuleve el caracter en mayuscula en caso de que se pase un caracter en minuscula o el valor recibido en otro caso

- tolower
int tolower(int c);
Convierte una letra mayucula en minuscula, se debe usar un unsigned char
Devuleve el caracter en minuscula en caso de que se pase un caracter en mayucula o el valor recibido en otro caso

- strchr
char *strchr(const char *s, int c);
Localiza la primera ocurrencia de c(convertida en char) en el string s, un caracter null es considerado parte del string, si c es '\0' la funciona debe localizar la terminacion del string
Devuleve un puntero al caracter encontrado o NULL si no lo ha encontrado

- strrchr
char *strchr(const char *s, int c);
Funciona igual que strchr pero locatiza la ultima ocurrencia 

- strncmp
int strncmp(const char *s1, const char *s2, size_t n);
Compara el s1 con s2, no compara mas de n caracteres
Devuleve 0 si son iguales o un numero con la diferencia de el caracter de s1 y s2

- memchr
void *memchr(const void *s, int c, size_t n);
Localiza la primra ocurrencia de c(convertido en unsigned char) en s en los primeros n bytes
Devuleve un puntero a el caracter encontrado o NULL si no lo encuentra

- memcmp
void *memchr(const void *s, int c, size_t n);
Compara s1 y s2 en los n primeros bytes
Devulve 0 si son iguales o la diferencia entre el primer caracter diferente(como unsigned chars)

- strnstr
char *strnstr(const char *haystack, const char *needle, size_t len);
Localiza la primera ocurrencia del string needle en haystack en los len primeros bytes
Se devuelve un puntero al primer caracter de la primera ocurrencia. Si needle es un string vacio se retorna haystack. Si no se encuentra de devuelve NULL

- atoi
int atoi(const char *str);
Convierte el numero de la string a un int, el formato debe ser correcto solo puede tener un signo +/-.
El numero terminara en cuando se encuentre algo que no sea un numero, al principio de la string solo se ignoran los caracteres ' ', \t, \n, \f, \r, \v
Retorna el numero obtenido o 0 si no se ha encontrado un numero valido

- calloc
void *calloc(size_t count, size_t size);
Reserva la sufiiente memoria para guadar size count y la rellena de 0
Retorna el puntero a la direccion de memoria obtenida

- strdup
char *strdup(const char *s1);
Reserva la suficiente memoria para guardar s1 y copia el s1 en el espacio reservado 
Retorna el puntero al string obtenido
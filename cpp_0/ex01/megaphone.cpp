
#include <stdio.h>
#include <string.h>
#include "iostream"

#define BLACK "\u001b[30m"  
#define RED "\u001b[31m" 
#define GREEN "\u001b[32m"  
#define YELLOW "\u001b[33m" 
#define BLUE "\u001b[34m"  
#define MAGENTA "\u001b[35m"  
#define CYAN "\u001b[36m"  
#define WHITE "\u001b[37m"  

class Contact
{
    public:
        std::string name;
        std::string last_name;
        std::string nickname;
        std::string phone;
        std::string secret;
};

void    truncate_text(std::string str)
{
    size_t i;
    
    i = 0;
    if (str.length() > 9)
    {
        while (str[i] && i < 9)
        {
            std::cout << str[i];
            i++;
        }
        std::cout << ".";
    }
    else
    {
        i = str.length();
        std::cout << str;
        while (i < 10)
        {
            std::cout << " ";
            i++;
        }
    }
}

Contact    create_contact(void)
{
    Contact agend;

    std::cout << CYAN"Introduce nombre:" WHITE << "\n";
    std::cin >> agend.name;
    std::cout << CYAN"Introduce apellido:" WHITE << "\n";
    std::cin >> agend.last_name;
    std::cout << CYAN"Introduce apodo:" WHITE << "\n";
    std::cin >> agend.nickname;
    std::cout << CYAN"Introduce telefono:" WHITE << "\n";
    std::cin >> agend.phone;
    std::cout << CYAN"Introduce secreto mas oscuro:" WHITE << "\n";
    std::cin >> agend.secret;
    return (agend);
}

void    add_contact(Contact *contacts, int *len)
{
    if (*len == 8)
        contacts[7] = create_contact();
    else
    {
        contacts[*len] = create_contact();
        *len += 1;
    }
}

void    print_contact(Contact cont)
{
    std::cout << CYAN"Nombre: " WHITE << "\n";
    std::cout << cont.name << "\n";
    std::cout << CYAN"Apellido: " WHITE << "\n";
    std::cout << cont.last_name << "\n";
    std::cout << CYAN"Apodo: " WHITE << "\n";
    std::cout << cont.nickname << "\n";
    std::cout << CYAN"Telefono: " WHITE << "\n";
    std::cout << cont.phone << "\n";
    std::cout << CYAN"Sectreto mas oscuro: " WHITE << "\n";
    std::cout << cont.secret << "\n";
}

/**
 * Muestra 4 columnas.
 * Indice, nombre, apellido, apodo
 * Ancho 10 caracteres.
 * Truncar si se pasa los caracteres con un . 
 */
void    search_contact(Contact *contacts, int *len)
{
    int i;

    i = 0;
        std::cout << "|";
        std::cout << " ";
        std::cout << "|" BLUE;
        truncate_text("Nombre");
        std::cout << WHITE"|" BLUE;
        truncate_text("Apellidos");
        std::cout << WHITE"|" BLUE;
        truncate_text("Apodo");
        std::cout << WHITE"|\n";
    while (i < *len)
    {
        std::cout << "|";
        std::cout << i + 1;
        std::cout << "|";
        truncate_text(contacts[i].name);
        std::cout << "|";
        truncate_text(contacts[i].last_name);
        std::cout << "|";
        truncate_text(contacts[i].nickname);
        std::cout << "|\n";
        i++;
    }
    if (i > 0)
    {
       std::cout << YELLOW"Selecciona contacto: " WHITE << "\n";
       std::cin >> i;
       if (i < *len)
        print_contact(contacts[i - 1]);
    }
}

void    select_action(std::string action, Contact *contacts, int *num)
{
    if (action == "EXIT")
        exit (0);
    else if (action == "ADD")
        add_contact(contacts, num);
    else if (action == "SEARCH")
        search_contact(contacts, num);
    else
        std::cout << RED"Accion no valida" WHITE << "\n";
}

int main(void)
{
    std::string action;
    Contact     contacts[8];
    int         num;

    num = 0;
    while (true)
    {
        std::cout << YELLOW"Introduce instruccion: (ADD | SEARCH | EXIT)" WHITE << "\n";
        std::cin >> action;
        select_action(action, contacts, &num);
    }
    return (0);
}
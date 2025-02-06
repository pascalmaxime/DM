#include <stdio.h>
#include <stdlib.h>

/*
 briefing : * Vérifie si un octet d'une adresse IP est valide.
            * Un octet est valide s'il est compris entre 0 et 255.
 param octet L'octet à vérifier.
 return 1 si l'octet est valide, 0 sinon.
 */
int valider_octet(int octet) {
    return (octet >= 0 && octet <= 255);
}

/*
 briefing : * Demande à l'utilisateur de saisir une adresse IP au format x.x.x.x,
            * valide les entrées et convertit l'adresse en un entier 32 bits.
 return L'adresse IP sous forme d'un entier 32 bits ou -1 en cas d'erreur.
 */
unsigned int saisir_adresse_ip() {
    unsigned int ip1, ip2, ip3, ip4;
    printf("Saisir une adresse IP: \n");
    if (scanf("%u.%u.%u.%u", &ip1, &ip2, &ip3, &ip4) != 4) {
        printf("Erreur saisie incorrecte\n");
        return -1;
    }
    
    if (!valider_octet(ip1) || !valider_octet(ip2) || !valider_octet(ip3) || !valider_octet(ip4)) {
        printf("Erreur saisie incorrecte: %u.%u.%u.%u\n", ip1, ip2, ip3, ip4);
        return -1;
    }
    
    return (ip1 << 24) | (ip2 << 16) | (ip3 << 8) | ip4;
}

/*
 Programme 'main' qui demande une adresse IP, la valide et affiche son équivalent en 32 bits.
 */
int main() {
    unsigned int ip_long = saisir_adresse_ip();
    if (ip_long != (unsigned int)-1) {
        printf("Adresse IP (32 bits): %u\n", ip_long);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

/*
 briefing : * Vérifie si un octet d'un masque de sous-réseau est valide.
            * Un octet est valide s'il est compris entre 0 et 255.
 param octet L'octet à vérifier.
 return 1 si l'octet est valide, 0 sinon.
*/
int valider_octet(int octet) {
    return (octet >= 0 && octet <= 255);
}

/*
 briefing : * Demande à l'utilisateur de saisir un masque de sous-réseau au format x.x.x.x,
            * valide les entrées et convertit le masque en un entier 32 bits.
 return Le masque sous-réseau sous forme d'un entier 32 bits ou -1 en cas d'erreur.
*/
unsigned int saisir_masque_sous_reseau() {
    unsigned int m1, m2, m3, m4;
    printf("Saisir un masque de sous-réseau:\n ");
    if (scanf("%u.%u.%u.%u", &m1, &m2, &m3, &m4) != 4) {
        printf("Erreur saisie incorrecte\n");
        return -1;
    }
    
    if (!valider_octet(m1) || !valider_octet(m2) || !valider_octet(m3) || !valider_octet(m4)) {
        printf("Erreur saisie incorrecte: %u.%u.%u.%u\n", m1, m2, m3, m4);
        return -1;
    }
    
    return (m1 << 24) | (m2 << 16) | (m3 << 8) | m4;
}

/*
 Programme principal qui demande un masque de sous-réseau, le valide et affiche son équivalent en 32 bits.
*/
int main() {
    unsigned int masque_long = saisir_masque_sous_reseau();
    if (masque_long != (unsigned int)-1) {
        printf("Masque sous-réseau (32 bits): %u\n", masque_long);
    }
    return 0;
}
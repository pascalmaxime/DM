#include <stdio.h>
#include <stdlib.h>

/*
 briefing : * Vérifie si un octet est valide (entre 0 et 255).
 param octet L'octet à vérifier.
 return 1 si valide, 0 sinon.
*/

int valider_octet(int octet) {
    return (octet >= 0 && octet <= 255);
}

/*
 briefing : * Demande à l'utilisateur de saisir une adresse IP valide et la convertit en entier 32 bits.
 return L'adresse IP sous forme d'un entier 32 bits ou -1 en cas d'erreur.
*/

unsigned int saisir_adresse_ip() {
    unsigned int o1, o2, o3, o4;
    printf("Saisir une adresse IP: \n ");
    if (scanf("%u.%u.%u.%u", &o1, &o2, &o3, &o4) != 4) {
        printf("Erreur saisie incorrecte\n");
        return -1;
    }
    if (!valider_octet(o1) || !valider_octet(o2) || !valider_octet(o3) || !valider_octet(o4)) {
        printf("Erreur saisie incorrecte: %u.%u.%u.%u\n", o1, o2, o3, o4);
        return -1;
    }
    return (o1 << 24) | (o2 << 16) | (o3 << 8) | o4;
}

/*
 briefing : * Demande à l'utilisateur de saisir un masque de sous-réseau valide et le convertit en entier 32 bits.
 return Le masque sous-réseau sous forme d'un entier 32 bits ou -1 en cas d'erreur.
*/

unsigned int saisir_masque_sous_reseau() {
    unsigned int m1, m2, m3, m4;
    printf("Saisir un masque de sous-réseau: \n");
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
 briefing : * Calcule l'adresse réseau en effectuant un ET logique bit à bit
            * entre l'adresse IP et le masque de sous-réseau.
 param :    * ip Adresse IP sous forme d'un entier 32 bits
            * masque Masque de sous-réseau sous forme d'un entier 32 bits
 return Adresse réseau sous forme d'un entier 32 bits
*/
unsigned int calculer_adresse_reseau(unsigned int ip, unsigned int masque) {
    return ip & masque;
}

/*
 briefing : * Programme principal qui demande une adresse IP et un masque,
            * puis affiche l'adresse réseau correspondante.
*/
int main() {
    unsigned int ip = saisir_adresse_ip();
    if (ip == (unsigned int)-1) return 1;
    
    unsigned int masque = saisir_masque_sous_reseau();
    if (masque == (unsigned int)-1) return 1;
    
    unsigned int adresse_reseau = calculer_adresse_reseau(ip, masque);
    
    printf("Adresse réseau: %u.%u.%u.%u\n",
           (adresse_reseau >> 24) & 0xFF,
           (adresse_reseau >> 16) & 0xFF,
           (adresse_reseau >> 8) & 0xFF,
           adresse_reseau & 0xFF);
    
    return 0;
}
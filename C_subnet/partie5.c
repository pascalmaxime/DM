#include <stdio.h>
#include <stdlib.h>

/**
 briefing : * Vérifie si un octet est valide (entre 0 et 255).

param : * octet L'octet à vérifier.
return : * 1 si valide, 0 sinon.
 */
int valider_octet(int octet) {
    return (octet >= 0 && octet <= 255);
}

/**
 briefing :* Demande à l'utilisateur de saisir un masque de sous-réseau valide et le convertit en entier 32 bits.

 return : * Le masque sous-réseau sous forme d'un entier 32 bits ou -1 en cas d'erreur.
 */
unsigned int saisir_masque_sous_reseau() {
    unsigned int m1, m2, m3, m4;
    printf("Saisir un masque de sous-r\xC3\xA9seau: ");
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

/**
 briefing : * Calcule la notation CIDR en comptant le nombre de bits à 1 dans le masque de sous-réseau.
 *
 param : * masque Masque de sous-réseau sous forme d'un entier 32 bits.
 return : *La notation CIDR (nombre de bits à 1).
 */
int calculer_cidr(unsigned int masque) {
    int cidr = 0;
    while (masque) {
        cidr += masque & 1;
        masque >>= 1;
    }
    return cidr;
}

/**
 briefing : * Programme principal qui demande un masque de sous-réseau,
            * puis affiche la notation CIDR correspondante.
 */
int main() {
    unsigned int masque = saisir_masque_sous_reseau();
    if (masque == (unsigned int)-1) return 1;
    
    int cidr = calculer_cidr(masque);
    printf("CIDR: /%d\n", cidr);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

/*
briefing : * Vérifie si un octet est valide (entre 0 et 255).
 */
int valider_octet(int octet) {
    return (octet >= 0 && octet <= 255);
}

/*
briefing : * Convertit une adresse IP ou un masque sous-réseau en entier 32 bits.
 */
unsigned int saisir_adresse() {
    unsigned int o1, o2, o3, o4;
    if (scanf("%u.%u.%u.%u", &o1, &o2, &o3, &o4) != 4) {
        printf("Erreur saisie incorrecte\n");
        return -1;
    }
    if (!valider_octet(o1) || !valider_octet(o2) || !valider_octet(o3) || !valider_octet(o4)) {
        printf("Erreur saisie incorrecte\n");
        return -1;
    }
    return (o1 << 24) | (o2 << 16) | (o3 << 8) | o4;
}

/*
briefing : * Affiche une adresse IP à partir d'un entier 32 bits.
 */
void afficher_adresse(unsigned int adresse) {
    printf("%u.%u.%u.%u", 
           (adresse >> 24) & 255, 
           (adresse >> 16) & 255, 
           (adresse >> 8) & 255, 
           adresse & 255);
}

/*
briefing : * Calcule l'adresse réseau (AND entre IP et masque).
 */
unsigned int calculer_adresse_reseau(unsigned int ip, unsigned int masque) {
    return ip & masque;
}

/*
briefing : * Calcule l'adresse de broadcast (OR entre adresse réseau et ~masque).
 */
unsigned int calculer_adresse_broadcast(unsigned int adresse_reseau, unsigned int masque) {
    return adresse_reseau | ~masque;
}

/*
briefing : * Calcule la notation CIDR en comptant le nombre de bits à 1 dans le masque de sous-réseau.
 */
int calculer_cidr(unsigned int masque) {
    int cidr = 0;
    while (masque) {
        cidr += masque & 1;
        masque >>= 1;
    }
    return cidr;
}

/*
briefing :  * Programme principal qui demande une adresse IP et un masque de sous-réseau,
            * puis affiche les informations calculées.
 */
int main() {
    unsigned int ip, masque, adresse_reseau, adresse_broadcast;
    int cidr;
    
    printf("Saisir une adresse IP: ");
    ip = saisir_adresse();
    if (ip == (unsigned int)-1) return 1;
    
    printf("Saisir un masque de sous-réseau: ");
    masque = saisir_adresse();
    if (masque == (unsigned int)-1) return 1;
    
    adresse_reseau = calculer_adresse_reseau(ip, masque);
    adresse_broadcast = calculer_adresse_broadcast(adresse_reseau, masque);
    cidr = calculer_cidr(masque);
    
    printf("Adresse r\xC3\xA9seau: ");
    afficher_adresse(adresse_reseau);
    printf(" /%d\n", cidr);
    
    printf("Adresse broadcast: ");
    afficher_adresse(adresse_broadcast);
    printf("\n");
    
    return 0;
}

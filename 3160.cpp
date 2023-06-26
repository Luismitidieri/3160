#include <stdio.h>
#include <string.h>

#define MAX_AMIGOS 1000
#define MAX_NOME 50

int main() {
    char amigos[MAX_AMIGOS][MAX_NOME], nova_lista[MAX_AMIGOS][MAX_NOME];
    char amigo_indicado[MAX_NOME], nome[MAX_NOME];
    int n_amigos, n_nova_lista, pos_amigo_indicado, i, j;

    
    fgets(amigos[0], MAX_NOME, stdin);
    n_amigos = 0;
    while (sscanf(amigos[n_amigos], "%s", nome) == 1) {
        n_amigos++;
        fgets(amigos[n_amigos], MAX_NOME, stdin);
    }

    
    fgets(nova_lista[0], MAX_NOME, stdin);
    n_nova_lista = 0;
    while (sscanf(nova_lista[n_nova_lista], "%s", nome) == 1) {
        n_nova_lista++;
        fgets(nova_lista[n_nova_lista], MAX_NOME, stdin);
    }

   
    fgets(amigo_indicado, MAX_NOME, stdin);
    if (sscanf(amigo_indicado, "%s", nome) == 1 && strcmp(nome, "nao") != 0) {
        
        pos_amigo_indicado = -1;
        for (i = 0; i < n_amigos; i++) {
            if (strcmp(amigos[i], nome) == 0) {
                pos_amigo_indicado = i;
                break;
            }
        }
        
        if (pos_amigo_indicado >= 0) {
            for (i = n_amigos + n_nova_lista - 1; i >= pos_amigo_indicado + n_nova_lista; i--) {
                strcpy(amigos[i], amigos[i - n_nova_lista]);
            }
            for (i = 0; i < n_nova_lista; i++) {
                strcpy(amigos[pos_amigo_indicado + i], nova_lista[i]);
            }
        }
        
        else {
            for (i = n_amigos; i < n_amigos + n_nova_lista; i++) {
                strcpy(amigos[i], nova_lista[i - n_amigos]);
            }
        }
        n_amigos += n_nova_lista;
    }
    else {
        
        for (i = n_amigos; i < n_amigos + n_nova_lista; i++) {
            strcpy(amigos[i], nova_lista[i - n_amigos]);
        }
        n_amigos += n_nova_lista;
    }

    
    for (i = 0; i < n_amigos; i++) {
        printf("\n%s", amigos[i]);
    }

    return 0;
}

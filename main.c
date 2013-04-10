/*
* Algoritmos e Estruturas de Dados III
* Professor: André Pimenta
* Alunos: Rogério Dias, Pedro Victor, Pedro Augusto
* Turma: 10A
* Sistema de Referências Bibliográficas utilizando Árvore-B
* IDE utilizada: NetBeans versão 7.2.2
* Sistema Operacional: Ubuntu 12.04
*/

/**
* @file main.c
* @brief Arquivo principal com função main e interface implementadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"

/**
* @brief Função principal main e Interfface.
*/
int main(int argc, char** argv) {

    Driver();
    printf("Sistema de gerenciamento de referências bibliográficas usando árvore B.\n");

    int j = 0;
    int i = 0;
    char tudoaux[256];
    char IR[3] = "IR\0";
    char RR[3] = "RR\0";
    char BR[3] = "BR\0";
    char IA[3] = "IA\0";
    char FM[3] = "FM\0";
    char caraux[3] = "NO";


    while (strcmp(caraux, FM) != 0) {
        j = 0;
        scanf("%[^\n]s", tudoaux);
        for (i = 0; i < 2; i++) {
            caraux[j] = tudoaux[i];
            j++;
        }

        if (strcmp(IR, caraux) == 0 && strlen(tudoaux) > 4) {
            printf("INSERÇÃO\n");
            char Key[6];

            int k = 3;
            for (i = 0; i < 5; i++) {
                Key[i] = tudoaux[k];
                k++;
            }

            Key[i] = '\0';

            DriverRoot(Key, ind->DataRRN);
            ind->DataRRN++;


            int l = 0;
            char Auxiliar[256];
            int tamanho = strlen(tudoaux);

            for (i = 3; i < tamanho; i++) {
                Auxiliar[l] = tudoaux[i];
                l++;
            }

            for (i = l; i < 256; i++) {
                Auxiliar[i] = '#';
            }
            Auxiliar[i] = '\0';

            fprintf(Data, "%s", Auxiliar);

        } else
            if (strcmp(RR, caraux) == 0) {
            printf("REMOVER REFERENCIA\n");
            char Key[6];

            int k = 3;
            for (i = 0; i < 5; i++) {
                Key[i] = tudoaux[k];
                k++;
            }
            Key[i] = '\0';
            printf("Key %s\n", Key);
            DriverRemove(Key);

        } else
            if (strcmp(BR, caraux) == 0) {
            printf("BUSCAR REFERENCIA\n");
            char Key[6];

            int k = 3;
            for (i = 0; i < 5; i++) {
                Key[i] = tudoaux[k];
                k++;
            }
            Key[i] = '\0';

            long FOUND_RRN = -1;
            int FOUND_POS = -1;
            if (SearchKey(ind->TreeRRN, Key, &FOUND_RRN, &FOUND_POS) == TRUE) {
                printf("Referência encontrada!\n");

                Page *Seekpage = getPage(FOUND_RRN);

                fseek(Data, Seekpage->ReferencesArray[FOUND_POS].FileRRN * 256 * (sizeof (char)), SEEK_SET);
                char BiblioReference[258];
                fread(&BiblioReference, 256 * (sizeof (char)), 1, Data);
                ParseString(BiblioReference);
            } else {
                printf("Chave não encontrada!\n");
            }
        } else
            if (strcmp(IA, caraux) == 0) {
            printf("ESTADO DO INDICE ATUAL\n");
            printtree(ind->TreeRRN);
        } else
            if (strcmp(FM, caraux) == 0) {
        } else {
            printf("Opção não existente!\n");
        }
        getchar();
    }

    WriteIndex();
    free(ind);
    fclose(Btree);
    fclose(Data);
    return (EXIT_SUCCESS);
}
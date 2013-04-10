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
* @file btree.h
* @brief Arquivo com o cabeçalho de implementação da árvore B.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#define Order 2
#define MAXKEYS 2*Order
#define NIL -1
#define TRUE 1
#define FALSE 0
#define PROMOTION -2
#define NO_PROMOTION -3
#define ERROR -4
#define NOT_FOUND -5
#define FOUND -6
#define LEAF -7
#define NOT_LEAF -8
#define UNDERFLOW -9
#define NOT_UNDERFLOW -10
#define CONCATENATE -11


    extern FILE *Btree;
    extern FILE *Data;

    /*
     *
     */

    /*Initial Header with the reference for tree.*/
    typedef struct Index {
        long TreeRRN;
        long CurrentRRN;
        long DataRRN;
    } Index;

    extern Index*ind;

    typedef struct References {
        /* data */
        char Reference[6]; /*Author's reference.*/
        long FileRRN; /*Reference for Structure on File.*/
    } References;

    /*Structure of page*/
    typedef struct Page {
        /* data */
        long RRN;
        short NumberOfKeys;
        References ReferencesArray[MAXKEYS];
        long RRNsArray[MAXKEYS + 1];
    } Page;

    /*Structure of page*/
    typedef struct AuxPage {
        /* data */
        long RRN;
        short NumberOfKeys;
        References ReferencesArray[MAXKEYS + 1];
        long RRNsArray[MAXKEYS + 2];
    } AuxPage;


    void ParseString(char *string);
    void Initialize(Page*page);
    void WritePage(Page* page, long RRN);
    Page* getPage(long RRN);
    void WriteIndex();
    int Driver();
    int BinarySearch(Page* page, char *Key, int*found);
    int SearchKey(long RRN, char *Key, long *FOUND_RRN, int *FOUND_POS);
    void InsertKey(Page* page, char *Key, long R_SON, long DataRRN);
    void Split(char *key, long r_child, Page *p_oldpage, char *promo_key, long *promo_r_child, Page *p_newpage, long *DataRRNPromoted);
    Page *createRoot(char *Key, long right, long left);
    int Insert(long CurrentRRN, char *Key, long DataRRN, long *PROMO_R_CHILD, char *PROMO_KEY, long *DataRRNPromoted);
    int DriverRoot(char *Key, long DataRRN);
    void Organize(Page *page, int Position);
    void DeletePage(long *ProblemRRN);
    void DriverRemove(char *Key);
    int isPageLeaf(Page *page);
    int Concatenate(Page *CurrentPage, long *ProblemRRN);
    int Redistribution(Page *CurrentPage, long *ProblemRRN);
    int Remove(long CurrentRRN, char *Key, int *Troca, char *ChaveTroca, Page *Dad, int *Trocando, long *ProblemRRN);
    void printtree(long t);




#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */


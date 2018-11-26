/***
 *
 * main.c: esercizio slide 9/10/2018
 * author: Gabriele Pappalardo - 09/10/2019
 * user: gabryon@izuku
 *
 */
#include <stdio.h>
#include <stdbool.h>
 
#define MAX_PATTERN 10
#define MAX_USER_INPUTS 128
 
#define INDEX_NAME i
 
#define X_POSITION INDEX_NAME-MAX_PATTERN+1
#define Y_POSITION INDEX_NAME-MAX_PATTERN+2
#define W_POSITION INDEX_NAME-MAX_PATTERN+3
 
#define A_POSITION INDEX_NAME-MAX_PATTERN+6
#define B_POSITION INDEX_NAME-MAX_PATTERN+7
 
typedef enum {
    OK, MATCHED
} status;
 
// Prototipi di funzioni
void print_matched_sequence(const char *buffer, int i);
bool is_matching(char buffer[], int i);
 
 
/***
 * Punto di partenza del programma
 * @author Gabriele Pappalardo <gabriele_pappalardo@outlook.com>
 *
 * @return int Status code
 */
int main(void){
 
    // Inizializzo un array di caratteri con dimensione predefinita
    char buffer[MAX_USER_INPUTS];
 
    // Imposto lo stato corrente del Programma
    status current_status = OK;
 
    // Dichiaro l'indice i di tipo int fuori dal ciclo for
    // poichè mi servirà per stampare la sequenza errata in presenza
    int i = 0;
 
    printf("Hai a dispozione %d caratteri.\n\n", MAX_USER_INPUTS);
 
    for (i = 0; i < MAX_USER_INPUTS; i++){
 
        // Nella variabile temp di tipo char memorizzo il carattere inserito dall'utente
        char temp = getchar();
 
        // Se il carattere è un new line allora non lo inserisco nel buffer
        if (temp == '\n'){
            i--;
            continue;
        }
 
        // Inserisco il carattere dell'utente nel buffer
        buffer[i] = temp;
 
        // Appena il buffer contiene più di 10 elementi controlla il pattern
        if (i >= MAX_PATTERN - 1){
 
            // Se trovo il pattern nel buffer esci dal ciclo for
            if (is_matching(buffer, i)){
                current_status = MATCHED;
                break;
            }
        }
    }
 
    // Se è stato trovato un matching allora stampalo
    if (current_status == MATCHED){
 
        print_matched_sequence(buffer, i);
    }
 
    return 0;
}
 
 
/***
 * Trova il pattern 'xywxxabxxx' all'interno del buffer
 * @author Gabriele Pappalardo <gabriele_pappalardo@outlook.com>
 *
 * @param const char* buffer
 * @param int i Indice del ciclo for
 * @return bool Torna true se ha trovato un'occorrenza, altrimenti false
 */
bool is_matching(char buffer[], int i){
 
    char x = buffer[X_POSITION],
         y = buffer[Y_POSITION],
         w = buffer[W_POSITION],
         a = buffer[A_POSITION],
         b = buffer[B_POSITION];
 
    if (x == buffer[X_POSITION + MAX_PATTERN - 1] &&
        x == buffer[X_POSITION + MAX_PATTERN - 2] &&
        x == buffer[X_POSITION + MAX_PATTERN - 3] &&
        x == buffer[X_POSITION + 3] &&
        x == buffer[X_POSITION + 4]){
        if (a == y || a == w || b == y || b == w) return true;
    }
 
    return false;
}
 
/***
 * Stampa la sequenza che corrisponde col pattern
 * @author Gabriele Pappalardo <gabriele_pappalardo@outlook.com>
 *
 * @param const char* buffer
 * @param int i Indice del ciclo for
 * @return null
 */
void print_matched_sequence(const char *buffer, int i) {
 
    printf("La seguente occorrenza '");
 
    for (int k = i - MAX_PATTERN + 1; k <= i; k++){
        printf("%c", buffer[k]);
    }
 
    printf("', inclusa tra il %d^esimo e il %d^esimo carattere, corrisponde con il pattern 'xywxxabxxx'!", i - MAX_PATTERN + 1, i);
 
    return;
}
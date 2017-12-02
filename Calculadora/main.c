#include <stdio.h>
#include <stdlib.h>
#include <String.h>
// https://es.wikipedia.org/wiki/String.h
#include <stdbool.h>

int length;
const char CHAR[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '(', ')'};

/*
* rep una expressió i retorna true si hi troba dos operands.
* Si només troba 1 operand retorna fals (cas directe)
*/
bool esSigne(char c)
{
    if (c == 42 || c == 43 || c == 45 || c == 47) return true;
    else return false;
}

bool trobaOperands(char op[], char opA[], char opB, char *signe, int length)
{
    int parentesi = 0; //funciona com una pila per a trobar el parentesi final en el cas que op sigui una expressio

    while (i < length)
    {
        if (op[i] == '(')   // si es un obrir parentesi
        {
            parentesi++;   // apilem parentesis
        }
        if (op [i] == ')')  // si es un de tancar
        {
            parentesi--;   // desapilem parentesis
        }
        if (esSigne(op[i]) && parentesi == 0)
        {
            for (j = 0; j =< i; j++) // copiem el contingut de l'operand A a l'array de parametre
            {
                opA[j] = op[j+pos_inici];
            }
        }
    }
     if (parentesi == 0) // si acabem de trobar el parentesi que tancava el primer llavors
            {
                pos_final = i;    // pos_final ens apunta al final del primer operand (ultim parentesi)
                operador = op[i+1]; // per tant l'operador s'ha de trobar a la següent pal osicio
                for (j = 0; j =< pos_final-pos_inici; j++) // copiem el contingut de l'operador A a l'operador
                {
                    opA[j] = op[j+pos_inici];
                }
                i++; // corregim per a que i apunti al signe al igual que en el cas directe
                break; // sortim
            }
    length1 = pos_final-pos_inici; // obtenim longitud de l'operand 1 si es tracta de parentesis
    i++; // i apunta al principi del segon operand
    pos_inici = i;
    parentesis = 0; // hauria de ser 0

   while (i < length)
    {
        if (i == pos_inici && op[i] != '(') // en el cas de que comencem a llegir i hi hagi un numero
        {
            llegim_nombre = true; // activem el flag de nombre
        }
        if (op[i] == '(')   // si es un obrir parentesi
        {
            if (parentesis == 0)    // si es el primer parentesi que obrim
            {
                pos_inici = i;    // guardem la posicio pel final (sempre sera 0)
            }
            parentesis++;   // apilem parentesis
        }
        if (op[i] == ')')  // si es un de tancar
        {
            parentesis--;   // desapilem parentesis
            if (parentesis == 0)
            {
                pos_final = i;    // pos_final ens apunta al final del segon operand (ultim parentesi)
                for (j = 0; j =< pos_final-pos_inici; j++) // copiem el contingut de l'array d'operacio a l'opera
                {
                    opB[j] = op[j+pos_inici];
                }
                break; // sortim
            }
        }
    }
}

int operate(char op[], int length)
{
    char opA[256];  // conté opA quan aquest es una expressio
    char opB[256];  // conte opB ""
    int length_opA;     // longitud de opA
    int length_opB;     // longitud de opB

    int i = 0, j = 0;   // comptadors


    bool llegim_nombre = false;
    int pos_inici;
    int pos_final;

/*
funcio esNumero(char op, int length) return numero //evalua que el primer operand sigui un nombre i si ho es el retorna en orma d'enter, sino retorna -1
*/



    switch (operand)
    {
    case '+':
        if
        return operate() + operate();
        break;
    case '-':
        break;
    case '*':
        break;
    case '/':
        break;

    }





    }
}

/* Valida que el veïnatge de les operacions sigui l'adequat
 * Pre = cert
 * Post = per a qualsevol alfa tal que alfa pren valors de 0 fins length - 1 i per a qualsevol beta tal que beta va de 0 fins
 * number.length-1 llavors, si op[alfa] == number[beta] llavors op[alfa+1] = seguent xifra del nombre | operador & !parentesis
 */
bool sintax_validation(char op[], int length)
{
    char number[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int i, j;
    bool nombrellegit = false;
    for (i = 0; i < length; i++)
    {
        for (j = 0; i < 10; i++)
        {
            if (op[i] == number[j])
            {
                nombrellegit = true;
                break;
            }
            else
            {
                nombrellegit = false;
            }
        }
        if (op[i] == '(' && nombrellegit)
        {
            return false;
        }
    }
    return true;
}

/* Valida que els simbols siguin correctes
 * Pre = cert
 * Post = per a qualsevol alfa tal que alfa pren valors de 0 fins length - 1 llavors op[alfa+1] = seguent xifra del nombre | operador & !parentesis
 */
bool op_validation(char op[], int length){
    int j, i=0;
    bool valid, match;
    valid=true;
    while (valid && i<length){
        j=0;
        match=false;
        while (!match && j<16){
            if (op[i]==CHAR[j]){
                match=true;
            }
            j++;
        }
        if (!match) {
            valid=false;
        }
        i++;
    }
    return valid;
}

bool parenthesis_validation (char op[], int lenght){
    int parenthesis=0, i=0;
    while(i<lenght){
        if(op[i]=='(' || op[i]==')'){
            if(op[i]=='(') parenthesis++;
            else if(op[i]==')') parenthesis--;
            if(parenthesis<0) return false;
            //printf("\nbucle parentesis: %c, %d", op[i], parenthesis);
        }
        i++;
    }
    if(parenthesis!=0) return false;
    else return true;
}

/****************************
*
*
*
*PROVES
*
*
*
*****************************/

void proof_op_validation(){
    char op[] = {'a', '1'};
    printf("\nExpressio amb una 'a' i un '1': %d", op_validation(op, 2));
    char op2[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '(', ')'};
    printf("\nExpressio amb els elements acceptats: %d", op_validation(op2, 16));
    char op3[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', 'b', '9', '+', '-', '*', '/', '(', ')'};
    printf("\nExpressio amb els elements acceptats i una 'b': %d", op_validation(op3, 17));
}

void parenthesis_op_validation(){
    char op[] = {'(', ')'};
    printf("\nParentesis correctes (): %d", parenthesis_validation(op, 2));
    char op2[] = {'(', '(', '(', ')', '(', ')', ')', ')', '(', '9', ')', '(', '(', '6', ')', ')'};
    printf("\nParentesis correcets ((()()))(9)((6)): %d", parenthesis_validation(op2, 16));
    char op3[] = {')'};
    printf("\nParentesis incorrecets ): %d", parenthesis_validation(op3, 1));
    char op4[] = {'(',')',')'};
    printf("\nParentesis incorrecets ()): %d", parenthesis_validation(op4, 3));
    char op5[] = {'(','(',')'};
    printf("\nParentesis incorrecets ((): %d", parenthesis_validation(op5, 3));
}

int main()
{
    FILE *f;
    f = fopen("proves.txt","rt");
    char op[256], c;
    int i;

    while (c!= EOF)
    {
        i = 0;
        while((c=fgetc(f))!='\n' && c != EOF )
        {
            if (c != ' ' && c != '\n' && c != EOF)
            {
                op[i] = c;
                i++;
            }
        }
        length = i;
        if (sintax_validation(op, length) && parenthesis_validation (op, length) && op_validation(op, length))
        {
            printf("\nEl resultat es %i", operate(op, length);
        }
        else
        {
            printf ("\nAlguna de les proves de validació no s'ha dut a terme satisfactoriament. Abortant.")
        }
    }

    fclose(f);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
// https://es.wikipedia.org/wiki/String.h
#include <stdbool.h>

int length;
const char CHAR[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '(', ')'};

/*int operate(char op[], int length)
{
    char op1[256];
    char op2[256];
    char nombre[16];
    int length1;
    int pos_inici;
    int pos_final;
    int nombre1 = -1;
    int nombre2 = -1;
    bool llegim_nombre = false;

    int i = 0, j = 0;
    int parentesis = 0;
    char operand;

    // considerar cas de parentesis rodejant tota l'expressio
    while (i < length)
    {
        if (i==0 && op[i] != '(') // en el cas de que comencem a llegir i hi hagi un numero
        {
            llegim_nombre = true; // activem el flag de nombre
        }
        if (op[i] > 41 && op[i] < 48 && llegim_nombre)  // si trobem el operand vol dir que ja hem llegit el nombre
        {
            for (j = 0; j< i-1; j++)
            {
                nombre1[j] = op[j]; // copiem el primer operand (en forma de nombre en un array)
            }
            operand == op[i];   // obtenim el operand
            op2 = i-1;          // op2 ens apunta al final del primer operand nombre (unitats del primer operand)
            nombre1 = atoi(nombre1);    // comvertim a integer i obtenim el primer valor
        }
        if (op[i] == '(')   // si es un obrir parentesi
        {
            if (parentesis == 0)    // si es el primer parentesi que obrim
            {
                op1 = i;    // guardem la posicio pel final (sempre sera 0)
            }
            parentesis++;   // apilem parentesis
        }
        if (op [i] == ')')  // si es un de tancar
        {
            parentesis--;   // desapilem parentesis
            if (parentesis == 0)
            {
                op2 = i;    // op2 ens apunta al final del primer operand ultim parentesi
                operand = op[i+1];
                for (i = pos_inici; i < pos_final; i++)
                {
                    op1[j] = op[i];
                }
                break;
            }
        }
    }
    length1 = op2-op1; // obtenim longitud de l'operand 1 si es tracta de parentesis
    i++; // i apunta al principi del segon operand
    pos_inici = i;
    parentesis = 0; // hauria de ser 0

   while (i < length)
    {
        if (i == pos_inici && op[i] != '(') // en el cas de que comencem a llegir i hi hagi un numero
        {
            llegim_nombre = true; // activem el flag de nombre
        }
        if ((op[i] > 41 && op[i] < 48 || op[i] == '\0') && llegim_nombre)  // si trobem el operand vol dir que ja hem llegit el nombre
        {
            for (j = pos_inici; j< i; j++)
            {
                nombre2[j] = op[j];
            }
            nombre2 = atoi(nombre2);

        }
        if (op[i] == '(')   // si es un obrir parentesi
        {
            if (parentesis == 0)    // si es el primer parentesi que obrim
            {
                pos_inici = i;    // guardem la posicio pel final (sempre sera 0)
            }
            parentesis++;   // apilem parentesis
        }
        if (op [i] == ')')  // si es un de tancar
        {
            parentesis--;   // desapilem parentesis
            if (parentesis == 0)
            {
                pos_final = i;
                for (j = pos_inici; j < pos_final; j++)
                {
                    op2[j] = op[j];
                }
                break;
            }
        }
    }

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
}*/

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

int esNumero (char op[], int lenght){
    int i, j=0;
    bool fin = false;
    char num[lenght]; //com a maxim sera de longitud lenght
    int numFinal;
    if (op[0]<48 || op[0]>57){ //si no es un numero
        return -1;
    }
    else for (i=0;i<length && !fin;i++){ //si es un numero fem el bucle per a recorrer tot l'array fins al final o fins trobar un simbol
        if (op[0]<48 || op[0]>57){ //si no es un numero
            fin=true; //parem de llegir el numero
        }
        //guardar el char en un altre char nomes dels numeros
        else{
            num[j]=op[i];
            j++;
        }
        numFinal = atoi(num);
        return numFinal;
    }
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

        }
    }
    //esNumero(op, length);
    fclose(f);
    return 0;
}

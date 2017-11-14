#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const char CHAR[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '(', ')'};

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

void parenthesis_op_validation();
void proof_op_validation();

int main()
{
    char op[256];
    proof_op_validation();
    parenthesis_op_validation();

    return 0;
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

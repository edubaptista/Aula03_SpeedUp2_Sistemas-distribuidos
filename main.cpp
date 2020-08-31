#include <iostream>
#include <stdlib.h>
#include <thread>

//Eduardo Baptista dos Santos - RA: 22.217.017-7
// aaa = 222
// bbb = 170
// ccc = 177

using namespace std;

//Variaveis globais para distribuir nas threads
int contaPrimos = 0;
int aaa = 222;
int bbb = 170;
int ccc = 177;
int P = bbb * ccc;
int somatoria = 0;
int nAtual;

//Reconhecimento de funcoes do codigo
int TestaPrimo3(int n);
void chamaProgramaPrimos1();
void chamaProgramaPrimos2();

int main(int argc, char* argv[]) {

    cout << "Valor de bbb*ccc: " << P << endl << endl;
	
	//Criacao das threads
    thread t1(chamaProgramaPrimos1);
    thread t2(chamaProgramaPrimos2);
    //Chamando as threads
    t1.join();
    t2.join();

	cout << "Somatoria dos numeros primos: " << somatoria;
	
	
	
    exit(0);
}

//Esta funcao testa se os numeros impares  sao primos durante a execucao
void chamaProgramaPrimos1() {
        int nAtual = P-1;
        while (contaPrimos < aaa) {
            if (TestaPrimo3(nAtual)) {
                somatoria += nAtual;
                contaPrimos++;
                //cout << "Numero primo " << contaPrimos << ": " << nAtual << endl;
            }
            nAtual -= 2;
        }
    }

//Esta funcao testa se os numeros pares sao primos durante a execucao
void chamaProgramaPrimos2() {
        int nAtual = P-2;
        while (contaPrimos < aaa) {
            if (TestaPrimo3(nAtual)) {
                if(nAtual != 2)
				somatoria += nAtual;
                contaPrimos++;
                //cout << "Numero primo " << contaPrimos << ": " << nAtual << endl;
       			}
		    }
            
            nAtual -= 2;
        }
    

//Funcao que verifica se o numero é primo, algoritmo cedido pelo professor
int TestaPrimo3(int n) {
    int EhPrimo,
        d = 3;
    if (n <= 1 || (n != 2 && n % 2 == 0))
        EhPrimo = 0;    /* nenhum numero inteiro <= 1 ou par > 2 e' primo */
    else
        EhPrimo = 1;        /* o numero e' primo ate que se prove o contrario */

    while (EhPrimo && d <= n / 2) {
        if (n % d == 0)
            EhPrimo = 0;
        d = d + 2;        /* testar apenas ímpares*/
    }
    return EhPrimo;
}


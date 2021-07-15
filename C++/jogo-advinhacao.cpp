#include <iostream>
#include <math.h>
#include <cstdlib> // Funcao srand
#include <ctime> // Funcao time

using namespace std;

void bemVindo(){
    system("clear || cls");
    cout << "****************************************" << endl;
    cout << "*** Bem-vindos ao Jogo da Adivinhação ***" << endl;
    cout << "****************************************\n" << endl;
    cout << "Aperte enter para começar...";
    getchar();
}

void menu(int *opcao){
    system("clear || cls");
    cout << "1 - Fácil" << endl;
    cout << "2 - Médio" << endl;
    cout << "3 - Difícil" << endl;
    cout << "4 - Sair" << endl;
    cout << "-> Selecione uma opcão: ";
    cin >> *opcao;
    system("clear || cls");
}

void jogo(int nivel){
    int chute;
    int maxTentativas = 5;
    int nTentativa = 0;
    srand(time(NULL));
    int randMax = 100 * pow(10, nivel - 1);
    int nSecreto = rand() % randMax;
    bool acertou = false;
    double pontos = 1000.00;
    while(nTentativa < maxTentativas){
        system("clear || cls");
        cout << "Qual o seu chute? " << nSecreto << endl;
        cin >> chute;
        if(chute == nSecreto){
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Sua pontuação é: " << pontos << endl;
            acertou = true;
            nTentativa = maxTentativas;
            cout << "Aperte enter para continuar...";
            getchar();
            cin.ignore();
        } else if(chute < nSecreto){
            cout << "O número que chutou está abaixo do número secreto" << endl;
            nTentativa++;
            pontos -= abs((nSecreto - chute)/ (2.0 * pow(10, nivel-1)));
            cout << "Aperte enter para continuar...";
            getchar();
            cin.ignore();
        } else if(chute > nSecreto){
            cout << "O número que chutou está acima do número secreto" << endl;
            nTentativa++;
            pontos -= abs((nSecreto - chute) / (2.0 * pow(10, nivel-1)));
            cout << "Aperte enter para continuar...";
            getchar();
            cin.ignore();
        }
    }
    if(acertou == false){
        system("clear || cls");
        cout << "-> Suas tentativas acabaram!" << endl;
        cout << "O número secreto era " << nSecreto << endl << endl;
        cout << "Aperte enter para continuar...";
        getchar();
        cin.ignore();
    }
}

int main(){
    int opcao = 0;
    bemVindo();
    while(opcao != 4){
        menu(&opcao);
        switch(opcao){
            case 1:{
                jogo(opcao);
                break;
            }
            case 2:{
                jogo(opcao);
                break;
            }
            case 3:{
                jogo(opcao);
                break;
            }
            default:{
                opcao = 4;
                break;
            }
        }
    }
    return 0;
}
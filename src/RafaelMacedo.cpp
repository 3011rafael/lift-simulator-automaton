#include <iostream>
#include <string>
using namespace std;
int main()
{

    enum estados { terreoAberto, terreoFechado, primeiroAberto, primeiroFechado, segundoAberto, segundoFechado , sumidouro}estadoAtual;

    string percurso;
    char alfabeto[3];
    alfabeto[0] = '0';
    alfabeto[1] = '1';
    alfabeto[2] = '2';


    cout<< "\n\t--> Este software simula o funcionamento de um elevador \n\tpara um predio com 3 andares (terreo, primeiro e segundo andar).\n";
    cout<< "\n\t--> O elevador inicia sempre no terreo com as portas abertas.\n";
    cout<< "\n\t--> O elevador pode finalizar o percurso em qualquer andar,\n\tporem apenas com as portas abertas.\n";
    cout<< "\n\t--> O elevador so se movimenta com as portas fechadas.\n";
    cout<< "\n\t--> Para abrir ou fechar a porta do elevador utilize o caractere 0(zero)\n";
    cout<< "\n\t--> Para subir um andar utilize o caractere 1(um).\n";
    cout<< "\n\t--> Para descer um andar utilize o caractere 2(dois).\n\n";





    while(true){

        char caractereLido;
        bool pertence = false;
        bool estadoFinal = true;
        int i, j;
        estadoAtual = terreoAberto;
        percurso = percurso + " " + "Terreo Aberto.";

        cout<< "\t\tNova Cadeia";
        while(true){

            cout<< "\n\tINFORME UM CARACTERE: ";
            cin>> caractereLido;

            pertence = false;
            for(j=0;j<3;j++){
                if(caractereLido == alfabeto[j]){
                    pertence = true;
                }
            }

                if(pertence){
                    if(estadoAtual == terreoAberto){
                        if(caractereLido == '0'){
                            estadoAtual = terreoFechado;
                            percurso = percurso + " " + "Terreo Fechado.";
                            estadoFinal = false;

                        }
                        else{
                            estadoAtual = sumidouro;
                            estadoFinal = false;
                            break;
                        }
                    }
                    else if(estadoAtual == terreoFechado){
                        if(caractereLido == '0'){
                            estadoAtual = terreoAberto;
                            percurso = percurso + " " + "Terreo Aberto.";
                            estadoFinal = true;
                        }
                        else if(caractereLido == '1'){
                            estadoAtual = primeiroFechado;
                            percurso = percurso + " " + "Primeiro Fechado.";
                            estadoFinal = false;
                        }
                        else{
                            estadoAtual = sumidouro;
                            estadoFinal = false;
                            break;
                        }
                    }
                    else if(estadoAtual == primeiroFechado){
                        if(caractereLido == '2'){
                            estadoAtual = terreoFechado;
                            percurso = percurso + " " + "Terreo Fechado.";
                            estadoFinal = false;
                        }
                        else if(caractereLido == '0'){
                            estadoAtual = primeiroAberto;
                            percurso = percurso + " " + "Primeiro Aberto.";
                            estadoFinal = true;
                        }
                        else if(caractereLido == '1')
                        {
                            estadoAtual = segundoFechado;
                            percurso = percurso + " " + "Segundo Fechado.";
                            estadoFinal = false;
                        }
                        else{
                            estadoAtual = sumidouro;
                            estadoFinal = false;
                            break;
                        }
                    }
                    else if(estadoAtual == primeiroAberto){
                        if(caractereLido == '0'){
                            estadoAtual = primeiroFechado;
                            percurso = percurso + " " + "Primeiro Fechado.";
                            estadoFinal = false;
                        }
                        else{
                            estadoAtual = sumidouro;
                            estadoFinal = false;
                            break;
                        }

                    }
                    else if(estadoAtual == segundoFechado){
                        if(caractereLido == '0'){
                            estadoAtual = segundoAberto;
                            percurso = percurso + " " + "Segundo Aberto.";
                            estadoFinal = true;
                        }
                        else if(caractereLido == '2'){
                            estadoAtual = primeiroFechado;
                            percurso = percurso + " " + "Primeiro Fechado.";
                        }
                        else{
                            estadoAtual = sumidouro;
                            estadoFinal = false;
                            break;
                        }
                    }
                    else if(estadoAtual == segundoAberto){
                        if(caractereLido == '0'){
                            estadoAtual = segundoFechado;
                            percurso = percurso + " " + "Segundo Fechado.";
                            estadoFinal = false;
                        }
                        else{
                            estadoAtual = sumidouro;
                            estadoFinal = false;
                            break;
                        }
                    }
                    else if(estadoAtual == sumidouro){
                        estadoAtual = sumidouro;
                    }


                }
                else{
                        if(caractereLido == '.'){
                            break;
                        }
                        else{
                            estadoFinal = false;
                            break;
                        }
                }

            }

            if(estadoFinal == true){
                    cout<<"\n\tCadeia aceita!";
                    cout<<"\n\tVoce passou pelos seguintes estados:\n\t";
                for(i=0; i<percurso.size();i++){
                    cout<<percurso[i];
                    if(percurso[i] == '.'){
                        cout<<"\n\t";
                    }
                }
                percurso.clear();
                cout<<"\n\n";
            }
            else{
                cout<<"\n\tCadeia NAO aceita!\n";
                percurso.clear();
            }
    }


    return 0;
}

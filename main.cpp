#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Acao {
    string ticket;
    int quantidade;
    double precoMedio;
};


map<string, Acao> mapaAcoes;

void registrarCompra() {
    string ticket;
    int quantidade;
    double preco;

    cout << "Digite o ticket: ";
    cin >> ticket;
    cout << "Digite a quantidade: ";
    cin >> quantidade;
    cout << "Digite o preço: ";
    cin >> preco;

    if (mapaAcoes.find(ticket) != mapaAcoes.end()) {

        Acao& acao = mapaAcoes[ticket];
        acao.quantidade += quantidade;
        acao.precoMedio = (acao.precoMedio * acao.quantidade + preco * quantidade) / (acao.quantidade + quantidade);
    } else {

        Acao acao;
        acao.ticket = ticket;
        acao.quantidade = quantidade;
        acao.precoMedio = preco;
        mapaAcoes[ticket] = acao;
    }
}


void registrarVenda() {
    string ticket;
    int quantidade;
    double preco;

    cout << "Digite o ticket: ";
    cin >> ticket;
    cout << "Digite a quantidade: ";
    cin >> quantidade;
    cout << "Digite o preço: ";
    cin >> preco;

    if (mapaAcoes.find(ticket) != mapaAcoes.end()) {
        Acao& acao = mapaAcoes[ticket];
        if (acao.quantidade >= quantidade) {
            acao.quantidade -= quantidade;
        } else {
            cout << "Não há ações suficientes para vender." << endl;
        }
    } else {
        cout << "Ação não encontrada." << endl;
    }
}


void exibirSaldoAcao() {
    string ticket;

    cout << "Digite o ticket: ";
    cin >> ticket;

    if (mapaAcoes.find(ticket) != mapaAcoes.end()) {
        Acao& acao = mapaAcoes[ticket];
        cout << "Saldo da ação: " << acao.quantidade << " - Preço médio: " << acao.precoMedio << endl;
    } else {
        cout << "Ação não encontrada." << endl;
    }
}


void exibirPortfolio() {
    for (auto& acao : mapaAcoes) {
        cout << "Ticket: " << acao.first << " - Quantidade: " << acao.second.quantidade << " - Preço médio: " << acao.second.precoMedio << endl;
    }
}


Acao* buscaBinaria(string ticket) {
    auto it = mapaAcoes.lower_bound(ticket);
    if (it != mapaAcoes.end() && it->first == ticket) {
        return &it->second;
    }
    return nullptr;
}

int main() {
    int escolha;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Registrar compra" << endl;
        cout << "2. Registrar venda" << endl;
        cout << "3. Exibir saldo da acao" << endl;
        cout << "4. Exibir portfolio" << endl;
        cout << "5. Sair" << endl;
        cout << "Digite a escolha: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                registrarCompra();
                break;
            case 2:
                registrarVenda();
                break;
            case 3:
                exibirSaldoAcao();
                break;
            case 4:
                exibirPortfolio();
                break;
            case 5:
                return 0;
            default:
                cout << "Escolha inválida." << endl;
        }
    }

    return 0;
}

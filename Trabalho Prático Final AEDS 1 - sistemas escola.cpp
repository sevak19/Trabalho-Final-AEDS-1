/*H**************************************************************************
*                   FILENAME:           trabalhofinal.cpp                   *
*                                                                           *
*                                                                           *
*                   DESCRIPTION :       Sistema para escolas.               *
*                                                                           *
*                                                                           *
*   Copyright ARTHUR "sevak" COSTA SERRA NEGRA 2024. All rights reserved.   *
*                                                                           *
*                                                                           *
*                   AUTHOR :            Arthur Costa                        *
*                                                                           *
*                   START DATE :        05 Jul 24                           *
*                                                                           *
*                                                                           *
**************************************************************************H*/
#include <iostream>
#include <stdbool.h>
#include <chrono>
#include <thread>
#include <fstream>


#define _MAX 1000

using namespace std;

class Data
{
    private:
        int dia;
        int mes;
        int ano;
    public:
        Data (){
            this->dia = 0;
            this->mes = 0;
            this->ano = 0;
        }
        void setData(int dia, int mes, int ano){
            setDia(dia);
            setMes(mes);
            setAno(ano);
        }
        void setDia(int dia){
            this->dia = dia;
        }
        void setMes(int mes){
            this->mes = mes;
        }
        void setAno(int ano){
            this->ano = ano;
        }
        int getDia() const{
            return this->dia;
        }
        int getMes() const{
            return this->mes;
        }
        int getAno() const{
            return this->ano;
        }
        bool dataValida(int dia, int mes, int ano){
            if(dia > 0 && dia <= 31 && mes > 0 && mes <= 12 && ano > 0 && ano < 2025){
                return true;
            }else{
                return false;
            }
        }
        void lerData(){
            int dia, mes, ano;
            do{
                cout << "Digite o dia: ";
                cin >> dia;
                cout << "Digite o mes: ";
                cin >> mes;
                cout << "Digite o ano: ";
                cin >> ano;
                if(!dataValida(dia, mes, ano)){
                    cout << "[AVISO]: Data Invalida" <<endl;
                }
            }while(!dataValida(dia, mes, ano));
            setData(dia, mes, ano);
        }
        void escrevaData() const{
            cout << getDia() << "/" << getMes() << "/" << getAno() <<endl;
        }
        bool verificaMes(int mes) const {
            return this->mes == mes;
        }
};

class Pessoa
{
    private:
        string nome;
        Data nascimento;
        static int quantidade;
    public:
        Pessoa (){
            this->nome = "Nao cadastrado";
        }
        virtual ~Pessoa() {}
        void setNome(string nome){
            this->nome = nome;
        }
        string getNome() const{
            return this->nome;
        }
        void lerNome(){
            string nome;
            cout << "Digite o nome: ";
            cin >> nome;
            setNome(nome);
        }
        void escrevaNome() const{
            cout << "Nome: " << getNome() <<endl;
        }
        void lerPessoa(){
            lerNome();
            nascimento.lerData();
        }
        virtual void escrevaPessoa() const{
            escrevaNome();
            cout << "Nascimento: ";
            nascimento.escrevaData();
        }
        Data getNascimento() const{
            return nascimento;
        }
        void setNascimento(int dia, int mes, int ano){
            nascimento.setData(dia, mes, ano);
        }
        static int getQuantidade(){
            return quantidade;
        }
        static void incrementarQuantidade(){
            quantidade++;
        }
        static void decrementarQuantidade(){
            quantidade--;
        }
};

int Pessoa::quantidade = 0;

class Aluno : public Pessoa
{
    private:
        int matricula;
        static int quantidade;
    public:
        Aluno(){
            this->matricula = 0;
        }
        virtual ~Aluno() {}
        void setMatricula(int matricula){
            this->matricula = matricula;
        }
        int getMatricula() const{
            return this->matricula;
        }
        void lerAluno(){
            lerPessoa();
            cout << "Digite o numero de matricula: ";
            cin >> matricula;
            setMatricula(matricula);
        }
        void escrevaPessoa() const override {
            Pessoa::escrevaPessoa();
            cout << "Matricula: " << matricula << endl;
        }
        static int getQuantidade(){
            return quantidade;
        }
        static void incrementarQuantidade(){
            quantidade++;
        }
        static void decrementarQuantidade(){
            quantidade--;
        }
};

int Aluno::quantidade = 0;

class Professor : public Pessoa
{
    private:
        string titulacao;
        static int quantidade;
    public:
        Professor(){
            this->titulacao = "Nao cadastrado";
        }
        virtual ~Professor() {}
        void setTitulacao(string titulacao){
            this->titulacao = titulacao;
        }
        string getTitulacao() const{
            return this->titulacao;
        }
        void lerProfessor(){
            lerPessoa();
            cout << "Digite a titulacao: ";
            cin >> titulacao;
            setTitulacao(titulacao);
        }
        void escrevaPessoa() const override {
            Pessoa::escrevaPessoa();
            cout << "Titulacao: " << titulacao << endl;
        }
        static int getQuantidade(){
            return quantidade;
        }
        static void incrementarQuantidade(){
            quantidade++;
        }
        static void decrementarQuantidade(){
            quantidade--;
        }
};

int Professor::quantidade = 0;

int menu() {
    int opcao;
        cout << "\nMenu de Opcoes:" << endl;
        cout << "\n\t0 - Sair" << endl;
        cout << "\t1 - Cadastrar(A/P)" << endl;
        cout << "\t2 - Listar(A/P)" << endl;
        cout << "\t3 - Alterar(A/P)" << endl;
        cout << "\t4 - Excluir(A/P)" << endl;
        cout << "\t5 - Aniversariantes do mes" << endl;
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;
        if(opcao!=0){
            system("clear || cls");
        }
    return opcao;
}

int submenu() {
    int opcao;
    cout << "\n\t0 - Retornar" << endl;
    cout << "\t1 - Aluno" << endl;
    cout << "\t2 - Professor" << endl;
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;
    system("clear || cls");
    return opcao;
}

void cadastrarAluno(Aluno *alunos[], Pessoa *pessoas[]) {
    if (Aluno::getQuantidade() >= _MAX/2) {
        cout << "Capacidade maxima de alunos atingida!" << endl;
        return;
    }

    Aluno* novoAluno = new Aluno();
    novoAluno->lerAluno();
    alunos[Aluno::getQuantidade()] = novoAluno;
    pessoas[Pessoa::getQuantidade()] = novoAluno;
    Aluno::incrementarQuantidade();
    Pessoa::incrementarQuantidade();
}

void cadastrarProfessor(Professor *professores[], Pessoa *pessoas[]) {
    if (Professor::getQuantidade() >= _MAX/2) {
        cout << "Capacidade maxima de professores atingida!" << endl;
        return;
    }

    Professor* novoProfessor = new Professor();
    novoProfessor->lerProfessor();
    professores[Professor::getQuantidade()] = novoProfessor;
    pessoas[Pessoa::getQuantidade()] = novoProfessor;
    Professor::incrementarQuantidade();
    Pessoa::incrementarQuantidade();
}

void listarAlunos(Aluno *alunos[]) {
    int quantidade = Aluno::getQuantidade();
    if (quantidade == 0) {
        cout << "Nenhum aluno cadastrado." << endl;
    }else{
        for (int i = 0; i < Aluno::getQuantidade(); i++) {
            alunos[i]->escrevaPessoa();
           cout << "\n";
        }
    }
}

void listarProfessores(Professor *professores[]) {
    int quantidade = Professor::getQuantidade();
    if (quantidade == 0) {
        cout << "Nenhum professor cadastrado." << endl;
    }else{
        for (int i = 0; i < Professor::getQuantidade(); i++) {
            professores[i]->escrevaPessoa();
            cout << "\n";
        }
    }
}

void alterarAluno(Aluno *alunos[]) {
    int matricula, seguranca;
    int id = -1;
    cout << "Digite a matricula do aluno a ser alterado: ";
    cin >> matricula;
    for(int i = 0; i < Aluno::getQuantidade(); i++) {
        if (alunos[i]->getMatricula() == matricula){
            id = i;
            break;
        }
    }
    if (id < 0 || id > Aluno::getQuantidade()) {
        cout << "Aluno nao encontrado." << endl;
        return;
    }
    cout << "\nDados do sistema:" <<endl;
    alunos[id]->escrevaPessoa();
    cout << "\nTem certeza que deseja alterar os dados do aluno? Esta ação é irreversivel" <<endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Nao" << endl;
    cout << "Escolha uma opcao: ";
    cin >> seguranca;
    if(seguranca == 2){
        system("clear || cls");
        cout << "Ação Cancelada..." << endl;
        return;
    }else if(seguranca == 1){
        cout << "\nNovos dados:" <<endl;
        alunos[id]->lerAluno();
        cout << "\nAlteracao realizada com sucesso!" << endl;
    }else{
        cout << "\nEscolha invalida";
        return;
    }
}

void alterarProfessor(Professor *professores[]) {
    int id, correto, seguranca;
    do{
        cout << "Digite o numero do professor a ser alterado: ";
        cin >> id;
        id -= 1;
        if (id < 0 || id > Professor::getQuantidade()) {
            cout << "Professor nao encontrado." << endl;
            return;
        }
        cout << "\nDados encontrados no sistema:" <<endl;
        professores[id]->escrevaPessoa();
        cout << "\nEncontrou o professor que procurava?" <<endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Nao" << endl;
        cout << "Escolha uma opcao: ";
        cin >> correto;
        if(correto == 2){
             system("clear || cls");
        }
    }while(correto == 2);
    system("clear || cls");
    cout << "Dados do sistema:" <<endl;
    professores[id]->escrevaPessoa();
    cout << "\nTem certeza que deseja alterar os dados do professor? Esta ação é irreversivel" <<endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Nao" << endl;
    cout << "Escolha uma opcao: ";
    cin >> seguranca;
    if(seguranca == 2){
        system("clear || cls");
        cout << "Ação Cancelada..." << endl;
        return;
    }else if(seguranca == 1){
        cout << "\nNovos dados:" <<endl;
        professores[id]->lerProfessor();
        cout << "\nAlteracao realizada com sucesso!" << endl;
    }else{
        cout << "\nEscolha invalida";
        return;
    }
}

void excluirAluno(Aluno *alunos[], Pessoa *pessoas[]) {
    int matricula;
    int seguranca;
    cout << "Digite o numero de matricula do aluno a ser excluido: ";
    cin >> matricula;

    for (int i = 0; i < Aluno::getQuantidade(); i++) {
        if (alunos[i]->getMatricula() == matricula) {
            cout << "\nDados do sistema:" <<endl;
            alunos[i]->escrevaPessoa();
            cout << "\nTem certeza que deseja apagar os dados do aluno? Esta ação é irreversivel" <<endl;
            cout << "1 - Sim" << endl;
            cout << "2 - Nao" << endl;
            cout << "Escolha uma opcao: ";
            cin >> seguranca;
            if(seguranca == 2){
                system("clear || cls");
                cout << "Ação Cancelada..." << endl;
                return;
            }else if(seguranca == 1){
                delete alunos[i];
                alunos[i] = nullptr;

                for (int j = i; j < Aluno::getQuantidade() - 1; j++) {
                    alunos[j] = alunos[j + 1];
                }
                alunos[Aluno::getQuantidade() - 1] = nullptr;

                Aluno::decrementarQuantidade();
                Pessoa::decrementarQuantidade();
                cout << "\nAluno excluido com sucesso!" << endl;
                return;
            }else{
                cout << "\nEscolha invalida";
                return;
            }
        }
    }
    cout << "\nAluno nao encontrado." << endl;
}

void excluirProfessor(Professor *professores[], Pessoa *pessoas[]) {
    int id, correto, seguranca;
    do{
        cout << "Digite o numero do professor a ser excluido: ";
        cin >> id;
        id -= 1;
        if (id < 0 || id > Professor::getQuantidade()-1) {
            cout << "Professor nao encontrado." << endl;
            return;
        }
        cout << "\nDados encontrados no sistema:" <<endl;
        professores[id]->escrevaPessoa();
        cout << "\nEncontrou o professor que procurava?" <<endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Nao" << endl;
        cout << "Escolha uma opcao: ";
        cin >> correto;
        if(correto == 2){
             system("clear || cls");
        }
    }while(correto == 2);
    system("clear || cls");
    cout << "Dados do sistema:" <<endl;
    professores[id]->escrevaPessoa();
    cout << "\nTem certeza que deseja alterar os dados do professor? Esta ação é irreversivel" <<endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Nao" << endl;
    cout << "Escolha uma opcao: ";
    cin >> seguranca;
    if(seguranca == 2){
        system("clear || cls");
        cout << "Ação Cancelada..." << endl;
        return;
    }else if(seguranca == 1){
        delete professores[id];
          professores[id] = nullptr;
        for (int j = id; j < Professor::getQuantidade() - 1; j++) {
            professores[j] = professores[j + 1];
        }
        professores[Professor::getQuantidade() - 1] = nullptr;
        Professor::decrementarQuantidade();
        Pessoa::decrementarQuantidade();
        cout << "\nProfessor excluido com sucesso!" << endl;
        return;
    }else{
        cout << "\nEscolha invalida";
        return;
    }
}


void listarAniversariantesDoMes(Pessoa *pessoas[], int quantidadeTotal, int mes) {
    bool encontrou = false;

    for (int i = 0; i < quantidadeTotal; i++) {
        if (pessoas[i] != nullptr && pessoas[i]->getNascimento().verificaMes(mes)) {
            if(!encontrou){
                cout << "\nANIVERSARIANTES DO MES " << mes << " !!!\n" <<endl;
            }
            pessoas[i]->escrevaPessoa();
            cout << "\n";
            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "\nNenhum aniversariante encontrado no mes " << mes << endl;
    }
}


void salvarDados(Pessoa *pessoas[], Aluno *alunos[], Professor *professores[]) {
    ofstream fileAlunos("alunos.txt");
    ofstream fileProfessores("professores.txt");

    if (!fileAlunos || !fileProfessores) {
        cout << "Erro ao abrir arquivos para salvar dados." << endl;
        return;
    }

    fileAlunos << Aluno::getQuantidade() << endl;
    fileProfessores << Professor::getQuantidade() << endl;

    for (int i = 0; i < Aluno::getQuantidade(); i++) {
        Aluno *aluno = alunos[i];
        fileAlunos << aluno->getNome() << " " << aluno->getNascimento().getDia() << " "
                   << aluno->getNascimento().getMes() << " " << aluno->getNascimento().getAno() << " "
                   << aluno->getMatricula() << endl;
    }

    for (int i = 0; i < Professor::getQuantidade(); i++) {
        Professor *professor = professores[i];
        fileProfessores << professor->getNome() << " " << professor->getNascimento().getDia() << " "
                        << professor->getNascimento().getMes() << " " << professor->getNascimento().getAno() << " "
                        << professor->getTitulacao() << endl;
    }

    fileAlunos.close();
    fileProfessores.close();
}

void carregarDados(Pessoa *pessoas[], Aluno *alunos[], Professor *professores[]) {
    ifstream fileAlunos("alunos.txt");
    ifstream fileProfessores("professores.txt");

    if (!fileAlunos || !fileProfessores) {
        cout << "Arquivos de dados nao encontrados. Criando novos arquivos." << endl;
        return;
    }

    int quantidadeAlunos, quantidadeProfessores;
    fileAlunos >> quantidadeAlunos;
    fileProfessores >> quantidadeProfessores;

    for (int i = 0; i < quantidadeAlunos; i++) {
        Aluno *aluno = new Aluno();
        string nome;
        int dia, mes, ano, matricula;
        fileAlunos >> nome >> dia >> mes >> ano >> matricula;
        aluno->setNome(nome);
        aluno->setNascimento(dia, mes, ano);
        aluno->setMatricula(matricula);
        alunos[i] = aluno;
        pessoas[i] = aluno;
        Aluno::incrementarQuantidade();
        Pessoa::incrementarQuantidade();
    }

    for (int i = 0; i < quantidadeProfessores; i++) {
        Professor *professor = new Professor();
        string nome, titulacao;
        int dia, mes, ano;
        fileProfessores >> nome >> dia >> mes >> ano >> titulacao;
        professor->setNome(nome);
        professor->getNascimento().setData(dia, mes, ano);
        professor->setTitulacao(titulacao);
        professores[i] = professor;
        pessoas[Aluno::getQuantidade() + i] = professor;
        Professor::incrementarQuantidade();
        Pessoa::incrementarQuantidade();
    }

    fileAlunos.close();
    fileProfessores.close();
}

int main()
{
    Pessoa *pessoas[_MAX] = { nullptr };
    Aluno *alunos[_MAX/2] = { nullptr };
    Professor *professores[_MAX/2] = { nullptr };

    carregarDados(pessoas, alunos, professores);

    int opcao;
    int subOpcao;
    int quantidadeTotal;
    try{
        do {
            opcao = menu();

            switch (opcao) {
            case 0:
                system("clear || cls");
                cout << "\nSalvando dados, por favor aguarde." << endl;
                salvarDados(pessoas, alunos, professores);
                cout << "\nSaindo..." << endl;
                break;
            case 1:
                cout << "\nSubmenu de Cadastro:" << endl;
                subOpcao = submenu();
                if (subOpcao == 1){
                    cadastrarAluno(alunos, pessoas);
                    cout << "\nCadastro do aluno realizado com sucesso!" <<endl;
                }else if (subOpcao == 2){
                    cadastrarProfessor(professores, pessoas);
                    cout << "\nCadastro do professor realizado com sucesso!" <<endl;
                }else if (subOpcao == 0){
                    system("clear || cls");
                    break;
                }else{
                    system("clear || cls");
                    cout << "Opcao invalida\n";
                }
                cout << "\nPressione Enter para voltar ao menu...";
                cin.ignore();
                cin.get();
                system("clear || cls");
                break;
            case 2:
                cout << "\nSubmenu de Listagem:" << endl;
                subOpcao = submenu();
                if (subOpcao == 1) {
                    listarAlunos(alunos);
                } else if (subOpcao == 2) {
                    listarProfessores(professores);
                }else if (subOpcao == 0){
                    system("clear || cls");
                    break;
                }else{
                    system("clear || cls");
                    cout << "Opcao invalida\n";
                }
                cout << "\nPressione Enter para voltar ao menu...";
                cin.ignore();
                cin.get();
                system("clear || cls");
                break;
            case 3:
                cout << "\nSubmenu de Alteracao:" << endl;
                subOpcao = submenu();
                if (subOpcao == 1) {
                    alterarAluno(alunos);
                } else if (subOpcao == 2) {
                    alterarProfessor(professores);
                }else if (subOpcao == 0){
                    system("clear || cls");
                    break;
                }else{
                    system("clear || cls");
                    cout << "Opcao invalida\n";
                }
                cout << "\nPressione Enter para voltar ao menu...";
                cin.ignore();
                cin.get();
                system("clear || cls");
                break;
            case 4:
                cout << "\nSubmenu de Exclusao:" << endl;
                subOpcao = submenu();
                if (subOpcao == 1) {
                    excluirAluno(alunos, pessoas);
                } else if (subOpcao == 2) {
                    excluirProfessor(professores, pessoas);
                }else if (subOpcao == 0){
                    system("clear || cls");
                    break;
                }else{
                    system("clear || cls");
                    cout << "Opcao invalida\n";
                }
                cout << "\nPressione Enter para voltar ao menu...";
                cin.ignore();
                cin.get();
                system("clear || cls");
                break;
            case 5:
                quantidadeTotal = Pessoa::getQuantidade();
                int mes;
                cout << "Digite o mes para listar os aniversariantes: ";
                cin >> mes;
                listarAniversariantesDoMes(pessoas, quantidadeTotal, mes);
                cout << "\nPressione Enter para voltar ao menu...";
                cin.ignore();
                cin.get();
                system("clear || cls");
                break;
            default:
                cout << "[AVISO] Opcao invalida! Tente novamente." << endl;
                cout << "\nPressione Enter para voltar ao menu...";
                cin.ignore();
                cin.get();
                system("clear || cls");
                break;
            }
        } while (opcao != 0);
    } catch (bad_alloc const&) {
        cerr << "Erro: Falha na alocação de memória!" << endl;
        return 1;
    }

    return 0;
}

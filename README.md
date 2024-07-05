# Sistema de Gerenciamento de Alunos e Professores

Este projeto consiste em um sistema de gerenciamento de alunos e professores, desenvolvido como trabalho final para a disciplina de Algoritmos e Estrutura de Dados 1 (AEDS 1) na PUC MG. O sistema permite cadastrar, manipular e exibir informações sobre alunos e professores em um ambiente acadêmico.

# Funcionalidades

Para Alunos:

-Cadastro de novos alunos com nome, data de nascimento e matrícula.
-Exibição dos dados de um aluno específico.
-Contagem total de alunos cadastrados no sistema.

Para Professores:

-Cadastro de novos professores com nome, data de nascimento e titulação.
-Exibição dos dados de um professor específico.
-Contagem total de professores cadastrados no sistema.

# Estrutura do Projeto

O projeto está estruturado em três classes principais:

-Pessoa: Classe base que encapsula informações básicas como nome e data de nascimento.

-Aluno: Subclasse de Pessoa que adiciona a matrícula do aluno.

-Professor: Subclasse de Pessoa que adiciona a titulação do professor.

Além disso, há uma classe auxiliar Data para manipulação e validação de datas.

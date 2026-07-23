# Guia de Git e Conventional Commits para Trabalho em Dupla

## Parte 1 — Fundamentos do Git

### O que é o Git?
Git é um sistema de controle de versão: ele guarda o histórico de todas as mudanças no código, permitindo que várias pessoas trabalhem no mesmo projeto sem sobrescrever o trabalho umas das outras.

### Conceitos essenciais

| Termo | O que significa |
|---|---|
| **Repositório (repo)** | A pasta do projeto, com todo o histórico versionado |
| **Commit** | Um "salvamento" com uma mensagem explicando o que mudou |
| **Branch (ramo)** | Uma linha de desenvolvimento separada, para não bagunçar o código principal |
| **Merge** | Juntar as mudanças de uma branch em outra |
| **Pull Request (PR)** | Pedido para revisar e juntar seu código com o de outra pessoa (usado no GitHub/GitLab) |
| **Remote** | A versão do repositório hospedada online (ex: GitHub) |
| **Conflito** | Quando duas pessoas mudam a mesma linha de código e o Git não sabe qual manter |

### Comandos do dia a dia

```bash
# Configuração inicial (só uma vez por máquina)
git config --global user.name "Seu Nome"
git config --global user.email "seu@email.com"

# Clonar um repositório existente
git clone https://github.com/usuario/projeto.git

# Ver o estado atual (o que mudou, o que está pronto pra commit)
git status

# Ver o histórico de commits
git log --oneline

# Adicionar mudanças para o próximo commit
git add nome-do-arquivo.js
git add .              # adiciona tudo que mudou

# Criar um commit
git commit -m "mensagem explicando a mudança"

# Enviar commits para o repositório remoto (GitHub, por exemplo)
git push

# Buscar mudanças que outra pessoa enviou
git pull

# Criar e trocar de branch
git checkout -b nome-da-branch

# Trocar de branch (sem criar)
git checkout nome-da-branch

# Juntar uma branch na atual
git merge nome-da-branch
```

---

## Parte 2 — Fluxo de trabalho em dupla

Trabalhar em dupla sem organização costuma gerar conflitos e confusão sobre quem fez o quê. Um fluxo simples e eficaz:

### 1. Cada funcionalidade em uma branch separada
Nunca trabalhem os dois direto na `main`/`master`. Para cada tarefa, criem uma branch nova:

```bash
git checkout -b feature/tela-de-login
```

Convenção comum de nomes de branch:
- `feature/nome-da-feature` — nova funcionalidade
- `fix/nome-do-bug` — correção de bug
- `docs/algo` — documentação

### 2. Commits pequenos e frequentes
Prefiram vários commits pequenos, cada um representando uma mudança lógica, em vez de um commit gigante com tudo junto. Isso facilita identificar quem fez o quê e reverter algo específico se precisar.

### 3. Pull Requests para revisão
Antes de juntar sua branch na `main`, abram um Pull Request no GitHub. Isso permite que a outra pessoa revise o código antes de ele entrar no projeto principal.

### 4. Puxem antes de começar a trabalhar
Sempre rodem `git pull` antes de começar a mexer no código, para evitar trabalhar em cima de uma versão desatualizada.

### 5. Resolvendo conflitos
Quando o Git não consegue juntar automaticamente duas mudanças na mesma linha, ele marca o conflito no arquivo assim:

```
seu código
```

Vocês decidem juntos qual versão (ou combinação) manter, apagam essas marcações, e fazem um novo commit.

---

## Parte 3 — Conventional Commits

### O que é?
É um padrão para escrever mensagens de commit de forma estruturada, facilitando entender o histórico do projeto rapidamente — algo essencial quando duas pessoas mexem no mesmo código.

### Formato básico

```
tipo(escopo opcional): descrição curta

corpo opcional explicando mais detalhes
```

### Tipos mais usados

| Tipo | Quando usar |
|---|---|
| `feat` | Nova funcionalidade |
| `fix` | Correção de bug |
| `docs` | Mudança só na documentação |
| `style` | Formatação, espaços, ponto e vírgula (sem mudar lógica) |
| `refactor` | Reorganização do código sem mudar comportamento |
| `test` | Adição ou ajuste de testes |
| `chore` | Tarefas de manutenção (configs, dependências, etc.) |
| `perf` | Melhoria de performance |

### Exemplos práticos

```bash
git commit -m "feat: adiciona validação de e-mail no formulário de cadastro"
git commit -m "fix: corrige erro ao salvar usuário sem senha"
git commit -m "docs: atualiza README com instruções de instalação"
git commit -m "refactor: separa lógica de autenticação em função própria"
git commit -m "style: ajusta indentação do arquivo main.js"
git commit -m "test: adiciona teste para função de login"
git commit -m "chore: atualiza dependências do projeto"
```

### Usando escopo (opcional, mas útil em dupla)
O escopo ajuda a identificar em qual parte do projeto a mudança aconteceu — muito útil quando cada pessoa está mexendo em uma área diferente:

```bash
git commit -m "feat(login): adiciona botão de 'esqueci minha senha'"
git commit -m "fix(carrinho): corrige cálculo do total com desconto"
```

### Mudanças que quebram compatibilidade
Se a mudança quebra algo que já existia, adiciona-se `!` depois do tipo:

```bash
git commit -m "feat!: remove suporte à API antiga de login"
```

### Por que isso ajuda vocês dois
- Dá pra rodar `git log --oneline` e entender rapidinho o que cada pessoa fez, sem precisar abrir cada arquivo.
- Fica fácil filtrar só os `fix` (bugs corrigidos) ou só os `feat` (novidades).
- Se quiserem, dá pra gerar um changelog automático a partir dessas mensagens no futuro.

---

## Parte 4 — Fluxo resumido sugerido para vocês dois

```bash
# 1. Antes de começar, atualize sua cópia local
git checkout main
git pull

# 2. Crie uma branch para a tarefa
git checkout -b feature/nome-da-tarefa

# 3. Trabalhe e vá commitando em pequenos passos
git add .
git commit -m "feat: implementa X"

# 4. Envie a branch para o GitHub
git push -u origin feature/nome-da-tarefa

# 5. Abra um Pull Request no GitHub para o outro revisar

# 6. Depois de aprovado, faça o merge na main
```

### Dica final
Combinem entre vocês, desde o início, um padrão comum (tipos de commit, nomes de branch etc.) e escrevam isso num arquivo `CONTRIBUTING.md` no repositório. Assim, mesmo que um dos dois esqueça, é só consultar.

# CTODO

#### With this project I learned a lot about structs, macros and was my first time using `libgcrypt`

> ⚠ **This program was made to work on linux, I think it cannot be runned in windows 🤷**

CTODO is a program made for saving todos in a secure or/and insecure way.
It has it's own custom file format, (also my first time creating a working file format from scratch).
Hope you found this useful! Have a nice day.

### Compiling

Before compiling you should have `libgcrypt20-dev` installed, then you can just run the command below:

```
gcc ctodo.c -o ctodo
```

### Running

To run the program you just need to execute the output file.

```
./ctodo
```

# CTODO

#### Com este projeto eu aprendi imenso acerca de structs, macros, static, typedef e foi a minha primeira vez a trabalhar com criptografia em C (com a `libgcrypt`)

> ⚠ **Este programa foi feito pra rodar no linux, mas nunca foi testada sua compatibilidade com o windows, então eu acho que não deve rodar lá**

CTODO é um programa feito para guardar tarefas de uma forma segura ou/e não segura.
O programa tem o seu próprio ficheiro (.ctodo), e pela primeira vez criei um formato de ficheiro do 0 😄
Espero que este programa seja-lhe útil. Caso não seja útil, espero apenas que gosto do projeto 😎.
Tenha um bom dia e almoço _(de preferência um almoço saudável, com salada)_.

### Compilar

Antes de compilar o programa, certifique-se que tem `libgcrypt20-dev` instalado.

```
gcc ctodo.c -o ctodo
```

### Rodar

Ah, para rodar é só executar o ficheiro. Tenha cuidado pois pode explodir 😮

```
./ctodo
```

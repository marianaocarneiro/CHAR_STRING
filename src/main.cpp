#include <Arduino.h>
#include <string.h> //? strlen, strcpy, strcat, strcmp e strchr.
#include <stdlib.h> //? atoi.

void textoChar();
void textoString();

void setup()
{
  Serial.begin(9600);
  Serial.println();
  textoChar();
  textoString();
}

void loop()
{
}

void textoChar()
{
  //* Texto literal.
  //? Use const char* quando o texto não será alterado.
  const char cidade[] = "Sao Paulo";
  Serial.println(cidade);

  //* Descobrindo o tamnho dos textos.
  //? strlen conta quantos caracteres antes do '\0'.
  int tamanhoTextoCidade = strlen(cidade);
  Serial.print("Comprimento do texto: ");
  Serial.println(tamanhoTextoCidade);

  //* Descobrindo o tamanho ocupado no memória.
  //? o sizeof() retornará um byte a mais que o comprimento por causa do '\0'.
  int tamanhoVariavelCidade = sizeof(cidade);
  Serial.print("Espaço Utilizado: ");
  Serial.println(tamanhoVariavelCidade);

  //? O caractere \0 é colocado automaticamente quando escrevemos um texto entre " ".
  char vetorTexto[8] = {'M', 'A', 'R', 'I', 'A', 'N', 'A', '\0'};
  Serial.println(vetorTexto);

  //* Comparar texto.
  const char *cidade1 = "Sao Caetano";
  const char *cidade2 = "Sao Caetano";

  if (strcmp(cidade1, cidade2) == 0)
    Serial.println("Os textos são iguais.");

  else
    Serial.println("Os textos são diferentes");
  //? strcmp analiza a ordem lexica das palavras,
  //? se a primeira palavra vem antes que a segunda o valor
  //? retornado será menos que zero, se a primeira palavra
  //? vem após a segunda o retorno será maior que zero.

  //* TEXTO EDITAVEL COM char[].
  char nomeAluno[20] = "Maryana";
  Serial.println(nomeAluno);

  //* Alterando caracteres individualmente.
  nomeAluno[3] = 'i';
  Serial.println(nomeAluno);

  //* Copiando outro texto para dentro do vetor.
  //! CUIDADO: o vetor precisa ter espaço suficiente.
  strcpy(nomeAluno, "Carneiro");
  Serial.println(nomeAluno);

  //* Concatenando.
  char frase[50] = "Bom ";
  strcat(frase, "Dia!");
  Serial.println(frase);

  //* Procurando um caractere no texto.
  char *posicaoLetra = strchr(frase, 'B');

  //? NULL = '/0'
  if (posicaoLetra != NULL)
  {
    Serial.println("Letra encontrada");
    Serial.println(posicaoLetra);
  }

  else
  {
    Serial.println("Letra não encontrada");
  }

  //* Convertendo texto numérico para inteiro.
  char idadeTexto[] = "45"; //? Esse VETOR contém: 52, 53, \0.
  int idade = atoi(idadeTexto);
  Serial.println(idade);
}

void textoString()
{
  //* USANDO STRING.
  String nome = "Mariana!";
  String curso = "Logica de programação";
  String mensagem = "Oi";

  //* Concatenando Strings.
  mensagem = mensagem + ", " + nome + " Bem vindo(a) ao curso de " + curso + ".";
  Serial.println(mensagem);

  //* Tamanho da String 
  int tamanhoMensagem = mensagem.length();
  Serial.print("Tamanho da String em letras: ");
  Serial.println(tamanhoMensagem);

  //* Acessando um caractere em uma posicao específica.
  char primeiraLetra = mensagem.charAt(0);
  Serial.print("Primeira Letra: ");
  Serial.println(primeiraLetra);

  //? Também é possivel acessar com colchetes.
  char segundaLetra = mensagem[1];
  Serial.print("Segunda Letra: ");
  Serial.println(segundaLetra);

  //* Procurando um texto dentro da String.
  int posicaoTextoProcurado = mensagem.indexOf("curso");
  Serial.println(posicaoTextoProcurado);

  //* Extraindo um texto de dentro da String.
int inicioNomeCurso = posicaoTextoProcurado + 9; //? Posição da palavra curso + 9 caracteres.
Serial.println(mensagem.substring(inicioNomeCurso, tamanhoMensagem));

//* Substituindo um texto de dentro da String.
mensagem.replace("Oi," , "Ola, tudo bem?");
Serial.println(mensagem);

//* Convertendo para maiúsculas.
mensagem.toUpperCase();
Serial.println(mensagem);

//* Convertendo para minúsculas.
mensagem.toLowerCase();
Serial.println(mensagem);

//* Convertendo texto numérico para inteiro.
String textoNumero = "123";
int numero = textoNumero.toInt();
Serial.println(numero * 2);

//* Verificando se a String está vazia.
String textoVazio = "";
if(textoVazio.length() == 0)
Serial.println("O texto está vazio.");

//* Convertendo String para const char*.
//? Isso é útil quando alguma biblioteca espera texto estilo C.
const char* textoComoChar = mensagem.c_str();
Serial.println(textoComoChar);

//TODO printf
}
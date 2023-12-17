#include <LiquidCrystal.h> // Inclui a biblioteca da Liquid Crystal.

LiquidCrystal lcd(12, 13, 7, 6, 5, 4); // Pinos que estão conectados na protoboard.

void setup() {
  lcd.begin(16, 2);  // Inicia o display.
  randomSeed(millis());  // Inicia uma semente aleatória com base no horário do sistema operacional.
}

void loop() {
  lcd.clear();  // Limpa o display.
  
  lcd.setCursor(3, 0);  // Determina a posição do cursor.
  lcd.print("Seu Token:"); // Imprime a mensagem "Seu Token:" na coluna 3 e linha 0.
  
  String token = gerarStringAleatoria(6); // Gera uma string aleatória com 6 caracteres.
  lcd.setCursor(5, 1);  // Determina a posição do cursor.
  lcd.print(token); // Imprime a string aleatória gerada na coluna 5 e linha 1.
  
  delay(2000);  // Espera 10 segundos antes de gerar uma nova string.
}

  String gerarStringAleatoria(int tamanho) { // Itera "n" vezes até chegar em 6 caracteres.
    String caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // Cria uma string com todos os caracteres possíveis.
    String token = ""; // Imprime os caracteres gerados com a string.
  
  for (int i = 0; i < tamanho; i++) {
    int indice = random(caracteres.length()); // Cria uma string adicionando um novo caractere aleatório a cada iteração do loop, até que a string alcance o tamanho desejado.
    token += caracteres.charAt(indice); // Obtem um caracter em uma determinada posição da string, o valor retornado é o que está na posição do índice da string caracteres.
  }
  
  return token; // Retorna a string aleatória gerada.
}
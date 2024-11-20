// Tabela de conexão dos pinos do Arduino Nano com o cubo de LEDs
// -------------------------------------------------------------------------------------------------------
// | **Coluna (Positivo)** | **Pino no Arduino Nano** | **Camada (Negativo)** | **Pino no Arduino Nano** |
// |-----------------------|--------------------------|-----------------------|--------------------------|
// | Coluna 0              | D2                       | Camada 0              | A0                       |
// | Coluna 1              | D3                       | Camada 1              | A1                       |
// | Coluna 2              | D4                       | Camada 2              | A2                       |
// | Coluna 3              | D5                       | Camada 3              | A3                       |
// | Coluna 4              | D6                       |                       |                          |
// | Coluna 5              | D7                       |                       |                          |
// | Coluna 6              | D8                       |                       |                          |
// | Coluna 7              | D9                       |                       |                          |
// | Coluna 8              | 1                        |                       |                          |
// | Coluna 9              | 0                        |                       |                          |
// | Coluna 10             | A5                       |                       |                          |
// | Coluna 11             | A4                       |                       |                          |
// | Coluna 12             | 10                       |                       |                          |
// | Coluna 13             | 11                       |                       |                          |
// | Coluna 14             | 12                       |                       |                          |
// | Coluna 15             | 13                       |                       |                          |
// -------------------------------------------------------------------------------------------------------
// Define pinos para as colunas e camadas
int Colunas[] = {2, 3, 4, 5, 6, 7, 8, 9, 1, 0, A5, A4, 10, 11, 12, 13};
int Filas[] = {A0, A1, A2, A3};

// Velocidade de acendimento
int vel = 200;         // Tempo em milissegundos para as colunas
int velCamadas = 200;  // Tempo em milissegundos para as camadas

void setup() 
{
  // Configura colunas como saída e inicializa desligadas
  for (int i = 0; i < 16; i++) {
    pinMode(Colunas[i], OUTPUT);
    digitalWrite(Colunas[i], LOW);
  }
  
  // Configura camadas como saída e inicializa desligadas
  for (int i = 0; i < 4; i++) {
    pinMode(Filas[i], OUTPUT);
    digitalWrite(Filas[i], LOW);
  }
}

void loop() 
{
  acendertodososleds();
  acenderumledporvez();
 acenderPorCamadas();
  acenderdadireitaparaesquerda();
  acenderdefretepratans();
}

// Função 1: Acender todos os LEDS de uma vez
void acendertodososleds()
{
  // Liga todas as colunas
  for (int col = 0; col < 16; col++) {
    digitalWrite(Colunas[col], HIGH);
  }

  // Liga todas as camadas
  for (int fila = 0; fila < 4; fila++) {
    digitalWrite(Filas[fila], HIGH);
  }

  // Mantém todos os LEDs acesos por um tempo (ajustar o delay se necessário)
  delay(1000);

  // Apaga todas as colunas
  for (int col = 0; col < 16; col++) {
    digitalWrite(Colunas[col], LOW);
  }

  // Apaga todas as camadas
  for (int fila = 0; fila < 4; fila++) {
    digitalWrite(Filas[fila], LOW);
  }

  // Pequena pausa antes de repetir
  delay(500);
}

// Função 2: Acender um LED de cada vez
void acenderumledporvez()
{
  // Percorre cada camada
  for (int camada = 0; camada < 4; camada++) {
    digitalWrite(Filas[camada], HIGH); // Liga a camada atual

    // Percorre cada LED da camada (colunas)
    for (int col = 0; col < 16; col++) {
      digitalWrite(Colunas[col], HIGH);  // Acende o LED da coluna
      delay(vel);  // Aguarda um tempo
      digitalWrite(Colunas[col], LOW);   // Apaga o LED da coluna
    }

    digitalWrite(Filas[camada], LOW); // Desliga a camada atual
  }
}

// Função 3: Acender todos os LEDs de uma camada por vez
void acenderPorCamadas() 
{
  // Loop para acender as camadas de 0 a 3
  for (int camada = 0; camada < 4; camada++) {
    digitalWrite(Filas[camada], HIGH); // Liga a camada atual

    // Acende todas as colunas
    for (int col = 0; col < 16; col++) {
      digitalWrite(Colunas[col], HIGH);
    }
    
    delay(velCamadas); // Aguarda um pouco com a camada acesa

    // Apaga todas as colunas
    for (int col = 0; col < 16; col++) {
      digitalWrite(Colunas[col], LOW);
    }

    digitalWrite(Filas[camada], LOW); // Desliga a camada atual
    delay(100); // Pequena pausa antes de passar para a próxima camada
  }
  
  // Loop inverso para acender as camadas de 3 a 0
  for (int camada = 3; camada >= 0; camada--) {
    digitalWrite(Filas[camada], HIGH); // Liga a camada atual

    // Acende todas as colunas
    for (int col = 0; col < 16; col++) {
      digitalWrite(Colunas[col], HIGH);
    }
    
    delay(velCamadas); // Aguarda um pouco com a camada acesa

    // Apaga todas as colunas
    for (int col = 0; col < 16; col++) {
      digitalWrite(Colunas[col], LOW);
    }

    digitalWrite(Filas[camada], LOW); // Desliga a camada atual
    delay(100); // Pequena pausa antes de passar para a próxima camada
  }
}

// Função 4: Acender blocos de 4 colunas da coluna 0 até a coluna 15
void acenderBlocosCrescentes() 
{
  for (int col = 0; col < 16; col += 4) {
    // Acende um bloco de 4 colunas simultaneamente
    for (int j = 0; j < 4; j++) {
      if (col + j < 16) {
        digitalWrite(Colunas[col + j], HIGH);
      }
    }

    // Liga todas as camadas
    for (int camada = 0; camada < 4; camada++) {
      digitalWrite(Filas[camada], HIGH);
    }

    delay(velCamadas); // Aguarda um pouco

    // Apaga todas as colunas
    for (int j = 0; j < 4; j++) {
      if (col + j < 16) {
        digitalWrite(Colunas[col + j], LOW);
      }
    }

    // Desliga todas as camadas
    for (int camada = 0; camada < 4; camada++) {
      digitalWrite(Filas[camada], LOW);
    }

    delay(vel);  // Aguarda para o próximo ciclo de colunas
  }
}

// Função 5: Acender blocos de 4 colunas da direita para esquerda
void acenderdadireitaparaesquerda() 
{
    // Acender os blocos da direita para a esquerda
    for (int col = 12; col >= 0; col -= 4) {
        // Liga todas as camadas
        for (int camada = 0; camada < 4; camada++) {
            digitalWrite(Filas[camada], HIGH);
        }

        // Acende um bloco de 4 colunas simultaneamente
        for (int j = 0; j < 4; j++) {
            if (col + j < 16) {
                digitalWrite(Colunas[col + j], HIGH);
            }
        }

        delay(velCamadas); // Aguarda um pouco

        // Apaga todas as colunas
        for (int j = 0; j < 4; j++) {
            if (col + j < 16) {
                digitalWrite(Colunas[col + j], LOW);
            }
        }

        // Desliga todas as camadas
        for (int camada = 0; camada < 4; camada++) {
            digitalWrite(Filas[camada], LOW);
        }

        delay(vel);  // Aguarda para o próximo ciclo de colunas
    }

    // Agora acender os blocos da esquerda para a direita
    for (int col = 0; col <= 12; col += 4) {
        // Liga todas as camadas
        for (int camada = 0; camada < 4; camada++) {
            digitalWrite(Filas[camada], HIGH);
        }

        // Acende um bloco de 4 colunas simultaneamente
        for (int j = 0; j < 4; j++) {
            if (col + j < 16) {
                digitalWrite(Colunas[col + j], HIGH);
            }
        }

        delay(velCamadas); // Aguarda um pouco

        // Apaga todas as colunas
        for (int j = 0; j < 4; j++) {
            if (col + j < 16) {
                digitalWrite(Colunas[col + j], LOW);
            }
        }

        // Desliga todas as camadas
        for (int camada = 0; camada < 4; camada++) {
            digitalWrite(Filas[camada], LOW);
        }

        delay(vel);  // Aguarda para o próximo ciclo de colunas
    }
}


// Função 6: Efeito de varredura por coluna com todas as camadas ligadas
void acenderdefretepratans() {
    // Acende todas as filas
    for (int i = 0; i < 4; i++) {
        digitalWrite(Filas[i], HIGH);
    }
    
    // Define as colunas a serem acesas para o primeiro padrão
    int primeiroPadrao[] = {0, 4, 8, 12};
    acenderColunas(primeiroPadrao, 4);
    
    // Repete a sequência para diferentes padrões
    int segundoPadrao[] = {1, 5, 9, 13};
    int terceiroPadrao[] = {2, 6, 10, 14};
    int quartoPadrao[] = {3, 7, 11, 15};

    acenderColunas(segundoPadrao, 4);
    acenderColunas(terceiroPadrao, 4);
    acenderColunas(quartoPadrao, 4);
    
    // Repete o quarto padrão duas vezes como no código original
    acenderColunas(quartoPadrao, 4);
    acenderColunas(terceiroPadrao, 4);
    acenderColunas(segundoPadrao, 4);
    
    // Reseta as filas após todos os padrões
    for (int i = 0; i < 4; i++) {
        digitalWrite(Filas[i], LOW);
    }
}

void acenderColunas(int colunas[], int tamanho) {
    // Acende as colunas especificadas
    for (int i = 0; i < tamanho; i++) {
        digitalWrite(Colunas[colunas[i]], HIGH);
    }
    delay(velCamadas); // Aguarda um pouco

    // Apaga as colunas especificadas
    for (int i = 0; i < tamanho; i++) {
        digitalWrite(Colunas[colunas[i]], LOW);
    }
    delay(velCamadas); // Aguarda um pouco
}

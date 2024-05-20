#define NOTE_D4  294
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_A5  880

int tons[4] = { NOTE_A5, NOTE_A4, NOTE_G4, NOTE_D4 };
int sequencia[100] = {};
int rodada_atual = 0;
int passo_atual_na_sequencia = 0;
int pinoAudio = 10;
int pinosLeds[4] = { 6, 7, 8, 9 };
int pinosBotoes[4] = { 2, 3, 4, 5 };
int botao_pressionado = 0;
int perdeu_o_jogo = false;
int triggerPin = 13; // Pino do trigger do sensor ultrassônico
int echoPin = 12;    // Pino do echo do sensor ultrassônico
int iniciarJogo = false; // Variável para iniciar o jogo

void setup() {
  for (int i = 0; i <= 3; i++) {
    pinMode(pinosLeds[i], OUTPUT);
  }
  for (int i = 0; i <= 3; i++) {
    pinMode(pinosBotoes[i], INPUT);
  }
  pinMode(pinoAudio, OUTPUT);
  pinMode(triggerPin, OUTPUT); // Configura o pino do trigger como saída
  pinMode(echoPin, INPUT);     // Configura o pino do echo como entrada
  randomSeed(analogRead(0));
}

void loop() {
  if (perdeu_o_jogo) {
    rodada_atual = 0;
    passo_atual_na_sequencia = 0;
    perdeu_o_jogo = false;
    iniciarJogo = false;
  }

  if (rodada_atual == 0 && !iniciarJogo) {
    while (!iniciarJogo) {
      iniciarJogo = verificarDistancia() < 10; // Aguarda até o jogo ser iniciado pelo sensor de distância
      delay(100);
    }
    tocarSomDeInicio();
    delay(1000);
  }

  proximaRodada();
  reproduzirSequencia();
  aguardarJogador();
  delay(1000);

  if (perdeu_o_jogo) {
    // Se perdeu, reinicia o jogo e aguarda a aproximação do sensor
    perdeu_o_jogo = false;
    rodada_atual = 0;
    passo_atual_na_sequencia = 0;
    iniciarJogo = false;
    while (!iniciarJogo) {
      iniciarJogo = verificarDistancia() < 10; // Aguarda até o jogo ser reiniciado pelo sensor de distância
      delay(100);
    }
    tocarSomDeInicio();
    delay(1000);
  }
}

void proximaRodada() {
  int numero_sorteado = random(0, 4);
  sequencia[rodada_atual++] = numero_sorteado;
}

void reproduzirSequencia() {
  for (int i = 0; i < rodada_atual; i++) {
    tone(pinoAudio, tons[sequencia[i]]);
    digitalWrite(pinosLeds[sequencia[i]], HIGH);
    delay(500);
    noTone(pinoAudio);
    digitalWrite(pinosLeds[sequencia[i]], LOW);
    delay(100);
  }
  noTone(pinoAudio);
}

void aguardarJogador() {
  for (int i = 0; i < rodada_atual; i++) {
    aguardarJogada();
    verificarJogada();
    if (perdeu_o_jogo) {
      return; // Sai da função se o jogador perdeu
    }
    passo_atual_na_sequencia++;
  }
  passo_atual_na_sequencia = 0;
}

void aguardarJogada() {
  boolean jogada_efetuada = false;
  while (!jogada_efetuada) {
    for (int i = 0; i <= 3; i++) {
      if (digitalRead(pinosBotoes[i]) == HIGH) {
        botao_pressionado = i;
        tone(pinoAudio, tons[i]);
        digitalWrite(pinosLeds[i], HIGH);
        delay(300);
        digitalWrite(pinosLeds[i], LOW);
        noTone(pinoAudio);
        jogada_efetuada = true;
      }
    }
    delay(10);
  }
}

void verificarJogada() {
  if (sequencia[passo_atual_na_sequencia] != botao_pressionado) {
    for (int i = 0; i <= 3; i++) {
      tone(pinoAudio, tons[i]);
      digitalWrite(pinosLeds[i], HIGH);
      delay(200);
      digitalWrite(pinosLeds[i], LOW);
      noTone(pinoAudio);
    }

    tone(pinoAudio, tons[3]);
    for (int i = 0; i <= 3; i++) {
      digitalWrite(pinosLeds[0], HIGH);
      digitalWrite(pinosLeds[1], HIGH);
      digitalWrite(pinosLeds[2], HIGH);
      digitalWrite(pinosLeds[3], HIGH);
      delay(100);
      digitalWrite(pinosLeds[0], LOW);
      digitalWrite(pinosLeds[1], LOW);
      digitalWrite(pinosLeds[2], LOW);
      digitalWrite(pinosLeds[3], LOW);
      delay(100);
    }
    noTone(pinoAudio);
    perdeu_o_jogo = true;
  }
}

void tocarSomDeInicio() {
  tone(pinoAudio, tons[0]);
  digitalWrite(pinosLeds[0], HIGH);
  digitalWrite(pinosLeds[1], HIGH);
  digitalWrite(pinosLeds[2], HIGH);
  digitalWrite(pinosLeds[3], HIGH);
  delay(500);
  digitalWrite(pinosLeds[0], LOW);
  digitalWrite(pinosLeds[1], LOW);
  digitalWrite(pinosLeds[2], LOW);
  digitalWrite(pinosLeds[3], LOW);
  delay(500);
  noTone(pinoAudio);
}

long verificarDistancia() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  return pulseIn(echoPin, HIGH) / 58.2;
}
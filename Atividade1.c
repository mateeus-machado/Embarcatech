#include "pico/stdlib.h" 
#include <stdio.h>

// Definição do pino para o LED
#define LED_PIN 12

// Definição dos tempos em milissegundos
#define TEMPO_PONTO 200
#define TEMPO_TRACO 800
#define GAP 125
#define INTERVALO_LETRA 250
#define INTERVALO_CICLO 3000

// Função para emitir um ponto em código Morse
void emitir_ponto() {
    gpio_put(LED_PIN, 1);  // Acende o LED
    sleep_ms(TEMPO_PONTO); // Mantém aceso por 0,2 segundos
    gpio_put(LED_PIN, 0);  // Apaga o LED
    sleep_ms(GAP);         // GAP entre sinais
}

// Função para emitir um traço em código Morse
void emitir_traco() {
    gpio_put(LED_PIN, 1);  // Acende o LED
    sleep_ms(TEMPO_TRACO); // Mantém aceso por 0,8 segundos
    gpio_put(LED_PIN, 0);  // Apaga o LED
    sleep_ms(GAP);         // GAP entre sinais
}

// Função para emitir o sinal SOS
void emitir_sos() {
    // Três pontos (S)
    for (int i = 0; i < 3; i++) {
        emitir_ponto();
    }

    // Intervalo entre letras
    sleep_ms(INTERVALO_LETRA);

    // Três traços (O)
    for (int i = 0; i < 3; i++) {
        emitir_traco();
    }

    // Intervalo entre letras
    sleep_ms(INTERVALO_LETRA);

    // Três pontos (S)
    for (int i = 0; i < 3; i++) {
        emitir_ponto();
    }

    // Pausa antes de reiniciar
    sleep_ms(INTERVALO_CICLO);
}

int main() {
    // Inicializa a GPIO
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Loop principal
    while (true) {
        emitir_sos();  // Executa o sinal SOS em loop
    }
    return 0;
}

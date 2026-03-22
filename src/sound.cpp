#include "sound.h"
#include "config.h"

int startMelody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int startDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int jingleMelody[] = {
  NOTE_C5, NOTE_E5, NOTE_G5, NOTE_C6
};
int jingleDurations[] = {
  120, 120, 120, 180
};
int jingleVolume = 120; // 0–255 (anpassen nach Geschmack)

void initBuzzer(){
  ledcSetup(BUZZER_CHANNEL, 2000, BUZZER_RESOLUTION); // Kanal, Frequenz, Auflösung (Startfrequenz egal)
  ledcAttachPin(BUZZER_PIN,BUZZER_CHANNEL);
}

void playStartMelody() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / startDurations[thisNote];
    ledcWriteTone(BUZZER_CHANNEL, startMelody[thisNote]);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // Ton stoppen
    ledcWriteTone(BUZZER_CHANNEL, 0);
  }
}

void playSuccessJingle() {
  for (int i = 0; i < 4; i++) {
    ledcWriteTone(BUZZER_CHANNEL, jingleMelody[i]);
    ledcWrite(BUZZER_CHANNEL, jingleVolume);
    delay(jingleDurations[i]);

    ledcWrite(BUZZER_CHANNEL, 0); // kurzer Cut zwischen Tönen
    delay(30);
  }

  ledcWrite(BUZZER_CHANNEL, 0); // sicher aus
}

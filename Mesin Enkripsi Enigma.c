#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int choose(), chooseRotor(), chooseSetting(), choosePosition(), cekInput(), resetInput();
int encrypt(), decrypt(), cek(), rotor();
int help(), howitwork();
void ringSetting(), ringPosition(), output();
int lp = 0, mp = 0, rp = 0, ls = 0, ms = 0, rs = 0, lr = 2, mr = 1, rr = 0, ref = 1; // Deklarasi Variabel posisi, setting, rotor
int rotorKey[5][26] = { // Array kunci jawaban rotor
/*r1*/{4, 10, 12, 5, 11, 6, 3, 16, 21, 25, 13, 19, 14,
    22, 24, 7, 23, 20, 18, 15, 0, 8, 1, 17, 2, 9},
/*r2*/{0, 9, 3, 10, 18, 8, 17, 20, 23, 1, 11, 7, 22,
    19, 12, 2, 16, 6, 25, 13, 15, 24, 5, 21, 14, 4},
/*r3*/{1, 3, 5, 7, 9, 11, 2, 15, 17, 19, 23, 21, 25,
    13, 24, 4, 8, 22, 6, 0, 10, 12, 20, 18, 16, 14},
/*r4*/{4, 18, 14, 21, 15, 25, 9, 0, 24, 16, 20, 8, 17,
    7, 23, 11, 13, 5, 19, 6, 10, 3, 2, 12, 22, 1},
/*r5*/{21, 25, 1, 17, 6, 8, 19, 24, 20, 15, 18, 3, 13,
    7, 11, 23, 0, 22, 12, 9, 16, 14, 5, 4, 2, 10}
  };
int knock[] = {17, 5, 22, 10, 0}; // Huruf yg menggeser posisi rotor
int reflectorKey[3][26] = { // Array kunci jawaban reflector
/*A*/{4, 9, 12, 25, 0, 11, 24, 23, 21, 1, 22, 5, 2,
    17, 16, 20, 14, 13, 19, 18, 15, 8, 10, 7, 6, 3},
/*B*/{24, 17, 20, 7, 16, 18, 11, 3, 15, 23, 13, 6, 14,
    10, 12, 8, 4, 1, 5, 25, 2, 22, 21, 9, 0, 19},
/*C*/{5, 21, 15, 9, 8, 0, 14, 24, 4, 3, 17, 25, 23,
    22, 6, 2, 19, 10, 20, 16, 18, 1, 13, 12, 7, 11}
};
int i, base, count = 1, chosen; // Deklarasi variabel lain yang sering dipakai
char a = 0;
FILE *cipher;

int white() {
    printf("\033[0;37m");
}

int reset() {
  printf("\033[0m");
}

int main() {
  system("COLOR 80");
  while (a != 13) {
    printf("\n%65s\n", "_______________");
    printf("%65s\n", "|             |");
    printf("%65s\n", "| E N I G M A |");
    printf("%65s\n\n\n", "|_____________|");
    if (count == 1) {
      white();
      printf("%61s\n\n", "Start!");
      reset();
    } else {
      printf("%61s\n\n", "Start!");
    }
    if (count == 2) {
      white();
      printf("%60s\n\n", "Help");
      reset();
    } else {
      printf("%60s\n\n", "Help");
    }
    if (count == 3) {
      white();
      printf("%65s\n\n", "How it works");
      reset();
    } else {
      printf("%65s\n\n", "How it works");
    }
    if (count == 4) {
      white();
      printf("%60s\n\n", "Exit");
      reset();
    } else {
      printf("%60s\n\n", "Exit");
    }
    printf("\n\n\n%42s\n\n", "Use arrow keys to navigate the menu.");
    printf("%30s\n", "Press Enter to continue.");
    a = getch();
    system("cls");
    if (a == -32) {
      a = getch();
      if (a == 80) {
        count++;
        if (count > 4) {
          count = 1;
        }
      } else if (a == 72) {
        count--;
        if (count < 1) {
          count = 4;
        }
      }
    }
  }
  switch (count) {
    case 1 : {
      system("cls");
      choose();
      break;
    }
    case 2 : {
      system("cls");
      help();
      break;
    }
    case 3 : {
      system("cls");
      howitwork();
      break;
    }
    case 4 : {
      printf("\n\n%50s", "T H A N K Y O U\n\n");
      exit(0);
    }
  }
  return 0;
}

int help(){
	printf("Enigma machine is an encoding machine used to encrypt and decrypt secret messages.");
	printf("\nThe Enigma machine was used by the Nazi German army and government before and during World War II.");
	printf("\nThis program is a simulation of an enigma machine");
	printf("\n\n[*]Start!\n");
	printf("This menu will run an enigma engine simulation.\nFirst,this menu will ask if the user wants to encrypt or decrypt.");
	printf("\nSecond, this menu will ask the user to input the rotor arrangement and the reflector.");
	printf("\nThird, this menu will ask the user to enter the position of the ring.");
	printf("\nFourth, this menu will ask the user to input key settings from enigma.");
	printf("\nFinally,this menu will ask the user to input sentences for encryption or decryption.");
	printf("\n\n[*]Help\n");
	printf("This menu will show the User how this program works");
	printf("\n\n[*]How it works");
	printf("\nThis menu will explain how the enigma works");
	printf("\n\n[*]Exit\n");
	printf("This menu is used to exit the program");
  printf("\n\n\n%72s\n\n\n", "---------------------------");
  printf("%42s\n", "Press Escape to return to main menu.");
	while (1) {
  	if (a == 27) {
   	  system("cls");
    	return main();
 		}
    a = getch();
  }
}

int howitwork(){
	printf("Final Project : Enigma Machine\n");
	printf("Created & Programmed By Group 3 : \n1.Mohammad Salman Alfarisi (1806200381) \n2.Josef Eric (1806148725)");
	printf("\n\nHow Enigma Machine Work\n");
	printf("\n1. The sender selects the rotor arrangement from right to left starting from rotor one to rotor five");
	printf("\n\n2. The sender selects the position of the letter letters in the rotor");
	printf("\n\n3. The sender can change the key lock on the rotor as they please");
	printf("\n\n4. The sender types each letter of the message into standard keyboard but in this simulation the user will be able to enter one sentence not just one word per word like the original machine  ");
	printf("\n\n5. When the sender presses a letter on the keyboard then letter by letter will be encrypted according to the key on the rotor, the position and settings in the previous step.");
	printf("\n\n6. In the original enigma machine, the lights on the keyboard will output words per word that have been encrypted and must be recorded on paper, but for this translation the word per word is stored in the file.");
  printf("\n\n\n%72s\n\n\n", "---------------------------");
  printf("%42s\n", "Press Escape to return to main menu.");
	while (1) {
  	if (a == 27) {
   	 system("cls");
     main();
 		}
  a = getch();
  }
}

int choose () {
  count = 1;
  a = 0;
  while (a != 13) {
    printf("\n\n\n%72s\n\n\n", "What would you like to do?");
    if (count == 1) {
      white();
      printf("%50s", "Encrypt");
      reset();
    } else {
      printf("%50s", "Encrypt");
    }
    if (count == 2) {
      white();
      printf("%25s", "Decrypt");
      reset();
    } else {
      printf("%25s", "Decrypt");
    }
    if (a == 27) {
      system("cls");
      resetInput();
      return main();
    }
    printf("\n\n\n%30s\n\n", "Press Enter to continue.");
    printf("%42s\n", "Press Escape to return to main menu.");
    a = getch();
    system("cls");
    if (a == -32) {
      a = getch();
      if (a == 77) {
        count++;
        if (count > 2) {
          count = 1;
        }
      } else if (a == 75) {
        count--;
        if (count < 1) {
          count = 2;
        }
      }
    }
  }
  system("cls");
  chosen = count;
  chooseRotor();
}

int chooseRotor() {
  count = 1;
  a = 0;
  while (a != 13) {
    printf("\n\n\n%72s\n\n", "Choose rotor positions.");
    printf("%79s\n\n\n", "Note: All rotors must be different.");
    if (count == 1) {
      white();
      printf("%60s: << %d >>\n\n", "Right rotor", rr + 1);
      reset();
    } else {
      printf("%60s: << %d >>\n\n", "Right rotor", rr + 1);
    }
    if (count == 2) {
      white();
      printf("%60s: << %d >>\n\n", "Middle rotor", mr + 1);
      reset();
    } else {
      printf("%60s: << %d >>\n\n", "Middle rotor", mr + 1);
    }
    if (count == 3) {
      white();
      printf("%60s: << %d >>\n\n", "Left rotor", lr + 1);
      reset();
    } else {
      printf("%60s: << %d >>\n\n", "Left rotor", lr + 1);
    }
    if (count == 4) {
      white();
      printf("\n%60s: << %c >>\n\n", "Reflector", ref + 65);
      reset();
    } else {
      printf("\n%60s: << %c >>\n\n", "Reflector", ref + 65);
    }
    if (a == 27) {
      system("cls");
      return choose();
    }
    printf("\n\n\n%30s\n\n", "Press Enter to continue.");
    printf("%30s\n", "Press Escape to go back.");
    a = getch();
    system("cls");
    if (a == -32) {
      a = getch();
      if (a == 80) {
        count++;
        if (count > 4) {
          count = 1;
        }
      } else if (a == 72) {
        count--;
        if (count < 1) {
          count = 4;
        }
      }
      if (a == 77) {
        if (count == 1) {
          rr++;
        } else if (count == 2) {
          mr++;
        } else if (count == 3){
          lr++;
        } else {
          ref++;
        }
      } else if (a == 75) {
        if (count == 1) {
          rr--;
        } else if (count == 2) {
          mr--;
        } else if (count == 3) {
          lr--;
        } else {
          ref--;
        }
      }
      if (rr < 0) {
        rr = 0;
      } else if (mr < 0) {
        mr = 0;
      } else if (lr < 0) {
        lr = 0;
      } else if (rr > 4) {
        rr = 4;
      } else if (mr > 4) {
        mr = 4;
      } else if (lr > 4) {
        lr = 4;
      } else if (ref < 0) {
        ref = 0;
      } else if (ref > 2) {
        ref = 2;
      }
    }
  }
  if (mr == rr || lr == rr || lr == mr) {
    system("cls");
    printf("\n\n\n\n\n%90s\n\n", "One or more of the rotors are similar, choose again!");
    Sleep(1000);
    system("cls");
    return chooseRotor();
  }
  chooseSetting();
}

int chooseSetting() {
  count = 1;
  a = 0;
  while (a != 13) {
    printf("\n\n\n%72s\n\n", "1. Choose ring settings.");
    if (count == 1) {
      white();
      printf("%60s: << %c >>\n\n", "Right rotor", rs + 65);
      reset();
    } else {
      printf("%60s: << %c >>\n\n", "Right rotor", rs + 65);
    }
    if (count == 2) {
      white();
      printf("%60s: << %c >>\n\n", "Middle rotor", ms + 65);
      reset();
    } else {
      printf("%60s: << %c >>\n\n", "Middle rotor", ms + 65);
    }
    if (count == 3) {
      white();
      printf("%60s: << %c >>\n\n", "Left rotor", ls + 65);
      reset();
    } else {
      printf("%60s: << %c >>\n\n", "Left rotor", ls + 65);
    }
    printf("\n\n\n%30s\n\n", "Press Enter to continue.");
    printf("%30s\n", "Press Escape to go back.");
    a = getch();
    system("cls");
    if (a == -32) {
      a = getch();
      if (a == 80) {
        count++;
        if (count > 3) {
          count = 1;
        }
      } else if (a == 72) {
        count--;
        if (count < 1) {
          count = 3;
        }
      }
      if (a == 77) {
        if (count == 1) {
          rs++;
        } else if (count == 2) {
          ms++;
        } else {
          ls++;
        }
      } else if (a == 75) {
        if (count == 1) {
          rs--;
        } else if (count == 2) {
          ms--;
        } else {
          ls--;
        }
      }
      if (rs < 0) {
        rs = 0;
      } else if (ms < 0) {
        ms = 0;
      } else if (ls < 0) {
        ls = 0;
      } else if (rs > 25) {
        rs = 25;
      } else if (ms > 25) {
        ms = 25;
      } else if (ls > 25) {
        ls = 25;
      }
    } else if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
        if (count == 1) {
          rs = cekInput(a) - base;
        } else if (count == 2) {
          ms = cekInput(a) - base;
        } else if (count == 3) {
          ls = cekInput(a) - base;
        }
    } else if (a == 27) {
      system("cls");
      return chooseRotor();
    } else if (a == 13) {
        break;
    }
  }
  choosePosition();
}

int choosePosition() {
  count = 1;
  a = 0;
  while (a != 13) {
    printf("\n\n\n%72s\n\n", "2. Choose rotor settings.");
    if (count == 1) {
      white();
      printf("%60s: << %c >>\n\n", "Right rotor", rp + 65);
      reset();
    } else {
      printf("%60s: << %c >>\n\n", "Right rotor", rp + 65);
    }
    if (count == 2) {
      white();
      printf("%60s: << %c >>\n\n", "Middle rotor", mp + 65);
      reset();
    } else {
      printf("%60s: << %c >>\n\n", "Middle rotor", mp + 65);
    }
    if (count == 3) {
      white();
      printf("%60s: << %c >>\n\n", "Left rotor", lp + 65);
      reset();
    } else {
      printf("%60s: << %c >>\n\n", "Left rotor", lp + 65);
    }
    printf("\n\n\n%30s\n\n", "Press Enter to continue.");
    printf("%30s\n", "Press Escape to go back.");
    a = getch();
    system("cls");
    if (a == -32) {
      a = getch();
      if (a == 80) {
        count++;
        if (count > 3) {
          count = 1;
        }
      } else if (a == 72) {
        count--;
        if (count < 1) {
          count = 3;
        }
      }
      if (a == 77) {
        if (count == 1) {
          rp++;
        } else if (count == 2) {
          mp++;
        } else {
          lp++;
        }
      } else if (a == 75) {
        if (count == 1) {
          rp--;
        } else if (count == 2) {
          mp--;
        } else {
          lp--;
        }
      }
      if (rp < 0) {
        rp = 0;
      } else if (mp < 0) {
        mp = 0;
      } else if (lp < 0) {
        lp = 0;
      } else if (rp > 25) {
        rp = 25;
      } else if (mp > 25) {
        mp = 25;
      } else if (lp > 25) {
        lp = 25;
      }
    } else if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
        if (count == 1) {
          rp = cekInput(a) - base;
        } else if (count == 2) {
          mp = cekInput(a) - base;
        } else if (count == 3) {
          lp = cekInput(a) - base;
        }
    } else if (a == 27) {
      system("cls");
      return chooseSetting();
    } else if (a == 13) {
        break;
    }
  }
  if (chosen == 1) {
    encrypt();
  } else if (chosen == 2) {
    decrypt();
  }
}

int cekInput (int input) {
  if (input >= 65 && input <= 90) { // Buat jadi fungsi cekInput
    base = 65;
  } else if (input >= 97 && input <= 122) {
    base = 97;
  } else {
    system("cls");
    printf("\n\n\n\n\n%90s\n\n", "Invalid input! Input only accepts letters!");
    Sleep(1000);
    system("cls");
  }
  return input;
}

int resetInput() {
  lp = 0, mp = 0, rp = 0, ls = 0, ms = 0, rs = 0, lr = 2, mr = 1, rr = 0;
}

//-------------------------------------- PROGRAM -------------------------------
int encrypt() {
  count = 1;
  char letterIn = 0;
  ringSetting();
  printf("\n\n\n%77s\n\n", "Input your message, then press enter to finish.");
  printf("%72s\n\n\n", "Press escape to edit your settings.");
  printf("\n%50s", "Your message: ");
  while (1) {
    letterIn = getch();
    if (letterIn == 13) {
      break;
    } else if (letterIn == 27) {
      system("cls");
      choosePosition();
    }
    if (letterIn >= 65 && letterIn <= 90) { // Buat jadi fungsi cekInput
      base = 65;
      printf("%c", letterIn);
      ringPosition();
    } else if (letterIn >= 97 && letterIn <= 122) {
      base = 97;
      printf("%c", letterIn);
      ringPosition();
    } else if (letterIn == 32 || letterIn == 33 || letterIn == 44 || letterIn == 46 || letterIn == 63){
      base = 0;
      printf("%c", letterIn);
    } else if (letterIn == 8) {
      base = -1;
      printf("\b");
      cipher = fopen("cipher.txt", "a");
      fprintf(cipher, "\b");
      fclose(cipher);
    } else {
      base = -1;
    }
    if (base == 65 || base == 97) {
      letterIn = letterIn - base;
      output(rotor(letterIn));
    } else if (base == 0) {
      output(letterIn);
    }
    count++;
  }
  printf("\n\n\n%32s\n\n", "Encryption successful!");
  printf("%42s\n", "Press Escape to return to menu.\n");
  while (letterIn != 27) {
    letterIn = getch();
    if (letterIn == 27) {
      system("cls");
      resetInput();
      choose();
    }
  }
}

int decrypt() {
  char letterIn;
  cipher = fopen("cipher.txt", "r");
  printf("\n\n\n%65s", "Decrypted Message:\n\n\n");
  printf("%50s", " ");
  ringSetting();
  while (1) {
    letterIn = fgetc(cipher);
    if (letterIn == EOF) {
      break;
    } else {
      if (letterIn >= 65 && letterIn <= 90) { // Buat jadi fungsi cekInput
        base = 65;
        ringPosition();
      } else if (letterIn >= 97 && letterIn <= 122) {
        base = 97;
        ringPosition();
      } else {
        base = 0;
      }
      letterIn = letterIn - base;
      if (base == 65 || base == 97) {
        letterIn = rotor(letterIn);
      }
    }
    printf("%c", letterIn + base);
  }
  printf("\n\n\n\n\n%42s\n", "Press Escape to return to menu.\n");
  while (letterIn != 27) {
    letterIn = getch();
    if (letterIn == 27) {
      system("cls");
      resetInput();
      choose();
    }
  }
}

int cek (int input) { // Untuk me-loop angka yang melewati A atau Z
  if (input > 25) {
    input = input - 26;
  } else if (input < 0) {
    input = input + 26;
  } else {
    input = input;
  }
  return input;
}

void ringSetting () {
  int rep, placeHolder; // rep = Berapa kali digeser (ringstellung)
  for (rep = rs; rep > 0; rep --) { // Jumlah pergeseran
    placeHolder = rotorKey[rr][25];
    for (i = 25; i > 0; i--) {
      rotorKey[rr][i] = rotorKey[rr][i - 1];
      rotorKey[rr][i] = cek(++rotorKey[rr][i]);
    }
    rotorKey[rr][0] = cek(++placeHolder);
    }
  for (rep = ms; rep > 0; rep --) { // Jumlah pergeseran
    placeHolder = rotorKey[mr][25];
    for (i = 25; i > 0; i--) {
      rotorKey[mr][i] = rotorKey[mr][i - 1];
      rotorKey[mr][i] = cek(++rotorKey[mr][i]);
    }
    rotorKey[mr][0] = cek(++placeHolder);
    }
  for (rep = ls; rep > 0; rep --) { // Jumlah pergeseran
    placeHolder = rotorKey[lr][25];
    for (i = 25; i > 0; i--) {
      rotorKey[lr][i] = rotorKey[lr][i - 1];
      rotorKey[lr][i] = cek(++rotorKey[lr][i]);
    }
    rotorKey[lr][0] = cek(++placeHolder);
    }
}

    // for (i = 0; i <= 25; i++) {
    //   printf("%c", rotorKey[lr][i] + 65);
    // }
    // printf("\n");


void ringPosition() {
  rp++;
  if (rp == knock[rr]) {
    mp++;
  } else if (mp == knock[mr] - 1) {
    mp++;
    lp++;
  }
  if (rp == 26) {
    rp = 0;
  } else if (mp == 26) {
    mp = 0;
  } else if (lp == 26) {
    lp == 0;
  }
}

int rotor (int letterOut) {
  letterOut = cek(rotorKey[rr][cek(letterOut + rp)] - rp);
  letterOut = cek(rotorKey[mr][cek(letterOut + mp)] - mp);
  letterOut = cek(rotorKey[lr][cek(letterOut + lp)] - lp);
  letterOut = reflectorKey[ref][letterOut];
  for (i = 0; i <= 25; i++) {
    if (rotorKey[lr][i] == cek(letterOut + lp)) {
      letterOut = cek(i - lp);
      break;
    }
  }
  for (i = 0; i <= 25; i++) {
    if (rotorKey[mr][i] == cek(letterOut + mp)) {
      letterOut = cek(i - mp);
      break;
    }
  }
  for (i = 0; i <= 25; i++) {
    if (rotorKey[rr][i] == cek(letterOut + rp)) {
      letterOut = cek(i - rp);
      break;
    }
  }
  return letterOut;
  // printf("%c ", letterOut + base);
}

void output (int print) {
  if (count == 1) {
    cipher = fopen("cipher.txt", "w");
    fprintf(cipher, "%c", print + base);
  } else {
    cipher = fopen("cipher.txt", "a");
    fprintf(cipher, "%c", print + base);
  }
  fclose(cipher);
}

// About ENIGMA
// wheel_position = tambah ke input alfabet (ETW), terus dikurang
// wheel_setting = kuncinya yang digeser
// R1 = EKMFLGDQVZNTOWYHXUSPAIBRCJ
// R2 = AJDKSIRUXBLHWTMCQGZNPYFVOE
// R3 = BDFHJLCPRTXVZNYEIWGAKMUSQO
// RefB = YRUHQSLDPXNGOKMIEBFZCWVJAT
// Enigma stepping = royal flags wave kings above (RFWKA)

// ASCII Code
// Left 75, Right 77, Up 72, Down 80
// Enter 13, Escape 27

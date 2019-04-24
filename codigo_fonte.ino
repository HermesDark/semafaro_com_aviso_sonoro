//Sequencia de portas definidas para A,B,C,D,E,F,G
int ledpins[] = {2,3,4,5,6,7,8,9};     

// Sequencia de digitos definidos 0,1,2,3,4,5,6,7,8,9
byte digits[] = {B11111100,B01100000,B11011010, B11110010,B01100110,B10110110,B10111110,B11100000,B11111110,B11110110};                           

void displayDigit(int digit)   //Função para imprimir Digito no Display!
{
  for (int i =0;i<8;i++)   
  {
    digitalWrite(ledpins[i],!bitRead(digits[digit],7-i));          //Comando que efetivamente vai imprimir os Digitos
  } 
}

void alloff()   //Função para apagar todo Display!
{
  for (int i =0;i<8;i++)
  {
    digitalWrite(ledpins[i], HIGH);             //Comando que efetivamente vai apagar o display
  }  
}

void Bip(){                // Bips curtos de Aviso
  tone(13,1802,50); 
}
void BipI(){               // Bip Inicial para abrir semafaro do pedestre
  tone(13,1902,300); 
}
void BipF(){               // Bip Final para fechar semafaro do pedestre
  tone(13,1999,700); 
}

int estadoBotao = 0;       //Checar estado botao(ligado/desligado)

const int botao = 9;       //Porta do botao

const int CVerde = 10;     //Porta do Semafaro Verde dos Carros
const int CAmarelo = 11;   //Porta do Semafaro Amarelo dos Carros
const int CVermelho = 12;  //Porta do Semafaro Vermelho dos Carros

const int PVerde = 1;      //Porta do Semafaro Verde dos pedestres
const int PVermelho = 0;   //Porta do Semafaro Vermelho dos pedestres

int frequencia = 0;     //Variavel de Frequencia p/ emitir Bip
int buzzer = 13;      //Variavel da porta do Buzzer/Bip


void setup() {

  {
  for (int i =0;i<8;i++)
  {
    pinMode(ledpins[i],OUTPUT);
    digitalWrite(ledpins[i], HIGH);
  } 
}
  
  pinMode(buzzer,OUTPUT);      
   
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  displayDigit(0);  // Turn the "dot" off
  
  pinMode (botao, INPUT);
  pinMode (10, OUTPUT); //definiÃ§Ã£o do pino 1 com saÃ­da para o LED vermelho para veÃ­culos
  pinMode (11, OUTPUT); //definiÃ§Ã£o do pino 2 com saÃ­da para o LED amarelo para veÃ­culos
  pinMode (12, OUTPUT); //definiÃ§Ã£o do pino 3 com saÃ­da para o LED verde para veÃ­culos
  pinMode (1, OUTPUT); //definiÃ§Ã£o do pino 5 com saÃ­da para o LED verde para pedestres
  pinMode (0, OUTPUT); //definiÃ§Ã£o do pino 6 com saÃ­da para o LED vermelho para pedestres
  

}
void loop() {

    estadoBotao = digitalRead(botao);  
    alloff(); 

    if ((estadoBotao == HIGH)) { 

    delay(200);
    displayDigit(9);
    delay(800);
    displayDigit(8);
    delay(800);
    displayDigit(7);
    delay(800);
    displayDigit(6);
    delay(800);
    displayDigit(5);
    delay(800);
    displayDigit(4);
    delay(800);
    displayDigit(3);
    delay(800);
    displayDigit(2);
    delay(800);
    displayDigit(1);
    delay(800);
    displayDigit(0);
    delay(50);
    alloff(); 
    digitalWrite (CVerde, LOW);
    digitalWrite (CAmarelo, HIGH);  

    delay(2000);

    digitalWrite (PVermelho, LOW);
    digitalWrite (CAmarelo, LOW);
    digitalWrite (CVermelho, HIGH);
    digitalWrite (PVerde, HIGH);BipI();

    delay(5000);


    displayDigit(9);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(250);
    digitalWrite (PVerde, HIGH);Bip(); 
    delay(550);
    displayDigit(8);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(250);
    digitalWrite (PVerde, HIGH);Bip(); 
    delay(550);
    displayDigit(7);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(250);
    digitalWrite (PVerde, HIGH);Bip(); 
    delay(550);
    displayDigit(6);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(250);
    digitalWrite (PVerde, HIGH);Bip(); 
    delay(550);
    displayDigit(5);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(200);
    digitalWrite (PVerde, HIGH);Bip(); 
    delay(200);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(400);
    displayDigit(4);
    digitalWrite (PVerde, HIGH);Bip(); 
    delay(200);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(200);
    digitalWrite (PVerde, HIGH);Bip(); 
    delay(400);
    displayDigit(3);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(150);
    digitalWrite (PVerde, HIGH);Bip(); 
    delay(150);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(150);
    digitalWrite (PVerde, HIGH);Bip(); 
    delay(350);
    displayDigit(2);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(150);
    digitalWrite (PVerde, HIGH);Bip(); 
    delay(150);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(150);
    digitalWrite (PVerde, HIGH);Bip(); 
    delay(350);
    displayDigit(1);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(100);
    digitalWrite (PVerde, HIGH);Bip(); 
    delay(100);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(100);
    digitalWrite (PVerde, HIGH);Bip(); 
    delay(100);
    digitalWrite (PVerde, LOW);Bip(); 
    delay(100);
    digitalWrite (PVerde, HIGH);BipF(); 
    delay(300);
    displayDigit(0);
    alloff(); 
    digitalWrite (PVerde, LOW); 
    digitalWrite (CVermelho, LOW);
    }
    else if ((estadoBotao == LOW)) {
      digitalWrite (PVermelho, HIGH);
      digitalWrite (CVerde, HIGH);
    }
}

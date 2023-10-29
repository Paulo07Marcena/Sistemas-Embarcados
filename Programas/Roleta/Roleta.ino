// Código para simular uma roleta da sorte desenvolvido por Paulo07Marcena


// Declaração de variáveis
int tempo = 400;
float numero = 0;
const int pinoPOT = A5;


// Declarando as funções:
void vitoria();
void derrota();
int numeroEscolhido();
void tom(char pino, int frequencia, int duracao);

void setup(){
  Serial.begin(9600);
  
  pinMode(3,OUTPUT);
  pinMode(pinoPOT, INPUT);

  randomSeed(analogRead(A0));
  
}

int numeroAleatorio = random(10); 


void loop(){

  int escolha = numeroEscolhido();
  

  if (escolha == numeroAleatorio){ 
       vitoria();
  }else{
        derrota();
  }    

  delay(2000);


}

void tom(char pino, int frequencia, int duracao){
  float periodo = 1000.0/frequencia; 
  for (int i = 0; i< duracao/(periodo);i++){ 
    digitalWrite(pino,HIGH);
    delayMicroseconds(periodo*500); 
    digitalWrite(pino, LOW);
    delayMicroseconds(periodo*500);
  }
}

void vitoria(){

  tom(3, 494, tempo); 
  delay(tempo);
  tom(3, 588, tempo); 

  delay(tempo);
  tom(3, 659, tempo); 
  delay(tempo);
  tom(3, 784, tempo); 

  delay(tempo);
  tom(3, 659, tempo); 
  delay(tempo);
  tom(3, 494, tempo); 
  delay(tempo);
  tom(3, 440, tempo); 
  delay(tempo);

}

void derrota(){

  tom(3, 330, tempo);
  delay(tempo);
  tom(3, 294, tempo); 
  delay(tempo);
  tom(3, 262, tempo);
  delay(tempo);

}

int numeroEscolhido(){
  numero = map(analogRead(pinoPOT), 0 , 1023, 0, 10);
  Serial.println(numero);

  return numero;

}




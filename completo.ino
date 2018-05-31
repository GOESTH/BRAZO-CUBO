#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int velmo = 5;// Tiempo (milisegundos)que tarda en dar un paso el motor paso a paso.
int anges = 0;// Angulo escogido por el caracter seleccionado.
int posicion_motor = 0;// grado en el que esta el motor paso a paso..

void setup() {
  
 servo1.attach(3); 
 servo2.attach(5);
 servo3.attach(6);

  servo1.write(127);
  servo2.write(85);
  servo3.write(35);
  
  pinMode(11, OUTPUT); // Pin 11 se conecta a al pin IN4 de la placa del motor paso a paso.
  pinMode(10, OUTPUT); // Pin 10 se conecta a al pin IN3 de la placa del motor paso a paso.
  pinMode(9, OUTPUT); // Pin 9 se conecta a al pin IN2 de la placa del motor paso a paso.
  pinMode(8, OUTPUT); // Pin 8 se conecta a al pin IN1 de la placa del motor paso a paso.
  
  Serial.begin(9600);
}

void loop() {

int angulos[4][24]={{138,130,128,124,120,118,115,114,110,108,105,103,100,100,100,100,100,100,100,100,100,127,127,127},
                    {62, 62,  62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 85, 86, 88, 89, 90 ,91, 95, 90, 87, 63, 85},
                    {73, 73, 73,  73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 72, 71, 64 ,64, 64, 64,  64, 64, 64, 35},
                    {0,   0,  0,   0,  0,  0,  0,  0,  0, 0,   0,  0,  0, 95, 95, 95, 95, 95, 95, 95, 95, 95,  95,  0}
                    
                    };
int i,j=0;
    for(i=0;i<24;i++){
       
        servo1.write(angulos[0][i]);
        delay(120);
        servo2.write(angulos[1][i]);
        delay(120);
        servo3.write(angulos[2][i]);
        delay(120);
         
        
         anges =angulos[3][i];
    anges = (anges * 1.4222222222);

  while (anges>posicion_motor){   // Giro hacia la izquierda en grados
       paso_izq();
       posicion_motor = posicion_motor + 1;
   }
   
  while (anges<posicion_motor){   // Giro hacia la derecha en grados
        paso_der();
        posicion_motor = posicion_motor -1;
   }
  
    }

}

void paso_der(){// funcion_movimiento hacia la derecha del motor paso a paso.
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, HIGH);  
   delay(velmo); 
 digitalWrite(11, LOW); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, LOW);  
   delay(velmo); 
   digitalWrite(11, HIGH); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
     delay(velmo);  
 digitalWrite(11, HIGH); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, HIGH);  
     delay(velmo);   
}

void paso_izq() {//funcion_movimiento hacia la izquierda del motor paso a paso.
 digitalWrite(11, HIGH); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
     delay(velmo);  
 digitalWrite(11, LOW); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, LOW);  
     delay(velmo);  
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, HIGH);  
     delay(velmo);  
 digitalWrite(11, HIGH); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, HIGH);  
     delay(velmo); 
}
        
void apagado() {// funcion_apagado del motor paso a paso.
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
 }

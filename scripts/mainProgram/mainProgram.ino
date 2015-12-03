#include <FlexiTimer2.h>
#include <SPI.h>
#include <SD.h>

// Vars
File counterFile;
File dataF;
#define LED1 7 // this pin flashes to indicate the moment of the recording
#define SAMPLETIME 120000 //In ms
#define TIMER2VAL 100 //Time between samples
#define SAMPLES SAMPLETIME/TIMER2VAL
unsigned int counter = 1;
unsigned int recording = 0;
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  4;      // number of pin that would indicate recording
unsigned int numOfFile;
char numOfFileC;
String valStr;
volatile unsigned char CurrentCh;
volatile unsigned int ADC_Value = 0; 
//unsigned int analogAr[6];

// Functions

//record gets data from the sensors and both records it in the SD and sends it trough serial
void record(void)
{
  recording = 1;
  valStr = String(counter);
  for(CurrentCh=0;CurrentCh<6;CurrentCh++)
  {
    
    ADC_Value = analogRead(CurrentCh);
    valStr += "," + String(ADC_Value);
    //valStr = "At indx" + String(CurrentCh) + " the value is " + String(ADC_Value) + "\n";
  }
  Serial.println(valStr); //prints new line on serial
  dataF.println(valStr); //prints new line on file
  
  
  static boolean output = HIGH;
  digitalWrite(LED1, output);
  output = !output;
  counter++;
  if(counter > SAMPLES)
  {
    FlexiTimer2::stop();
    recording = 0;
    Toggle_LED3(recording);
    
    dataF.close(); // closes file
    Serial.print("File recorded\n");
    Serial.print("Waiting for button\n");
  }
}

void Toggle_LED3(int state) //LED that indicates that the device is recording
{
  if (state == 1)
  {
    digitalWrite(ledPin, HIGH);
    Serial.print("On\n");
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.print("Off\n");
  }
  
}



void setup() //initual setup
{
  Serial.begin(57600); //starts serial
  //Starts SD card, if fails, stops program
  if (!SD.begin(10)) 
  {
    Serial.println("initialization failed!");
    return;
  }
  
  
  

  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);  //Setup LED1 direction
  pinMode(buttonPin, INPUT);  //Setup button direction
  //digitalWrite(buttonPin,LOW);
  digitalWrite(LED1,LOW); //Setup LED1 state
  pinMode(ledPin, OUTPUT);  //Setup LED3 direction
  digitalWrite(ledPin,LOW); //Setup LED3 state

  FlexiTimer2::set(TIMER2VAL, record);
  recording = 0;
  Serial.print("Waiting for button\n");
  
}

void loop() 
{
  //Serial.print(digitalRead(buttonPin));
  //Serial.print(recording);
  if (recording == 0)
  {
    //Serial.print("Recording is 0");
    if (digitalRead(buttonPin))
    {
      
      // Continues with the count of the file
      Serial.print("Opening file");
      counterFile = SD.open("0FILE.txt");
      Serial.print("File opened");
      numOfFile = counterFile.parseInt() + 1;
      Serial.print("Last number of file is: " + String(numOfFile-1) + "\n");
      counterFile.close();
      SD.remove("0FILE.txt");
      Serial.print("Adding number of file\n");
      counterFile = SD.open("0FILE.txt", FILE_WRITE);
      counterFile.println(String(numOfFile));
      counterFile.close();
      // Finishes counting the file

      // Opens new file
      Serial.print("Creating file " + String(numOfFile) + "\n");
      dataF = SD.open("F" + String(numOfFile) + ".csv", FILE_WRITE);
      

      
      recording = 1;
      counter = 1;
      Toggle_LED3(recording);
      FlexiTimer2::start();
      while (digitalRead(buttonPin))
      {
        //Serial.print(digitalRead(buttonPin));
      }
    }
  }
  else
  {
    //Serial.print("Button pressed\n");
    if (!digitalRead(buttonPin))
    {
      while (recording == 1)
      {
        //Serial.print(digitalRead(buttonPin));
        delay(1);
        //Serial.print(recording);
      }
    }
  }
}
  


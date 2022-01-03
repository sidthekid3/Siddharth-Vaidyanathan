

#include "HyperDisplay_UG2856KLBAG01.h"   // graphics library
                                          

#define SERIAL_PORT Serial   
#define WIRE_PORT Wire      // Used if USE_SPI == 0
#define SPI_PORT SPI        // Used if USE_SPI == 1

#define RES_PIN 2           // Optional
#define CS_PIN 4            // Used only if USE_SPI == 1
#define DC_PIN 5            // Used only if USE_SPI == 1

#define USE_SPI 0           // Choose your interface. 0 = I2C, 1 = SPI

// END USER SETUP


// Object Declaration. A class exists for each interface option
#if USE_SPI
  UG2856KLBAG01_SPI myTOLED;  // Declare a SPI-based Transparent OLED object called myTOLED
#else
  UG2856KLBAG01_I2C myTOLED;  // Declare a I2C-based Transparent OLED object called myTOLED
#endif /* USE_SPI */

// Create Windows
wind_info_t windowZero;  //declaring window in the scope for the window

void setup() {
  Serial.begin(9600);

  //Serial.println(F("Example1_DisplayTest: Transparent Graphical OLED"));

#if USE_SPI 
  SPI_PORT.begin();
  myTOLED.begin(CS_PIN, DC_PIN, SPI_PORT);                  // Begin for SPI requires that you provide the CS and DC pin numbers
#else
  WIRE_PORT.begin();
  myTOLED.begin(WIRE_PORT, false, SSD1309_ARD_UNUSED_PIN);  // Begin for I2C has default values for every argument
  Wire.setClock(400000);                                    // initializing the oled display
#endif /* USSE_SPI */

//myTOLED.pCurrentWindow = &windowZero;                     //initializing the oled display

// Don't show the logo on boards with small memory
#if !defined(__AVR_ATmega328P__) && !defined(__AVR_ATmega168__)
  showLogo( );      // The showLogo function is a hacky way to get a large bitmap into program space without using <avr/pgspace.h>
  delay(5000) ;
  myTOLED.clearDisplay();    //clears the screen
  // Create Windows
  //wind_info_t windowZero;
  myTOLED.setWindowDefaults(&windowZero);  //initializing windowZero
  myTOLED.setWindowColorSet(&windowZero);  //initializing windowZero

  windowZero.xMin = 0;                    //basic parameters for the window to set the resolution on the screen.
  windowZero.yMin = 0;
  windowZero.xMax = 127;
  windowZero.yMax = 9;

  myTOLED.pCurrentWindow = &windowZero;   //calls for function from the ssetup
  myTOLED.println("In Setup");            //displays text "In setup" in the setup.
  myTOLED.resetTextCursor();              //Resets the screen
  delay(5000) ;
  
#endif
}

void loop() {
  
  myTOLED.clearDisplay();
  myTOLED.setContrastControl(0);
  myTOLED.pCurrentWindow = &windowZero;   //calls for function in the scope
  myTOLED.println("In loop");        //prints in loop to show program is running in the loop
  myTOLED.resetTextCursor();
  myTOLED.setContrastControl(128);
  delay(5000);

  
}



#if !defined(__AVR_ATmega328P__) && !defined(__AVR_ATmega168__)
void showLogo( void ){
  myTOLED.clearDisplay();
  
 myTOLED.pixelSet(21, 12); myTOLED.pixelSet(27, 12); myTOLED.pixelSet(34, 12); myTOLED.pixelSet(42, 12); myTOLED.pixelSet(44, 12); myTOLED.pixelSet(45, 12); myTOLED.pixelSet(60, 12); myTOLED.pixelSet(61, 12); myTOLED.pixelSet(62, 12); myTOLED.pixelSet(74, 12); myTOLED.pixelSet(77, 12); myTOLED.pixelSet(96, 12); myTOLED.pixelSet(98, 12); myTOLED.pixelSet(99, 12); myTOLED.pixelSet(100, 12); myTOLED.pixelSet(103, 12); myTOLED.pixelSet(104, 12); myTOLED.pixelSet(105, 12); myTOLED.pixelSet(107, 12); myTOLED.pixelSet(108, 12); 
 myTOLED.pixelSet(45, 13); myTOLED.pixelSet(54, 13); 
  myTOLED.pixelSet(46, 14); 
  myTOLED.pixelSet(50, 15); 
  
  
  myTOLED.pixelSet(22, 18); 
  myTOLED.pixelSet(22, 19); 
  
  myTOLED.pixelSet(21, 21); 
  myTOLED.pixelSet(32, 22); 
  
  
  myTOLED.pixelSet(37, 25); 
  
  
  myTOLED.pixelSet(19, 28); myTOLED.pixelSet(30, 28); myTOLED.pixelSet(38, 28); 
  myTOLED.pixelSet(30, 29); 
  
  myTOLED.pixelSet(18, 31); 
  
  
  myTOLED.pixelSet(17, 34); 
  
  myTOLED.pixelSet(108, 36); 
  myTOLED.pixelSet(38, 37); myTOLED.pixelSet(108, 37); 
  
  
  
  myTOLED.pixelSet(26, 41); myTOLED.pixelSet(72, 41); myTOLED.pixelSet(77, 41); 
  myTOLED.pixelSet(69, 42); myTOLED.pixelSet(79, 42); myTOLED.pixelSet(93, 42); myTOLED.pixelSet(94, 42); myTOLED.pixelSet(97, 42); 
  myTOLED.pixelSet(14, 43); myTOLED.pixelSet(15, 43); myTOLED.pixelSet(16, 43); myTOLED.pixelSet(17, 43); myTOLED.pixelSet(18, 43); myTOLED.pixelSet(25, 43); myTOLED.pixelSet(43, 43); myTOLED.pixelSet(44, 43); myTOLED.pixelSet(45, 43); myTOLED.pixelSet(50, 43); myTOLED.pixelSet(52, 43); myTOLED.pixelSet(54, 43); myTOLED.pixelSet(55, 43); myTOLED.pixelSet(56, 43); myTOLED.pixelSet(57, 43); myTOLED.pixelSet(58, 43); myTOLED.pixelSet(59, 43); myTOLED.pixelSet(60, 43); myTOLED.pixelSet(61, 43); myTOLED.pixelSet(83, 43); myTOLED.pixelSet(86, 43); myTOLED.pixelSet(98, 43); myTOLED.pixelSet(99, 43); myTOLED.pixelSet(101, 43); myTOLED.pixelSet(103, 43); myTOLED.pixelSet(106, 43); myTOLED.pixelSet(107, 43); myTOLED.pixelSet(108, 43); myTOLED.pixelSet(109, 43); myTOLED.pixelSet(110, 43); 
  

  for(uint8_t indi = 0; indi < 254; indi++)
  {
    myTOLED.setContrastControl(indi);
    delay(5);
  }
  
}
#endif


/* Azip Arduino Zcode Interpreter Program
 * --------------------------------------------------------------------
 * Derived from John D. Holder's Jzip V2.1 source code
 * http://jzip.sourceforge.net/
 * --------------------------------------------------------------------
 */
 
 /*
  * Created by Louis Davis April, 2012
  * Code update by Tal Ofer April 2021
  */


#include <SdFat.h>
#include <SdFatUtil.h>
#include "ztypes.h"

// SD chip select pin
const uint8_t chipSelect = 53;

const uint8_t SD_CS_PIN = SS;
#define SD_CONFIG SdSpiConfig(SD_CS_PIN, DEDICATED_SPI)

// file system
SdFat sd;

void setup()
{
  Serial.begin(115200);
  
  Serial.println("Enter any key to start...");
  
  while (!Serial.available()) {}
  Serial.read();
  //Serial.print("init sd ...");
  //if (!sd.init(SPI_HALF_SPEED, chipSelect)) sd.initErrorHalt();
  if (!sd.begin(SD_CONFIG)) sd.initErrorHalt();
  //Serial.println("done !");
  open_story( );
  
  // put your setup code here, to run once:
  configure( V1, V8 );

  initialize_screen(  );

  z_restart(  );
}

void loop()
{
  // put your main code here, to run repeatedly:
  interpret( );  
}

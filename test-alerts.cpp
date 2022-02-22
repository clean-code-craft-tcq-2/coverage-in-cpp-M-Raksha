#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(40, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
}

TEST_CASE("classifies and infers temperature breachs accoring to coolingtype ")
{
  
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,-12) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,40) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,25) == NORMAL);
 
   
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING,-12) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING,56) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING,25) == NORMAL);
  
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING,-12) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING,42) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING,25) == NORMAL);
 
}

TEST_CASE("check and alert the respective target")
{
   BatteryCharacter BatteryChar;
   
  BatteryChar.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_EMAIL, BatteryChar, -12 );
  checkAndAlert(TO_EMAIL, BatteryChar, 40 );
  checkAndAlert(TO_EMAIL, BatteryChar, 25 );
  
  checkAndAlert(TO_CONTROLLER, BatteryChar, -12 );
  checkAndAlert(TO_CONTROLLER, BatteryChar, 40 );
  checkAndAlert(TO_CONTROLLER, BatteryChar, 25 );
  
  
   BatteryChar.coolingType = HI_ACTIVE_COOLING;
  checkAndAlert(TO_EMAIL, BatteryChar, -12 );
  checkAndAlert(TO_EMAIL, BatteryChar, 56 );
  checkAndAlert(TO_EMAIL, BatteryChar, 25 );
  
  checkAndAlert(TO_CONTROLLER, BatteryChar, -12 );
  checkAndAlert(TO_CONTROLLER, BatteryChar, 56 );
  checkAndAlert(TO_CONTROLLER, BatteryChar, 25 );


BatteryChar.coolingType = MED_ACTIVE_COOLING;
  checkAndAlert(TO_EMAIL, BatteryChar, -12 );
  checkAndAlert(TO_EMAIL, BatteryChar, 42 );
  checkAndAlert(TO_EMAIL, BatteryChar, 25 );
  
  checkAndAlert(TO_CONTROLLER, BatteryChar, -12 );
  checkAndAlert(TO_CONTROLLER, BatteryChar, 42 );
  checkAndAlert(TO_CONTROLLER, BatteryChar, 25 );

}

#include "typewise-alert.h"
#include <stdio.h>

void sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
 printf("hi %s\n",BreachTypeToAlertMsgMap[breachType]);
}

BreachType inferBreach(double value, double lowerLimit, double upperLimit) 
{
  if(value < lowerLimit) 
  {
    return TOO_LOW;
  }
  if(value > upperLimit) 
  {
      
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC)
{
    
    return inferBreach(temperatureInC, mapTempratureLimtsToCoolingtype[coolingType].at(0), mapTempratureLimtsToCoolingtype[coolingType].at(1));
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
    callAlertFunctionfromTargetType[alertTarget](breachType);
}

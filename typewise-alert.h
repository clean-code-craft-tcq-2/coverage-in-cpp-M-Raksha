#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

map<CoolingType, std::vector<int>>mapTempratureLimtsToCoolingtype
{
    {PASSIVE_COOLING, {0,35}},
    {HI_ACTIVE_COOLING, {0,45}},
    {MED_ACTIVE_COOLING, {0,40}}
    
};


map<AlertTarget, void (*)(BreachType)> callAlertFunctionfromTargetType 
{
{TO_CONTROLLER, sendToController},
{TO_EMAIL, sendToEmail}
};

map <BreachType, const char * > BreachTypeToAlertMsgMap
{
    {NORMAL, "all is well"},
    {TOO_LOW, "the temperature is too low"},
    {TOO_HIGH, "the temperature is too high"}
};

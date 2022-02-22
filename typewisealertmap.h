#include <vector>
#include <map>
using std::map;

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

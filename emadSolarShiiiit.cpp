#include <iostream>

int main() {
  // Constants (  mamulan ba harfe bozorg minevisan in variable ro)
  
  const double WATT_PER_HOUR_SOLAR = 300; // average output of a solar Watts/H
  const double PANEL_LENGTH = 1.6; // metr
  const double PANEL_WIDTH = 1; // Metr 
  const double METER_IN_FEET = 3.28; // meters -> feet (1 metr = 3.28 Ft)
  
  // input from a consumer (masrafe salane ro migirm ay input stdin mizaram tu in variable)
  double powerElectricConsumptionkWh;
  std::cout << "Please enter your annual power consumption in kWh: ";
  std::cin >> powerElectricConsumptionkWh;
  
  // Calculate: number of required panels 
  //(1 kiloWattHour = 1000 WattHour)
  double annualWattHours = powerElectricConsumptionkWh * 1000;
  
  // "(int)..." type casting for Double to int
  int numPanels = (int) (annualWattHours / WATT_PER_HOUR_SOLAR); 
  
  // Calculate: total surface area
  double solarPanelSurfaceAreaFtQ = (PANEL_LENGTH * METER_IN_FEET) * (PANEL_WIDTH * METER_IN_FEET); // change to meter to Feet
  double totalSurfaceAreaForSolarPalensInFtQ = solarPanelSurfaceAreaFtQ * numPanels;
  
  // Output
  std::cout << "Number of solar panels required: " << numPanels << std::endl;
  std::cout << "Solar panel surface area required: " << totalSurfaceAreaForSolarPalensInFtQ << std::endl;
  
  return 0;
}

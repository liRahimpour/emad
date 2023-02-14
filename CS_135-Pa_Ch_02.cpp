#include <iostream>
#include <string>

using namespace std;

int main() {
    
    // define the variables
    double panelArea, panelAreaLength, panelAreaWidth, efficiencyOfPanel, sunlightInHours;

    //Prompt user for panel dimensions, efficiency, and sunlight 
    cout << "Enter the length and width of a panel in meters, separated by a space: ";
    cin >> panelAreaLength >> panelAreaWidth;

    cout << "Enter the efficiency of the system as a decimal (0 to 1): ";
    cin >> efficiencyOfPanel;

    cout << "Enter the amount of sunlight received in hours: ";
    cin >> sunlightInHours;
    
    // electricity generated in kWh
    panelArea = panelAreaLength * panelAreaWidth;
    double electricity = panelArea * efficiencyOfPanel * sunlightInHours * 300 * 0.001;
    int electricityGeneratedKwh = static_cast<int>(electricity); // Convert to integer
    
    // resault message
    string message = "kilowatt-hours (kWh) of energy per panel per day: " + to_string(electricityGeneratedKwh);
    
    // Output 
    cout << message << endl;
    
    return 0;
}

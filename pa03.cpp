#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

double CalculateDistance(double lat1, double lon1, double lat2, double lon2);

int main() {
    string filename;
    cout << "Please enter the name of the data file: ";
    cin >> filename;

    ifstream infile;
    infile.open(filename);
    if (!infile.is_open()) {
        cerr << "Error: file not found!" << endl;
        return 1;
    }

    string line;
    getline(infile, line);  // Ignore first line
    double lv_lat, lv_lon, c1_lat, c1_lon, c2_lat, c2_lon;
    getline(infile, line);
    sscanf(line.c_str(), "%*[^,],%*[^,],%lf,%lf", &lv_lat, &lv_lon);
    getline(infile, line);
    sscanf(line.c_str(), "%*[^,],%*[^,],%lf,%lf", &c1_lat, &c1_lon);
    getline(infile, line);
    sscanf(line.c_str(), "%*[^,],%*[^,],%lf,%lf", &c2_lat, &c2_lon);

    infile.close();

    double c1_dist = CalculateDistance(lv_lat, lv_lon, c1_lat, c1_lon);
    double c2_dist = CalculateDistance(lv_lat, lv_lon, c2_lat, c2_lon);

    // Output table to screen
    cout << "City" << setw(18) << "State" << setw(15) << "Distance" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "City 1" << setw(12) << "ST" << setw(16) << c1_dist << endl;
    cout << "City 2" << setw(12) << "ST" << setw(16) << c2_dist << endl;

    // Output table to file
    ofstream outfile("report.txt");
    if (!outfile.is_open()) {
        cerr << "Error: cannot create report.txt!" << endl;
        return 1;
    }
    outfile << "City" << setw(18) << "State" << setw(15) << "Distance" << endl;
    outfile << "------------------------------------------------" << endl;
    outfile << "City 1" << setw(12) << "ST" << setw(16) << c1_dist << endl;
    outfile << "City 2" << setw(12) << "ST" << setw(16) << c2_dist << endl;
    outfile.close();

    return 0;
}

double CalculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double latD2M = 69.0;
    const double latVegas = 36.114647;
    double lonD2M = -0.73 * latVegas + 81.8;

    double vDistance = abs(lat1 - lat2) * latD2M;
    double hDistance = abs(abs(lon1) - abs(lon2)) * lonD2M;
    double distance = sqrt(vDistance * vDistance + hDistance * hDistance);

    return distance;
}

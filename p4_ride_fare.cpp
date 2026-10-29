#include <iostream>
#include<fstream>
using namespace std;
double fare(double km, double ratePerKm = 40.0);
double fare(double km, double ratePerKm, bool peakHour);
double fare(double km, char vehicle);
double fare(double km, char vehicle, int promoPercent);
int main() {
    cout << "fare(10) = " << fare(10) << endl;
    cout << "fare(10, 30.0) = " << fare(10, 30.0) << endl;
    cout << "fare(10, 30.0, true) = " << fare(10, 30.0, true) << endl;
    cout << "fare(8, 'B') = " << fare(8, 'B') << endl;
    cout << "fare(8, 'C') = " << fare(8, 'C') << endl;
    cout << "fare(8, 'C', 10) = " << fare(8, 'C', 10) << endl;

    // ---- Part B: write your code below this line ----
    int rides;
    cout << "How many rides?";
    cin >> rides;
    char type;
    int percent;
    double kilometer;
    double total=0;
    ofstream fout("rides.txt");
    for (int i = 0;i < rides;i++) {
        cout << "Ride " << i + 1 << ": " << "Type (B/R/C), KM , Promopercent" << endl;
        cin >> type >> kilometer >> percent;
        if (percent == 0) {
            total += fare(kilometer, type);
            fout << "Ride " << i + 1 << " (" << type << "), " << kilometer << " km -> Rs. " << fare(kilometer, type) << endl;
        }
        else
        {
            total += fare(kilometer, type, percent);

            fout << "Ride " << i + 1 << " (" << type << "), " << kilometer << " km -> Rs. " << fare(kilometer, type,percent) << endl;
        }
    }
    fout << "Total collected: Rs. " << total << endl;
    fout.close();
    
    //Part C- Ambigious call
//   fare(10,40);
// Error : <more than one instance of overloaded function "fare" matches the arguments list
// Reason: arguments matches more than one functions so compiler cannat distinguish the function
// Fix 1 :    fare(10);
// Fix 2 :    fare(10,40.0);



    return 0;
}
double fare(double km, double ratePerKm) {
    return 100 + km * ratePerKm;

}
double fare(double km, double ratePerKm, bool peakHour) {
    if (peakHour == true)
        return (fare(km, ratePerKm) + (0.20 * fare(km, ratePerKm)));
    else
      return  fare(km, ratePerKm);
}
double fare(double km, char vehicle) {
    if (vehicle == 'B')
        return fare(km, 25.0);
    if (vehicle == 'R')
        return fare(km, 35.0);

    if (vehicle == 'C')
        return fare(km, 50.0);
    else
        return 0;
}
double fare(double km, char vehicle, int promoPercent) {
    return (fare(km, vehicle) - ((promoPercent / 100.0) * fare(km, vehicle)));
}

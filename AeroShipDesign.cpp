//Ian Lingo
//khj23
//June 22 2023 
//Aerospace Ship Designing Project


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;

  struct Ship{
  string shipName;
  string designerName;
  float mass;
  float acceleration;;
  float impulse;
  float maxAltitude;
};

void designShip(){
  //defines and prompt function designShip when user_selects 'D' or 'd'

  string designerName, shipName, timeStamp, fileName;
  float shipMass, engineThrust, acceleration, impulse, maxAltitude;
  char user_select;

  Ship designShip;
  
  cout << "Enter designer name: " << endl;
  cin.ignore();
  getline(cin, designerName);
  //getline is a std lib that reads a str/line from an input stream
  cout << "Enter ship name: " << endl;
  cin >> shipName;
  cout << "Enter ship mass: " << endl;
  cin >> shipMass; 
  cout << "Enter engine thrust: " << endl;
  cin >> engineThrust;
  
    
  acceleration = (engineThrust/shipMass);
  impulse = 9.8 * log(acceleration);
  //g0 = 9.8
  //log = natural log 
  maxAltitude = (100 + (impulse*200))/10; 
  time_t timeNow = time(0); 
  //line of code that reads number of secs since Jan 1, 1970
  fileName = shipName + ".txt";
  //specifies fileName
  
  ofstream outputFile(fileName);
  if(outputFile.is_open()){ //ifstream::is_open 
  outputFile << "Contents of " << shipName << ".txt" << endl;
  
  outputFile << " " << endl;
  outputFile << left << setw(20) << "Ship Name: " << shipName << endl;
  outputFile << left << setw(20) << "Ship Mass: " << fixed 
    << setprecision(1) << shipMass << "kg" << endl; 
  outputFile << left << setw(20) << "Acceleration: " << fixed 
    << setprecision(1) << acceleration << "m/s2" << endl;
  outputFile << left << setw(20) << "Impulse: " << fixed 
    << setprecision(1) << impulse << "Ns/kg" << endl;
  outputFile << left << setw(20) << "Max Altitude: " << fixed
    << setprecision(1) << maxAltitude << "km" << endl;
  outputFile << left << setw(20) << "Designer name: "
    << designerName << endl;
  outputFile << left << setw(20) << "File saved at: " << timeNow << endl;
  outputFile.close();
  cout << "File written for " << shipName << endl;
  } else{
    cout << "ERROR opening file" << endl;
  }
}
  //above fstream output will print in new file "shipName.txt"

void testShip(){ //Prompts this void function when selected
  string designerName, shipName, timeStamp, fileName, 
  Ship, Name, Mass, kg, Acceleration, ms2, Impulse, Nskg, Max, Altitude,
  km, Designer;
  float shipMass, engineThrust, acceleration, impulse, maxAltitude;
  char user_select;

  
    cout << "Enter ship name: " << endl;
    cin >> shipName;
    
  ifstream inputFile(shipName + ".txt");
    if (inputFile.is_open()) {
        string designerName;
        float shipMass, acceleration, impulse, maxAltitude;

        inputFile >> shipName; 
        inputFile.ignore(100, '\n'); // Ignore the ship name header
        inputFile >> Ship >> Name >> shipName;
        
        inputFile >> Ship >> Mass >> shipMass >> kg;
        
        inputFile >> Acceleration >> acceleration >> ms2; 
       
        inputFile >> Impulse >> impulse >> Nskg;
     
        inputFile >> Max >> Altitude >> maxAltitude >> km;

        inputFile >> Designer >> Name >> designerName;




        inputFile.close();

        bool failedTest = false;
        int test = 1;

        if(designerName == "Thomas Harris") {
            cout << shipName << " has failed test number " << test << endl;
            failedTest = true;
            return;
        }

        test++;
        if(shipMass >= 1000) {
            cout << shipName << " has failed test number " << test << endl;
            failedTest = true;
            return;
        }

        test++;
        if(acceleration < 1 || acceleration > 10) {
            cout << shipName << " has failed test number " << test << endl;
            failedTest = true;
            return;
        }

        test++;
        if(impulse < 10) {
            cout << shipName << " has failed test number " << test << endl;
            failedTest = true;
            return;
        }

        test++;
        if(shipMass < 100 && maxAltitude < 150){
            cout << shipName << " has failed test number " << test << endl;
            failedTest = true;
            return;
        }

        test++;
        if(shipMass >= 100 && maxAltitude < 200){
            cout << shipName << " has failed test number " << test << endl;
            failedTest = true;
            return;
        }
          
        if(!failedTest) {
            cout << shipName << " has passed all tests" << endl;
        }
    }else { //connects to file input curly bracket
        cout << "ERROR: Opening the file" << endl;
    }
}

void simulateShip(){
  int time;
  float acceleration, speed, altitude, altitudeInKm;

    cout << "Enter acceleration value for space flight: " << endl;
    cin >> acceleration; 
    cout << "Enter seconds to run: "; 
    cin >> time;

  for(int i = 0; i <= time; i++){ //seconds increment into calculations    
      
    speed = (acceleration*i);
    altitude = (0.5) * acceleration * (i*i);

    if(altitude < 1000){ 
      cout << "At " << setw(2) << i <<  " seconds:  " <<
      fixed << setprecision(1) << setw(6) << speed << " m/s   " //line up
      << fixed << setprecision(1) << setw(6) << altitude << " m" << endl; 
    }
    
    if(altitude >= 1000){ 
      altitudeInKm = (altitude /= 1000); //convert anything over 1000 into 1
      cout << "At " << i <<  " seconds:  " <<
      fixed << setprecision(1) << setw(6) << speed << " m/s   " << fixed << 
      setprecision(1) << setw(6) << altitudeInKm << "km" << endl;
    }
  }
}

int main(){

  char user_select;

  cout << "This is Craft Designer Plus" << endl;

  do{ //will continually ask for menu
    
    cout << " " << endl;
    cout << "D - design a new ship" << endl;
    cout << "T - test a new ship" << endl;
    cout << "S - simulate a flight" << endl;
    cout << "Q - quit the program" << endl;
    cout << "Please make a selection: " << endl;
    cin >> user_select;

    switch(user_select){
      case 'D':
      case 'd':
        designShip();//prompts user to function designShip()
        break;
      case 'T':
      case 't':
        testShip();//prompts user to function testShip()
        break;
      case 'S':
      case 's':
        simulateShip();//prompts user to function simulateShip()
        break;
      case 'Q':
      case 'q':
        cout << "Thank you for using Craft Designer Plus" << endl;
        return 0;//ends program
        break;
      default:
        cout << "ERROR Invalid Input" << endl;  
    }  
  }while(user_select != 'Q' || user_select != 'q');
  
return 0;
  
}
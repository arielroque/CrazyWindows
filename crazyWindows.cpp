//Crazy Windows
//(C) 2019 Ariel Roque 

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <windows.h>

using namespace std;

void crazyCursor(){
	int x,y;
	x = (rand()% 1000) +2;
	y = (rand()% 1000) + 2;
	SetCursorPos(x,y);
}

int main(){
	int startTime,durationTime;
	
	cout << "Start time in seconds: (Ex: 10)" << endl;
	cin >> startTime;
	cout << "Duration time in seconds: (Ex: 40)" << endl;
	cin >> durationTime;
	
	auto startPreTime = chrono::steady_clock::now();
	auto endPreTime = chrono::steady_clock::now();
	int secondsPreTime = 0;
	
	while(secondsPreTime <= startTime){
		endPreTime = chrono::steady_clock::now();
		secondsPreTime = chrono::duration_cast<chrono::seconds>(endPreTime - startPreTime).count();
	}
	
	auto start = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();
	int secondsElapseds = 0;
	
	while(secondsElapseds < durationTime){
		end = chrono::steady_clock::now();
		secondsElapseds = chrono::duration_cast<chrono::seconds>(end - start).count();
		crazyCursor();
		Beep(523,500); 
	}
	return 0;
}

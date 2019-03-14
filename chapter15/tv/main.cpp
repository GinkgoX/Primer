#include<iostream>
#include"tv.h"

using namespace std;

int main()
{
	Tv s27;
	cout << "Initial setting for 27 \"TV :\n";
	s27.setting();
	s27.on_off();
	s27.chan_up();
	cout << "\nAdjusted settings for 27 \"TV :\n";
	s27.setting();
	
	Remote grey;
	grey.set_chan(s27, 10);
	grey.vol_up(s27);
	grey.vol_up(s27);
	cout << "\n27\"setting after using remote : \n";
	s27.setting();
	
	Tv s32(Tv::On);
	s32.set_mode();
	grey.set_chan(s32, 38);
	cout << "\n32\" setting for 32 \"TV \n";
	s32.setting();
	
	return 0;
}






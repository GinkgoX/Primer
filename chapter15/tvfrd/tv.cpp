#include<iostream>
#include"tv.h"

bool Tv::vol_up()
{
	if(volume < Maxval)
	{
		volume++;
		return true;
	}
	else
	{
		return false;
	}
}

bool Tv::vol_down()
{
	if(volume > Minval)
	{
		volume--;
		return true;
	}
	else
	{
		return false;
	}
}

void Tv::chan_up()
{
	if(channel < maxchannel)
	{
		channel++;
	}
	else
	{
		channel = 1;
	}
}

void Tv::chan_down()
{
	if(channel > 1)
	{
		channel--;
	}
	else
	{
		channel = maxchannel;
	}
}

void Tv::setting()const
{
	using std::cout;
	using std::endl;
	cout << "TV is " << (state == On ? "On" : "Off") << endl;
	if(state == On)
	{
		cout << "Volume setting : " << volume << endl;
		cout << "Channel setting : " << channel << endl;
		cout << "Mode : " << (mode == Antenna ? "Antenna" : "Cable") << endl;
		cout << "Input : " << (input == TV ? "TV" : "VCR") << endl;
	}
}

bool Remote::vol_up(Tv &t){return t.vol_up();};
bool Remote::vol_down(Tv &t){return t.vol_down();};
void Remote::on_off(Tv &t){return t.on_off();};
void Remote::chan_up(Tv &t){return t.chan_up();};
void Remote::chan_down(Tv &t){return t.chan_down();};
void Remote::set_chan(Tv &t, int c){t.channel = c;};
void Remote::set_input(Tv &t){t.set_input();};
void Remote::set_mode(Tv &t){t.set_mode();};


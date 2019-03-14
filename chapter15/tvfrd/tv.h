#ifndef TV_H_
#define TV_H_

class Tv;	//forward declaration

class Remote
{
private:
	int mode;
public:
	enum state{Off, On};
	enum{Minval, Maxval = 20};
	enum{Antenna, Cable};
	enum{TV, VCR};
	Remote(int m = TV):mode(m){};
	bool vol_up(Tv &t);
	bool vol_down(Tv &t);
	void on_off(Tv &t);
	void chan_up(Tv &t);
	void chan_down(Tv &t);
	void set_chan(Tv &t, int c);
	void set_input(Tv &t);
	void set_mode(Tv &t);
};

class Tv
{
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int input;
	int mode;
public:
	friend void Remote::set_chan(Tv &t, int c);
	enum state{Off, On};
	enum{Minval, Maxval = 20};
	enum{Antenna, Cable};
	enum{TV, VCR};
	
	Tv(int s = Off, int mc = 100):state(s), volume(5), maxchannel(mc), channel(2), input(TV), mode(Cable){};
	bool vol_up();
	bool vol_down();
	bool is_on()const{return state == On;};
	void on_off(){state = (state == On) ? Off : On;};
	void chan_up();
	void chan_down();
	void set_input(){input = (input == TV) ? VCR : TV;};
	void set_mode(){mode = (mode == Antenna) ? Cable : Antenna;};
	void setting()const;
};

#endif

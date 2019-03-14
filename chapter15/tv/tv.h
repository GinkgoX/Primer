#ifndef TV_H_
#define TV_H_

class Tv
{
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
public:
	friend class Remote;
	enum{Off, On};
	enum{Minval, Maxval = 20};
	enum{Antenna, Cable};
	enum{TV, VCR};
	Tv(int s = Off, int mc = 100):state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV){};
	void on_off(){state = (state == On) ? Off : On;};
	bool is_On()const{return (state == On);};
	bool vol_up();
	bool vol_down();
	void chan_up();
	void chan_down();
	void set_mode(){mode = (mode == Antenna) ? Cable : Antenna;};
	void set_input(){input = (input == TV) ? VCR : TV;};
	void setting()const;
};

class Remote
{
private:
	int mode;
public:
	Remote(int m = Tv::TV):mode(m){};
	void on_off(Tv &t){return t.on_off();};
	bool vol_up(Tv &t){return t.vol_up();};
	bool vol_down(Tv &t){return t.vol_down();};
	void chan_up(Tv &t){return t.chan_up();};
	void chan_down(Tv &t){return t.chan_down();};
	void set_chan(Tv &t, int c){t.channel = c;};
	void set_mode(Tv &t){return t.set_mode();};
	void set_input(Tv &t){return t.set_input();};	
};
#endif


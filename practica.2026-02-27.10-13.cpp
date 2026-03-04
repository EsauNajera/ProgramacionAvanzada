#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

#define PROPORTION_16_9 16.0f/9.0f
#define PROPORTION_4_3   4.0f/3.0f

class event{
public:
   event(const char* strEvent){
	m_event = new char[strlen(strEvent)+1];
	strcpy(m_event, strEvent);
	};

   void print(){
	cout << "DETALLES DEL EVENTO\n"<< m_event << endl;
	};
private:
	char* m_event;
};

class IODevice;
class Computer{
  public:
    Computer(const char* name){
	m_name = new char[strlen(name)+1];
	strcpy(m_name, name);
	for(int i = 0;i<256;i++)
		m_devs[i] = NULL;
	};
    unsigned int addIODevice(IODevice* Dev){
	if(m_addr==255) return 0xFFFF;
	m_addr ++;
	m_devs[m_addr] = Dev;
	return m_addr;
	};
   void pingDev();
  private:
	char* m_name;
//	unsigned int m_addrs[256];
	IODevice* m_devs[256];
	unsigned int m_addr = 0;
};

class IODevice{
  public:
    IODevice(Computer* parent_computer ){
	m_computer = parent_computer;
	m_addr = m_computer->addIODevice(this);
	};
   void notify(event* e){
	e->print();
	};
  private:
    Computer* m_computer;
    unsigned int m_addr;
};
void Computer::pingDev(){
	event ping_e("Ping Test");
	for(int i=0;i<m_addr;i++){
		m_devs[i]->notify(&ping_e);
	};
	};
class display_properties{
    public:
        display_properties(int x_pix,int y_pix, string MonitorName, int range = 256){
            x_pixels = x_pix;
            y_pixels = y_pix;
            color_bitDepth = int(sqrt(range)); // 8, 16 bits
            m_name = MonitorName;
        }
        display_properties(int x_pix,float proportion, string MonitorName, int range = 256){
            x_pixels = x_pix;
            y_pixels = x_pix /proportion;
            color_bitDepth = int(sqrt(range)); // 8, 16 bits
            m_name = MonitorName;
        }
        void get_display_properties();
    private:
        uint x_pixels;
        uint y_pixels;
        uint color_bitDepth;
        string m_name;
};
void display_properties::get_display_properties(){
    cout << "Nombre del Monitor: "<<m_name<<endl;
    cout << "Resolución: "<<x_pixels << "px x "<<y_pixels <<"px"<<endl;
    cout << "Bits: "<<color_bitDepth<<endl;
}

class Display : public display_properties , public IODevice{

};


int main(){

    display_properties DELL(1440,720,"DELL FHD 15inch Monitor");

    DELL.get_display_properties();
    Computer comp("DELL INSPIRON");
    IODevice dev(&comp);
    comp.pingDev();
}

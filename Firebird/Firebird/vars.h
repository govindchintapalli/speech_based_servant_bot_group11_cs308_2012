#ifndef VARIABLES
#define  VARIABLES
int x_pres=0,y_pres=0,x_dest=0,y_dest=0;
int facing=0;
int dump=0,diff_fac=0;
char coor [10],back;
unsigned char data;

float WheelRadius = 25.5;
float BotRadius = 80;
int flag4, flag7, flag6;


/***********************************
off   lcd_string(arr);   :number of elements in the path
off_d    :number of destinations
path_off :present path offset
pres_off :present target offset
************************************/

int off,off_d,path_off,pres_off; 

int path[50],edges[36][4];
int next_dest[100];
int priority[8]={0123, 1023, 1023, 1203, 2130, 3210, 3201, 3012};  //order of priority of edges while doing dfs
int offset[4] = {6,1,-6,-1};  //neighbours of a node in single_int form
int visit[36];  //used in dfs
int pres_fin_dest; 


#define SetBit(x,b) ((x)|=(b))
#define GetBit(x,b) ((x)&(b))
#define ResetBit(x,b) ((x)&=(~(b)))



void port_init();
void timer5_init();
void velocity(unsigned char, unsigned char);
void motors_delay();

static volatile unsigned char ShaftCountLeft = 0;
static volatile unsigned char ShaftCountRight = 0;
unsigned char ADC_Conversion(unsigned char);
unsigned char ADC_Value;
unsigned char flag = 0;
unsigned char Left_white_line = 0;
unsigned char Center_white_line = 0;
unsigned char Right_white_line = 0;
unsigned char Front_IR_Sensor = 0;
unsigned char Left_IR_Sensor = 0;
unsigned char Right_IR_Sensor = 0;


char *inpStr,*backup ;
char msg[100];
int len,ack=1,next_stop=0,backlen,msglen;
int read_inp=0;



#define W_THRESHOLD 0x1f
#define W_THRESHOLD_STOP 0x08
#define ROTATE_THRESHOLD 0x0f //0x41

#define LEFT_SENSOR   3
#define CENTER_SENSOR 2
#define RIGHT_SENSOR  1
#define FRONT_IR_SENSOR 6
#define LEFT_IR_SENSOR  4
#define RIGHT_IR_SENSOR 8

#define CONT_BLACK 5

#endif

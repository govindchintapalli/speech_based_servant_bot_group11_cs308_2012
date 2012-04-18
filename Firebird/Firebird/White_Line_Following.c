#include "motion.h"
#include "funcs.h"
#include <stdio.h>
#include "bt.h"
#include <stdlib.h>
void initAll(){
	Init_USART3();
	inpStr = (char*)malloc(100);
	backup=(char*)malloc(100);
	init_devices();
	lcd_set_4bit();
	lcd_init();
	init();
	//set the destination in the path array
	//next_dest[0]=7;
	//next_dest[1]=2;
	pres_off=-1;
	path_off=-1;
	off_d=0;
	off=0;
	back=0;
	x_pres=0;
	y_pres=0;
	x_dest=0;
	y_dest=0;
	
}
int main()
{
	initAll();
	data='1';
	char val[10];
	while(1)
	{
			
		if(read_inp){
			bluetooth();
			//lcd_string("working");

		}
		/*
		lcd_cursor(1,5);
		lcd_wr_char(data);
		_delay_ms(1000);
		lcd_cursor(1,5);
		lcd_wr_char('0');
		_delay_ms(1000);
		if (data == 'F'){
			lcd_cursor(1,10);
			lcd_wr_char('9');
		}
		continue;		
		*/
		buzzer_off();
		
		sprintf(val, "%d %d", pres_off, path_off);
			lcd_cursor(1,10);
			lcd_string(coor);
		read_sensors();
		print_sensor_data();

		if(x_pres == x_dest && y_pres == y_dest){
			//give the next destination
			_delay_ms(10);		
			if(off_d == pres_off){
				off_d=0;
				pres_off=0;
				continue;
			}
			path_off++;
			if(path_off == off) {
				path_off=0;
				pres_off++;
				if (pres_off!=off_d){
					path[0]=next_dest[pres_off];
					off=1;
				}

			}
			_delay_ms(500);
			set_dest(path_off);
			dump=0;
			lcd_cursor(2,1);

			lcd_string("Stop");
			//x_dest=3;
			//y_dest=3;	//if something is there in path[i], set_dest[i];		
		}	

		else{	
		int prev_facing;
		  
	      if(Left_white_line<W_THRESHOLD && Right_white_line<W_THRESHOLD && Center_white_line<W_THRESHOLD){
			  
		      prev_facing = facing;
			  if(dump){
			  	 if(prev_facing==0) y_pres++;
				 else if (prev_facing==1)x_pres++;
				 else if (prev_facing==2)y_pres--;
				 else x_pres--;
			  }
			  if(next_stop){
			  	x_dest = x_pres;	
				y_dest = y_pres;
				next_stop=0;
				off=0;
				off_d=0;
				pres_off=0;
				path_off=0;
			  }
  			sprintf(coor, "%d %d %d", x_pres, y_pres,facing);
			lcd_cursor(2,6);
			lcd_string(coor);	  
			  if(x_pres == x_dest && y_pres == y_dest)
					continue;				



				forward();
				mod_velocity(0,0);
										
				mod_velocity(85,85);
				_delay_ms(700);							

		      if(x_pres==x_dest && y_pres<y_dest ) {
		        facing = 0;
		      }
		      else if(x_pres<x_dest ){
		        facing = 1;
		      }
		      else if(x_pres==x_dest && y_pres>y_dest ){
		        facing = 2;
		      }
		      else if(x_pres>x_dest ){
		        facing = 3; 
		      }
  				diff_fac = prev_facing - facing;
		      if( (diff_fac) == 2 || (diff_fac) == -2){
		        //reverse
		        turn_right();
		        turn_right();
				lcd_cursor(2,1);
				lcd_string("BACK");
		      }
		      else if(diff_fac == -1 || diff_fac == 3){
		        //right
		        turn_right();
				lcd_cursor(2,1);
				lcd_string("righ");
		      }
  
		      else if(diff_fac == 1 || diff_fac== -3){
		        //left
		        turn_left();
				lcd_cursor(2,1);
				lcd_string("LEFT");
		      }
			  
			}
			dump=1;
			read_sensors();
			go_upto_next_cross();
			_delay_ms(1000);
			read_sensors();
		}
  }
}

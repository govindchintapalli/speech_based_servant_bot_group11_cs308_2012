void read_sensors();
void buzzer_on (void);
void buzzer_off (void);
void left_position_encoder_interrupt_init(void);
void right_position_encoder_interrupt_init(void);
void reset_shaft_counters();
void lcd_port_config (void);
void adc_pin_config (void);
void motion_pin_config (void) ;
void port_init();
void timer5_init();
void adc_init();
void motion_set (unsigned char Direction);
void forward (void) ;
void stop (void);
void init_devices (void);

void turn_right();
void turn_left();
void go_upto_next_cross();
void dfs_init();
void set_dest(int i);
void init();
int dfs(int a ,int b);
void print_sensor(char row, char coloumn,unsigned char channel);
void print_sensor_data();
void velocity (unsigned char left_motor, unsigned char right_motor);
void mod_velocity(int l,int r);


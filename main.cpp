#include "mbed.h"


InterruptIn button(USER_BUTTON);
Serial pc(USBTX, USBRX); //TX, RX
Thread thread;
DigitalOut led(LED1);


int speed = 0;//ค่าเริ่มต้นเป็น0
double delay = 0.5; // 500 ms

void tx_thread() {
    while (true) {
        pc.printf("test %d \n", speed); //ไว้ดูข้อมูลที่จะส่ง
        wait(0.1);
        wait(60);
    }
}

void interrup()
{
    speed = speed + 1 ;
    wait(0.1);
    if(speed == 11){
        speed = 0 ;
    }
    wait(0.1);
}


int main()
{
    // Assign functions to button
    button.fall(&interrup);
    thread.start(tx_thread);
    
    while (1) {
        led = !led;
        pc.printf("%d" , speed);
        wait(1);
    }
}

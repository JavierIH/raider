#include "../../libraries/raider/raider.h"
#include <iostream>

int main()
{
    Raider raider;
    bool flag_side=0;
    int left_distance;
    int right_distance;
    int state=1;
    int state_vertical;

    while(true){
        switch (state) {
        case 1:
            raider.defense();
            usleep(600000);
            left_distance=raider.getLeftIR();
            right_distance=raider.getRightIR();
            if(left_distance==2 && right_distance==2) state=7;
            else if(left_distance==2) state=8;
            else if(right_distance==2) state=9;
            else if(left_distance==1 && right_distance==1) state=4;
            else if(left_distance==1) state=5;
            else if(right_distance==1) state=6;
            else if(flag_side){
                flag_side=0;
                state=2;
            }
            else{
                flag_side=1;
                state=3;
            }
            break;

        case 2:

            raider.lookL();
            usleep(600000);
            left_distance=raider.getLeftIR();
            right_distance=raider.getRightIR();

            if(left_distance==2){
                raider.miniPunchL();
            }
            else if(right_distance==2){
                raider.miniPunchR();
            }
            else if(left_distance==1) state=5;
            else if(right_distance==1) state=4;
            else state=10;
            break;

        case 3:
            raider.lookR();
            usleep(600000);
            left_distance=raider.getLeftIR();
            right_distance=raider.getRightIR();

            if(right_distance==2){
                raider.miniPunchR();
            }
            else if(left_distance==2){
                raider.miniPunchL();
            }
            else if(right_distance==1) state=6;
            else if(left_distance==1) state=4;
            else state=10;
            break;

        case 4:
            raider.run();
            state=10;
            break;

        case 5:
            raider.turnL();
            state=10;
            break;

        case 6:
            raider.turnR();
            state=10;
            break;

        case 7:
            raider.crab();
            state=10;
            break;

        case 8:
            raider.punchL();
            state=10;
            break;

        case 9:
            raider.punchR();
            state=10;
            break;
        case 10:
            raider.getUp();
            state=1;
         break;

        default:
            state=1;
            break;

        }

    }
}


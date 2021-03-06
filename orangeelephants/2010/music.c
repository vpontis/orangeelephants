/*
From Andover Robotics
 Program for looping a piece of music
Music included:
 Pachelbel's Canon in D (pachelbel() pachelbel2())
 Star Wars Main Theme  (starwars() and starwarslong())
*/

#include "musiclib.c"

//main() is at the bottom

int pachelbel()
{
    d(2.0,1.021);
    a(2.0,1.021);
    b(2.0,1.021);
    fs(1.0,1.021);
    g(1.0,1.021);
    d(1.0,1.021);
    g(1.0,1.021);
    a(1.0,1.021);
}

int pachelbel2()
{
    a(2.0,.25);
    fs(1.0,.125);
    g(1.0,.125);
    a(2.0,.25);
    fs(1.0,.125);
    g(1.0,.125);
    a(2.0,.125);
    a(1.0,.125);
    b(1.0,.125);
    cs(1.0,.125);
    d(1.0,.125);
    e(1.0,.125);
    fs(1.0,.125);
    g(1.0,.125);
    
    fs(1.0,.25);
    d(1.0,.125);
    e(1.0,.125);
    fs(1.0,.25);
    fs(.5,.125);
    g(.5,.125);
    a(1.0,.125);
    b(1.0,.125);
    a(1.0,.125);
    g(.5,.125);
    a(1.0,.125);
    fs(.5,.125);
    g(.5,.125);
    a(1.0,.125);
    
    g(.5,.25);
    b(1.0,.125);
    a(1.0,.125);
    g(.5,.25);
    fs(.5,.125);
    e(.5,.125);
    fs(.5,.125);
    e(.5,.125);
    d(.5,.125);
    e(.5,.125);
    fs(.5,.125);
    g(.5,.125);
    a(1.0,.125);
    b(1.0,.125);
    
    g(.5,.25);
    b(1.0,.125);
    a(1.0,.125);
    b(1.0,.25);
    cs(1.0,.125);
    d(1.0,.125);
    a(1.0,.125);
    b(1.0,.125);
    cs(1.0,.125);
    d(1.0,.125);
    e(1.0,.125);
    fs(1.0,.125);
    g(1.0,.125);
    a(2.0,.125);
    
    fs(1.0,.25);
    d(1.0,.125);
    e(1.0,.125);
    fs(1.0,.25);
    e(1.0,.125);
    d(1.0,.125);
    e(1.0,.125);
    cs(1.0,.125);
    d(1.0,.125);
    e(1.0,.125);
    fs(1.0,.125);
    e(1.0,.125);
    d(1.0,.125);
    cs(1.0,.125);
    
    d(1.0,.25);
    b(1.0,.125);
    cs(1.0,.125);
    d(1.0,.25);
    d(.5,.125);
    e(.5,.125);
    fs(.5,.125);
    g(.5,.125);
    fs(.5,.125);
    e(.5,.125);
    fs(.5,.125);
    d(1.0,.125);
    cs(1.0,.125);
    d(1.0,.125);
    
    b(1.0,.25);
    d(1.0,.125);
    cs(1.0,.125);
    b(1.0,.25);
    a(1.0,.125);
    g(.5,.125);
    a(1.0,.125);
    g(.5,.125);
    fs(.5,.125);
    g(.5,.125);
    a(1.0,.125);
    b(1.0,.125);
    cs(1.0,.125);
    d(1.0,.125);
    
    b(1.0,.25);
    d(1.0,.125);
    cs(1.0,.125);
    d(1.0,.25);
    cs(1.0,.125);
    b(1.0,.125);
    cs(1.0,.125);
    d(1.0,.125);
    e(1.0,.125);
    d(1.0,.125);
    cs(1.0,.125);
    d(1.0,.125);
    b(1.0,.125);
    cs(1.0,.125);
}


int starwars()
{
    d(.5,.1667);
    d(.5,.1667);
    d(.5,.1667);
    g(.5,1.0);
    d(1.0,1.0);
    c(1.0,.1667);
    b(1.0,.1667);
    a(1.0,.1667);
    g(1.0,1.0);
    d(1.0,.5);
    c(1.0,.1667);
    b(1.0,.1667);
    a(1.0,.1667);   
    g(1.0,1.0);
    d(1.0,.5);
    c(1.0,.1667);
    b(1.0,.1667);
    c(1.0,.1667);
    a(1.0,.90);
    rest(.1);
    
    d(.5,.333);
    d(.5,.1667);
    g(.5,1.0);
    d(1.0,1.0);
    c(1.0,.1667);
    b(1.0,.1667);
    a(1.0,.1667);
    g(1.0,1.0);
    d(1.0,.5);
    c(1.0,.1667);
    b(1.0,.1667);
    a(1.0,.1667);   
    g(1.0,1.0);
    d(1.0,.5);
    c(1.0,.1667);
    b(1.0,.1667);
    c(1.0,.1667);
    a(1.0,.90);    
    rest(.10);
}

int starwarslong()
{
    starwars();
    
    d(.5,.333);
    d(.5,.1667);
    e(.5,.75);
    e(.5,.25);
    c(1.0,.25);
    b(1.0,.25);
    a(1.0,.25);
    g(.5,.25);
    g(.5,.1667);
    a(1.0,.1667);
    b(1.0,.1667);
    a(1.0,.333);
    e(.5,.1667);
    fs(.5,.5);
    
    d(.5,.333);
    d(.5,.1667);
    e(.5,.75);
    e(.5,.25);
    c(1.0,.25);
    b(1.0,.25);
    a(1.0,.25);
    g(.5,.25);
    d(1.0,.375);
    a(1.0,.125);
    a(1.0,.90);
    rest(.1);
    
    d(.5,.333);
    d(.5,.1667);
    e(.5,.75);
    e(.5,.25);
    c(1.0,.25);
    b(1.0,.25);
    a(1.0,.25);
    g(.5,.25);
    g(.5,.1667);
    a(1.0,.1667);
    b(1.0,.1667);
    a(1.0,.333);
    e(.5,.1667);
    fs(.5,.5);
    
    d(1.0,.333);
    d(1.0,.1667);
    g(1.0,.333);
    f(1.0,.1667);
    ds(1.0,.333);
    d(1.0,.1667);
    c(1.0,.333);
    as(1.0,.1667);
    a(1.0,.333);
    g(.5,.1667);
    d(1.0,1.45);
    
    starwars();
    
    d(1.0,.5);
    g(1.0,3.0);
    rest(.5);
    g(1.0,.1667);
    g(1.0,.1667);
    g(1.0,.1667);
    g(1.0,.25);
    rest(1.5);
}

/*
int main(){
    while(a_button()){
        while(!b_button()){
            pachelbel();
        }
    }
}
*/

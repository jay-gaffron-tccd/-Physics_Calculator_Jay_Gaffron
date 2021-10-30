/* A header file to hold the 
main defintions of the program
Student: Jay Gaffron
Teacher: Dr_T 10-17-2019, updated 3-24-2020 (clear screen methods for Ubuntu)
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
//put libraries here
#include <iostream>
#include <iomanip>
#include<string>
#include<cmath>
#include "Input_Validation_Extended.h" 
using namespace std;

//Define variables for various equasions
double dt;    //time placeholder for eq
double ds;    //distance placeholder for eq
string us;    //units for distance
string ut;    //units for time
double dv;    //velcoity placeholder for eq
string uv;    //units for velocity
double dm;    //mass placeholder for eq
string um;    //units for mass
double da;    //acceleration placeholder for eq
string ua;    //units for acceleration
double dg;    //gravity placeholder
string uw;    //units for weight
string uq;    //units for momentum

//put prototypes here
void handleOption(string); //function prototype 
void showMenu();
void velocity(double,double); //velocity funct 
void acceleration(double,double); // accelration funct
void newtonsLaw(double,double); // force funct
void weight(double,double); // weight funct
void momentum(double,double); //momentum funct
void motionMenu(); // motion menu
void motionOptions(string); // handles the motion options
// motion menu options
void motionVelocity(double,double,double);
void motionDisplacement(double,double,double);
void motionV2(double,double,double);
void motionConstantVelocity(double,double);



//put definitions here
void handleOption(string userOption)
{
  string color = "\x1b[" + to_string(34) + ";1m";
  string reset = "\x1b[0m";
  cout << color; // blue menu :)
    if(userOption == "A" || userOption == "a") // Velocity
    {
      cout << "\nSolving for velocity." << endl;
      cout << "\nWhat is the change in distance? ";
      ds = validateDouble(ds);
      cout << "What is the units of measure for the distance? ";
      us = validateString(us);
      cout << "You input " << ds << us << " as your distance." << endl;
      cout << "\nWhat is the change in time? ";
      dt = validateDouble(dt);
      cout << "What is the units of measure for the time? ";
      ut = validateString(ut);
      cout << "You input " << dt << ut << " as your time." << endl;
      velocity(dt, ds);
    }
    else if(userOption == "B" || userOption == "b") // Acceleration
    {
      cout << "\nSolving for acceleration." << endl;
      cout << "\nWhat is the velocity? ";
      dv = validateDouble(dv);
      cout << "What is the units of measure for velocity? (Ex: m/s) ";
      uv = validateString(uv);
      cout << "You input " << dv << " " << uv << " as your velocity." << endl;
      cout << "\nWhat is the change in time? ";
      dt = validateDouble(dt);
      cout << "What is the units of measure for time? ";
      ut = validateString(ut);
      cout << "You input " << dt << ut << " as your time." << endl;
      acceleration(dv,dt);
    }
    else if(userOption == "C" || userOption == "c") // Newton's Second Law
    {
      cout << "\nSolving for Newton's Second Law." << endl;
      cout << "\nWhat is the mass? ";
      dm = validateDouble(dm);
      cout << "What is the units of mass? ";
      um = validateString(um);
      cout << "You input " << dm << um << " as your mass." << endl;
      cout << "\nWhat is the acceleration? ";
      da = validateDouble(da);
      cout << "What is the units for acceleration? (Ex. m/s^2 or m/s/s) ";
      ua = validateString(ua);
      cout << "You input " << da << " " << ua << " as your acceleration." << endl;
      newtonsLaw(dm,da);
    }
    else if(userOption == "D" || userOption == "d") // Weight
    { 
      cout << "\nSolving for weight." << endl;
      cout << "\nWhat is the mass? ";
      dm = validateDouble(dm);
      cout << "You input " << dm << " as your mass." << endl;
      cout << "\nWhat is the gravity? ";
      dg = validateDouble(dg);
      cout << "You input " << dg << " as your gravity." << endl;
      cout << "\nWhat is the expected unit output? (Ex. lbs, stone) ";
      uw = validateString(uw);
      cout << "Your expected unit ouput is " << uw << endl;
      weight(dm,dg);
    }
    else if(userOption == "E" || userOption == "e") // Momentum
    {
      cout << "\nSolving for momentum." << endl;
      cout << "\nWhat is the mass? ";
      dm = validateDouble(dm);
      cout << "What is the units of mass? ";
      um = validateString(um);
      cout << "You input " << dm << um << " as your mass." << endl;
      cout << "\nWhat is the velocity? ";
      dv = validateDouble(dv);
      cout << "What is units for velocity? ";
      uv = validateString(uv);
      cout << "You input " << dv << uv << " as your velocity." << endl;
      momentum(dm,dv);
    }
    else if(userOption == "F" || userOption == "f") //motion menu
    {
      cout << "Motion solver sub-menu." << endl;
      motionMenu();
      userOption = validateString(userOption);
      motionOptions(userOption);
    }
    else if(userOption == "X" || userOption == "x")
    {
      string reset = "\x1b[0m";
      //Linux Umbunu
      cout << reset; 
      cout << "\033[2J\033[1;1H";  //for ubuntu Linux Option 1 of 2
      //Windows: system("cls"); 
      system("clear"); //for ubuntu Linux Option 2 of 2
    }
    else if(userOption == "z" || userOption == "Z")
    {
      char answer = '\0';

      cout << "\nPlease enter Y or N: ";
      answer = validateChar(answer); 

      if(answer == 'Y')
      {
        cout << "\nEnd program. Goodbye!!" << endl;
      }
      else if (answer == 'N')
      {
        cout << "\nBlue sky." << endl;
      }

    }
    else
    {
      cout << "\nInvalid input: try again." << endl; 
    }
}

void motionOptions(string userOption) //motion sub menu options
{
  if(userOption == "A" || userOption == "a")
  {
    cout << "\nSolving for velocity with motion." << endl;
    cout << "\nWhat is the initial velocity? (v_0) ";
    dv = validateDouble(dv);
    cout << "What is the units for velocity? (Ex. m/s) ";
    uv = validateString(uv);
    cout << "You input " << dv << uv << " as your initial velocity." << endl;
    cout << "\nWhat is the acceleration? ";
    da = validateDouble(da); // no units here bc the equation is solving for velocity
    cout << "You input " << da << " as your acceleration." << endl;
    cout << "\nWhat is the change in time? ";
    dt = validateDouble(dt);
    cout << "You input " << dt << " as your time." << endl;
    motionVelocity(dv,da,dt);
  }
  else if(userOption == "B" || userOption == "b")
  {
    cout << "\nSolving for displacement with motion." << endl;
    cout << "\nWhat is the initial velocity? (v_0) ";
    dv = validateDouble(dv);
    cout << "What is the units of measure for the initial velocity? _______ / _______ ? " << endl;
    us = validateString(us);
    ut = validateString(ut);
    cout << "You input " << dv << " " << us << "/" << ut << " as your initial velocity." << endl;
    cout << "\nWhat is the acceleration? ";
    da = validateDouble(da);
    cout << "You input " << da << " as your acceleration." << endl;
    cout << "\nWhat is the change in time? ";
    dt = validateDouble(dt);
    cout << "You input " << dt << " as your time." << endl;
    motionDisplacement(dv,da,dt);
  }
  else if(userOption == "C" || userOption == "c")
  {
    cout << "\nSolving for velocity with position." << endl;
    cout << "\nWhat is the initial velocity? (v_0) ";
    dv = validateDouble(dv);
    cout << "What is the units of measure for the initial velocity? ";
    uv = validateString(uv);
    cout << "You input " << dv << uv << " as your initial velocity." << endl;
    cout << "\nWhat is the acceleration? ";
    da = validateDouble(da);
    cout << "You input " << da << " as your acceleration." << endl;
    cout << "\nWhat is the change in position? ";
    ds = validateDouble(ds);
    cout << "You input " << ds << " as your change in position." << endl;
    motionV2(dv,da,ds);
  }
  else if(userOption == "D" || userOption == "d")
  {
    cout << "\nSolving for constant velocity." << endl;
    cout << "\nWhat is the  velocity? ";
    dv = validateDouble(dv);
    cout << "What is the units for velocity? ";
    uv = validateString(uv);
    cout << "You input " << dv << uv << " as the velocity." << endl;
    cout << "\nWhat is the initial velocity? (v_0) ";
    ds = validateDouble(ds);
    cout << "You input " << ds << uv << " as your initial velocity." << endl;
    motionConstantVelocity(dv,ds);
  }
  else
  {
    cout << "\nInvalid input: try again." << endl;
  }
}

void showMenu()
{
  cout << "\nMENU" << endl; 
  cout << "A: Velocity solver" << endl; 
  cout << "B: Acceleration solver" << endl; 
  cout << "C: Force solver" << endl; 
  cout << "D: Weight solver" << endl; 
  cout << "E: Momentum solver" << endl;
  cout << "F: Motion solver menu" << endl;
  cout << "Z: Exit" << endl; 
  cout << "X: clear the screen" << endl;  
}
void motionMenu()
{
  cout << "\nMotion Menu" << endl;
  cout << "A: Ma = solving for velocity" << endl;
  cout << "B: Ms = solving for displacement" << endl;
  cout << "C: Mv2 = solving for velocity with position (v^2)" << endl;
  cout << "D: Mv = solving for constant velocity" << endl;
  cout << "\nPlease choose an option: ";
}
//definintion 
void velocity(double ds, double dt)
{
  double v = (ds / dt);
  cout << "\nVelocity is equal to " << v << " " << us << "/" << ut << endl;
}
void acceleration(double dv, double dt)
{
  double a = (dv / dt);
  cout << "\nAcceleration is equal to " << a << " " << uv << "/" << ut << endl;
}
void newtonsLaw(double dm, double da)
{
  double f = (dm * da);
  cout << "\nNewton's Second Law, force, is equal to " << f << " " << um << " " << ua << endl;
}
void weight(double dm, double dg)
{
  double w = (dm * dg);
  cout << "\nWeight is equal to " << w << " " << uw << endl;
}
void momentum(double dm, double dv)
{
  double q = (dm * dv);
  cout << "\nMomentum is equal to " << q << " " << um << " " << uv << endl;
}
void motionVelocity(double dv, double da, double dt)
{
  double v = (dv + (da * dt));
  cout << "\nVelocity in regards to motion is equal to " << v << " " << uv << endl;
}
void motionDisplacement(double dv, double da, double dt)
{
  double s = ((dv * dt) + (.5 * da * (dt * dt)));
  cout << "\nDisplcaement in regards to motion is equal to " << s << " " << us << endl;
}
void motionV2(double dv, double da, double ds)
{
  double v = ((dv * dv) + (2 * da * ds));
  double sv = sqrt(v);
  cout << "\nThe equation for this function gives the final answer as velocity squared, which is " << v << uv << "." << endl;
  cout << "The square root of that answer is " << sv << uv << endl;
}
void motionConstantVelocity(double dv, double ds)
{
  double v = (.5 * (dv + ds));
  cout << "\nThe constant velocity is equal to " << v << " " << uv << "." << endl;
}
#endif
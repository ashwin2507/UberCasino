#ifndef START_WINDOW_H
#define START_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Round_Button.H>
#include <iostream>
#include <FL/Fl_Group.H>
#include <FL/fl_ask.H> 


using namespace std;

//---------------------------------------------------
 
class StartWindow : public Fl_Window{
 
   public:
      StartWindow(int w, int h, const char* title,const char* uuid_in);
      ~StartWindow();
      Fl_Box * welcome;
      Fl_Button* start;
      Fl_Button* quit;
      Fl_Input* name;
      Fl_Output* uuid;
      Fl_Round_Button* test_deck;
      Fl_Round_Button* eight_deck;
      Fl_Round_Button* infinite_deck;

      const char* get_dealer_name();


   
   private:
      static void cb_start(Fl_Widget* o, void* v);
      inline void cb_start_i(Fl_Widget* b, void* d);
 
      static void cb_quit(Fl_Widget* o, void* v);
      inline void cb_quit_i(Fl_Widget* b, void* d);

      static void cb_radio(Fl_Widget* o, void* v); 
      inline void cb_radio_i(Fl_Widget *b, void *d); 

      const char* dealer_name;

};

#endif


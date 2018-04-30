#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <FL/Fl_PNG_Image.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Round_Button.H>
#include <iostream>
#include <FL/Fl_Group.H>
#include <vector>
#include <FL/Fl_Widget.H>
#include "UberCasino.h"


using namespace std;

//---------------------------------------------------
 
class MainWindow : public Fl_Window{
 
   public:
      MainWindow(int w, int h, const char* title, const char* dealer_Name, const char* dealer_Uid, const char* deck_Type);
      ~MainWindow();

      Fl_PNG_Image* png;
      Fl_Box* box;   

      Fl_Box* game_info;
      Fl_Output *dealerName;
      Fl_Output *dealerUid;
      Fl_Output *deckType;
      Fl_Output *numPlayers;
      Fl_Box* table_count;

      //images for cards
      Fl_PNG_Image* AC = new Fl_PNG_Image("src/PNG/AC.png");
      Fl_PNG_Image* AD = new Fl_PNG_Image("src/PNG/AD.png");
      Fl_PNG_Image* AH = new Fl_PNG_Image("src/PNG/AH.png");
      Fl_PNG_Image* AS = new Fl_PNG_Image("src/PNG/AS.png");
      Fl_PNG_Image* C2 = new Fl_PNG_Image("src/PNG/2C.png");
      Fl_PNG_Image* D2 = new Fl_PNG_Image("src/PNG/2D.png");
      Fl_PNG_Image* H2 = new Fl_PNG_Image("src/PNG/2H.png");
      Fl_PNG_Image* S2 = new Fl_PNG_Image("src/PNG/2S.png");
      Fl_PNG_Image* C3 = new Fl_PNG_Image("src/PNG/3C.png");
      Fl_PNG_Image* D3 = new Fl_PNG_Image("src/PNG/3D.png");
      Fl_PNG_Image* H3 = new Fl_PNG_Image("src/PNG/3H.png");
      Fl_PNG_Image* S3 = new Fl_PNG_Image("src/PNG/3S.png");
      Fl_PNG_Image* C4 = new Fl_PNG_Image("src/PNG/4C.png");
      Fl_PNG_Image* D4 = new Fl_PNG_Image("src/PNG/4D.png");
      Fl_PNG_Image* H4 = new Fl_PNG_Image("src/PNG/4H.png");
      Fl_PNG_Image* S4 = new Fl_PNG_Image("src/PNG/4S.png");
      Fl_PNG_Image* C5 = new Fl_PNG_Image("src/PNG/5C.png");
      Fl_PNG_Image* D5 = new Fl_PNG_Image("src/PNG/5D.png");
      Fl_PNG_Image* H5 = new Fl_PNG_Image("src/PNG/5H.png");
      Fl_PNG_Image* S5 = new Fl_PNG_Image("src/PNG/5S.png");
      Fl_PNG_Image* C6 = new Fl_PNG_Image("src/PNG/6C.png");
      Fl_PNG_Image* D6 = new Fl_PNG_Image("src/PNG/6D.png");
      Fl_PNG_Image* H6 = new Fl_PNG_Image("src/PNG/6H.png");
      Fl_PNG_Image* S6 = new Fl_PNG_Image("src/PNG/6S.png");
      Fl_PNG_Image* C7 = new Fl_PNG_Image("src/PNG/7C.png");
      Fl_PNG_Image* D7 = new Fl_PNG_Image("src/PNG/7D.png");
      Fl_PNG_Image* H7 = new Fl_PNG_Image("src/PNG/7H.png");
      Fl_PNG_Image* S7 = new Fl_PNG_Image("src/PNG/7S.png");
      Fl_PNG_Image* C8 = new Fl_PNG_Image("src/PNG/8C.png");
      Fl_PNG_Image* D8 = new Fl_PNG_Image("src/PNG/8D.png");
      Fl_PNG_Image* H8 = new Fl_PNG_Image("src/PNG/8H.png");
      Fl_PNG_Image* S8 = new Fl_PNG_Image("src/PNG/8S.png");
      Fl_PNG_Image* C9 = new Fl_PNG_Image("src/PNG/9C.png");
      Fl_PNG_Image* D9 = new Fl_PNG_Image("src/PNG/9D.png");
      Fl_PNG_Image* H9 = new Fl_PNG_Image("src/PNG/9H.png");
      Fl_PNG_Image* S9 = new Fl_PNG_Image("src/PNG/9S.png");
      Fl_PNG_Image* C10 = new Fl_PNG_Image("src/PNG/10C.png");
      Fl_PNG_Image* D10 = new Fl_PNG_Image("src/PNG/10D.png");
      Fl_PNG_Image* H10 = new Fl_PNG_Image("src/PNG/10H.png");
      Fl_PNG_Image* S10 = new Fl_PNG_Image("src/PNG/10S.png");
      Fl_PNG_Image* JC = new Fl_PNG_Image("src/PNG/JC.png");
      Fl_PNG_Image* JD = new Fl_PNG_Image("src/PNG/JD.png");
      Fl_PNG_Image* JH = new Fl_PNG_Image("src/PNG/JH.png");
      Fl_PNG_Image* JS = new Fl_PNG_Image("src/PNG/JS.png");
      Fl_PNG_Image* QC = new Fl_PNG_Image("src/PNG/QC.png");
      Fl_PNG_Image* QD = new Fl_PNG_Image("src/PNG/QD.png");
      Fl_PNG_Image* QH = new Fl_PNG_Image("src/PNG/QH.png");
      Fl_PNG_Image* QS = new Fl_PNG_Image("src/PNG/QS.png");
      Fl_PNG_Image* KC = new Fl_PNG_Image("src/PNG/KC.png");
      Fl_PNG_Image* KD = new Fl_PNG_Image("src/PNG/KD.png");
      Fl_PNG_Image* KH = new Fl_PNG_Image("src/PNG/KH.png");
      Fl_PNG_Image* KS = new Fl_PNG_Image("src/PNG/KS.png");
      
      //dealer
      Fl_Box* dealer_value;
      Fl_Box* card1;
      Fl_Box* card2;
      Fl_Box* card3;
      Fl_Box* card4;
      Fl_Box* card5;
      Fl_Box* card6;
      Fl_Box* card7;
      Fl_Box* card8;
      Fl_Box* card9;
      Fl_Box* card10;

      //player 1
      Fl_Box* player1_value;
      Fl_Box* card1_1;
      Fl_Box* card1_2;
      Fl_Box* card1_3;
      Fl_Box* card1_4;
      Fl_Box* card1_5;
      Fl_Box* card1_6;
      Fl_Box* card1_7;
      Fl_Box* card1_8;
      Fl_Box* card1_9;
      Fl_Box* card1_10;

      //player 2
      Fl_Box* player2_value;
      Fl_Box* card2_1;
      Fl_Box* card2_2;
      Fl_Box* card2_3;
      Fl_Box* card2_4;
      Fl_Box* card2_5;
      Fl_Box* card2_6;
      Fl_Box* card2_7;
      Fl_Box* card2_8;
      Fl_Box* card2_9;
      Fl_Box* card2_10;

      //player 3
      Fl_Box* player3_value;
      Fl_Box* card3_1;
      Fl_Box* card3_2;
      Fl_Box* card3_3;
      Fl_Box* card3_4;
      Fl_Box* card3_5;
      Fl_Box* card3_6;
      Fl_Box* card3_7;
      Fl_Box* card3_8;
      Fl_Box* card3_9;
      Fl_Box* card3_10;

      //player 4
      Fl_Box* player4_value;
      Fl_Box* card4_1;
      Fl_Box* card4_2;
      Fl_Box* card4_3;
      Fl_Box* card4_4;
      Fl_Box* card4_5;
      Fl_Box* card4_6;
      Fl_Box* card4_7;
      Fl_Box* card4_8;
      Fl_Box* card4_9;
      Fl_Box* card4_10;

      //player 5
      Fl_Box* player5_value;
      Fl_Box* card5_1;
      Fl_Box* card5_2;
      Fl_Box* card5_3;
      Fl_Box* card5_4;
      Fl_Box* card5_5;
      Fl_Box* card5_6;
      Fl_Box* card5_7;
      Fl_Box* card5_8;
      Fl_Box* card5_9;
      Fl_Box* card5_10;

      //player 6
      Fl_Box* player6_value;
      Fl_Box* card6_1;
      Fl_Box* card6_2;
      Fl_Box* card6_3;
      Fl_Box* card6_4;
      Fl_Box* card6_5;
      Fl_Box* card6_6;
      Fl_Box* card6_7;
      Fl_Box* card6_8;
      Fl_Box* card6_9;
      Fl_Box* card6_10;

      //player 7
      Fl_Box* player7_value;
      Fl_Box* card7_1;
      Fl_Box* card7_2;
      Fl_Box* card7_3;
      Fl_Box* card7_4;
      Fl_Box* card7_5;
      Fl_Box* card7_6;
      Fl_Box* card7_7;
      Fl_Box* card7_8;
      Fl_Box* card7_9;
      Fl_Box* card7_10;

      Fl_Button* start;
      Fl_Button* quit;
      Fl_Input* name;

      void create_dealer_group();
      void create_player1();
      void create_player2();
      void create_player3();
      void create_player4();
      void create_player5();
      void create_player6();
      void create_player7();

      void card_to_string(Fl_Box** box, UberCasino::card_t c);
      void resetGame();

   private:
      static void cb_start(Fl_Widget* o, void* v);
      inline void cb_start_i(Fl_Widget* b, void* d);
 
      static void cb_quit(Fl_Widget* o, void* v);
      inline void cb_quit_i(Fl_Widget* b, void* d);

};

#endif
